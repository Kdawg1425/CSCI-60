#include "pickup.h"

Pickup::Pickup() : Automobile() {
  capacity_ = 0;
  extended_ = false;
}

Pickup::Pickup(std::string imake, std::string imodel, int iyear, double iprice, int istall, int cap, bool ext)
: Automobile(imake, imodel, iyear, iprice, istall) {
  capacity_ = cap;
  extended_ = ext;
}


bool Pickup::park(bool lot[], int size) {
  int spot=size;
  for(int i=0; i<size-1; i++) {
    if((!lot[i])&&(!lot[i+1]))
      spot = i;
  }
  if(spot>=size)
    return false;
  else{
    lot[spot] = true;
    lot[spot+1] = true;
    set_stall(spot);
    return true;
  }
}
