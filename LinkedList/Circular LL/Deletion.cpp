#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
};

// Insert at end function
void insertEnd(Node*& head, int value) {
    Node* newNode = new Node;
    newNode->data = value;

    // Empty list case
    if (head == NULL) {
        head = newNode;
        newNode->next = head;
        return;
    }

    // Non-empty list
    Node* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->next = head;
    // temp->next=newNode->next;
    // temp=newNode;
}

// Traverse function
void traverse(Node* head) {
    if (head == NULL) {
        cout << "List is empty\n";
        return;
    }

    Node* temp = head;
    do {
        cout << temp->data << " -> ";
        temp = temp->next;
    } while (temp != head);

    cout << "(back to head)\n";
}

// Delete by value function
void deleteNode(Node*& head, int key) {
    // Step 1: Empty list
    if(head==nullptr){
        cout<<"Empty List"<<endl;
        return;
    }
    Node*current=head;
    Node*previous=nullptr;
    if(head->data==key){
        //single node
        if(head->next==head){
            delete head;
            head=nullptr;
            return;
        }
        //multiple nodes
       
        // Multiple nodes
        while (current->next != head) {
            previous = current;
            current = current->next;
        }

        previous->next = head->next;
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }
        
    }


// Main function
int main() {
    Node* head = NULL;

    // Insert nodes
    insertEnd(head, 10);
    insertEnd(head, 20);
    insertEnd(head, 30);
    insertEnd(head, 40);

    cout << "Original list:\n";
    traverse(head);

    // Delete middle node
    cout << "\nDeleting 30...\n";
    deleteNode(head, 30);
    traverse(head);

    // Delete head
    cout << "\nDeleting head (10)...\n";
    deleteNode(head, 10);
    traverse(head);

    // Delete last node
    cout << "\nDeleting last node (40)...\n";
    deleteNode(head, 40);
    traverse(head);

    // Delete non-existing
    cout << "\nDeleting non-existing (99)...\n";
    deleteNode(head, 99);
    traverse(head);

    // Delete remaining node
    cout << "\nDeleting remaining node (20)...\n";
    deleteNode(head, 20);
    traverse(head);

    return 0;
}
