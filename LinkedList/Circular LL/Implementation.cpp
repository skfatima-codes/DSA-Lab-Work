#include <iostream>
using namespace std;
struct Node{
    int data ;
    Node*next;
};
int main(){
    Node*first=new Node();
    Node*second=new Node();
    Node*third=new Node();
    first->data=10;
    second->data=20;
    third->data=30;
    //now we make it circular
    first->next=second;
    second->next=third;
    third->next=first;
    //traversing
    Node*temp=first;
    for(int i=0;i<6;i++){
        cout<<temp->data<<"-->";
        temp=temp->next;
    }
    cout<<endl;

    return 0;
}