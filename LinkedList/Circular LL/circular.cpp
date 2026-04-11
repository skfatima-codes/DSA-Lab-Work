#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;
void traverse() {
    if (head == NULL) {
        cout << "List is empty\n";
        return;
    }

    Node* temp = head;

    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);

    cout << endl;
}
void insert(Node*&head,int value){
    Node*n1=new Node();
    n1->data=value;
    if(head==NULL){
        head=n1;
        n1->next=head;
        return;
    }
    Node*temp=head;
    while(temp->next!=head){
        temp=temp->next;

    }
    temp->next=n1;
    n1->next=head; //last node pointing towards first node
}
void search(Node*&head,int key,int pos){
    if(head==nullptr){
        return ;

    }
    Node*temp=head;
    int count=1;
    do{
        if(temp->data==key){
            cout<<"Element found at position"<<count<<" ";
            return;
        }
        temp=temp->next;
        count++;

    }while(temp!=head);
    cout<<"Not found ! OOPS"<<endl;
}
int main(){
    insert(head,10);
    insert(head,20);
    insert(head,30);
    insert(head,40);
    traverse();
    cout<<"\n";
    search(head,20,2);
    traverse();
}