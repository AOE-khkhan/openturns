//                                               -*- C++ -*-
/**
 *  @brief The MixedHistogramUserDefined distribution
 *
 *  Copyright 2005-2019 Airbus-EDF-IMACS-ONERA-Phimeca
 *
 *  This library is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU Lesser General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public License
 *  along with this library.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#ifndef OPENTURNS_MIXEDHISTOGRAMUSERDEFINED_HXX
#define OPENTURNS_MIXEDHISTOGRAMUSERDEFINED_HXX

#include "openturns/DistributionImplementation.hxx"
#include "openturns/Mixture.hxx"

BEGIN_NAMESPACE_OPENTURNS

/**
 * @class MixedHistogramUserDefined
 *
 * The MixedHistogramUserDefined distribution.
 */
class OT_API MixedHistogramUserDefined
  : public DistributionImplementation
{
  CLASSNAME;
public:

  typedef Pointer<DistributionImplementation>   Implementation;

  enum Kind { DISCRETE, CONTINUOUS };

  /** Default constructor */
  MixedHistogramUserDefined();

  /** Parameters constructor */
  MixedHistogramUserDefined(const PointCollection & ticksCollection,
                            const Indices & kind,
                            const Point & probabilityTable);

  /** Comparison operator */
  using DistributionImplementation::operator ==;
  Bool operator ==(const MixedHistogramUserDefined & other) const;
protected:
  Bool equals(const DistributionImplementation & other) const;
public:

  /** String converter */
  String __repr__() const;
  String __str__(const String & offset = "") const;



  /* Interface inherited from Distribution */

  /** Virtual constructor */
  virtual MixedHistogramUserDefined * clone() const;

  /** Get one realization of the distribution */
  Point getRealization() const;
  Sample getSample(const UnsignedInteger size) const;

  /** Get the PDF of the distribution, i.e. P(point < X < point+dx) = PDF(point)dx + o(dx) */
  using DistributionImplementation::computePDF;
  Scalar computePDF(const Point & point) const;

  /** Get the CDF of the distribution, i.e. P(X <= point) = CDF(point) */
  using DistributionImplementation::computeCDF;
  Scalar computeCDF(const Point & point) const;
  using DistributionImplementation::computeComplementaryCDF;
  Scalar computeComplementaryCDF(const Point & point) const;

  /** Get the quantile of the distribution */
  using DistributionImplementation::computeQuantile;
  Point computeQuantile(const Scalar prob,
                            const Bool tail = false) const;

  /** Get the characteristic function of the distribution, i.e. phi(u) = E(exp(I*u*X)) */
  Complex computeCharacteristicFunction(const Scalar x) const;

  /** Get the i-th marginal distribution */
  Distribution getMarginal(const UnsignedInteger i) const;

  /** Get the distribution of the marginal distribution corresponding to indices dimensions */
  Distribution getMarginal(const Indices & indices) const;

  /** Check if the distribution is continuous */
  Bool isContinuous() const;

  /** Check if the distribution is discrete */
  Bool isDiscrete() const;

  /** Check if the distribution is integral */
  Bool isIntegral() const;

  /** Get the standard deviation of the distribution */
  Point getStandardDeviation() const;

  /** Get the skewness of the distribution */
  Point getSkewness() const;

  /** Get the kurtosis of the distribution */
  Point getKurtosis() const;

  /** Get the raw moments of the standardized distribution */
  Point getStandardMoment(const UnsignedInteger n) const;

  /** Get the standard representative in the parametric family, associated with the standard moments */
  Distribution getStandardRepresentative() const;

  /* Interface specific to MixedHistogramUserDefined */

  /** Ticks collection accessor */
  void setTicksCollection(const PointCollection & ticksCollection);
  PointCollection getTicksCollection() const;

  /** Kind accessor */
  void setKind(const Indices & kind);
  Indices getKind() const;

  /** Probability table accessor */
  void setProbabilityTable(const Point & probabilityTable);
  Point getProbabilityTable() const;

  /** Conversion as a Mixture */
  Mixture asMixture() const;

  /** Method save() stores the object through the StorageManager */
  void save(Advocate & adv) const;

  /** Method load() reloads the object from the StorageManager */
  void load(Advocate & adv);

  /** Description accessor */
  void setDescription(const Description & description);

protected:

private:

  /** Compute the mean of the distribution */
  void computeMean() const;

  /** Compute the covariance of the distribution */
  void computeCovariance() const;

  /** Compute the numerical range of the distribution given the parameters values */
  void computeRange();

  /** The main parameter set of the distribution */
  /** Ticks per dimension */
  PersistentCollection<Point> ticksCollection_;

  /** Nature of each marginal (continuous/discrete) */
  Indices kind_;

  /** Probability table as a flat vector (no d-dim array available) */
  Point probabilityTable_;

  /** Cache some data */
  Indices discreteIndices_;
  Indices continuousIndices_;
  IndicesCollection allIndices_;
  Point normalizedProbabilityTable_;

  /** Structures for the alias sampling method */
  mutable Point base_;
  mutable Indices alias_;

}; /* class MixedHistogramUserDefined */

END_NAMESPACE_OPENTURNS

#endif /* OPENTURNS_MIXEDHISTOGRAMUSERDEFINED_HXX */
