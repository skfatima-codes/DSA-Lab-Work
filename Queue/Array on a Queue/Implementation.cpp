#include <iostream>
using namespace std;
#define SIZE 5
int queue[SIZE];
int front=-1;
int rear=-1;
//checking if the queue is empty
bool isEmpty(){
    return(front==-1);
}
bool isFull(){
    return(rear==SIZE-1);
}
void enqueue(int c){
    if(isFull()){
        cout<<"Underflow! Can't Insert"<<c<<endl;

    }
    if(isEmpty()){
        front=0;//1st elemt kyliye fr=0 krdia
        rear++;
        queue[rear]=c;
        cout<<"Inserted ELements "<<c<<endl;
    }
}
void dequeue(){
    if(isEmpty()){
        cout<<"Stack underflow";
        return;
    }
    cout<<queue[front]<<"ELements removed"<<endl;
    if(front==rear){
        front=rear=-1;
    }else{
        front++;
    }
}
int peek() {
    if(isEmpty()) {
        cout << "Queue is empty" << endl;
        return -1; // Error value
    }
    return queue[front];
}
void display() {
    if(isEmpty()) {
        cout << "Queue empty" << endl;
        return;
    }
    cout << "Queue: ";
    for(int i = front; i <= rear; i++) {
        cout << queue[i] << " ";
    }
    cout << endl;
}z


int main(){
        enqueue(10);
    enqueue(20);
    enqueue(30);
    display();      // Queue: 10 20 30

    dequeue();      // 10 removed
    display();      // Queue: 20 30

    enqueue(40);
    enqueue(50);
    enqueue(60);    // Overflow
    display();      // Queue: 20 30 40 50

    cout << "Front element: " << peek() << endl; // Front = 20

    dequeue(); // 20 removed
    dequeue(); // 30 removed
    dequeue(); // 40 removed
    dequeue(); // 50 removed
    dequeue(); // Underflow
    display(); // Queue empty

    return 0;
    
};