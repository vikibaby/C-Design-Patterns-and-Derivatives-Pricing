#include <iostream>
#include "SimpleMC.hpp"
#include "PayOff2.hpp"

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

  //PayOffCall callPayOff(Strike);
  PayOffCall callPayOff = PayOffCall(Strike);
  PayOffPut putPayOff = PayOffPut(Strike);

  //PayOffPut putPayOff(Strike);

  double resultCall = SimpleMonteCarlo2(callPayOff,Expiry,Spot,Vol,r,NumberOfPaths);
  double resultPut = SimpleMonteCarlo2(putPayOff,Expiry,Spot,Vol,r,NumberOfPaths);

  cout<<"the prices are"<<resultCall<<"for the call and"<<resultPut<<" for the put \n";
  return 0;
}
