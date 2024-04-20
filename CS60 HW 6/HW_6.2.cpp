#include"npoint.h"
#include<iostream>
#include<string>

using namespace std;

int main() {
  int a1[5]={2,5,8,4,6};
  int a2[6]={2,3,1,2,1,7};
  int a5[6]={4,6,2,4,2,14};
  string a3[2]={"Hello","There"};
  string a4[3]={"I","Am","Sam"};
  string a6[3]={"I","Am","Sam"};
  NPoint<int> p1;
  NPoint<int> p2(5,a1);
  NPoint<int> p3(6,a2);
  NPoint<string> p4(2,a3);
  NPoint<string> p5(3,a4);
  NPoint<int> p6(6,a5);
  NPoint<string> p7(3,a6);
  p2 += p3;
  for(int i = 0; i < p2.size(); i++) {
    cout << p2.get_item(i) << " ";
  }
  cout << endl;
  p4 += p5;
  for(int j = 0; j < p4.size(); j++) {
    cout << p4.get_item(j) << " ";
  }
  cout << endl;
  p1 = p3 + p3;
  for(int k = 0; k < p1.size(); k++) {
    cout << p1.get_item(k) << " ";
  }
  cout << endl;

  cout << (p1==p6) << endl;
  cout << (p1==p2) << endl;
  cout << (p5==p7) << endl;

  int coor[2] = {0,0};
  int coor1[2] = {3,4};
  NPoint<int> p8(2,coor);
  NPoint<int> p9(2,coor1);
  cout << distance(p9,p8) << endl;
}
