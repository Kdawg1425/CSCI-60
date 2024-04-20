#ifndef VAN_H
#define VAN_H
#include <string>
#include "automobile.h"

class Van:public Automobile{
public:
  Van();
  Van(std::string imake, std::string imodel, int iyear, double iprice, int istall, int seat);
  int seat(){return seat_;}

  bool park(bool lot[], int size);

private:
  int seat_;
};

#endif
