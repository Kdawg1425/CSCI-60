#include "Atm.h"
#include "bankaccount.h"


Atm::Atm() {
  twenties_ = 0;
  tens_ = 0;
}

Atm::Atm(int tw, int te) {
  twenties_ = tw;
  tens_ = te;
}

int Atm::twenties() {
  return twenties_;
}

int Atm::tens() {
  return tens_;
}

BankAccount Atm::get_cash(int amount, BankAccount b) {
  b.withdraw(amount);
  int num_tw = amount/20;
  int remain = amount - (num_tw * 20);
  int num_te = remain/10;
  std::cout << "You will recieve " << num_tw << " twenty dollar bill(s)." << std::endl;
  std::cout << "And you will reieve " << num_te << " ten dollar bill(s)." << std::endl;
  return b;
}

void Atm::operator +=(Atm& rhs) {
  twenties_ = twenties_ + rhs.twenties();
  tens_ = tens_ + rhs.tens();
}

void Atm::restock(int new20s, int new10s) {
  twenties_ = twenties_ + new20s;
  tens_ = tens_ + new10s;
}

bool operator ==(Atm lhs, Atm rhs) {
  if(lhs.twenties() == rhs.twenties() && lhs.tens() == rhs.tens()) {
    return true;
  }
  else{
    return false;
  }
}

std::ostream& operator <<(std::ostream& out, Atm a){
  out << "Number of twenties left in ATM: " << a.twenties() << std::endl;
  out << "Number of tens left in ATM: " << a.tens() << std::endl;
  return out;
}
