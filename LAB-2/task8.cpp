#include<iostream>
using namespace std;
int main(){
    int n,m;
    cout<<"For how many days we have to store temperature reading:  ";
    cin>>n;
    cout<<"For how many times we have to store temperature reading in a day:  ";
    cin>>m;
    int **temperature=new int*[n];
    float *avg_temperature=new float[n];
    for(int i=0;i<n;i++){
        temperature[i]=new int[m];
    }
    for(int i=0;i<n;i++){
        cout<<"For Day "<<i+1<<endl;
        for(int j=0;j<m;j++){
            cout<<"Enter temperature at time "<<j+1<<": ";
            cin>>temperature[i][j];
        }
        cout<<endl;
    }
    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=0;j<m;j++){
            sum+=temperature[i][j];
        }
        avg_temperature[i]=sum/(float)m;
        cout<<"Day "<<i+1<<" average temperature: "<<avg_temperature[i]<<endl;
    }
    float hottest_temp=avg_temperature[0],coldest_temp=avg_temperature[0];
    int hottest_day=0,coldest_day=0;
    for(int i=1;i<n;i++){
        if(avg_temperature[i]>hottest_temp){
            hottest_temp=avg_temperature[i];
            hottest_day=i;
        }
    }
    for(int i=1;i<n;i++){
        if(avg_temperature[i]<coldest_temp){
            coldest_temp=avg_temperature[i];
            coldest_day=i;
        }
    }
    cout<<"Day "<<hottest_day+1<<" is hottest day average temperature of "<<hottest_temp<<endl;
    cout<<"Day "<<coldest_day+1<<" is coldest day average temperature of "<<coldest_temp<<endl;
    for(int i=0;i<n;i++){
        delete[] temperature[i];
    }
    delete[] temperature;
    delete[] avg_temperature;
    return 0;
}