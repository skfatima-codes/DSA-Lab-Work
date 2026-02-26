#include <iostream>
using namespace std;

#define size 5

int arr[size];
int front = -1;
int rear = -1;

void enqueue(int value) {
    if ((rear + 1) % size == front) {
        cout << "Queue Full\n";
        return;
    }

    if (front == -1) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % size;
    }

    arr[rear] = value;
}

void dequeue() {
    if (front == -1) {
        cout << "Queue Empty\n";
        return;
    }

    cout << "Deleted: " << arr[front] << endl;

    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % size;
    }
}

void display() {
    if (front == -1) {
        cout << "Queue Empty\n";
        return;
    }

    int i = front;

    while (true) {
        cout << arr[i] << " ";
        if (i == rear)
            break;
        i = (i + 1) % size;
    }
    cout << endl;
}
