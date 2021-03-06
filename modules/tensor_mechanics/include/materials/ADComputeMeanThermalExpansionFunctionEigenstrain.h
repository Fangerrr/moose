//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html

#pragma once

#include "ADComputeMeanThermalExpansionEigenstrainBase.h"

template <ComputeStage>
class ADComputeMeanThermalExpansionFunctionEigenstrain;

declareADValidParams(ADComputeMeanThermalExpansionFunctionEigenstrain);

/**
 * ADComputeMeanThermalExpansionFunctionEigenstrain computes an eigenstrain for thermal
 * expansion according to a mean thermal expansion function.
 */
template <ComputeStage compute_stage>
class ADComputeMeanThermalExpansionFunctionEigenstrain
  : public ADComputeMeanThermalExpansionEigenstrainBase<compute_stage>
{
public:
  static InputParameters validParams();

  ADComputeMeanThermalExpansionFunctionEigenstrain(const InputParameters & parameters);

protected:
  /*
   * Get the reference temperature for the mean thermal expansion relationship.  This is
   * the temperature at which \f$\delta L = 0\f$.
   */
  virtual Real referenceTemperature() override;

  /*
   * Compute the mean thermal expansion coefficient relative to the reference temperature.
   * This is the linear thermal strain divided by the temperature difference:
   * \f$\bar{\alpha}=(\delta L / L)/(T - T_{ref})\f$.
   * param temperature  temperature at which this is evaluated
   */
  virtual ADReal meanThermalExpansionCoefficient(const ADReal & temperature) override;

  const Function & _thermal_expansion_function;

  const Real & _thexp_func_ref_temp;

  usingComputeMeanThermalExpansionEigenstrainBaseMembers;
};
