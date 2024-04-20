#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
  vector<string> s;
  vector<string>::iterator i;
  vector<int> c;
  vector<int>:: iterator j;
  string temp;
  ifstream inputFile;
  ofstream outputFile;
  outputFile.open("gsresult.txt");
  inputFile.open("gentleseduction.txt");
  while(inputFile >> temp) {
    s.push_back(temp);
  }
  sort(s.begin(), s.end());
  int count = 1;
  int tempcount = 1;
  for(i = s.begin(); i != s.end(); i++) {
    if((*i).compare(*(i+1)) == 0) {
      s.erase(i);
      i--;
      tempcount++;
    }
    else {
      c.push_back(tempcount);
      tempcount = 1;
    }
  }
  i = s.begin();
  j = c.begin();
  for(; i != s.end() && j != c.end(); i++, j++) {
    outputFile << *i << " Occurs: " << *j << endl;
  }
  inputFile.close();
  outputFile.close();
}
