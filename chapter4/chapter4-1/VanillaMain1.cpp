#include <iostream>
#include "DoubleDigital.hpp"
#include "PayOff2.hpp"
#include "SimpleMC3.hpp"
#include "Vanilla1.hpp"


using namespace std;

int main(){
  double Expiry;
  double Low,Up;
  double Spot;
  double Vol;
  double r;
  unsigned long NumberOfPaths;

  cout << "\nEnter expiry\n";
  cin >> Expiry;

  cout << "\nEnter low barrier\n";
  cin >> Low;

  cout << "\nEnter up barrier\n";
  cin >> Up;

  cout << "\nEnter spot\n";
  cin >> Spot;

  cout << "\nEnter vol\n";
  cin >> Vol;

  cout << "\nEnter r\n";
  cin >> r;

  cout << "\nEnter Number Of Paths\n";
  cin >> NumberOfPaths;

  PayOffDoubleDigital thePayOff(Low,Up);

  VanillaOption theOption(thePayOff, Expiry);

  double result= SimpleMonteCarlo3(theOption,Spot,Vol,r,NumberOfPaths);
  cout<<"\n the prices are"<<result << "\n";
  return 0;

}
