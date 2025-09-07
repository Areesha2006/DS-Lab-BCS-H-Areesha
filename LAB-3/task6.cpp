#include<iostream>
using namespace std;
class Node{
    public:
        int data;
        Node *next;
        Node *child;
        Node(int value){
            data=value;
            next=NULL;
            child=NULL;
        }
};
class LinkedList{
    void flatten_child(Node *child_head){
        Node *temp=child_head;
        while(temp!=NULL){
            insert(temp->data);
            if(temp->child!=NULL){
                flatten_child(temp->child);
            }
            temp=temp->next;
        }
    }
    public:
        Node *head,*tail;
        LinkedList(){
            head=NULL;
            tail=NULL;
        }
        void create_child_list(Node *n,int level=0){
            int is_child_list;
            for(int i=0;i<level;i++){
                cout<<"   ";
            }
            cout<<"Enter '0' if this node is not connected to a chld list or any number otherwise: ";
            cin>>is_child_list;
            if(is_child_list!=0){
                LinkedList child_list;
                int m;
                for(int i=0;i<level;i++){
                    cout<<"   ";
                }
                cout<<"How many nodes are connected to this child list: ";
                cin>>m;
                for(int i=0;i<m;i++){
                    int value;
                    for(int i=0;i<level;i++){
                        cout<<"   ";
                    }
                    cout<<"Enter value "<<i+1<<": ";
                    cin>>value;
                    Node *n=child_list.insert(value);
                    child_list.create_child_list(n,level+1);
                }
                n->child=child_list.head;
            }
        }
        Node* insert(int value){
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
            return n;
        }
        void display(int level=0){
            Node *temp=head;
            while(temp!=tail){
                for(int i=0;i<level;i++){
                    cout<<"  ";
                }
                cout<<temp->data<<" ";
                cout<<endl;
                if(temp->child!=NULL){
                    LinkedList list;
                    list.head=temp->child;
                    list.display(level+1);            
                }
                temp=temp->next;
            }    
        }
        void flatten(){
            Node *temp=head;
            head=NULL;
            while(temp!=tail){
                insert(temp->data);
                if(temp->child!=NULL){
                    flatten_child(temp->child);
                }
                temp=temp->next;
            }
        }
};
int main(){
    int n;
    LinkedList list;
    cout<<"How many nodes are there in the list: ";
    cin>>n;
    for(int i=0;i<n;i++){
        int value;
        cout<<"Enter value for node "<<i+1<<": ";
        cin>>value;
        Node *n=list.insert(value);
    
            list.create_child_list(n);
    }
    cout<<endl<<"List before flattening"<<endl;
    list.display();
    list.flatten();
    cout<<endl<<"List after flattening"<<endl;
    list.display();
    return 0;
}