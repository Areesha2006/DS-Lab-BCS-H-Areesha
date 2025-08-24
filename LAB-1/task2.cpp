#include<iostream>
using namespace std;
class Exam{
    string *student_name,*exam_date;
    int *score;
    public:
        Exam(){
            student_name=new string("");
            exam_date=new string("");
            score=new int(0);
        }
        void setStudentName(string name){
            *student_name=name;
        }
        void setExamDate(string date){
            *exam_date=date;
        }
        void setScore(int score){
            *(this->score)=score;
        }
        void printExamDetails(){
            cout<<"Student Name: "<<*student_name<<endl;
            cout<<"Exam Date: "<<*exam_date<<endl;
            cout<<"Score: "<<*score<<endl;
        }
        ~Exam(){
            delete student_name;
            delete exam_date;
            delete score;
        }
};
int main(){
    Exam s1;
    s1.setStudentName("Ali");
    s1.setExamDate("10 August 2025");
    s1.setScore(88);
    Exam s2=s1;
    cout<<"Printing the details of student 1"<<endl;
    s1.printExamDetails();
    cout<<"\nPrinting the details of student 2 copied from student 1"<<endl;
    s2.printExamDetails();
    s2.setStudentName("Sara");
    s2.setExamDate("15 August 2025");
    s2.setScore(77);
    cout<<"\nAfter changing the attributes of student2 which was copied from student 1"<<endl;
    cout<<"Printing the details of student 1"<<endl;
    s1.printExamDetails();
    cout<<"\nPrinting the details of student 2"<<endl;
    s2.printExamDetails();   
    return 0;
}