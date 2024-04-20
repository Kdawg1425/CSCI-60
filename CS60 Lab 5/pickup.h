#ifndef PICKUP_H
#define PICKUP_H
#include <string>
#include "automobile.h"

class Pickup:public Automobile{
public:
  Pickup();
  Pickup(std::string imake, std::string imodel, int iyear, double iprice, int istall, int cap, bool ext);
  int capacity(){return capacity_;}
  bool extended(){return extended_;}

  bool park(bool lot[], int size);

private:
  int capacity_;
  bool extended_;

};




#endif
