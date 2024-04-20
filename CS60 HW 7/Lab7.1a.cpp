#include<iostream>
#include<string>
#include<fstream>
#include<unordered_set>

using namespace std;

int main() {
  unordered_set<string> s;
  string temp;
  ifstream inputFile;
  ofstream outputFile;
  outputFile.open("Result1.txt");
  inputFile.open("Lab7.txt");
  while(getline(inputFile, temp)) {
    s.insert(temp);
  }
  for(auto i : s) {
    outputFile << i << endl;
  }
  cout << "Served: " << s.size() << " people" << endl;

  return 0;
}
