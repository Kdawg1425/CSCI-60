#ifndef ATM_H
#define ATM_H
#include "bankaccount.h"

class Atm {
public:
  Atm();
  Atm(int tw, int te);
  int twenties();
  int tens();
  BankAccount get_cash(int amount, BankAccount b);
  void operator +=(Atm& rhs);
  void restock(int new20s, int new10s);

private:

  int twenties_;
  int tens_;

};

bool operator ==(Atm lhs, Atm rhs);
std::ostream& operator <<(std::ostream& out, Atm a);


#endif
