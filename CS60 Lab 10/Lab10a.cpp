#include <iostream>
#include "bag.h"

using namespace std;

int main() {
  size_t size = 5;
  int a[size] = {1,2,3,4,5};
  bag b = bag(a,size);
  for(auto i: b) {
    cout << *i << endl; 
  }
}
