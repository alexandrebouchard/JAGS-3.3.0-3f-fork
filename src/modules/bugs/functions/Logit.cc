#include <config.h>
#include "Logit.h"

#include <cmath>

using std::vector;
using std::log;

namespace bugs {

    Logit::Logit ():ScalarFunction ("logit", 1)
    {
    }

    double Logit::evaluate(vector <double const *> const &args) const
    {
	double arg = *args[0];
	return log(arg) - log(1 - arg);
    }

    bool Logit::checkScalarValue (vector <double const *> const &args) const
    {
	double arg = *args[0];
	return (arg >= 0 && arg <= 1);
    }

}
