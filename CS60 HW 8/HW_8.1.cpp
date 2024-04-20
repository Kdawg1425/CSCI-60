#include <iostream>

using namespace std;

int sequence(int n);

int main() {
  cout << sequence(0) << endl;
  cout << sequence(1) << endl;
  cout << sequence(2) << endl;
  cout << sequence(3) << endl;
  cout << sequence(4) << endl;
  cout << sequence(5) << endl;
  cout << sequence(6) << endl;
  cout << sequence(7) << endl;
  cout << sequence(8) << endl;

}

int sequence(int n) {
  if(n == 0) {
    return 1;
  }
  else if(n == 1) {
    return 1;
  }
  else {
    return sequence(n-2) + (n-1);
  }
}
