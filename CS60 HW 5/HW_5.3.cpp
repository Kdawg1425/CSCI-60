#include "dSet.h"
#include <iostream>

using namespace std;

int main() {

  DynamicBag b;
  b.insert(5);
  b.insert(70);
  b.insert(4);
  b.insert (2);
  b.insert(5);
  cout<<b<<endl;

  dSet d1 = dSet();
  cout << "Default Constructed dSet: " << d1 << endl;
  dSet d2 = dSet(b);

  cout << d2 << endl;


  d1.insert(3);
  d1.insert(1);
  d1.insert(2);
  d1.insert(1);
  cout << d1;

  return 0;
}
