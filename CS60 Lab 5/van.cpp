#include "van.h"

Van::Van() : Automobile() {
  seat_ = 0;
}

Van::Van(std::string imake, std::string imodel, int iyear, double iprice, int istall, int seat)
: Automobile(imake, imodel, iyear, iprice, istall) {
  seat_ = seat;
}


bool Van::park(bool lot[], int size) {
  int spot=size;
  if(seat_ > 7) {
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
  else {
    for(int i=0; i<size-1; i++) {
      if(!lot[i])
        spot = i;
    }
    if(spot>=size)
      return false;
    else{
      lot[spot] = true;
      set_stall(spot);
      return true;
    }
  }
}
