#include <iostream>
using namespace std;

#define SIZE 5

int queue[SIZE];
int front=-1;
int rear=-1;

bool isEmpty()
{
    return(front==-1);
}

bool isFull()
{
    return((rear+1)%SIZE==front);
}

void enqueue(int value)
{
    if(isFull())
    {
        cout<<"Queue Overflow"<<endl;
        return;
    }

    if(isEmpty())
    {
        front=rear=0;
    }
    else
    {
        rear=(rear+1)%SIZE;
    }

    queue[rear]=value;

    cout<<"Inserted "<<value<<endl;
}

void dequeue()
{
    if(isEmpty())
    {
        cout<<"Queue Underflow"<<endl;
        return;
    }

    cout<<queue[front]<<" removed"<<endl;

    if(front==rear)
    {
        front=rear=-1;
    }
    else
    {
        front=(front+1)%SIZE;
    }
}

void display()
{
    if(isEmpty())
    {
        cout<<"Queue empty"<<endl;
        return;
    }

    cout<<"Queue: ";

    int i=front;

    while(true)
    {
        cout<<queue[i]<<" ";

        if(i==rear)
        break;

        i=(i+1)%SIZE;
    }

    cout<<endl;
}

int getSize()
{
    if(isEmpty())
        return 0;
    
    if(front <= rear)
        return rear - front + 1;
    else
        return SIZE - (front - rear - 1);
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);

    display();
    cout<<"Size: "<<getSize()<<endl;

    dequeue();
    dequeue();

    enqueue(60);
    enqueue(70);

    display();
    cout<<"Size: "<<getSize()<<endl;

    return 0;
}