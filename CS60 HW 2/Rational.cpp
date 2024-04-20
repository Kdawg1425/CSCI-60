#include "Rational.h"

Rational::Rational(int n, int d){//We need the Rational:: because it looks like we're defining this at the global scope, but it BELONGS in Rational's scope.
  numer_ = n;
  denom_ = d;
}
Rational::Rational(){
  numer_ = 0;
  denom_ = 1;
}


void Rational::reduce() {
  for (int i = denom_ * numer_; i > 1; i--) {
    if ((denom_ % i == 0) && (numer_ % i == 0)) {
      denom_ /= i;
      numer_ /= i;
    }
  }
}

Rational operator *(Rational a, Rational b){
    Rational ans(a.numer()*b.numer(), a.denom()*b.denom());
    ans.reduce();
    return ans;
}

void Rational::operator *=(Rational b){
    numer_ = (numer_*b.numer_);
    denom_ = (denom_*b.denom_);
    reduce();
}
Rational operator +(Rational a, Rational b){
  Rational ans((a.numer()*b.denom()+b.numer()*a.denom()), (a.denom()*b.denom()));
  ans.reduce();
  return ans;
}

std::ostream& operator <<(std::ostream& out, Rational a){
  out<<a.numer()<<"/"<<a.denom()<<std::endl;
  return out;
}

bool operator ==(Rational lhs, Rational rhs) {
  lhs.reduce();
  rhs.reduce();
  if((lhs.numer() == rhs.numer()) && (lhs.denom() == rhs.denom())) {
    return true;
  }
  else {
    return false;
  }
}



void Rational::operator +=(Rational rhs) {
  numer_ = numer_*rhs.denom() + rhs.numer() * denom_;
  denom_ = denom_ * rhs.denom();
  reduce();
}
