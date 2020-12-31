#ifndef SIMPLEMC_HPP
#define SIMPLEMC_HPP
#include "PayOff1.hpp"

double SimpleMonteCarlo2(PayOff& thePayOff, double Expiry, double Spot, double Vol,double r,unsigned long NumberOfPaths);

#endif
