#include <iostream>
using namespace std;

// Node structure for stack
struct Node {
    int data;
    Node* next;
};

// Function to push an element onto the stack
void push(Node*& top, int value) {
    Node* newNode = new Node; // create new node dynamically
    newNode->data = value;
    newNode->next = top; // link new node to current top
    top = newNode;       // update top
    cout << value << " pushed to stack." << endl;
}

// Function to pop an element from the stack
void pop(Node*& top) {
    if (top == nullptr) {
        cout << "Stack Underflow! Nothing to pop." << endl;
        return;
    }
    Node* temp = top;
    top = top->next; // move top pointer
    cout << temp->data << " popped from stack." << endl;
    delete temp;     // free memory
}

// Function to peek at the top element
void peek(Node* top) {
    if (top == nullptr) {
        cout << "Stack is empty." << endl;
        return;
    }
    cout << "Top element is: " << top->data << endl;
}

// Function to display the stack
void display(Node* top) {
    if (top == nullptr) {
        cout << "Stack is empty." << endl;
        return;
    }
    cout << "Stack: ";
    Node* temp = top;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

// Driver code
int main() {
    Node* top = nullptr; // empty stack

    push(top, 10);
    push(top, 20);
    push(top, 30);

    display(top);
    peek(top);

    pop(top);
    display(top);

    pop(top);
    pop(top);
    pop(top); // pop from empty stack

    return 0;
}
