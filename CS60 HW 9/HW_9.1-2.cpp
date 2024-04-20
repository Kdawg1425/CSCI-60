#include <iostream>
#include "lbag.h"
using namespace std;

int main() {
  lbag<int> a;
  lbag<int> b;
  lbag<int> c;
  lbag<int> d;
  b.insert(4);
  b.insert(6);
  b.insert(7);
  b.insert(1);
  c.insert(3);
  c.insert(6);
  c.insert(3);
  d.insert(1);
  d.insert(2);
  d.insert(9);
  d.insert(2);
  cout << "B: " << b << endl;
  cout << "C: " << c << endl;
  cout << endl;
  b += c;
  cout << "B: " << b << endl;
  cout << endl;
  a = c + d;
  cout << "A: " << a << endl;
  cout << endl;
  a.erase_one(2);
  cout << "A: " << a << endl;
  cout << endl;
  a.erase(3);
  cout << "A: " << a << endl;
  cout << endl;



  return 0;
}
