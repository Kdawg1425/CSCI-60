#include "biguint.h"
#include <iostream>
#include <string>
#include "biguint.cpp"

using namespace std;


int main()
{
  biguint num1 = biguint();

  biguint num2 = biguint("1472");
  biguint num3 = biguint("1119");

  cout << num2;
  num2+=num3;
  cout << num2;

  return 0;
}
