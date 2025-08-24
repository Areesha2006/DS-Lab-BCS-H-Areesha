#include<iostream>
using namespace std;
class Box{
    int *len;
    public:
        Box(int len){
            this->len=new int(len);
        }
        Box(const Box &obj){
            len=new int(*obj.len);
        }
        void operator=(const Box &obj){
            if(this!=&obj){
                *len=*obj.len;
            }
        }
        void change_len(int l){
            *len=l;
        }
        int get_len(){
            return *len;
        }
        ~Box(){
            delete len;
        }
};
int main(){
    int l,new_len;
    cout<<"Enter the length of box 1: ";
    cin>>l;
    Box b1(l);
    Box b2(b1),b3(0);
    b3=b1;
    cout<<"Length of box 1: "<<b1.get_len()<<endl;
    cout<<"Length of box 2 copied from box 1: "<<b2.get_len()<<endl;
    cout<<"Length of box 3 copied from box 1: "<<b3.get_len()<<endl;
    cout<<endl<<"Enter the new lebgth for box 2: ";
    cin>>new_len;
    b2.change_len(new_len);       
    cout<<"Enter the new lebgth for box 3: ";
    cin>>new_len;
    b3.change_len(new_len);
    cout<<endl<<"After changing the lengths of box 2 and box 3\nLength of box 1: "<<b1.get_len()<<endl;
    cout<<"Length of box 2: "<<b2.get_len()<<endl;
    cout<<"Length of box 3: "<<b3.get_len()<<endl;
    return 0;
}