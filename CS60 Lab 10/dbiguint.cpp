#include "dbiguint.h"
#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>


// CONSTRUCTORS

// pre: none
// post: creates a biguint with value 0
dbiguint::dbiguint() {
    capacity_ = 1;
    data_ = new unsigned short[capacity_];
    data_[0] = 0;
}

dbiguint::dbiguint(const std::string & s) {
  capacity_ = s.length();
  data_ = new unsigned short[capacity_];
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
}

dbiguint::dbiguint(const dbiguint & b) {
  capacity_ = b.size();
  data_ = new unsigned short[capacity_];
  for(size_t i = 0; i < b.size(); i++) {
    data_[i] = b[i];
  }
}


std::size_t dbiguint::size() const {
  return capacity_;
}

unsigned short dbiguint::operator [](std::size_t pos) const {
  if(pos <= capacity_ -1) {
    return data_[pos];
  }
  else {
    return 0;
  }
}


std::ostream& operator << (std::ostream& out, const dbiguint &b) {
  for(size_t i = b.size()-1; i > 0; i--) {
    out <<  b[i];
  }
  out << b[0] << std::endl;
  return out;
}

void dbiguint::reserve(std::size_t newcapacity_) {
  if(newcapacity_ > capacity_) {
    unsigned short *temp = new unsigned short[newcapacity_];
    size_t i = 0;
    for(; i < capacity_; i++) {
      temp[i] = data_[i];
    }
    for(; i < newcapacity_; i++) {
      temp[i] = 0;
    }
    delete data_;
    data_ = temp;
    capacity_ = newcapacity_;
    temp = nullptr;
  }
  if(newcapacity_ < capacity_) {
    unsigned short *temp = new unsigned short[newcapacity_];
    size_t i = 0;
    for(; i < newcapacity_; i++) {
      temp[i] = data_[i];
    }
    delete data_;
    data_ = temp;
    capacity_ = newcapacity_;
    temp = nullptr;
  }
}

void dbiguint::operator += (const dbiguint & b) {
  if(capacity_ < b.size()) {
    reserve(b.size());
  }
  int carry = 0;
  size_t i = 0;
  for(; i < b.size()-1; i++) {
    data_[i] = data_[i] + b[i] + carry;
    if(data_[i] >= 10) {
      carry = data_[i] / 10;
      data_[i] = data_[i] % 10;
    }
    else {
      carry = 0;
    }
  }
  data_[i] = data_[i] + b[i] + carry;
  if(carry > 0) {
    reserve(capacity_);
    data_[capacity_] = carry;
  }
}

dbiguint::~dbiguint() {
  delete data_;
  data_ = nullptr;
  capacity_ = 0;
}

int dbiguint::compare(const dbiguint & b) const {
  if(size() < b.size()) {
    return -1;
  }
  if(size() > b.size()) {
    return 1;
  }
  else {
    for(size_t i = size()-1; i > 0; i--) {
      if(data_[i] > b[i]) {
        return 1;
      }
      if(data_[i] < b[i]) {
        return -1;
      }
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

dbiguint operator + (const dbiguint & a, const dbiguint & b) {
  dbiguint result;
  result += a;
  result += b;
  return result;
}




bool operator <(const dbiguint & a, const dbiguint & b){
  if(a.size() > b.size()) {
    return false;
  }
  if(a.size() < b.size()) {
    return true;
  }
  else {
    for(size_t i = a.size()-1; i > 0; i--) {
      if(a[i] > b[i]) {
        return false;
      }
    }
    if(a[0] >= b[0]) {
      return false;
    }
    else {
      return true;
    }
  }
}


bool operator <= (const dbiguint & a, const dbiguint & b) {
  if(a.size() > b.size()) {
    return false;
  }
  if(a.size() < b.size()) {
    return true;
  }
  else {
    for(size_t i = a.size()-1; i > 0; i--) {
      if(a[i] > b[i]) {
        return false;
      }
    }
    if(a[0] > b[0]) {
      return false;
    }
    else {
      return true;
    }
  }
}

bool operator != (const dbiguint & a, const dbiguint & b) {
  if(a.size() != b.size()) {
    return true;
  }
  else {
    for(size_t i = a.size()-1; i > 0; i--) {
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
}

bool operator ==(const dbiguint & a, const dbiguint & b) {
  if(a.size() != b.size()) {
    return false;
  }
  else {
    for(size_t i = a.size()-1; i > 0; i--) {
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
}

bool operator >= (const dbiguint & a, const dbiguint & b) {
  if(a.size() >= b.size()) {
    return true;
  }
  if(a.size() < b.size()) {
    return false;
  }
  else {
    for(size_t i = a.size()-1; i > 0; i--) {
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
}

bool operator > (const dbiguint & a, const dbiguint & b) {
  if(a.size() > b.size()) {
    return true;
  }
  if(a.size() < b.size()) {
    return false;
  }
  else {
    for(size_t i = a.size()-1; i > 0; i--) {
      if(a[i] < b[i]) {
        return false;
      }
    }
    if(a[0] < b[0]) {
      return false;
    }
    else {
      return true;
    }
  }
}

void dbiguint::operator =(const dbiguint & b) {
  reserve(b.size());
  for(size_t i = 0; i < b.size(); i++) {
    data_[i] = b[i];
  }
}

void dbiguint::operator -=(const dbiguint & b) {
  if(*this < b) {
    reserve(1);
    data_[0] = 0;
  }
  else {
    int temp = 0;
    for(size_t i = 0; i < capacity_; i++) {
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
  size_t j = capacity_-1;
  if(data_[j] == 0) {
    for(; j > 0; j--) {
      if(data_[j] == 0) {
        reserve(capacity_-1);
      }
    }
  }
}

dbiguint operator -(const dbiguint & a, const dbiguint & b) {
  dbiguint result;
  result += a;
  result -= b;
  return result;
}


void dbiguint::operator *=(const dbiguint & b) {
  dbiguint temp = *this;
  dbiguint hold;
  hold.reserve(20);
  reserve(20);
  for(size_t a = 0; a < capacity_; a++) {
    data_[a] = 0;
  }
  int carry = 0;
  for(size_t i = 0; i < b.size(); i++) {
    for(size_t j = 0; j < hold.size(); j++) {
      hold.data_[j] = 0;
    }
    for(size_t k = 0; k < temp.size(); k++) {
      hold.data_[k+i] += (temp[k] * b[i] + carry) % 10; //more looping temp size
      carry = (temp[k] * b[i] + carry) / 10;
    }
    *this += hold;
    int counter = 0;
    for(size_t l = 0; l < size(); l++) {
      if(data_[l] == 0) {
        break;
      }
      else {
        counter++;
      }
    }
    reserve(counter);
  }
}

dbiguint operator *(const dbiguint & a, const dbiguint & b) {
  dbiguint result;
  result += a;
  result *= b;
  return result;
}

std::istream & operator >> (std::istream & in, dbiguint & b) {
  std::string input;
  in >> input;
  b = dbiguint(input);
  return in;
}

void dbiguint::clean() {
  size_t index = capacity_;
  for(size_t i = capacity_-1; i > 0; i--) {
    if(data_[i] == 0) {
      index--;
    }
  }
  reserve(index);
}


/*

string biguint::toString(const biguint & b) const {
  string result = "";
  for(size_t i = CAPACITY-1; i > 0; i--) {
    result << data_[i];
  }
  result << data_[0];
  return result;
}
*/
