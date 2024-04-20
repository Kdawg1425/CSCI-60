#include "dSet.h"
#include "dynamicbag.h"

dSet::dSet() : DynamicBag() {

}

dSet::dSet(const DynamicBag & b) : DynamicBag() {
  int min;
  int lowBound = INT_MIN;
  for(size_t i = 0; i < b.size(); i++) {
    min = INT_MAX;
      for(size_t j = 0; j < b.size(); j++) {
        if(b[j] <= min && b[j] > lowBound) {
          min = b[j];
        }
      }
      lowBound = min;
      if(min == INT_MAX) {
        break;
      }
      insert(min);
  }
}

void dSet::insert(int target) {
  if(size() == 0) {
    DynamicBag::insert(target);
  }
  else if(size() == 1) {
    if(target < (*this)[0]) {
      insertAt(target, 0);
    }
    else {
      DynamicBag::insert(target);
    }
  }
  else {
    bool end = true;
    for(size_t i = 0; i < size()-1; i++) {
      if(target == (*this)[i] || target == (*this)[i+1]) {
        end = false;
        break;
      }
      if(target > (*this)[i] && target < (*this)[i+1]) {
        insertAt(target, i+1);
      }
    }
    if(end == true) {
      DynamicBag::insert(target);
    }
  }
}
