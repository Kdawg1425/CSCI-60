#include<iostream>

using namespace std;

int salary(int n);

int main() {
  cout << salary(0) << endl;
  cout << salary(1) << endl;
  cout << salary(2) << endl;
  cout << salary(10) << endl;

}


int salary(int n) {
  if(n == 0) {
    return 50;
  }
  else {
    return salary(n-1)*1.1+5;
  }
}
