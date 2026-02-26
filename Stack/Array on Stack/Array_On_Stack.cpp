#include <iostream>
using namespace std;

#define SIZE 5   // Stack size

int arr[SIZE];   // Stack array
int top = -1;    // Initially stack empty


bool isEmpty() {
    return (top == -1);
}


bool isFull() {
    return (top == SIZE - 1);
}


void push(int value) {
    if (isFull()) {
        cout << "Stack Overflow\n";
        return;
    }
    top = top + 1;      // Move top up
    arr[top] = value;   // Store value
    cout << value << " pushed into stack\n";
}

int pop() {
    if (isEmpty()) {
        cout << "Stack Underflow\n";
        return -1;
    }
    int value = arr[top]; // Store top value
    top = top - 1;        // Move top down
    return value;
}

int peek() {
    if (isEmpty()) {
        cout << "Stack Empty\n";
        return -1;
    }
    return arr[top];     // Return top element
}

void display() {
    if (isEmpty()) {
        cout << "Stack Empty\n";
        return;
    }
    cout << "Stack elements (top → bottom):\n";
    for (int i = top; i >= 0; i--) {
        cout << arr[i] << endl;
    }
}

int main() {
    int choice, value;

    while (true) {
        
        cout << "\n=== Stack Menu ===\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Peek\n";
        cout << "4. Display\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                push(value);
                break;

            case 2:
                value = pop();
                if (value != -1)
                    cout << "Popped: " << value << endl;
                break;

            case 3:
                value = peek();
                if (value != -1)
                    cout << "Top element: " << value << endl;
                break;

            case 4:
                display();
                break;

            case 5:
                cout << "Exiting...\n";
                return 0;

            default:
                cout << "Invalid choice! Try again.\n";
        }
    }
}

