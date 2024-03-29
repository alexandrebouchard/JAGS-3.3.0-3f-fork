#ifndef DMULTI_H_
#define DMULTI_H_

#include <distribution/VectorDist.h>

struct RNG;

namespace bugs {

/**
 * <pre>
 * X[] ~ dmulti(p[], N)
 * f(x | p, N) = prod (p^x) ; sum(x) = N
 * </pre>
 * @short Multinomial distribution
 */
class DMulti : public VectorDist {
public:
  DMulti();

  double logDensity(double const *x, unsigned int length, PDFType tpye, 
		    std::vector<double const *> const &parameters,
		    std::vector<unsigned int> const &lengths,
		    double const *lower, double const *upper) const;
  void randomSample(double *x, unsigned int length,
		    std::vector<double const *> const &parameters,
		    std::vector<unsigned int> const &lengths,
		    double const *lower, double const *upper, RNG *rng) const;
  void typicalValue(double *x, unsigned int length,
		    std::vector<double const *> const &par,
		    std::vector<unsigned int> const &lengths,
		    double const *lower, double const *upper) const;
  /**
   * Checks that elements of p lie in range (0,1) and 
   * and sum to 1. Checks that N >= 1
   */
  bool checkParameterValue(std::vector<double const *> const &parameters,
                           std::vector<unsigned int> const &lengths)
      const;
  /** Checks that N is a scalar */
  bool checkParameterLength(std::vector<unsigned int> const &lengths) const;
  /** Checks that N is discrete-valued */
  bool checkParameterDiscrete(std::vector<bool> const &mask) const;
  unsigned int length(std::vector<unsigned int> const &dim) const;
  void support(double *lower, double *upper, unsigned int length,
	       std::vector<double const *> const &parameters,
	       std::vector<unsigned int> const &lengths) const;
  bool isSupportFixed(std::vector<bool> const &fixmask) const;
  unsigned int df(std::vector<unsigned int> const &lengths) const;
  bool isDiscreteValued(std::vector<bool> const &mask) const;
  double KL(std::vector<double const *> const &par1,
	    std::vector<double const *> const &par2,
	    std::vector<unsigned int> const &lengths) const;
};

}

#endif /* DMULTI_H_ */
