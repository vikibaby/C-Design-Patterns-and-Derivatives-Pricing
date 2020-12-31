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

  unsigned long optionType;

  cout<<"\n enter 0 for call,otherwise put ";
  cin>>optionType;

  PayOff* thePayOffPtr;

  if(optionType == 0){
    thePayOffPtr = new PayOffCall(Strike);
  }
  else{
    thePayOffPtr = new PayOffPut(Strike);
  }


  double result= SimpleMonteCarlo2(*thePayOffPtr,Expiry,Spot,Vol,r,NumberOfPaths);

  cout<<"\n the prices are"<<result << "\n";
  delete thePayOffPtr;
  return 0;
}
