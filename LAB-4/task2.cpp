#include<iostream>
using namespace std;
int main(){
	int n;
	cout<<"How many integers are there in the array: ";
	cin>>n;
	int num[n];
	for(int i=0;i<n;i++){
		cout<<"Enter integer "<<i+1<<": ";
		cin>>num[i];
	}
	cout<<"Unsorted Array"<<endl;
	for(int i=0;i<n;i++){
		cout<<num[i]<<" ";
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n-i-1;j++){
			if(num[j]>num[j+1]){
				int a=num[j];
				num[j]=num[j+1];
				num[j+1]=a;
			}
		}
	}
	cout<<"\nSorted Array"<<endl;
	for(int i=0;i<n;i++){
		cout<<num[i]<<" ";
	}
	return 0;
}
