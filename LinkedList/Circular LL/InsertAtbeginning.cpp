#include <iostream>
using namespace std;
struct Node{
    int data;
    Node*next;
};
void insertAtBeginning(Node*& head, int value) {
    Node* newNode = new Node(); // Step 1: allocate memory
    newNode->data = value;

    if (head == nullptr) { // Step 2: empty list
        newNode->next = newNode; // points to itself
        head = newNode;
        return;
    }

    // Step 3: non-empty list
    Node* temp = head;
    // Find the last node
    while (temp->next != head) {
        temp = temp->next;
    }
    
    newNode->next = head; // Step 4: new node points to current head
    temp->next = newNode; // Step 5: last node points to new node
    head = newNode;       // Step 6: update head
}

int main(){

}