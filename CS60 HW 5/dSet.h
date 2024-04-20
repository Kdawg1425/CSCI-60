#ifndef DSET_H
#define DSET_H

#include "dynamicbag.h"

class dSet : public DynamicBag {

public:
  //Pre: none
  //Post: Constructs a dSet with no parameters and using default constructor of
  //      DynamicBag.
  dSet();

  //Pre: none
  //Post: Constructs a dSet filled with copies of the values in the inputted
  //      DynamicBag.
  dSet(const DynamicBag & b);

  //Pre: none
  //Post:
  void insert(int target);

};

#endif
