#include<iostream>
using namespace std;
    int calculateFactorial(int n){
    if(n==0||n==1){
        return 1;
    }
    return n*calculateFactorial(n-1);
}
int main(){
    int n;
    cout<<"Enter a positive number: ";
    cin>>n;
    if(n>=0){
        cout<<n<<"!="<<calculateFactorial(n);
    }
    else{
        cout<<"Invalid input";
    }
    return 0;
}