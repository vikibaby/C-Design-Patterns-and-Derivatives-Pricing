#include <iostream>
#include <cmath>
#include "Random1.hpp"
using namespace std;

double SimpleMonteCarlo1(double Expiry,double Strike, double Spot, double Vol,double r,unsigned long NumberOfPaths){
  double variance = Vol * Vol * Expiry;
  double rootvariance = sqrt(variance);
  double itoCorrection = -0.5 * variance;

  double movedSpot = Spot*exp(r* Expiry + itoCorrection);
  double thisSpot;
  double runningSum = 0;


  for(unsigned long i = 0; i < NumberOfPaths; i++){
    double thisGaussian = GetOneGuassianBynormal();
    thisSpot = movedSpot*exp(rootvariance*thisGaussian);
    double thisPayoff = thisSpot - Strike;
    thisPayoff = thisPayoff > 0 ? thisPayoff : 0;
    runningSum += thisPayoff;
  }
  double mean = runningSum/NumberOfPaths;
  mean *= exp(-r*Expiry);
  return mean;
}

int main(){
    double Expiry;
    double Strike;
    double Spot;
    double Vol;
    double r;
    unsigned long NumberOfPaths;
    cout << "\nEnter expiry\n";
    cin >> Expiry;

    cout << "\nEnter strike\n";
    cin >> Strike;

    cout << "\nEnter spot\n";
    cin >> Spot;

    cout << "\nEnter vol\n";
    cin >> Vol;

    cout << "\nEnter r\n";
    cin >> r;

    cout << "\nEnter Number Of Paths\n";
    cin >> NumberOfPaths;

    double result = SimpleMonteCarlo1(Expiry,Strike,Spot,Vol,r,NumberOfPaths);
    cout<< "the price is"<<result<<"\n";

    return 0;
  }
