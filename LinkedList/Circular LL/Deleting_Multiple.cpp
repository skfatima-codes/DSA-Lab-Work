#include <iostream>
using namespace std;

struct Node { int data; Node* next; };

void traverse(Node* head) {
    if (!head) { cout << "List empty\n"; return; }
    Node* temp = head;
    do { cout << temp->data << " -> "; temp = temp->next; 
    } while (temp != head);
    cout << "(back to head)\n";
}
void deleteHead(Node*&head,int key){
    if(!head){
        cout<<"Empty"<<endl;
        return;

    }
    if(head->data!=key){
        cout<<"Key not found in head node\n";
        return;
    }
    if(head->next==head){
        delete head;
        head=nullptr;
        return;
    }
    //for multi
    //now we find last node
    Node*last=head;
    while(last->next!=head){
        last=last->next;
        Node*temp=head;
        head=head->next;
         last->next = head;
    delete temp;
    }
}
int main(){

    Node*head=new Node{110,nullptr};
    Node*n2=new Node{120,nullptr};
    Node*n3=new Node{130,nullptr};
    head->next = n2; n2->next = n3; n3->next = head;

    cout << "Original list:\n";
    traverse(head);

    cout << "\nDeleting head (110)...\n";
    deleteHead(head,110);
    traverse(head);

    return 0;
}
