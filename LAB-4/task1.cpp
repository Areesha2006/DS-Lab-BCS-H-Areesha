#include<iostream>
using namespace std;
int main(){
	int n,target,found=0;
	cout<<"How many integers are there in the array: ";
	cin>>n;
	int num[n];
	for(int i=0;i<n;i++){
		cout<<"Enter integer "<<i+1<<": ";
		cin>>num[i];
	}
	cout<<"\nEnter the target value which you want to search: ";
	cin>>target;
	for(int i=0;i<n;i++){
		if(target==num[i]){
			found=1;
			cout<<"Index of the target value is "<<i;
			break;
		}
	}
	if(!found){
		cout<<"Value does not found";
	}
	return 0;
}
