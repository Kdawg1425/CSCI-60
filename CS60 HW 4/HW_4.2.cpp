#include "dbiguint.h"
#include <iostream>

using namespace std;

int main() {
  //Below is from the lab. I kept it in to show that my previous functions work
  dbiguint b1 = dbiguint();
  dbiguint b2 = dbiguint("16");
  dbiguint b3 = dbiguint("33");
  cout << b2.size() << endl;
  cout << b2[1] << " " << b2[5] << endl;
  cout << b2 << endl;
  b2.reserve(2);
  cout << b2.size() << endl;
  cout << b2.size() << endl;
  cout << b2 << endl;
  b2 += b3;
  cout << b2 << endl;  //b2's value is now 49

  //Below is HW functions. Might use some dbiguint above
  dbiguint b4 = dbiguint("49");
  dbiguint b5 = dbiguint("352");
  cout << (b4.compare(b3)) << endl;
  cout << (b4.compare(b2)) << endl;
  cout << (b4.compare(b5)) << endl;
  cout << endl;

  b1 = b3 + b4; //Also shows problem 7 of lab (= operator) works
  cout << b1;
  cout << endl;

  cout << (b5 < b4) << endl;
  cout << (b4 < b5) << endl;
  cout << (b4 <= b2) << endl;
  cout << (b5 > b4) << endl;
  cout << (b4 > b5) << endl;
  cout << (b4 >= b2) << endl;
  cout << endl;

  cout << (b4 == b5) << endl;
  cout << (b4 == b2) << endl;
  cout << (b4 != b5) << endl;
  cout << (b4 != b2) << endl;

  dbiguint b6 = dbiguint();
  dbiguint b7 = dbiguint("127");
  cout << "Enter in a number." << endl;
  cin >> b6;
  cout << b6;
  b6 = dbiguint(b7);
  cout << b6;
  cout << endl;

  cout << b2;
  b2 -= b3;
  cout << b2;
  dbiguint b8 = dbiguint("106");
  b8 = b8 - b6;
  cout << b8;
  cout << endl;
  dbiguint b9 = dbiguint("25");
  b6 *= b9;
  cout << b6;
  return 0;
}
