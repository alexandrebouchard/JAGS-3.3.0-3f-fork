#include <config.h>
#include <graph/LinkNode.h>
#include <function/LinkFunction.h>
#include <util/dim.h>

#include <stdexcept>
#include <vector>
#include <string>
#include <math.h>

class GraphMarks;

using std::vector;
using std::string;
using std::set;
using std::logic_error;
using std::runtime_error;

LinkNode::LinkNode(LinkFunction const *function, 
		   vector<Node const *> const &parents)
    : LogicalNode(vector<unsigned int>(1,1), parents, function), 
      _func(function)
{
    if (!isScalar(parents[0]->dim())) {
	throw runtime_error("Invalid parent dims in LinkNode");
    }

    // Initialize if fully observed 
    if (isObserved()) {
	for (unsigned int ch = 0; ch < _nchain; ++ch) {
	    deterministicSample(ch);
	}
    }
}

void LinkNode::deterministicSample(unsigned int chain)
{
    _data[chain] = _func->inverseLink(*_parameters[chain][0]);
}

bool LinkNode::checkParentValues(unsigned int chain) const
{
    return true;
}
   
DeterministicNode *
LinkNode::clone(vector<Node const *> const &parents) const
{
    return new LinkNode(_func, parents);
}

double LinkNode::eta(unsigned int chain) const
{
    return *_parameters[chain][0];
}

double LinkNode::grad(unsigned int chain) const
{
    return _func->grad(*_parameters[chain][0]);
}

string const &LinkNode::linkName() const
{
    return _func->linkName();
}
