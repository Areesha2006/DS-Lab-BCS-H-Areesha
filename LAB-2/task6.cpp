#include<iostream>
using namespace std;
class Student{
    int *marks;
    public:
        void setValue(int m){
            marks=new int(m);
        }
        int getValue(){
            return *marks;
        }
        void release(){
            if(marks!=NULL){
                delete marks;
            }
        }
};
int main(){
    Student students[5];
    for(int i=0;i<5;i++){
        int marks;
        cout<<"Enter marks of student "<<i+1<<": ";
        cin>>marks;
        students[i].setValue(marks);
    }
    for(int i=0;i<5;i++){
        cout<<endl<<"Student "<<i+1<<" marks: "<<students[i].getValue();
    }
    for(int i=0;i<5;i++){
        students[i].release();
    }
    return 0;
}