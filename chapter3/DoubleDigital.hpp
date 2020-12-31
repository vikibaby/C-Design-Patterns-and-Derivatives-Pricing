#ifndef DOUBLEDIGITAL_HPP
#define DOUBLEDIGITAL_HPP
#include "PayOff2.hpp"

class PayOffDoubleDigital: public PayOff
{
public:
  PayOffDoubleDigital(double LowerLevel_,double UpperLevel_);

  virtual double operator()(double Spot)const;
  virtual ~PayOffDoubleDigital(){}

private:
  double LowerLevel;
  double UpperLevel;
};

#endif
