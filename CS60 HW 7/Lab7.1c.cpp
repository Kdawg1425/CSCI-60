#include<iostream>
#include<string>
#include<fstream>
#include<vector>

using namespace std;

int main() {
  vector<string> list;
  string temp;
  ifstream inputFile;
  ofstream outputFile;
  outputFile.open("Result3.txt");
  inputFile.open("Lab7.txt");
  while(getline(inputFile, temp)) {
    list.push_back(temp);
  }
  for(auto i : list) {
    outputFile << i << endl;
  }
  cout << "Served: " << list.size() << " meals" << endl;
  cout << "First served: " << *(list.begin()) << endl;
  cout << "Last served: " << *(list.end()-1) << endl;

  return 0;
}
