#include "automobile.h"
#include "pickup.h"
#include "van.h"
#include <iostream>

using namespace std;

int main(){
  int size = 10;
  bool parklot[size];
  Automobile car1 = Automobile();
  Automobile car2 = Automobile("Honda", "Civic", 2019, 2500.0, 2);
  cout << car2.make() << " " << car2.model() << " " << car2.year() << " " << car2.price() << " " << car2.stall();
  cout << endl;
  cout << car2.park(parklot, size) << endl;
  cout << car2.make() << " " << car2.model() << " " << car2.year() << " " << car2.price() << " " << car2.stall();
  cout << endl;

  Pickup car3 = Pickup();
  Pickup car4 = Pickup("Ford", "Thundra", 2018, 3000.0, 5, 100, false);
  cout << car4.make() << " " << car4.model() << " " << car4.year() << " " << car4.price() << " " << car4.stall() <<
  " " << car4.capacity() << " " << car4.extended() << endl;

  car4.park(parklot,size);
  cout << car4.make() << " " << car4.model() << " " << car4.year() << " " << car4.price() << " " << car4.stall() <<
  " " << car4.capacity() << " " << car4.extended() << endl;

  Van car5 = Van();
  Van car6 = Van("Ford", "Transit", 2020, 3500.0, 3, 6);
  Van car7 = Van("Ford", "Bus", 2020, 3500.0, 0, 10);
  cout << car6.park(parklot, size) << endl;
  cout << car7.park(parklot, size) << endl;
  cout << car6.make() << " " << car6.model() << " " << car6.year() << " " << car6.price() << " " << car6.stall() <<
  " " << car6.seat() << endl;
  cout << car7.make() << " " << car7.model() << " " << car7.year() << " " << car7.price() << " " << car7.stall() <<
  " " << car7.seat() << endl;
}
