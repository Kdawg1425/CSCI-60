#include "dbiguint.h"
#include <iostream>

using namespace std;

int main() {
  dbiguint b1 = dbiguint();
  dbiguint b2 = dbiguint("127");
  dbiguint b3 = dbiguint("25");
  dbiguint b4 = dbiguint("33");

  b2 *= b3;
  cout << b2;

  b1 = b3 * b4;
  cout << b1;

  return 0;
}
