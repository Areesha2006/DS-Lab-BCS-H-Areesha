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
    Node* reverse_second_half(Node *curr,int n){
        Node *prev=NULL,*next;
        for(int i=0;i<n;i++){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
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
        bool is_palindrome(){
            int size=0;
            Node *temp=head;
            while(temp!=tail){
                temp=temp->next;
                size++;
            }
            int middle_pos=size/2;
            if(size%2==1){
                middle_pos=(size/2)+1;
            }
            else{
                middle_pos=(size/2);
            }
            int count=0;    
            temp=head;
            Node *middle;
            while(temp!=tail){
                count++;
                if(middle_pos==count){
                    middle=temp;
                    break;
                }
                temp=temp->next;
            }
            middle->next=reverse_second_half(middle->next,size-middle_pos);
            Node *start=middle->next;
            temp=head;
            while(temp!=middle){
                if(temp->data!=start->data){
                    return false;
                }
                temp=temp->next;
                start=start->next;
            }
            return true;
        }
};
int main(){
    SinglyList list;
    int n;
    cout<<"Enter the number of elements in the list: ";
    cin>>n;
    for (int i = 0; i < n; i++){
        int value;
        cout<<"Enter value "<<i+1<<": ";
        cin>>value;
        list.insert_at_tail(value);
    }
    if(list.is_palindrome()){
        cout<<"Yes the list is palindrome";
    }
    else{
        cout<<"No the list is not palindrome";
    }
    return 0;
}