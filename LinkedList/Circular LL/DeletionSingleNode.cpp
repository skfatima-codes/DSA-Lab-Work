#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void traverse(Node* head) {
    if (!head) { cout << "List is empty\n"; return; }
    Node* temp = head;
    do {
        cout << temp->data << " -> ";
        temp = temp->next;
    } while (temp != head);
    cout << "(back to head)\n";
}

void deleteNode(Node*& head, int key) {
    if (!head) { cout << "List empty\n"; return; }

    if (head->data == key && head->next == head) { // single node
        delete head;
        head = NULL;
        return;
    }
}

int main() {
    Node* head = new Node{10, nullptr};
    head->next = head; // single node circular

    cout << "Original list:\n";
    traverse(head);

    cout << "\nDeleting 10 (single node)...\n";
    deleteNode(head, 10);
    traverse(head);

    return 0;
}
