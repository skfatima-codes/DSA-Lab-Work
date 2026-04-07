#include <iostream>
using namespace std;

#define SIZE 5

int queue[SIZE];
int front=-1;
int rear=-1;

bool isEmpty(){
    return(front==-1);
}

bool isFull(){
    return(rear==SIZE-1);
}

void enqueue(int c){

    if(isFull()){
        cout<<"Overflow! Can't Insert "<<c<<endl;
        return;
    }

    if(isEmpty()){
        front=0;
        rear=0;
    }
    else{
        rear++;
    }

    queue[rear]=c;

    cout<<"Inserted Element "<<c<<endl;
}

void dequeue(){

    if(isEmpty()){
        cout<<"Queue underflow"<<endl;
        return;
    }

    cout<<queue[front]<<" Element removed"<<endl;

    if(front==rear){
        front=rear=-1;
    }
    else{
        front++;
    }
}

int peek(){

    if(isEmpty()){
        cout<<"Queue empty"<<endl;
        return -1;
    }

    return queue[front];
}

void display(){

    if(isEmpty()){
        cout<<"Queue empty"<<endl;
        return;
    }

    cout<<"Queue: ";

    for(int i=front;i<=rear;i++){
        cout<<queue[i]<<" ";
    }

    cout<<endl;
}

int main(){

    enqueue(10);
    enqueue(20);
    enqueue(30);

    display();

    dequeue();

    display();

    enqueue(40);
    enqueue(50);
    enqueue(60);

    display();

    cout<<"Front element: "<<peek()<<endl;

    dequeue();
    dequeue();
    dequeue();
    dequeue();
    dequeue();

    display();

    return 0;
}
