#include <iostream>
#include "bag.h"
#include "dbiguint.h"

using namespace std;

int main() {
  cout << "Part A:" << endl;
  int arr[5] = {1,2,3,4,5};
  bag<int> b1(arr,5);
  for(auto i : b1) {
    cout << i << " ";
  }
  cout << endl;
  bag<int>::iterator j;
  for(j=b1.begin(); j!=b1.end(); j++) {
    cout << *j << " ";
  }
  cout << endl;
  cout << endl;
  cout << "Part B:" << endl;
  dbiguint b2 = dbiguint("001346");
  cout << b2;
  b2.clean();
  cout << b2;
}
