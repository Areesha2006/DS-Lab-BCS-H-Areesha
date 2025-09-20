#include<iostream>
using namespace std;
int ackermann(int m,int n){
    if(m==0){
        return n+1;
    }
    if(m>0&&n==0){
        return ackermann(m-1,1);
    }
    if(m>0&&n>0){
        return ackermann(m,ackermann(m,n-1));
    }
    return 0;
}
int main(){
    int m,n;
    cout<<"Enter a number for m: ";
    cin>>m;
    cout<<"Enter a number for n: ";
    cin>>n;
    cout<<"Ackermann Function Result: "<<ackermann(m,n);
    return 0;
}