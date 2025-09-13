#include<iostream>
using namespace std;
int main(){
	int n,gap,compares=0,swaps=0;
	bool swapped=true;
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
	gap=n;
	while(gap>1||swapped){
		gap=(int)(gap/1.3);
		if(gap<1){
			gap=1;
		}
		swapped=false;
		for(int i=0;i+gap<n;i++){
			compares++;
			if(num[i]>num[i+gap]){
				int a=num[i];
				num[i]=num[i+gap];
				num[i+gap]=a;
				swaps++;
				swapped=true;
			}
		}
	}
	cout<<"\nSorted Array"<<endl;
	for(int i=0;i<n;i++){
		cout<<num[i]<<" ";
	}
	cout<<endl<<"Total Compares: "<<compares<<endl;
	cout<<"Total Swaps: "<<swaps;
	return 0;
}
