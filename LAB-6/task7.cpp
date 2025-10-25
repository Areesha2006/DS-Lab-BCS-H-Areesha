#include<iostream>
using namespace std;
class Process{
    int id,priority;
    public:
        Process(int id=0,int p=0){
            this->id=id;
            priority=p;
        }
        int get_id(){
            return id;
        }
        int get_priority(){
            return priority;
        }
};
class Queue{
    Process processes[100];
    int front,rear;
    bool isFull(){
        return (rear+1)%100==front;
    }
    bool isEmpty(){
        return rear==-1&&front==-1;
    }
    public:
        Queue(){
            front=-1;
            rear=-1;
        }
        void enqueue(Process p){
            if(isFull()){
                cout<<"Queue overflow! no further process can be enqueued"<<endl;
            }
            else{
                if(isEmpty()){
                    front=0;
                }
                rear=(rear+1)%100;
                processes[rear]=p;
                cout<<"Process enqueued successfully"<<endl;
            }
        }
        void dequeue(Process p){
            if(isEmpty()){
                cout<<"Queue underflow! There is no process to dequeue"<<endl;
            }
            else{
                for (int i = front; i != (rear+1)%100; i=(i+1)%100){
                    if(p.get_id()==processes[i].get_id()){
                        if(i==front){
                            if(front==rear){
                                rear=-1;
                                front=-1;
                            }
                            else{
                                front=(front+1)%100;
                            }
                        }
                        else if(i==rear){
                            rear=(rear+99)%100;
                        }
                        else{
                            int j=i;
                            while (j!=rear){
                                int k=(j+1)%100;
                                processes[j]=processes[k];
                                j=k;
                            }
                            rear=(rear+99)%100;
                        }
                        break;
                    }
                }
            }
        }
};
class Stack{
    Process processes[100];
    int top=-1;
    bool isFull(){
        return top==99;
    }
    bool isEmpty(){
        return top==-1;
    }
    public:
        void push(Process p){
            if(isFull()){
                cout<<"Stack overflow"<<endl;
            }
            else{
                int i=top;
                while(i>=0&&processes[i].get_priority()>p.get_priority()){
                    processes[i+1]=processes[i];
                    i--;
                }
                processes[i+1]=p;
                top++;
                cout<<"Process pushed successfully"<<endl;
            }
        }
        Process* pop(){
            if(isEmpty()){
                cout<<"Stack underflow"<<endl;
                return NULL;
            }
            else{
                cout<<"Process  with least priority poped successfully"<<endl;
                return &processes[top--];
            }
        }
        void display(){
            if(top==-1){
                cout<<"No process found"<<endl;
                return;
            }
            for (int i = 0; i <= top; i++){
                cout<<"Process "<<i+1<<endl;
                cout<<"ID: "<<processes[i].get_id()<<endl;
                cout<<"Priority: "<<processes[i].get_priority()<<endl<<endl;
            }
        }
};
int main(){
    int c;
    Queue queue;
    Stack stack;
    while(true){
        cout<<"Enter appropriate key according to the function you want to perform\n1.Add a process\n2.Remove least priority process\n3.Display all processes\nAny other key to exit\nEnter: ";
        cin>>c;
        switch(c){
            case 1:{
                int id,priority;
                cout<<"Enter process id: ";
                cin>>id;
                while(1){
                    cout<<"Enter priority (1-(HIGHEST) to 5-(LOWEST)): ";
                    cin>>priority;
                    if(priority>=1&&priority<=5){
                        break;
                    }
                    else{
                        cout<<"Invalid input"<<endl;
                    }
                }
                Process p(id,priority);
                queue.enqueue(p);
                stack.push(p);
                break;
            }
            case 2:{
                Process *p=stack.pop();
                if(p!=NULL){
                    queue.dequeue(*p);
                }
                break;
            }
            case 3:
                cout<<"Displaying all processes in descending order of priority (HIGHEST-FIRST TO LOWEST-LAST)"<<endl;
                stack.display();
                break;
            default:
                cout<<"Exited successfully";
                return 0;
        }
        cout<<endl;
    }
}