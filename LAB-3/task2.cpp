#include<iostream>
using namespace std;
class Node{
    public:
        int data;
        Node *next;
        Node(int value){
            data=value;
            next=NULL;
        }
};
class SinglyList{
    public:
        Node *head,*tail;
        SinglyList(){
            head=NULL;
            tail=NULL;
        }
        void insert_at_tail(int value){
            Node *n=new Node(value);
            if(head==NULL){
                head=n;
            }
            else{
                Node *temp=head;
                while(temp->next!=tail){
                    temp=temp->next;
                }
                temp->next=n;
                n->next=tail;
            }
        }
        void sort_list(){
            Node *start=head,*p,*q;
            for(Node *end=tail;end!=start->next;end=p){    
                for(p=start;p->next!=end;p=p->next){
                    q=p->next;
                    if(p->data>q->data){
                        int temp=p->data;
                        p->data=q->data;
                        q->data=temp;
                    }
                }
            }
        }
        void display(){
            Node *temp=head;
            while(temp!=tail){
                cout<<temp->data<<" ";
                temp=temp->next;
            }
        }
        SinglyList merge_list(SinglyList l){
            SinglyList list;
            Node *temp=head;
            while(temp!=tail){
                list.insert_at_tail(temp->data);
                temp=temp->next;
            }
            temp=l.head;
            while(temp!=l.tail){
                list.insert_at_tail(temp->data);
                temp=temp->next;
            }
            list.sort_list();
            return list;
        }
};
int main(){
    SinglyList list1,list2;
    int n;
    cout<<"Enter the number of elements in list 1: ";
    cin>>n;
    for (int i = 0; i < n; i++){
        int value;
        cout<<"Enter value "<<i+1<<": ";
        cin>>value;
        list1.insert_at_tail(value);
    }
    cout<<"\nEnter the number of elements in list 2: ";
    cin>>n;
    for (int i = 0; i < n; i++){
        int value;
        cout<<"Enter value "<<i+1<<": ";
        cin>>value;
        list2.insert_at_tail(value);
    }
    SinglyList merged_list=list1.merge_list(list2);
    cout<<"List 1: ";
    list1.sort_list();
    list1.display();
    cout<<"\nList 2: ";
    list2.sort_list();
    list2.display();
    cout<<"\nMerged List: ";
    merged_list.display();
    return 0;
}