#include <cmath>
#include "SimpleMC3.hpp"
#include "Random1.hpp"

using namespace std;


double SimpleMonteCarlo3( const VanillaOption& TheOption,
                          double Spot,
                          double Vol,
                          double r,
                          unsigned long NumberOfPaths)
{
  double Expiry = TheOption.GetExpiry();
  double variance = Vol * Vol * Expiry;
  double rootvariance = sqrt(variance);
  double itoCorrection = -0.5 * variance;

  double movedSpot = Spot*exp(r* Expiry + itoCorrection);
  double thisSpot;
  double runningSum = 0;

  for(unsigned long i = 0; i < NumberOfPaths; i++){
    double thisGaussian = GetOneGuassianByBoxMuller();
    thisSpot = movedSpot*exp(rootvariance*thisGaussian);
    double thisPayoff = TheOption.OptionPayOff(thisSpot);
    runningSum += thisPayoff;
  }
  double mean = runningSum/NumberOfPaths;
  mean *= exp(-r*Expiry);
  return mean;

}
