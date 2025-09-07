#include<iostream>
using namespace std;
class Singly_Node{
    public:
        int data;
        Singly_Node *next;
        Singly_Node(int value){
            data=value;
            next=NULL;
        }
};
class Doubly_Node{
    public:
        int data;
        Doubly_Node *next;
        Doubly_Node *prev;
        Doubly_Node(int value){
            data=value;
            next=NULL;
            prev=NULL;
        }
};
class LinkedList{
    Singly_Node *shead,*stail;
    Doubly_Node *dhead,*dtail;
    public:
        LinkedList(){
            shead=NULL;
            stail=NULL;
            dhead=NULL;
            dtail=NULL;
        }
        void convert_to_doubly(){
            if(shead==NULL){
                return;
            }
            else{
                Singly_Node *temp=shead;
                while(temp!=stail){
                    Doubly_Node *n=new Doubly_Node(temp->data);
                    if(dhead==NULL){
                        dhead=n;
                        dtail=n;
                    }
                    else{
                        dtail->next=n;
                        n->prev=dtail;
                        dtail=n;
                    }
                    temp=temp->next;
                }
            }
            shead=NULL;
        }
        void convert_to_circular(){
            Singly_Node *temp=shead;
            while(temp->next!=stail){
                temp=temp->next;
            }
            stail=temp;
            temp->next=shead;
        }
        void insert(int value){
            Singly_Node *n=new Singly_Node(value);
            if(shead==NULL){
                shead=n;
                return;
            }
            Singly_Node *temp=shead;
            while(temp->next!=stail){
                temp=temp->next;
            }
            temp->next=n;
            n->next=stail;
        }
        void display(){
            if(shead!=NULL){
                Singly_Node *temp=shead;
                while(temp!=stail){
                    cout<<temp->data<<" ";
                    temp=temp->next;
                }
                if(stail!=NULL){
                    cout<<stail->data;
                }
            }
            else{
                Doubly_Node *temp=dhead;
                while(temp!=NULL){
                    cout<<temp->data<<" ";
                    temp=temp->next;
                }
            }
        }
};
int main(){
    int n;
    LinkedList list1,list2;
    cout<<"How many numbers are there in the list 1: ";
    cin>>n;
    for(int i = 0; i < n; i++){
        int d;
        cout<<"Enter value "<<i+1<<": ";
        cin>>d;
        list1.insert(d);
    }
    cout<<"List 1 in Singly Linked List form"<<endl;
    list1.display();
    list1.convert_to_circular();
    cout<<endl<<"After converting list1 into Circular Linked List"<<endl;;
    list1.display();
    cout<<endl<<endl<<"How many numbers are there in the list 2: ";
    cin>>n;
    for(int i = 0; i < n; i++){
        int d;
        cout<<"Enter value "<<i+1<<": ";
        cin>>d;
        list2.insert(d);
    }
    cout<<"List2 in Singly Linked List form"<<endl;
    list2.display();
    list2.convert_to_doubly();
    cout<<endl<<"After converting list2 into Doubly Linked List"<<endl;;
    list2.display();
    return 0;
}