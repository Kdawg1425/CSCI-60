#include "biguint.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
  biguint num1 = biguint();
  biguint num2 = biguint("1472");
  biguint num3 = biguint("1119");
  biguint num4 = biguint("550");
  biguint num5 = biguint("254");
  biguint num6 = biguint("254");

  cout << num2;
  num2+=num3;
  cout << num2;

//Code lines 26-44 encompasses HW problem 2
//Code lines 26 & 27 cover #8 of the lab
//Code lines 29-44 cover #9 of the lab
//Code lines 46-49 encompasses HW problem 3 and cover #10 of the lab
//Code lines 51-52 encompasses HW problem 4 and cover #11 of the lab

  num1 = num4 + num5;
  cout << num1;

  cout << (num4.compare(num5)) << endl;
  cout << (num5.compare(num4)) << endl;
  cout << (num5.compare(num6)) << endl;
  cout << endl;

  cout << (num4 < num5) << endl;
  cout << (num4 > num5) << endl;
  cout << (num5 <= num6) << endl;
  cout << (num5 >= num6) << endl;
  cout << endl;

  cout << (num5 != num6) << endl;
  cout << (num5 != num4) << endl;
  cout << (num5 == num6) << endl;
  cout << (num5 == num4) << endl;
  cout << endl;

  num3 -= num4;
  cout << num3;
  num1 = num4 - num5;
  cout << num1;

  string result = num6.toString();
  cout << result << endl;

  return 0;
}
