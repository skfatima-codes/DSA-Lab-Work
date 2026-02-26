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
void preorder(Node*root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
int main(){
    Node*root=NULL;
    root=insert(root,10);
    root=insert(root,30);
    root=insert(root,13);
    root=insert(root,6);
    root=insert(root,60);
    preorder(root);

}