#include <config.h>
#include "Dirichlet.h"

#include <sampler/GraphView.h>
#include <rng/RNG.h>

#include <cmath>
#include <algorithm>
#include <cfloat>

using std::copy;
using std::exp;
using std::log;
using std::string;
using std::vector;

static vector<double> initValue(GraphView const *gv, unsigned int chain)
{
    vector<double> ivalue(gv->length());
    gv->getValue(ivalue, chain);
    return ivalue;
}

namespace bugs {

DirchMetropolis::DirchMetropolis(GraphView const *gv, unsigned int chain)
    : RWMetropolis(initValue(gv, chain), 0.1),
      _gv(gv), _chain(chain), _s(1)
{
}

void DirchMetropolis::step(vector<double> &value,  double step, RNG *rng) const
{
    //Random walk on a log scale. 
    for (unsigned int i = 0; i < value.size(); ++i) {
	value[i] *= exp(step * rng->normal());
    }
}

void DirchMetropolis::getValue(vector<double> &value) const
{
    _gv->getValue(value, _chain);
    for (unsigned int i = 0; i < value.size(); ++i) {
	value[i] *= _s;
    }
}

void DirchMetropolis::setValue(vector<double> const &value)
{
    double s = 0;
    for (unsigned int i = 0; i < value.size(); ++i) {
	s += value[i];
    }
    //Make a scaled down copy of the value
    vector<double> v = value;
    for (unsigned int i = 0; i < v.size(); ++i) {
	v[i] /= s;
    }

    _gv->setValue(v, _chain);
    _s = s;
}

double DirchMetropolis::logDensity() const
{
    // We need to add a penalty based on _s to stop the random walk
    // going off to infinity. This penalty is based on a normal 
    // distribution for log(_s) with mean 0 and variance 0.1.
    
    double logS = log(_s);
    return _gv->logFullConditional(_chain) - 5 * logS * logS;
}

double DirchMetropolis::logJacobian(vector<double> const &value) const
{
    //Compensate for random walk on log scale

    double lj = 0;
    for (unsigned int i = 0; i < value.size(); ++i) {
        if (value[i]) {
	   lj += log(value[i]);
        }
    }
    return lj;
}

string DirchMetropolis::name() const
{
    return "DirchMetropolis";
}

}
