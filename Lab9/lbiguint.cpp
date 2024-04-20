#include "lbiguint.h"
#include "LabNode.h"
#include <cassert>
#include <sstream>
#include <algorithm>

lbiguint::lbiguint(){
     head = tail = new node(0, nullptr);
}

 lbiguint::lbiguint (const std::string & s) {

     if (s.size() == 0){
      head = tail = new node(0, nullptr);
      return;
     }
     char c = s[0];
     node * p;
     for (int i = s.size()-1; i >= 0; --i)
     {
        if(i == s.size()-1) {
          head = p = new node(s[i] - '0', nullptr);
        }
        else {
          assert(isdigit(s[i]));
          p->set_link(new node(s[i]-'0', nullptr));
          p = p->link();
        }
     }
     tail = p;
 }

 lbiguint::~lbiguint() {
   if(head == nullptr) {
     return;
   }
   node *next = head;
   next = next->link();
   for(; next != nullptr; next = next->link()) {
     delete head;
     head = next;
   }
   delete head;
   head = nullptr;
   tail = nullptr;
 }

 std::size_t lbiguint::size() const {
   size_t count = 0;
   node * p;
   for(p = head; p != nullptr; p = p->link()) {
     count++;
   }
   return count;
 }

 int lbiguint::operator [](std::size_t pos) const {
   node * p = head;
   for(size_t i = 0; i != pos; i++) {
     p = p->link();
     if(p ==  nullptr) {
       return 0;
     }
   }
   return p->data();
 }

 std::ostream & operator << (std::ostream & out, const lbiguint & lb) {
   for(size_t i = lb.size(); i > 0; i--) {
     out << lb[i-1];
   }
   return out;
 }

 void lbiguint::operator =(const lbiguint & b) {
   head = tail = nullptr;
    for (const node* p = b.head; p!=nullptr; p = p->link()){
      if(head==nullptr){
          head = tail = new node(p->data(), nullptr);
      }
      else{
          tail->set_link(new node(p->data(), nullptr));
          tail = tail->link();
      }
    }
 }


/*
 unsigned short biguint::operator [](std::size_t pos) const
 {
     assert(pos < CAPACITY);
     return _data[pos];
 }



 int biguint::compare(const biguint & b) const{
     for(std::size_t i =CAPACITY-1; i>=0; --i){
         if(_data[i]>b._data[i])
             return 1;
         else if (_data[i]<b._data[i])
             return -1;

     }
     return 0;
 }



 void biguint::operator += (const biguint & b){
     int carry = 0;
     int next = 0;
     for(std::size_t i=0; i<CAPACITY; ++i){
         next = carry+_data[i]+b._data[i];
         _data[i]=next%10;
        carry=next/10;
     }
 }
 std::string biguint::toStdString() const
 {
     std::stringstream ss;
     ss << *this;
     return ss.str();
 }//We haven't talked about stringstreams; just ignore this, I was being lazy.
 std::ostream & operator << (std::ostream & os, const biguint & b)
 {

     for (int i = biguint::CAPACITY - 1; i >= 0; --i)
         os << b[i];
     return os;
 }

 std::istream & operator >> (std::istream & is, biguint & b)
 {
     std::string s;
     is >> s;
     b = biguint(s);
     return is;


 }

 bool operator <(const biguint& a, const biguint& b){
     return (a.compare(b)==-1);
 }

 bool operator <= (const biguint & b1, const biguint & b2)
 {
     return (b1.compare(b2) <= 0);
 }

 bool operator == (const biguint & b1, const biguint & b2)
 {
     return (b1.compare(b2) == 0);
 }

 bool operator != (const biguint & b1, const biguint & b2)
 {
     return (b1.compare(b2) != 0);
 }

*/
//You do > and >=
