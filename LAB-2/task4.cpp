#include<iostream>
using namespace std;
void resize(int **expenses,int *old,int add){
    int *new_expenses=new int[*old+add];
    for(int i=0;i<*old+add;i++){
        if(i<*old){
            new_expenses[i]=(*expenses)[i];
        }
        else{
            cout<<"Enter the expense for month "<<i+1<<": ";
            cin>>new_expenses[i];
        }
    }
    if(*expenses!=NULL){
        delete[] *expenses;
    }
    *expenses=new_expenses;
    *old+=add;
}
int main(){
    int n;
    cout<<"Enter the number of months of which expenses have to store: ";
    cin>>n;
    int *month_expenses=new int[n];
    for (int i = 0; i < n; i++){
        cout<<"Enter the expense of month "<<i+1<<": ";
        cin>>month_expenses[i];
    }
    int is_resize;
    cout<<"Do you want to resize the array? (Enter 0 for no or else any number for yes): ";
    cin>>is_resize;
    while(is_resize!=0){
        int add;
        do{
            cout<<"Enter the additional months of expenses you want to store: ";
            cin>>add;
            if(add<=0){
                cout<<"Invalid Input"<<endl;
            }
        }while(add<=0);
        resize(&month_expenses,&n,add);
        cout<<"Do you want to resize the array again? (Enter 0 for no or else any number for yes): ";
        cin>>is_resize;
    }
    int total=0;
    float avg;
    for(int i=0;i<n;i++){
        total+=month_expenses[i];
    }
    avg=total/(float)n;
    cout<<"Total Expenses: "<<total<<endl;
    cout<<"Average Expenses: "<<avg;
    return 0;
}