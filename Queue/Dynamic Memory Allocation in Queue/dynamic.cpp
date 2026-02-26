#include <iostream>
using namespace std;
struct Node{
    int data;
    Node*next;
};
Node*front=NULL;
Node*rear=NULL;
void enqueue(int v){
    Node*n1=new Node;
    n1->data=v;
    n1->next=NULL;
    if(front==NULL){// when queue is empty
        front=rear=n1;
    }
    else{
        rear->next=n1; //if queue is not empty, 
                       //add new node to the end of the queue
        rear=n1;
    }
}
void dequeue(){
    if(front==NULL){
        cout<<"Queue is empty"<<endl;
    }else{
        Node*temp=front;
        front=front->next;
        delete temp;// free the memory of the dequeued node
    }

}
void display(){
    if(front==NULL){
        cout<<"Queue is empty"<<endl;
        return;
    }
    Node*temp=front;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int main(){
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);

    cout<<"Queue after enqueuing 10, 20, 30, 40: ";
    display();
    
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    
    cout<<"Queue after 4 dequeues: ";
    display();

    return 0;
}