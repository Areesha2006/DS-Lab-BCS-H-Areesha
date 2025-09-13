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
	cout<<"Unsorted Array"<<endl;
	for(int i=0;i<n;i++){
		cout<<num[i]<<" ";
	}
	for(int i=0;i<n;i++){
		int temp=num[i],j=i-1;
		while(num[j]>temp&&j>=0){
			num[j+1]=num[j];
			j--;
		}
		num[j+1]=temp;
	}
	cout<<"\nSorted Array"<<endl;
	for(int i=0;i<n;i++){
		cout<<num[i]<<" ";
	}
	cout<<"\nEnter the target value which you want to find: ";
	cin>>target;
	int start=0,end=n-1;
	while(start<=end){
		int mid=(start+end)/2;
		if(num[mid]==target){
			found=1;
			cout<<"Value found at index "<<mid;
			break;;
		}
		else if(target>num[mid]){
			start=mid+1;
		}
		else{
			end=mid-1;
		}
	}
	if(!found){
		cout<<"Value not found";
	}
	return 0;
}
