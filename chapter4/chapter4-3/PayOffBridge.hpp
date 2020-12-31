#ifndef PAYOFFBRIDGE_HPP
#define PAYOFFBRIDGE_HPP

#include "PayOff3.hpp"

class PayOffBridge
{
  public:
    PayOffBridge(const PayOff& innerPayOff);
    
    PayOffBridge(const PayOffBridge& original);

    inline double operator()(double Spot) const;
    ~PayOffBridge();
    PayOffBridge& operator=(const PayOffBridge& original);

  private:
    PayOff* ThePayOffPtr;
};

inline double PayOffBridge::operator()(double Spot)const
{
  return ThePayOffPtr->operator()(Spot);
}

#endif
