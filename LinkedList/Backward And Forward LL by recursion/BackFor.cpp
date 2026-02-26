#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void printForward(Node* head) {
    if (head == NULL)
        return;

    cout << head->data << " ";
    printForward(head->next);
}

void printBackward(Node* head) {
    if (head == NULL)
        return;

    printBackward(head->next);
    cout << head->data << " ";
}

int main() {
    Node* head = NULL;

    
    Node* n1 = new Node();
    Node* n2 = new Node();
    Node* n3 = new Node();

    n1->data = 10;
    n2->data = 20;
    n3->data = 30;

    n1->next = n2;
    n2->next = n3;
    n3->next = NULL;

    head = n1;

    cout << "Forward Data: "<<endl;
    printForward(head);

    cout << "Backward: "<<endl;;
    printBackward(head);

    return 0;
}
