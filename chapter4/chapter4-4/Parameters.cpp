#include "Parameters.hpp"

Parameters::Parameters(const ParametersInner& innerObject)
{
  InnerObjectPtr = innerObject.clone();
}

Parameters::Parameters(const Parameters& original)
{
  InnerObjectPtr = original.InnerObjectPtr->clone();
}

Parameters& Parameters::operator = (const Parameters& original)
{
  if (this !=  &original)
  {
    delete InnerObjectPtr;
    InnerObjectPtr = original.InnerObjectPtr->clone();
  }
  return *this;
}

Parameters::~Parameters()
{
  delete InnerObjectPtr;
}

double Parameters::Mean(double time1, double time2) const
{
  double total = Intergal(time1,time2);
  return total/(time2-time1);
}

double Parameters::RootMeanSquare(double time1, double time2) const
{
  double total = IntergalSquare(time1,time2);
  return total/(time2-time1);
}

ParametersConstant::ParametersConstant(double constant)
{
  Constant = constant;
  ConstantSquare =  constant* constant;
}

ParametersInner* ParametersConstant::clone() const
{
  return new ParametersConstant(*this);
}

double ParametersConstant::Intergal(double time1, double time2) const
{
  return (time2-time1)*Constant;
}

double ParametersConstant::IntergalSquare(double time1, double time2) const
{
  return (time2-time1)*ConstantSquare;
}
