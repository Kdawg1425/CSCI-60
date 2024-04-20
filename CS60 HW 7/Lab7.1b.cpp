#include<iostream>
#include<string>
#include<fstream>
#include<map>

using namespace std;

int main() {
  map<string,int> m;
  string temp;
  int high = 0;
  ifstream inputFile;
  ofstream outputFile;
  double count = 0.0;
  outputFile.open("Result2.txt");
  inputFile.open("Lab7.txt");
  while(getline(inputFile, temp)) {
    m[temp]++;
  }
  for(auto i : m) {
    outputFile << i.first << " " << i.second << endl;
    count += i.second;
    if(i.second > high) {
      temp = i.first;
      high = i.second;
    }
  }
  cout << "Average number of times someone received our services: "
  << (count/m.size()) << endl;
  cout << temp << " received from our services the most. Times: " << high << endl;

  count = 0;
  for(auto i : m) {
    count += i.second;
  }
  return 0;
}
