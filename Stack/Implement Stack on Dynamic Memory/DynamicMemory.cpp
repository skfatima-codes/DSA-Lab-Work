#include <iostream>
using namespace std;
struct Node{
    int data;
    Node*next;
};
Node*top=NULL;
//check is stck is empty?
bool isEmpty(){
    return(top==NULL);
}
void push(int value){
    Node*newNode=new Node;
    newNode->data=value;
    newNode->next=top;
    top=newNode;
}
int pop(){
    if(isEmpty()){
        cout<<"Stack is empty"<<endl;
        return -1;
    }
    Node*temp=top;
    int val=temp->data;
    top=temp->next;
    delete temp;
    return val;
}
int peek(){
    if(isEmpty()){
       cout<<"Stack is empty"<<endl;
       return -1;
    }
    return top->data;
}

void display(){
    if(isEmpty()){
        cout<<"Stack is empty"<<endl;
        return;
    }
    Node*temp=top;
    while(temp!=NULL){
        cout<<temp->data<<endl;
        temp=temp->next;
    }
}
int main(){
    push(10);
    push(20);
    push(30);
    peek();
    cout<<pop()<<endl;
    peek();
    display();
    display();
    // peek();
    // peek();

}