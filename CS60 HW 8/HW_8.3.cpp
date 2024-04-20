#include <iostream>
#include <ctime>

using namespace std;

void reverse(int a[], int first, int last);

int main() {
  int size = 10;
  int a1[size];
  for(int i=0; i<size; i++){
    a1[i] = (rand()%100)+1;
  }
  for(int i = 0; i < size; i++) {
    cout << a1[i] << " ";
  }
  cout << endl;
  reverse(a1,0,9);
  for(int i = 0; i < size; i++) {
    cout << a1[i] << " ";
  }
  cout << endl;
}


void reverse(int a[], int first, int last) {
  int temp;
  if(first >= last) {
    return;
  }
  else {
    temp = a[first];
    a[first] = a[last];
    a[last] = temp;
    reverse(a,first+1,last-1);
  }
}
