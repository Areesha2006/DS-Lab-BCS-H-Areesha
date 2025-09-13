#include<iostream>
#include<ctime>
using namespace std;
int main(){
	int n=1000,compares=0,swaps=0;
	clock_t start,end;
	double time_taken;
	int shell_num[1000],insertion_num[1000],bubble_num[1000];
	for(int i=1000,j=0;i>0;i--,j++){
		shell_num[j]=i;
		bubble_num[j]=i;
		insertion_num[j]=i;
	}	
	cout<<"In Shell  Sort\n";
	cout<<"Unsorted Array"<<endl;
	for(int i=0;i<n;i++){
		cout<<shell_num[i]<<" ";
	}
	start=clock();
	for(int gap=n/2;gap>0;gap/=2){
		for(int i=gap;i<n;i++){
			int temp=shell_num[i],j=i;
			compares++;
			while(shell_num[j-gap]>temp&&j>=gap){
				shell_num[j]=shell_num[j-gap];
				j-=gap;
				compares++;
				swaps++;
			}
			shell_num[j]=temp;
		}
	}
	end=clock();
	time_taken=(1000.0*end-start)/CLOCKS_PER_SEC;
	cout<<"\nSorted Array"<<endl;
	for(int i=0;i<n;i++){
		cout<<shell_num[i]<<" ";
	}
	cout<<endl<<"Total Comparisons: "<<compares<<endl;
	cout<<"Total swaps: "<<swaps<<endl;
	cout<<"Time Taken: "<<time_taken<<" milliseconds"<<endl;
	compares=0;
	swaps=0;
	cout<<"\nIn Bubble Sort\n";
	cout<<"Unsorted Array"<<endl;
	for(int i=0;i<n;i++){
		cout<<bubble_num[i]<<" ";
	}
	start=clock();
	for(int i=0;i<n;i++){
		for(int j=0;j<n-1-i;j++){
			compares++;
			if(bubble_num[j]>bubble_num[j+1]){
				int a=bubble_num[j];
				bubble_num[j]=bubble_num[j+1];
				bubble_num[j+1]=a;
				swaps++;
			}
		}
	}
	end=clock();
	time_taken=(1000.0*end-start)/CLOCKS_PER_SEC;
	cout<<"\nSorted Array"<<endl;
	for(int i=0;i<n;i++){
		cout<<bubble_num[i]<<" ";
	}
	cout<<endl<<"Total Comparisons: "<<compares<<endl;
	cout<<"Total swaps: "<<swaps<<endl;
	cout<<"Time Taken: "<<time_taken<<" millisecond"<<endl;
	compares=0;
	swaps=0;
	cout<<"\nIn Insertion Sort\n";
	cout<<"Unsorted Array"<<endl;
	for(int i=0;i<n;i++){
		cout<<insertion_num[i]<<" ";
	}
	start=clock();
	for(int i=0;i<n;i++){
		int temp=insertion_num[i],j=i-1;
		compares++;
		while(j>=0&&insertion_num[j]>temp){
			insertion_num[j+1]=insertion_num[j];
			j--;
			compares++;
			swaps++;
		}
		insertion_num[j+1]=temp;
	}
	end=clock();
	time_taken=(1000.0*end-start)/CLOCKS_PER_SEC;	
	cout<<"\nSorted Array"<<endl;
	for(int i=0;i<n;i++){
		cout<<insertion_num[i]<<" ";
	}
	cout<<endl<<"Total Comparisons: "<<compares<<endl;
	cout<<"Total swaps: "<<swaps<<endl;
	cout<<"Time Taken: "<<time_taken<<" millisecond"<<endl;
	return 0;
}
