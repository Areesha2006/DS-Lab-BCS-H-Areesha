#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"How many students are there: ";
    cin>>n;
    int **students_marks=new int*[n],*num_courses=new int[n];
    for(int i=0;i<n;i++){
        while(1){
            cout<<"How many courses student "<<i+1<<" have: ";
            cin>>num_courses[i];
            if(num_courses[i]>0){
                break;
            }
            else{
                cout<<"Invalid input"<<endl;
            }
        }
        students_marks[i]=new int[num_courses[i]];
    }
    for(int i=0;i<n;i++){
        cout<<endl<<"For student "<<i+1<<endl;
        for(int j=0;j<num_courses[i];j++){
            cout<<"Enter marks of course "<<j+1<<": ";
            cin>>students_marks[i][j];
        }
    }
    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=0;j<num_courses[i];j++){
            sum+=students_marks[i][j];
        }
        float avg=sum/(float) num_courses[i];
        cout<<endl<<"Student "<<i+1<<" average marks: "<<avg;
    }
    for(int i=0;i<n;i++){
        delete[] students_marks[i];
    }
    delete[] num_courses;
    delete[] students_marks;
    return 0;
}