//                                               -*- C++ -*-
/**
 *  @brief Chebychev polynomial factory
 *
 *  Copyright 2005-2016 Airbus-EDF-IMACS-Phimeca
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
 *  You should have received a copy of the GNU Lesser General Public
 *  along with this library.  If not, see <http://www.gnu.org/licenses/>.
 *
 */
#ifndef OPENTURNS_CHEBYCHEVFACTORY_HXX
#define OPENTURNS_CHEBYCHEVFACTORY_HXX

#include "openturns/OrthogonalUniVariatePolynomialFactory.hxx"

BEGIN_NAMESPACE_OPENTURNS



/**
 * @class ChebychevFactory
 *
 * Chebychev polynomial factory
 */

class OT_API ChebychevFactory
  : public OrthogonalUniVariatePolynomialFactory
{
  CLASSNAME;
public:

  /** Default constructor */
  ChebychevFactory();

  /** Virtual constructor */
  virtual ChebychevFactory * clone() const;

  /** Calculate the coefficients of recurrence a0n, a1n, a2n such that
      Pn+1(x) = (a0n * x + a1n) * Pn(x) + a2n * Pn-1(x) */
  Coefficients getRecurrenceCoefficients(const UnsignedInteger n) const;

  /** Roots of the polynomial of degree n as the eigenvalues of the associated matrix */
  NumericalPoint getRoots(const UnsignedInteger n) const;

  /** Nodes and weights of the polynomial of degree n as the eigenvalues of the associated matrix, to build quadrature rules */
  NumericalPoint getNodesAndWeights(const UnsignedInteger n,
                                    NumericalPoint & weights) const;

  /** String converter */
  String __repr__() const;

private:

} ; /* class ChebychevFactory */


END_NAMESPACE_OPENTURNS

#endif /* OPENTURNS_CHEBYCHEVFACTORY_HXX */
