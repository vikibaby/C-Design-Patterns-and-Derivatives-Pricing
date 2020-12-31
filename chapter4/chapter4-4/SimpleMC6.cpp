#include <cmath>
#include "SimpleMC6.hpp"
#include "Random1.hpp"

using namespace std;


double SimpleMonteCarlo4( const VanillaOption& TheOption,
                          double Spot,
                          const Parameters& Vol,
                          const Parameters& r,
                          unsigned long NumberOfPaths)
{
  double Expiry = TheOption.GetExpiry();
  double variance = Vol.IntergalSquare(0,Expiry);
  double rootvariance = sqrt(variance);
  double itoCorrection = -0.5 * variance;

  double movedSpot = Spot*exp(r.IntergalSquare(0,Expiry) + itoCorrection);
  double thisSpot;
  double runningSum = 0;

  for(unsigned long i = 0; i < NumberOfPaths; i++)
  {
    double thisGaussian = GetOneGuassianByBoxMuller();
    thisSpot = movedSpot*exp(rootvariance*thisGaussian);
    double thisPayoff = TheOption.OptionPayOff(thisSpot);
    runningSum += thisPayoff;
  }
  double mean = runningSum/NumberOfPaths;
  mean *= exp(-r.Intergal(0,Expiry));
  return mean;

}
