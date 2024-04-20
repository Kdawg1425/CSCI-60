#include "dynamicbag.h"
#include "dUSet.h"

dUSet::dUSet() : DynamicBag::DynamicBag() {

}

dUSet::dUSet(const DynamicBag & b) : DynamicBag::DynamicBag(b){
  size_t occur;
  for(size_t i = 0; i < b.size(); i++) {
    occur = count(b[i]);
    for(size_t j = 1; j < occur; j++) {
      erase_one(b[i]);
    }
  }
}

void dUSet::insert(int target) {
  if(count(target) == 0)  {
    DynamicBag::insert(target);
  }
}
