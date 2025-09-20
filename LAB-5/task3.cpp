#include<iostream>
using namespace std;
int sumTail(int n,int total){
    if(n<1){
        return total;
    }
    return sumTail(n-1,total+n);
}
int sumNonTail(int n){
    if(n<1){
        return 0;
    }
    return n+sumNonTail(n-1);
}
int main(){
    int n;
    cout<<"Enter a natural number: ";
    cin>>n;
    if(n>0){
        cout<<"By sumTail"<<endl;
        cout<<"Sum to "<<n<<" natural numbers: "<<sumTail(n,0);
        cout<<"\nBy sumNonTail"<<endl;
        cout<<"Sum to "<<n<<" natural numbers: "<<sumNonTail(n);
    }
    else{
        cout<<"Invalid input";
    }
    return 0;
}