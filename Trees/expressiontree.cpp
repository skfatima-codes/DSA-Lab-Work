#include <iostream>
#include <cctype>
using namespace std;

#define SIZE 50  // stack size

struct ETNode {
    char data;
    ETNode* left;
    ETNode* right;
};

// stack for storing tree nodes
ETNode* arr[SIZE];
int top = -1;

bool isEmpty() { 
    return (top == -1); }
bool isFull() { 
    return (top == SIZE - 1); }

void push(ETNode* value) {
    if(isFull()) {
        cout << "Overflow\n";
        return;
    }
    arr[++top] = value;
}

ETNode* pop() {
    if(isEmpty()) {
        cout << "Underflow\n";
        return NULL;
    }
    return arr[top--];
}

// creatingg a tree node
ETNode* createNode(char t) {
    ETNode* temp = new ETNode;
    temp->data = t;
    temp->left = temp->right = NULL;
    return temp;
}

//traversals
void preorder(ETNode* root) {
    if(!root) 
    return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(ETNode* root) {
    if(!root) 
    return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void postorder(ETNode* root) {
    if(!root) 
    return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

// Operator precedence logic
int precedence(char op) {
    if(op=='+'||op=='-') return 1;
    if(op=='*'||op=='/') return 2;
    if(op=='^') return 3;
    return 0;
}

// Convert infix to postfix
string infixToPostfix(string infix) {
    ETNode* opStack[SIZE]; //  this is a temporary stack for operators
    char opTop = -1;
    string postfix = "";
    char stackCh[SIZE];
    int stTop = -1;

    for(char ch : infix) {
        if(isalnum(ch)) {
            postfix += ch;
        } else if(ch == '(') {
            stackCh[++stTop] = ch;
        } else if(ch == ')') {
            while(stTop >= 0 && stackCh[stTop] != '(') {
                postfix += stackCh[stTop--];
            }
            if(stTop >= 0) stTop--; // remove '('
        } else { // operator
            while(stTop >= 0 && precedence(stackCh[stTop]) >= precedence(ch)) {
                postfix += stackCh[stTop--];
            }
            stackCh[++stTop] = ch;
        }
    }
    while(stTop >= 0) {
        postfix += stackCh[stTop--];
    }
    return postfix;
}

int main() {
    string infix;
    cout << "Enter infix expression:\n";
    cin >> infix;

    string postfix = infixToPostfix(infix);
    cout << "Postfix: " << postfix << "\n";

    // Build expression tree using manual stack
    for(int i = 0; i < postfix.length(); i++) {
        char ch = postfix[i];
        //check if a character is alphanumeric.
        //means digots or letters
        if(isalnum(ch)) { // operand
            push(createNode(ch));
        } else { // operator
            ETNode* temp = createNode(ch);
            temp->right = pop();
            temp->left = pop();
            push(temp);
        }
    }

    ETNode* root = pop();

    cout << "\nPreorder: ";
    preorder(root);

    cout << "\nInorder: ";
    inorder(root);

    cout << "\nPostorder: ";
    postorder(root);

    cout << endl;
    return 0;
}
//exa,mple (a+b)/(c-d)*e