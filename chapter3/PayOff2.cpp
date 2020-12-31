#include <algorithm> //max

#include "PayOff2.hpp"

using namespace std;

PayOffCall::PayOffCall(double Strike_):Strike(Strike_){}

double PayOffCall::operator()(double Spot)const{
  return max(Spot - Strike,0.0);
}

PayOffPut::PayOffPut(double Strike_):Strike(Strike_){}

double PayOffPut::operator()(double Spot)const{
  return max(Strike - Spot,0.0);
}
