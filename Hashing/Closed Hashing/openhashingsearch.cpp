#include <iostream>
using namespace std;
struct Node{
    int data;
    Node*next;
};
Node HT[10];
// void insert(int value){
void search(int value){
    int index=value%10;
    Node*current=HT[index].next;
    while(current!=NULL){
        if(current->data==value){
            cout<<"Found"<<endl;
            return;
        }
        current=current->next;
    }
    cout<<"Not Found"<<endl;
}
void insert(int value){
    int index=value%10;
    if(HT[index].data==-1){
    }

    // else{
    else{
        Node*temp=new Node;
        temp->data=value;
        temp->next=NULL;
        Node*current=HT[index].next;
        if(current==NULL){
            HT[index].next=temp;
        }
        else{
            while(current->next!=NULL){
                current=current->next;
            }
            current->next=temp;
        }
    }
}

int main(){
for(int i=0;i<10;i++){
    HT[i].data=-1;
    HT[i].next=NULL;
}


    insert(10);
    insert(15);
    insert(18);
    search(23);
    return 0;

}


