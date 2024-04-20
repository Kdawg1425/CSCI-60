#include<iostream>
#include<string>

using namespace std;

//Pre: T1 can be any type variable. T2 has to be numerical type variable since
//     it will be compared to and is added too.
//Post: Returns the most frequent item in the array.
// Type variables for T1 need to support the == operator
// Type variables for T2 need to support the ++ operator
template <typename T1, typename T2>
T1 frequent(T1 a[], T2 size) {
  int count;
  int index;
  int temp = 0;
  for(T2 i = T2(); i < size; i++) {
    count = 0;
    for(T2 j = i+1; j < size; j++) {
      if(a[i] == a[j]) {
        count++;
      }
    }
    if(count > temp) {
      index = i;
      count = temp;
    }
  }
  return a[index];
}

int main() {
  int arr[8] = {2,4,5,2,1,7,2,5};
  cout << frequent(arr,8) << endl;
  string arr1[4] = {"Hi","Hello","Hi","Hey"};
  cout << frequent(arr1,4) << endl;
}
