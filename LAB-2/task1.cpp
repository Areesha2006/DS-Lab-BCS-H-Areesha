#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"How many numbers you want to enter: ";
    cin>>n;
    int *num=new int[n]();
    cout<<"Currently the array looks like"<<endl;
    for(int i=0;i<n;i++){
        cout<<*(num+i)<<" ";
    }
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<"Enter number for index "<<i<<": ";
        cin>>num[i];
    }
    cout<<"\n\nNow the array looks like"<<endl;
    for(int i=0;i<n;i++){
        cout<<num[i]<<" ";
    }
    delete[] num;
    return 0;
}