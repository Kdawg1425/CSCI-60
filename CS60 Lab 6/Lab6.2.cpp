#include"npoint.h"
//#include"npoint.cpp"
#include<iostream>
#include<string>
using namespace std;
int main(){
    int a1[5]={2,5,8,4,6};
    string a2[5]={"Jin","Alpha","Beta","c","Alpha"};
    NPoint<int> p1;
    NPoint<int> p2(3);
    NPoint<int> p3(5,a1);
    NPoint<string> p4(5,a2);
    cout<<p1.size()<<endl;
    cout<<p2.size()<<endl;
    cout<<p3.size()<<endl;
    cout<<p4.size()<<endl;
    cout<<p3.get_item(2)<<endl;
    cout<<p4.get_item(3)<<endl;
    p1=p3;
    cout<<p3.get_item(2)<<endl;
    return 0;
}
