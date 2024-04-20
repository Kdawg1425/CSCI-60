#include "dbiguint.h"
#include <iostream>
using namespace std;

int main() {
  dbiguint b1 = dbiguint();
  dbiguint b2 = dbiguint("17");
  dbiguint b3 = dbiguint("43");
  cout << b2.size() << endl;
  cout << b2[1] << " " << b2[5] << endl;
  cout << b2 << endl;
  b2.reserve(1);
  cout << b2.size() << endl;
  cout << b2.size() << endl;
  cout << b2 << endl;
  b2 += b3;
  cout << b2 << endl;
}
