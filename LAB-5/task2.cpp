#include<iostream>
using namespace std;
void printNumbers(int n){
    if(n<1){
        return;
    }
    cout<<n<<" ";
    printNumbers(n-1);
}
void functionB(int n);
void functionA(int n){
    if(n<1){
        return;
    }
    cout<<n<<" ";
    functionB(n-1);
}
void functionB(int n){
    if(n<1){
        return;
    }
    cout<<n<<" ";
    functionA(n-1);
}
int main(){
    int n;
    cout<<"Enter a number greater than 1: ";
    cin>>n;
    if(n>0){
        cout<<"By Direct Recursion"<<endl;
        printNumbers(n);
        cout<<"\nBy Indirect Recursion"<<endl;
        functionA(n);
    }
    else{
        cout<<"Invalid input";
    }
    return 0;
}