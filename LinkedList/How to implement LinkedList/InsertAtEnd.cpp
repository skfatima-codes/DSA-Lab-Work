#include <iostream>
using namespace std;

struct Node {
    int data;      
    Node* next;     // next node ka address
};

//  Insert at END function
void insertAtEnd(Node* &head, int value) {

    //  naya node banao
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = NULL;


    if (head == NULL) {
        head = newNode;
        return;
    }

    //warna last tak jao
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    // last node ko new node se jor do
    temp->next = newNode;
}

//  Print function
void printList(Node* head) {
    Node* temp = head;

    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

// search function
bool search(Node* head, int key) {
    Node* temp = head;

    while (temp != NULL) {
        if (temp->data == key) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}


int main() {

    Node* head = NULL;   // shuru me list khali

    // insert values
    insertAtEnd(head, 10);
    insertAtEnd(head, 20);
    insertAtEnd(head, 30);
    insertAtEnd(head, 40);

    // print list
    cout << "Linked List: ";
    printList(head);

    // search value
    int key;
    cout << "Search value enter karo: ";
    cin >> key;

    if (search(head, key)) {
        cout << "Value mil gayi ✔" << endl;
    } else {
        cout << "Value nahi mili " << endl;
    }

    return 0;
}
