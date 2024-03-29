#include <config.h>
#include "matrix.h"
#include <util/dim.h>
#include "Inverse.h"

using std::vector;

namespace bugs {

    Inverse::Inverse (): ArrayFunction ("inverse", 1)
    {
    }

    void Inverse::evaluate (double *value, vector<double const *> const &args,
			    vector<vector<unsigned int> > const &dims) const
    {
	//FIXME: RETURN VALUE IGNORED
	inverse_spd (value, args[0], dims[0][0]);
    }

    bool 
    Inverse::checkParameterDim (vector<vector<unsigned int> > const &dims) const
    {
	return isSquareMatrix(dims[0]) || isScalar(dims[0]);
    }

    bool 
    Inverse::checkParameterValue(vector<double const *> const &args,
				 vector<vector<unsigned int> > const &dims) const
    {
	return check_symmetry(args[0], dims[0][0]);
    }

    vector<unsigned int> 
    Inverse::dim (vector<vector<unsigned int> > const &dims) const
    {
	return dims[0];
    }

}
