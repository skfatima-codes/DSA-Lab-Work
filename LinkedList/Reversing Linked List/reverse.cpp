#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// Insert at end
void insert(Node*& head, int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
}

// Print list
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

// Reverse function
void reverseList(Node*& head) {
    Node* prev = NULL;
    Node* current = head;
    Node* next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    head = prev;
}

int main() {
    Node* head = NULL;

    insert(head, 10);
    insert(head, 20);
    insert(head, 30);

    cout << "Original List:\n";
    printList(head);

    reverseList(head);

    cout << "Reversed List:\n";
    printList(head);

    return 0;
}
