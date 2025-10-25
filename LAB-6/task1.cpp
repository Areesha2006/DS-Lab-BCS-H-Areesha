#include<iostream>
using namespace std;
class Stack{
    int top=-1,arr[1000];
    public:
        void push(int x){
            if(top==999){
                cout<<"Stack Overflow"<<endl;
            }
            else{
                arr[++top]=x;
            }
        }
        int* pop(){
            if(top<0){
                cout<<"Stack Underflow"<<endl;
                return NULL;
            }
            else{
                return &arr[top--];
            }
        }
        int* peak(){
            if(top<0){
                cout<<"Stack Underflow"<<endl;
                return NULL;
            }
            else{
                return &arr[top];
            }
        }
        void display(){
            if(top<0){
                cout<<"Stack Underflow"<<endl;
            }
            else{
                for (int i = 0; i <=top; i++){
                    cout<<arr[i]<<" ";
                }
            }
        }
};
int main(){
    int n,is_to_do;
    Stack stack;
    cout<<"How many numbers are there in the stack: ";
    cin>>n;
    for (int i = 0; i < n; i++){
        int a;
        cout<<"Enter number "<<i+1<<": ";
        cin>>a;
        stack.push(a);
    }
    cout<<"\nDisplaying stack\n";
    stack.display();
    cout<<"\nDo you want to find the peak of stack? Enter 0 for no else any number for yes: ";
    cin>>is_to_do;
    if(is_to_do!=0){
        if(stack.peak()!=NULL){
            cout<<"Peak: "<<*stack.peak()<<endl;
        }
    }
    cout<<"Do you want to pop the last element of stack? Enter 0 for no else any number for yes: ";    
    cin>>is_to_do;
    while(is_to_do!=0){
        cout<<*stack.pop()<<" popped"<<endl;
        cout<<"Displaying stack\n";
        stack.display();
        cout<<"\nDo you want to find the new peak of stack? Enter 0 for no else any number for yes: ";
        cin>>is_to_do;
        if(is_to_do!=0){
            if(stack.peak()!=NULL){
                cout<<"Peak: "<<*stack.peak()<<endl;
            }
        }
        cout<<"Do you again want to pop the last element of stack? Enter 0 for no else any number for yes: ";    
        cin>>is_to_do;
    }
    return 0;
}