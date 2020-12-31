#include <iostream>
#include "SimpleMC6.hpp"
#include "Vanilla3.hpp"
#include "PayOff3.hpp"
#include "Parameters.hpp"



using namespace std;

int main(){
  double Expiry;
  double Strike;
  double Spot;
  double Vol;
  double r;
  unsigned long NumberOfPaths;

  cout << "\nEnter expiry\n";
  cin >> Expiry;

  cout << "\nEnter Strike\n";
  cin >> Strike;

  cout << "\nEnter spot\n";
  cin >> Spot;

  cout << "\nEnter vol\n";
  cin >> Vol;

  cout << "\nEnter r\n";
  cin >> r;

  cout << "\nEnter Number Of Paths\n";
  cin >> NumberOfPaths;

  PayOffCall thePayOff(Strike);
  VanillaOption theOption(thePayOff, Expiry);

  ParametersConstant VolParam(Vol);
  ParametersConstant rParam(r);

  double result= SimpleMonteCarlo4(theOption,Spot,VolParam,rParam,NumberOfPaths);
  cout<<"\n the call prices are"<<result << "\n";

  VanillaOption secondOption(theOption);
  result= SimpleMonteCarlo4(theOption,Spot,VolParam,rParam,NumberOfPaths);
  cout<<"\n the call prices are"<<result << "\n";

  PayOffPut otherPayOff(Strike);
  VanillaOption thirdOption(otherPayOff,Expiry);
  theOption = thirdOption;

  result =  SimpleMonteCarlo4(theOption,Spot,VolParam,rParam,NumberOfPaths);
  cout<<"\n the put prices are"<<result << "\n";

  return 0;

}
