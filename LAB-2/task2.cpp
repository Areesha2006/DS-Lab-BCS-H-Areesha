#include<iostream>
using namespace std;
int main(){
    int r,c,seat=1,is_occupied;
    cout<<"How many benches are there: ";
    cin>>r;
    cout<<"How many seats are there: ";
    cin>>c;
    int **seating_chart=new int*[r];
    for(int i=0;i<r;i++){
        seating_chart[i]=new int[c]();
    }
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cout<<"Is seat "<<seat++<<" occupied? (Enter 0 for not occupied or any other number for occupied): ";
            cin>>is_occupied;
            if(is_occupied==0){
                seating_chart[i][j]=0;
            }
            else{
                seating_chart[i][j]=1;
            }
        }
    }
    cout<<endl<<"Below is the final seating chart"<<endl;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cout<<seating_chart[i][j]<<" ";
        }
        cout<<endl;
    }
    for(int i=0;i<r;i++){
        delete[] seating_chart[i];
    }
    delete[] seating_chart;
    return 0;
}