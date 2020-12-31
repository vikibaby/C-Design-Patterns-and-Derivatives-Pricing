#include <cmath>
#include "SimpleMC.hpp"
#include "Random1.hpp"

double SimpleMonteCarlo2( PayOff& thePayOff,
                          double Expiry,
                          double Spot,
                          double Vol,
                          double r,
                          unsigned long NumberOfPaths)
                          {
          double variance = Vol * Vol * Expiry;
          double rootvariance = sqrt(variance);
          double itoCorrection = -0.5 * variance;

          double movedSpot = Spot*exp(r* Expiry + itoCorrection);
          double thisSpot;
          double runningSum = 0;

          for(unsigned long i = 0; i < NumberOfPaths; i++){
            double thisGaussian = GetOneGuassianByBoxMuller();
            thisSpot = movedSpot*exp(rootvariance*thisGaussian);
            double thisPayoff = thePayOff(thisSpot);
            runningSum += thisPayoff;
          }
          double mean = runningSum/NumberOfPaths;
          mean *= exp(-r*Expiry);
          return mean;
          }
