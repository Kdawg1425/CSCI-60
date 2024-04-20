#include <iostream>

using namespace std;


//Pre: Type variable can only be a numerical type in order
//     for the code to work, because are subtracting each other.
//Post: Returns the absolute value of the difference of a and b.
template <typename T>
T abs(T a, T b) {
  if((a-b) > (b-a)) {
    return (a-b);
  }
  else {
    return (b-a);
  }
}

int main() {
  cout << abs(11,7) << endl;
  cout << abs(7,11) << endl;
}
