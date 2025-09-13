#include<iostream>
using namespace std;
int main(){
	int n,asc=1;
	cout<<"How many integers are there in the array: ";
	cin>>n;
	int num[n];
	cout<<"Enter all values in ascending order"<<endl;
	for(int i=0;i<n;i++){
		cout<<"Enter integer "<<i+1<<": ";
		cin>>num[i];
	}
	for(int i=0;i<n-1;i++){
		if(num[i]>num[i+1]){
			asc=0;
			break;
		}
	}
	if(asc){
		int target,found=0;
		cout<<"Enter the target value which you want to search: ";
		cin>>target;
		int l=0,h=n-1;
		while(l<=h&&target>=num[l]&&target<=num[h]){
			int pos=l+((h-l)/(num[h]-num[l]))*(target-num[l]);
			if(num[pos]==target){
				found=1;
				cout<<"Value found at index "<<pos;
				break;
			}
			else if(target>num[pos]){
				l=pos+1;
			}
			else{
				h=pos-1;
			}
		}
		if(!found){
			cout<<"Value not found";
		}
	}
	else{
		cout<<"As the array is not sorted in ascending order so interpolation search can not be peformed";
	}
	return 0;
}
