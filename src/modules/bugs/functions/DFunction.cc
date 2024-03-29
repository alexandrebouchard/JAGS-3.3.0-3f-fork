#include <config.h>
#include "RScalarDist.h"
#include "DFunction.h"

using std::vector;
using std::string;

namespace bugs {

    DFunction::DFunction(RScalarDist const *dist)
	: DPQFunction(dist->name(), dist)
    {}
    
    double DFunction::evaluate(vector<double const *> const &args) const
    {
	double x = *args[0];
	vector<double const *> param(args.size() - 1);
	for (unsigned int i = 1; i < args.size(); ++i) {
	    param[i-1] = args[i];
	}
	
	return dist()->d(x, PDF_FULL, param, false);
    }

    bool 
    DFunction::checkParameterValue(vector<double const *> const &args) const
    {
	if (dist()->discrete()) {
	    double x = *args[0];
	    if (x != static_cast<int>(x))
		return false;
	}
	
	return checkArgs(args);
    }
}
