#include <config.h>

#include "CODA.h"
#include <model/BUGSModel.h>
#include <model/Monitor.h>
#include <model/NodeArray.h>
#include <model/MonitorFactory.h>
#include <graph/StochasticNode.h>
#include <graph/GraphMarks.h>
#include <graph/Node.h>
#include <rng/RNG.h>
#include <sampler/Sampler.h>
#include <util/dim.h>

#include <list>
#include <utility>
#include <stdexcept>
#include <fstream>
#include <cmath>

using std::vector;
using std::ofstream;
using std::list;
using std::pair;
using std::string;
using std::logic_error;
using std::runtime_error;
using std::map;

/* 
   Nodes accessible to the user in a BUGSModel are identified
   by a variable name and range of indices 
*/
typedef pair<string, Range> NodeId;

BUGSModel::BUGSModel(unsigned int nchain)
    : Model(nchain), _symtab(this)
{
}

BUGSModel::~BUGSModel()
{
    for (list<MonitorInfo>::iterator i = _bugs_monitors.begin();
	 i != _bugs_monitors.end(); ++i)
    {
	Monitor const *monitor = i->monitor();
	delete monitor; //FIXME: constant pointer
    }

}

SymTab &BUGSModel::symtab()
{
    return _symtab;
}

Node *BUGSModel::getNode(string const &name, Range const &target_range)
{
    NodeArray *array = _symtab.getVariable(name);
    if (!array) {
	return 0;
    }
    Range range = target_range;
    if (isNULL(range)) {
	range = array->range();
    }
    else if (array->range().ndim(false) != target_range.ndim(false)) {
	return 0; //Dimension mismatch
    }
    else if (!array->range().contains(target_range)) {
	return 0; //Indices out of range
    }
    unsigned int NNode = graph().size();
    Node *node = array->getSubset(range, *this);
    if (graph().size() != NNode) {
	addExtraNode(node); // Node was newly allocated
    }
    return node;
}

void BUGSModel::coda(vector<NodeId> const &node_ids, string const &stem,
		     string &warn)
{
    warn.clear();

    list<MonitorControl> dump_nodes;
    for (unsigned int i = 0; i < node_ids.size(); ++i) {
	string const &name = node_ids[i].first;
	Range const &range = node_ids[i].second;
	list<MonitorInfo>::const_iterator p;
	for (p = _bugs_monitors.begin(); p != _bugs_monitors.end(); ++p) {
	    if (p->name() == name && p->range() == range) {
		break;
	    }
	}
	if (p == _bugs_monitors.end()) {
	    string msg = string("No Monitor ") + name + 
		print(range) + " found.\n";
	    warn.append(msg);
	}
	else {
	    list<MonitorControl>::const_iterator q; 
	    for (q = monitors().begin(); q != monitors().end(); ++q) {
		if (q->monitor() == p->monitor()) {
		    dump_nodes.push_back(*q);		    
		    break;
		}
	    }
	    if (q == monitors().end()) {
		throw logic_error(string("Monitor ") + name + print(range) +
				  "not found");
	    }
	}
    }

    if (dump_nodes.empty()) {
	warn.append("There are no matching monitors\n");
	return;
    }

    CODA0(dump_nodes, stem, warn);    
    CODA(dump_nodes, stem, nchain(), warn);
    TABLE0(dump_nodes, stem, warn);    
    TABLE(dump_nodes, stem, nchain(), warn);
}

void BUGSModel::coda(string const &stem, string &warn)
{
    warn.clear();
    
    if (monitors().empty()) {
	warn.append("There are no monitors\n");
	return;
    }
    
    CODA0(monitors(), stem, warn);    
    CODA(monitors(), stem, nchain(), warn);
    TABLE0(monitors(), stem, warn);    
    TABLE(monitors(), stem, nchain(), warn);
}


void BUGSModel::setParameters(map<string, SArray> const &param_table,
			      unsigned int chain)
{
    _symtab.writeValues(param_table, chain);


    //Strip off .RNG.seed (user-supplied random seed)
    if (param_table.find(".RNG.seed") != param_table.end()) {
	if (rng(chain) == 0) {
	    throw runtime_error(".RNG.seed supplied but RNG type not set");
	}
	SArray const &seed = param_table.find(".RNG.seed")->second;
	if (seed.length() != 1) {
	    throw runtime_error(".RNG.seed must be a single integer");
	}
	if (seed.value()[0] < 0) {
	    throw runtime_error(".RNG.seed must be non-negative");
	}
	int iseed = static_cast<int>(seed.value()[0]);
	rng(chain)->init(iseed);
    }

    //Strip off .RNG.state (saved state from previous run)
    if (param_table.find(".RNG.state") != param_table.end()) {
	if (rng(chain) == 0) {
	    throw runtime_error(".RNG.state supplied, but RNG type not set");
	}
	SArray const &state = param_table.find(".RNG.state")->second;
	vector<int>(istate);
	//double const *value = state.value();
	vector<double> const &value = state.value();
	for (unsigned int i = 0; i < state.length(); ++i) {
	    istate.push_back(static_cast<int>(value[i]));
	}
	if (rng(chain)->setState(istate) == false) {
	    throw runtime_error("Invalid .RNG.state");
	}
    }
}


bool BUGSModel::setMonitor(string const &name, Range const &range,
			   unsigned int thin, string const &type,
			   string &msg)
{
    for (list<MonitorInfo>::const_iterator i = _bugs_monitors.begin();
	 i != _bugs_monitors.end(); ++i)
    {
	if (i->name() == name && i->range() == range && i->type() == type) {
	    msg = "Monitor already exists and cannot be duplicated";
	    return false; 
	}
    }

    msg.clear();
    Monitor *monitor = 0;

    list<pair<MonitorFactory*, bool> > const &faclist = monitorFactories();
    for(list<pair<MonitorFactory*, bool> >::const_iterator j = faclist.begin();
	j != faclist.end(); ++j)
    {
	if (j->second) {
	    monitor = j->first->getMonitor(name, range, this, type, msg);
	    if (monitor || !msg.empty())
		break;
	}
    }

    if (monitor) {
	addMonitor(monitor, thin);
	_bugs_monitors.push_back(MonitorInfo(monitor, name, range, type));
	return true;
    }
    else {
	return false;
    }
}

bool BUGSModel::deleteMonitor(string const &name, Range const &range,
			      string const &type)
{
    for (list<MonitorInfo>::iterator i = _bugs_monitors.begin();
	 i != _bugs_monitors.end(); ++i)
    {
	if (i->name() == name && i->range() == range && i->type() == type) {
	    Monitor *monitor = i->monitor();
	    removeMonitor(monitor);
	    _bugs_monitors.erase(i);
	    delete monitor; 
	    return true;
	}
    }
    return false;
}

void BUGSModel::samplerNames(vector<vector<string> > &sampler_names) const
{
    sampler_names.clear();
    sampler_names.reserve(_samplers.size());

    for (unsigned int i = 0; i < _samplers.size(); ++i) {

	vector<string> names;	
	vector<StochasticNode *> const &nodes = _samplers[i]->nodes();
	names.reserve(nodes.size()+1);
	
	names.push_back(_samplers[i]->name());
	for (unsigned int j = 0; j < nodes.size(); ++j) {
	    names.push_back(_symtab.getName(nodes[j]));
	}
	sampler_names.push_back(names);
    }    
}
