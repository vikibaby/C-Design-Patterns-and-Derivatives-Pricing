#ifndef VANILLA_1_HPP
#define VANILLA_1_HPP

#include "PayOff2.hpp"

class VanillaOption
{
public:
  VanillaOption(PayOff& ThePayOff_, double Expiry_);
  double GetExpiry()const;
  double OptionPayOff(double Spot)const;
private:
  double Expiry;
  PayOff& ThePayOff;
};

#endif
