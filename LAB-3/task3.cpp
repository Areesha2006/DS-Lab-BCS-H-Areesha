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
class SinglyLinkedList{
    public:
        Node *head,*tail;
        SinglyLinkedList(){
            head=NULL;
            tail=NULL;
        }
        void insert_at_tail(int value){
            Node *n=new Node(value);
            if(head==NULL){
                head=n;
                return;
            }
            Node *temp=head;
            while(temp->next!=tail){
                temp=temp->next;
            }
            temp->next=n;
            n->next=tail;
        }
        void reverse_in_group(int k){
            Node *temp=head;
            if(head==NULL){
                cout<<"There are no elements so reverse is not possible"<<endl;
                return;
            }
            int size=0;
            while(temp!=tail){
                size++;
                temp=temp->next;
            }
            int no_groups;
            if(size%k==0){
                no_groups=size/k;
            }
            else{
                no_groups=(size/k)+1;
            }
            int i=0;
            temp=head;
            Node *curr,*prev,*next;
            bool first_group=true;
            while(i<no_groups){
                prev=NULL;
                curr=temp;
                bool curr_is_null=false;
                for(int j=0;j<k;j++){
                    next=curr->next;
                    curr->next=prev;
                    prev=curr;
                    curr=next;
                    if(curr==tail){
                        curr_is_null=true;
                        break;
                    }
                }
                if(first_group){
                    head=prev;
                    first_group=false;
                }
                else{
                    temp=head;
                    while(temp->next!=tail){
                        temp=temp->next;
                    }
                    temp->next=prev;
                }
                if(curr_is_null){
                    break;
                }
                temp=curr;
                i++;
            }
        }
        void display(){
            Node *temp=head;
            while(temp!=tail){
                cout<<temp->data<<" ";
                temp=temp->next;
            }
        }
};
int main(){
    int n,k;
    SinglyLinkedList list;
    cout<<"How many numbers are there in the list: ";
    cin>>n;
    for(int i=0;i<n;i++){
        int value;
        cout<<"Enter number "<<i+1<<": ";
        cin>>value;
        list.insert_at_tail(value);
    }
    do{
        cout<<"Enter the value of k (k must be greater than 1): ";
        cin>>k;
        if(k<=1){
            cout<<"Invalid input"<<endl;
        }
    }while(k<=1);
    cout<<"List before reversing in groups"<<endl;
    list.display();
    list.reverse_in_group(k);
    cout<<endl<<"List after reversing in groups"<<endl;
    list.display();
    return 0;
}