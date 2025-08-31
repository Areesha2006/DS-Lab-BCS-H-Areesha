#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"How many departments are there: ";
    cin>>n;
    int **department_data=new int*[n],*num_employees=new int[n];
    float *avg_salaries=new float[n];
    for(int i=0;i<n;i++){
        while(1){
            cout<<"How many employees are there in department "<<i+1<<": ";
            cin>>num_employees[i];
            if(num_employees[i]>0){
                break;
            }
            else{
                cout<<"Invalid input"<<endl;
            }
        }
        department_data[i]=new int[num_employees[i]];
    }
    for(int i=0;i<n;i++){
        cout<<endl<<"For department "<<i+1<<endl;
        for(int j=0;j<num_employees[i];j++){
            cout<<"Enter salary of employee "<<j+1<<": ";
            cin>>department_data[i][j];
        }
    }
    for(int i=0;i<n;i++){
        int highest_salary=department_data[i][0];
        for(int j=1;j<num_employees[i];j++){
            if(highest_salary<department_data[i][j]){
                highest_salary=department_data[i][j];
            }
        }
        cout<<endl<<"The highest salary of department "<<i+1<<" is "<<highest_salary;
    }
    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=0;j<num_employees[i];j++){
            sum+=department_data[i][j];
        }
        avg_salaries[i]=sum/(float) num_employees[i];
    }
    float max_avg=avg_salaries[0];
    int max_avg_dept=1;
    for(int i=1;i<n;i++){
        if(max_avg<avg_salaries[i]){
            max_avg=avg_salaries[i];
            max_avg_dept=i+1;
        }
    }
    cout<<"\nDepartment "<<max_avg_dept<<" has the overall maximum average salary which is "<<max_avg;
    for(int i=0;i<n;i++){
        delete[] department_data[i];
    }
    delete[] num_employees;
    delete[] department_data;
    delete[] avg_salaries;
    return 0;
}