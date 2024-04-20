#include <string>
#include <iostream>
#include <cassert>
#include "Atm.h"
#include "bankaccount.h"
using namespace std;

int main() {
  Atm a1 = Atm(20,20);
  Atm a2 = Atm();
  Atm atm1(6,8);
  Atm atm2(6,8);
  cout <<a2<< endl;
  cout << atm2 << endl;
  bool result;
  if(atm1 == atm2){
    result = 1;
  }
  else{
    result = 2;
  }
  cout << result << endl;
  atm1+=(atm2);
  std::cout << "+= test: "<<atm1 << endl;
  BankAccount account(1,100,123,"Gerald");
  atm1.get_cash(50, account);
  std::cout <<"Widthdrawn: "<< atm1 << endl;
  atm1.restock(1,2);
  std::cout << "Restocked: "<< atm1 << endl;

}
