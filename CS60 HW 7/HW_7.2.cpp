#include<iostream>
#include<string>
#include<fstream>
#include<set>

using namespace std;

int main() {
  set<string> s;
  string temp;
  ifstream inputFile;
  ofstream outputFile;
  outputFile.open("gsresult2.txt");
  inputFile.open("gentleseduction.txt");
  while(inputFile >> temp) {
    s.insert(temp);
  }
  for(auto i : s) {
    outputFile << i << endl;
  }
  inputFile.close();
  outputFile.close();
}
