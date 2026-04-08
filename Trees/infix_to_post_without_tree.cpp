#include <iostream>
using namespace std;

#define MAX 100


struct Stack {
    char arr[MAX];
    int top;
};


void init(Stack &s) {
    s.top = -1;
}

// Push
void push(Stack &s, char ch) {
    if (s.top == MAX - 1) 
    return; // overflow
    s.arr[++s.top] = ch;
}

// Pop
char pop(Stack &s) {
    if (s.top == -1) 
    return '\0'; // empty
    return s.arr[s.top--];
}

// Peek
char peek(Stack &s) {
    if (s.top == -1) 
    return '\0';
    return s.arr[s.top];
}

// Check if empty
bool isEmpty(Stack &s) {
    return s.top == -1;
}

// Operator precedence logic
// Operator precedence logic
int precedence(char op) {
    switch(op) {
        case '!': return 4;      // unary NOT (highest)
        case '^': return 3;      // exponent
        case '*':
        case '/': return 2;      
        case '+':
        case '-': return 1;      
        case '<':
        case '>':
        case '=': return 0;      // comparison operators
        // (like <, >, ==)
        default: 
        return -1;      // for other cases
    }
}

// check if character is operand digit or letter
bool isOperand(char ch) {
    return (ch >= '0' && ch <= '9') || 
           (ch >= 'a' && ch <= 'z') || 
           (ch >= 'A' && ch <= 'Z');
}

// Infix to Postfix
string infixToPostfix(string infix) {
    Stack s;
    init(s);
    string postfix = "";

    for (int i = 0; i < infix.length(); i++) {
        char ch = infix[i];

        if (isOperand(ch)) { // operand
            postfix += ch;
        } 
        else if (ch == '(') {
            push(s, ch);
        } 
        else if (ch == ')') {
            while (!isEmpty(s) && peek(s) != '(') {
                postfix += pop(s);
            }
            pop(s); // remove '('
        } 
        else { // operator
            while (!isEmpty(s) && precedence(peek(s)) >= precedence(ch)) {
                postfix += pop(s);
            }
            push(s, ch);
        }
    }

    // pop remaining operators
    while (!isEmpty(s)) {
        postfix += pop(s);
    }

    return postfix;
}

int main() {
    string infix;
    cout << "Enter infix expression: ";
    cin >> infix;

    string postfix = infixToPostfix(infix);
    cout << "Postfix: " << postfix << endl;

    return 0;
}
//my example o/p ((a+b)*c-d)^e,(a+b)*c>d||e!=f,(a+b)*c>d+e