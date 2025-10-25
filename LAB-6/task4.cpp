#include<iostream>
using namespace std;
const int N=100;
int arr[N],rear=-1,front=-1;
bool isFull(){
    if((rear+1)%N==front){
        return true;
    }
    else{
        return false;
    }
}
bool isEmpty(){
    if(rear==-1&&front==-1){
        return true;
    }
    else{
        return false;
    }
}
void enqueue(int x){
    if(isFull()){
        cout<<"Queue overflow occurs so no element can be enqueued"<<endl;
        return;
    }
    if(isEmpty()){
        front=0;
    }
    rear=(rear+1)%N;
    arr[rear]=x;
    cout<<arr[rear]<<" enqueued successfully"<<endl;
}
void dequeue(){
    if(isEmpty()){
        cout<<"Queue underflow so no element can be dequeued"<<endl;
    }
    else{
        int x=arr[front];
        if(front==rear){
            front=-1;
            rear=-1;            
        }
        else{
            front=(front+1)%N;
        }
        cout<<x<<" dequeued"<<endl;
    }
}
int main(){
    int c,a;
    while(1){
        cout<<"Press the appropriate key according to the function you ant to perform\n1.Enqueue a element in the queue\n2.Dequeue the first element of the queue\nAny other key to exit\nEnter: ";
        cin>>c;
        switch(c){
            case 1:
                cout<<"Enter a number: ";
                cin>>a;
                enqueue(a);
                break;
            case 2:
                dequeue();
                break;
            default:
                cout<<"Exited successfuuly"<<endl;
                return 0;
        }
        cout<<endl;
    }
}