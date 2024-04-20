#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<map>
#include<pair>

using namespace std;

int main() {
  map<int,pair<int, vector<string> > > m;
  //string temp;
  string temp2;
  int in;
  ifstream inputFile;
  inputFile.open("scorename.txt");
  for(int i = 0; i < 11; i++) {
    m[i];
  }
  while(inputFile >> in) {
    getline(inputFile, temp2);
    //in = (int)temp;
    m[in].first++;
    m[in].second.push_back(temp2);
  }
  for(int j = 0; j <= 10; j++) {
    cout << j << " ";
    for(size_t k = 0; k < m[j].first; k++) {
      cout << "X";
    }
    cout << endl;
  }
  //int answer;
  //int pos;
  cout << "Would like to see the names of people who got a given score?" << endl;
  cout << "If so, input the score. If not, type in a number other than a score." << endl;
  cin >> in;
  //pos = (int)answer;
  if(in >= 0 && in <= 10) {
    for(size_t l = 0; l < m[in].second.size(); l++) {
      cout << m[in].second[l] << ", ";
    }
    cout << endl;
  }
}
