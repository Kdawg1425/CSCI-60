#include <iostream>
using namespace std;


class ModInt {
private:
  int numSongs;
  int mod;
public:
  ModInt();
  ModInt(int numOfSongs, int skips);

  void operator +=(ModInt rhs);

  int get_NumSongs() {
    return numSongs;
  }
  int get_mod() {
    return mod;
  }
};

bool operator ==(ModInt lhs, ModInt rhs);
ModInt operator +(ModInt lhs, ModInt rhs);

int main() {
  ModInt m1 = ModInt();
  ModInt m2 = ModInt(11, 2);
  ModInt m3 = ModInt(10, 2);
  ModInt m4 = ModInt(13, 2);
  ModInt m5 = ModInt(10, 2);
  cout << m1.get_NumSongs() << " " << m2.get_mod() << endl;
  if(m2==m3) {
    cout << "true" << endl;
  }
  else {
    cout << "false" << endl;
  }
  m2 += m3;
  cout << m2.get_NumSongs() << " " << m2.get_mod() << endl;

  ModInt  m6 = m4 + m5;
  cout << m6.get_NumSongs() << " " << m6.get_mod() << endl;
}

ModInt::ModInt() {
  numSongs = 0;
  mod = 0;
}

ModInt::ModInt(int numOfSongs, int skips) {
  numSongs = numOfSongs;
  mod = skips;
}

bool operator ==(ModInt lhs, ModInt rhs) {
  if(lhs.get_NumSongs() == rhs.get_NumSongs() && lhs.get_mod() == rhs.get_mod()) {
    return true;
  }
  else {
    return false;
  }
}

void ModInt::operator +=(ModInt rhs) {
  if(mod == rhs.get_mod()) {
    numSongs = numSongs + rhs.get_NumSongs();
    numSongs %= mod;
  }
  else {
    numSongs = -1;
    mod =-1;
  }
}

ModInt operator +(ModInt lhs, ModInt rhs) {
  lhs+=rhs;
  return lhs;
}
