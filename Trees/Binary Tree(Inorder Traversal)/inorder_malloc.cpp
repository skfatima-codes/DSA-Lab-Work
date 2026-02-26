#include <iostream>
#include <cstdlib>
using namespace std;

struct Node{
    int data;
    Node*left;
    Node*right;
};

Node*createNode(int value){
    Node*n1 = (Node*)malloc(sizeof(Node));
    n1->data = value;
    n1->left = NULL;
    n1->right = NULL;
    return n1;
}

Node*insert(Node*root, int value){
    if(root == NULL){
        return createNode(value);
    }
    if(value < root->data){
        root->left = insert(root->left, value);
    }else{
        root->right = insert(root->right, value);
    }
    return root;
}

void inorder(Node*root){
    if(root == NULL){
        return;
    }
    
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main(){
    Node*root = NULL;
    root = insert(root, 10);
    root = insert(root, 21);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 60);
    inorder(root);
    
    return 0;
}
