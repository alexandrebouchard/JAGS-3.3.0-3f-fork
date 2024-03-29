#include <config.h>
#include <util/dim.h>
#include <util/nainf.h>
#include "DMNorm.h"
#include "DMT.h"

#include <lapack.h>
#include <matrix.h>

#include <cmath>
#include <vector>

#include <JRmath.h>

using std::vector;

namespace bugs {

DMT::DMT()
  : ArrayDist("dmt", 3) 
{}

double DMT::logDensity(double const *x, unsigned int m, PDFType type,
		       vector<double const *> const &parameters,
		       vector<vector<unsigned int> > const &dims,
		       double const *lower, double const *upper) const
{
    double const * mu = parameters[0];
    double const * T = parameters[1];
    double k = parameters[2][0];

    /* Calculate inner product ip = t(x - mu) %*% T %*% (x - mu) */
    double ip = 0;
    double * delta = new double[m];
    for (unsigned int i = 0; i < m; ++i) {
	delta[i] = x[i] - mu[i];
	double const *Ti = T + i*m;
	ip += (delta[i] * Ti[i] * delta[i]);
	for (unsigned int j = 0; j < i; ++j) {
	    ip += 2 * delta[i] * Ti[j] * delta[j];
	}
    }
    delete [] delta;

    double d = m; // Avoid problems with integer division
    if (type == PDF_PRIOR) {
	//No need to calculate normalizing constant
	return -((k + d)/2) * log(1 + ip/k);
    }
    else {
	return -((k + d)/2) * log(1 + ip/k) + logdet(T, m)/2 +
	    lgammafn((k + d)/2) - lgammafn(k/2) - (d/2) * log(k) - 
	    (d/2) * log(M_PI);
    }
}

void DMT::randomSample(double *x, unsigned int length,
		       vector<double const *> const &parameters,
		       vector<vector<unsigned int> > const &dims,
		       double const *lower, double const *upper, RNG *rng) const
{

    double const * mu = parameters[0];
    double const * T = parameters[1];
    double k = *parameters[2];

    DMNorm::randomsample(x, mu, T, true, length, rng);
    double C = sqrt(rchisq(k, rng)/k);
    for (unsigned int i = 0; i < length; ++i) {
	x[i] = mu[i] + (x[i] - mu[i]) / C;
    }
}

bool DMT::checkParameterDim(vector<vector<unsigned int> > const &dims) const
{
  if (!isVector(dims[0]))
    return false;
  if (!isSquareMatrix(dims[1]))
    return false;
  if (dims[0][0] != dims[1][0])
    return false;
  if (!isScalar(dims[2]))
      return false;
  return true;
}

vector<unsigned int> DMT::dim(vector<vector<unsigned int> > const &dims) const
{
    return dims[0];
}

bool
DMT::checkParameterValue(vector<double const *> const &parameters,
			    vector<vector<unsigned int> > const &dims) const
{
    unsigned int n = dims[0][0];
    double const *T = parameters[1];
    double k = *parameters[2];

    if (k < 2) {
	return false;
    }
    else {
	//NB Not checking positive definiteness
	return check_symmetry(T, n);
    }
}


void DMT::support(double *lower, double *upper, unsigned int length,
		     vector<double const *> const &parameters,
		     vector<vector<unsigned int> > const &dims) const
{
    for (unsigned int i = 0; i < length; ++i) {
	lower[i] = JAGS_NEGINF;
	upper[i] = JAGS_POSINF;
    }
}

void DMT::typicalValue(double *x, unsigned int length,
		       vector<double const *> const &parameters,
		       vector<vector<unsigned int> > const &dims,
		       double const *lower, double const *upper) const
{
    for (unsigned int i = 0; i < length; ++i) {
	x[i] = parameters[0][i];
    }
}

bool DMT::isSupportFixed(vector<bool> const &fixmask) const
{
    return true;
}

}
