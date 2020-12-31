#ifndef SIMPLEMC_6_HPP
#define SIMPLEMC_6_HPP

#include "Vanilla3.hpp"
#include "Parameters.hpp"


double SimpleMonteCarlo4( const VanillaOption& TheOption,
                          double Spot,
                          const Parameters& Vol,
                          const Parameters& r,
                          unsigned long NumberOfPaths);
# endif
