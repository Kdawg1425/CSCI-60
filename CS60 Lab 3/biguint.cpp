#include "biguint.h"
#include <cstdlib>
#include <iostream>
#include <string>



// CONSTRUCTORS

// pre: none
// post: creates a biguint with value 0
biguint::biguint() {
    for(size_t i = 0; i < CAPACITY; i++) {
      data_[i] = 0;
    }
}

biguint::biguint(const std::string &s) {
  size_t index = 0;
  int num;
  for(size_t i = s.length()-1; i > 0; i--) {
    num = s.at(i) - '0';
    data_[index] = num;
    index++;
  }
  num = s.at(0) - '0';
  data_[index] = num;
  index++;
  for(size_t j = index; j < CAPACITY; j++) {
    data_[j] = 0;
  }
}

unsigned short biguint::operator [](std::size_t pos) const {
  if(pos <= CAPACITY) {
    return data_[pos];
  }
  else {
    return 0;
  }
}

std::ostream& operator << (std::ostream& out, const biguint &b) {
  for(size_t i = b.CAPACITY-1; i > 0; i--) {
    out <<  b[i];
  }
  out << b[0] << std::endl;
  return out;
}

void biguint::operator += (const biguint & b) {
  int carry = 0;
  for(size_t i = 0; i < CAPACITY; i++) {
    data_[i] = data_[i] + b[i] + carry;
    if(data_[i] >= 10) {
      carry = data_[i] / 10;
      data_[i] = data_[i] % 10;
    }
    else {
      carry = 0;
    }
  }
}

biguint operator + (const biguint & a, const biguint & b) {
  biguint result = biguint();
  result += a;
  result += b;
  return result;
}

int biguint::compare(const biguint & b) const {
  for(size_t i = CAPACITY-1; i > 0; i--) {
    if(data_[i] > b[i]) {
      return 1;
    }
    if(data_[i] < b[i]) {
      return -1;
    }
  }
  if(data_[0] > b[0]) {
    return 1;
  }
  if(data_[0] < b[0]) {
    return -1;
  }
  else {
    return 0;
  }
}

bool operator < (const biguint & a, const biguint & b) {
  if(a.compare(b) == -1) {
    return true;
  }
  else {
    return false;
  }
}

bool operator <= (const biguint & a, const biguint & b) {
  if(a.compare(b) == -1 || a.compare(b) == 0) {
    return true;
  }
  else {
    return false;
  }
}

bool operator != (const biguint & a, const biguint & b) {
  for(size_t i = a.CAPACITY-1; i > 0; i--) {
    if(a[i] != b[i]) {
      return true;
    }
  }
  if(a[0] != b[0]) {
    return true;
  }
  else {
    return false;
  }
}

bool operator == (const biguint & a, const biguint & b) {
  for(size_t i = a.CAPACITY-1; i > 0; i--) {
    if(a[i] != b[i]) {
      return false;
    }
  }
  if(a[0] != b[0]) {
    return false;
  }
  else {
    return true;
  }
}

bool operator >= (const biguint & a, const biguint & b) {
  for(size_t i = a.CAPACITY-1; i > 0; i--) {
    if(a[i] < b[i]) {
      return false;
    }
  }
  if(a[0] < b[0]) {
    return false;
  }
  else{
    return true;
  }
}

bool operator > (const biguint & a, const biguint & b) {
  if(a.compare(b) == 1) {
    return true;
  }
  else {
    return false;
  }
}


void biguint::operator -= (const biguint & b){
  if(*this < b) {
    for(size_t i = 0; i < CAPACITY; i++) {
      data_[i] = 0;
    }
  }
  else {
    int temp = 0;
    for(size_t i = 0; i < CAPACITY; i++) {
      if(data_[i] >= b[i]) {
        data_[i] -= b[i];
      }
      else {
        temp = 10 + data_[i];
        data_[i+1] -= 1;
        data_[i] = temp-b[i];
      }
    }
  }
}


biguint operator - (const biguint & a, const biguint & b) {
  biguint result = biguint();
  result += a;
  result -= b;
  return result;
}

std::string biguint::toString() {
  char *num = new char[CAPACITY];
  size_t index = 0;
  for(size_t i = CAPACITY-1; i > 0; i--) {
    num[index] = data_[i] + '0';
    index++;
  }
  num[CAPACITY-1] = data_[0] + '0';
  std::string result = "";
  for(size_t j = 0; j < CAPACITY; j++) {
    result = result + num[j];
  }
  return result;
}
