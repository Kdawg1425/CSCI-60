#ifndef DUSET_H
#define DUSET_H

#include "dynamicbag.h"

class dUSet : public DynamicBag {

public:
  //Pre: none
  //Post: Constructs a dUSet with no parameters using the default constructor
  //      of DynamicBag.
  dUSet();

  //Pre: none
  //Post: Constructs a dUSet filled with the copy of the values in the
  //     inputed DynamicBag.
  dUSet(const DynamicBag & b);

  //Pre: none
  //Post: Inserts a copy of target to the dUSet if the value of target is not
  //      already in the dUSet. If there is already a copy, then nothing changes
  void insert(int target);
};

#endif
