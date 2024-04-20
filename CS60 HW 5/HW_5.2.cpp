#include "dUSet.h"
#include <iostream>

using namespace std;

int main() {

  DynamicBag b;
  b.insert(5);
  b.insert(70);
  for(int i=0; i<5; i++)
    b.insert(i+1);
  cout<<b<<endl;
  b.insert(2);
  b.insert (4);
  b.erase(5);
  cout<<b<<endl;

  dUSet d1 = dUSet();
  dUSet d2 = dUSet(b);

  cout << "Default Constructed dUSet: " << d1 << endl;
  cout << d2 << endl;

  d2.insert(5);
  d2.insert(2);

  cout << d2 << endl;


  return 0;
}
