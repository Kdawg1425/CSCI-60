#include <iostream>
#include <fstream>

using namespace std;


//Pre: None
//Post: Iterates throught the names array, and any name that starts with the
//      char "letter" is sent to the out stream file.
void writeletter(string names[], int size, char letter, ostream& out);

int main() {
  ifstream inFile("names.txt");
  ofstream outFile("result.txt");
  string namelist[100];
  int count = 0;
  int min;
  int last = 64;
  string input;
  while(inFile >> input) {
    namelist[count] = input;
    count++;
  }
  for(int i = 0; i < count; i++) {
    min = 91;
    for(int j = i+1; j < count; j++) {
      if(namelist[j].at(0) < min && namelist[j].at(0) > last) {
        min = namelist[j].at(0);
      }
    }
    last = min;
    writeletter(namelist,count,min,outFile);
  }
}


void writeletter(string names[], int size, char letter, ostream& out) {
  for(int i = 0; i < size; i++) {
    if(names[i].at(0) == letter) {
        out << names[i] << endl;
    }
  }
}
