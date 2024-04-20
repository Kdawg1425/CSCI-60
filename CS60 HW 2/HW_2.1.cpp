#include "Rational.h"
#include "Rational.cpp"
#include <iostream>
using namespace std;
//To compile the 3-file version, type: g++ main.cpp Rational.cpp
int main(){
  Rational r1 = Rational(1, 2);
  Rational r2(3, 4);
  Rational r;
  Rational r3 = r1*r2;
  Rational r4(2, 3);
  Rational r5(2, 3);
  cout<<r3<<endl;//Must return cout to be able to chain <<
  r3*=r1;
  cout<<r3;
  bool res1 = (r4==r5);
  bool res2 = (r4==r1);
  cout << res1 << endl;
  cout << res2 << endl;
  r2 = r2+r4;
  r1 += r5;
  cout << r1;
  cout << r2;
}
