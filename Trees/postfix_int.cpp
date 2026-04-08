#include <iostream>
using namespace std;

#define SIZE 20

int stackArr[SIZE];
int top = -1;


bool isEmpty() {
    return top == -1;
}


bool isFull() {
    return top == SIZE - 1;
}


void push(int value) {
    if (isFull()) {
        cout << "Stack Overflow\n";
        return;
    }
    stackArr[++top] = value;
}

// 
int pop() {
    if (isEmpty()) {
        cout << "Stack Underflow\n";
        return -1;
    }
    return stackArr[top--];
}

// Display current stack
void showStack() {
    for (int i = top; i >= 0; i--) {
        cout << stackArr[i] << " ";
    }
    if (top == -1) cout << "(empty)";
}

int main() {
    string postfix;

    cout << "Enter postfix expression ";
    cin >> postfix;

    cout << "\nPostfix Evaluation Steps:\n";

    for (int i = 0; i < postfix.length(); i++) {
        char ch = postfix[i];
        cout << "\nMy Stack before processing "<<ch<<":";
        showStack();
        cout << "\nMy Stack after processing my logic " << ch << endl;

        if (ch >= '0' && ch <= '9') { // Operand
            int num = ch - '0';
            push(num);
            cout << "Push " << num << endl;
        } else { // Operator
            int val1 = pop();
            int val2 = pop();
            int myresult;

            switch (ch) {
                case '+': myresult = val2 + val1; break;
                case '-': myresult = val2 - val1; break;
                case '*': myresult = val2 * val1; break;
                case '/': myresult = val2 / val1; break;
                default:
                    cout << "Invalid operator:(Sadly) " << ch << endl;
                    return 1;
            }

            cout << "Pop " << val2 << " and " << val1 << endl;
            cout << "Result: " << myresult << endl;

            push(myresult);
        }

        cout << "Stack now: ";
        showStack();
        cout << endl;
    }

    cout << "\nFinal Result = " << pop() << endl;

    return 0;
}
// 23+54*6-7+