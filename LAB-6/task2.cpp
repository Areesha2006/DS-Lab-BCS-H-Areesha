#include<iostream>
using namespace std;
struct Node{
    string data;
    Node *link;
};
Node *top=NULL;
void push(string website){
    Node *n=new Node();
    if(!n){
        cout<<"Heap Overflow"<<endl;
    }
    else{
        n->data=website;
        n->link=top;
        top=n;
        cout<<n->data<<" visited and added to the browser history"<<endl;
    }
}
bool isEmpty(){
    return top==NULL;
}
void pop(){
    if(isEmpty()){
        cout<<"There is no website in the browser history so pop operation cannot be performed"<<endl;
    
    }
    else{
        cout<<top->data<<" popped from the browser history"<<endl;
        top=top->link;
        
    }
}
void peak(){
    if(isEmpty()){
        cout<<"There is no website in the browser history"<<endl;
    }
    else{
        cout<<"Last website visited: "<<top->data<<endl;;
    }
}
int main(){
    int c;
    while(1){
        cout<<"Enter the appropriate according to the operation you want to perform\n1.Push an element in the stack\n2.Pop an element from the stack\n3.Find the peak of the stack\n4.Check if the stack is empty or not?\nAny other key to exit\nEnter: ";
        cin>>c;
        switch(c){
            case 1:{
                string name;
                cout<<"Enter the name of the website which you want to visit: ";
                cin>>name;
                push(name);
                break;
            }
            case 2:
                pop();
                break;
            case 3:
                peak();
                break;
            case 4:
                if(isEmpty()){
                    cout<<"The browser history is empty"<<endl;
                }
                else{
                    cout<<"The browser history is not empty"<<endl;
                }
                break;
            default:
                cout<<"Exited successfully";
                return 0;
        }
        cout<<endl;
    }
}