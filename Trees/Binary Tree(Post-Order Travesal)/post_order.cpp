#include <iostream>
using namespace std;
struct Node{
    int data;
    Node*left=NULL;
    Node*right=NULL;
};
Node*createNode(int value){
    Node*newNode=new Node;
    newNode->data=value;
    
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;

}
Node*insert(Node*root,int value){
    if(root==NULL){
        return createNode(value);

    }
    if(value<root->data){
        root->left= insert(root->left,value);
    }
    else{
       root->right= insert(root->right,value);
    }
    return root;


}
void postOrder(Node*root){
    if(root==NULL){
        return ;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}
int main(){
    Node*root=NULL;
    root=insert(root,12);
    root=insert(root,42);
    root=insert(root,2);
    root=insert(root,1);
    root=insert(root,4);
    root=insert(root,32);
    root=insert(root,72);
    postOrder(root);

}