#include <iostream>
#include<string>
using namespace std;

//pre: T1 must have == operator
//     T2 must be a numerical value, must have ++ and < operator
template <typename T1, typename T2>
int count_exact(T1 a[], T2 size, T1 find){
    int count=0;
    for(T2 i=0;i<size;i++){
        if(a[i]==find)count++;
    }
    return count;
}
//pre: T1 must have >= and <= operator
//     T2 must be a numerical value, must have ++ and < operator
template <typename T1, typename T2>
int count_range(T1 a[], T2 size, T1 low, T1 high){
    int count=0;
    for(T2 i=0;i<size;i++){
        if((a[i]>=low)&&(a[i]<=high))count++;
    }
    return count;
}
int main(){
    cout<<"================= A1 ==================="<<endl;
    int a1[5]={2,6,2,8,5};
    cout<<count_exact(a1,5,2)<<endl;
    string a2[5]={"Jin","Alpha","Beta","c","Alpha"};
    string s1="Alpha";
    cout<<count_exact(a2,5,s1)<<endl;
    cout<<"================= A2 ==================="<<endl;
    int a3[5]={2,6,2,8,5};
    cout<<count_range(a3,5,2,5)<<endl;
    string a4[5]={"Jin","Alpha","Beta","c","Alpha"};
    string s2="A";
    string s3="B";
    cout<<count_range(a4,5,s2,s3)<<endl;

}
