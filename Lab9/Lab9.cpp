#include "lbiguint.h"
#include "LabNode.h"
#include <iostream>

using namespace std;

int main() {
  lbiguint b1 = lbiguint();
  lbiguint b2 = lbiguint("1472");
  cout << b2.size() << endl;
  cout << b2[1] << endl;
  cout << b2 << endl;
  b1 = b2;
  cout << b1 << endl;
}
