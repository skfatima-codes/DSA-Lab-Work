#include <iostream>
using namespace std;


struct Node {
    int data;
    Node* next;
};

//  Insert at End
void insertAtEnd(Node* &head, int value) {

    Node* newNode = new Node;   // heap me naya box
    newNode->data = value;
    newNode->next = NULL;

    
    if (head == NULL) {
        head = newNode;
        return;
    }

    // warna last tak jao
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode; // last ko new se jor do
}

//  Print list
void printList(Node* head) {

    if (head == NULL) {
        cout << "List khali hai\n";
        return;
    }

    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

//  Search function
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

//  MAIN (MENU)
int main() {

    Node* head = NULL;
    int choice, value;

    do {
        cout << "\n===== LINKED LIST MENU =====\n";
        cout << "1. Insert at End\n";
        cout << "2. Print List\n";
        cout << "3. Search Value\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {

            case 1:
                cout << "Enter value: ";
                cin >> value;
                insertAtEnd(head, value);
                cout << "Value insert ho gayi\n";
                break;

            case 2:
                printList(head);
                break;

            case 3:
                cout << "Search value enter karo: ";
                cin >> value;
                if (search(head, value))
                    cout << "Value mil gayi ✔\n";
                else
                    cout << "Value nahi mili \n";
                break;

            case 4:
                cout << "Program exit ho raha hai\n";
                break;

            default:
                cout << "Galat choice!\n";
        }

    } while (choice != 4);

    return 0;
}
