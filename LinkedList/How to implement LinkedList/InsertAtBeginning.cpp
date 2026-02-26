#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void insertAtBeginning(Node* &head, int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = head;  // new node ka next = old head
    head = newNode;        // head ab new node ko point kare
}

void printList(Node* head) {
    int count=0;
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
        count++;
    }
    cout << "NULL\n";
    cout << "No of nodes: " << count << endl;
}

int main() {
    Node* head = NULL;        // empty list

    insertAtBeginning(head, 10);  // first node
    insertAtBeginning(head, 5);   // second node at beginning
    insertAtBeginning(head, 1);   // third node at beginning

    printList(head);   // check final list

    return 0;
}
