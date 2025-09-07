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
class CircularLinkedList{
    Node *head,*tail;
    public:
        CircularLinkedList(){
            head=NULL;
            tail=NULL;
        }
        void insert(int value){
            Node *n=new Node(value);
            if(head==NULL){
                head=n;
                tail=n;
                tail->next=head;
            }
            tail->next=n;
            tail=n;
            tail->next=head;
        }
        void display(){
            Node *temp=head;
            do{
                cout<<temp->data<<" ";
                temp=temp->next;
            }while(temp!=head);
        }
        int delete_every_kth(int k){
            Node *temp=head;
            while(head->next!=head){
                Node *delete_node;
                for(int i=1;i<k-1;i++){
                    temp=temp->next;
                }
                delete_node=temp->next;
                temp->next=delete_node->next;
                temp=temp->next;
                if(delete_node==head){
                    head=head->next;
                }
                delete delete_node;
            }
            return head->data;
        }
};
int main(){
    int N,k;
    CircularLinkedList list;
    cout<<"How many people are there: ";
    cin>>N;
    for(int i=0;i<N;i++){
        list.insert(i+1);
    }
    cout<<"S.no of people is as follows starting from head till tail in sequence stored in circular form"<<endl;
    list.display();
    cout<<"\nEnter the value of kth: ";
    cin>>k;
    cout<<"S.no of the surviving person: "<<list.delete_every_kth(k);
    return 0;
}