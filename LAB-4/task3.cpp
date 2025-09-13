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
		int min_index=i;
		for(int j=i+1;j<n;j++){
			if(num[j]<num[min_index]){
				min_index=j;
			}
		}
		int a=num[i];
		num[i]=num[min_index];
		num[min_index]=a;
	}
	cout<<"\nSorted Array"<<endl;
	for(int i=0;i<n;i++){
		cout<<num[i]<<" ";
	}
	return 0;
}
