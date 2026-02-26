#include <iostream>
#include <cstdlib>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int value){
    Node* n1 = new Node;

    n1->data = value;
    n1->left = NULL;
    n1->right = NULL;

    return n1;
}

Node* insert(Node* root, int value){
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

Node* search(Node* root, int value){
    if(root == NULL){
        return NULL;
    }
    if(root->data == value){
        return root;
    }
    if(value < root->data){
        return search(root->left, value);
    }else if(value > root->data){
        return search(root->right, value);
    }
    return NULL;
}

Node* deleteNode(Node* root, int value){
    if(root == NULL){
        return NULL;
    }
    if(value < root->data){
        root->left = deleteNode(root->left, value);
    }else if(value > root->data){
        root->right = deleteNode(root->right, value);
    }
    else{
        //  leaf node
        if(root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
        }
        // right child
        else if(root->left == NULL){
            Node* temp = root;
            root = root->right;
            delete temp;
            return root;
        }
        // node ky pass left child
        else if(root->right == NULL){
            Node* temp = root;
            root = root->left;
            delete temp;
            return root;
        }
        //: Node has two children
        else{
            Node* minRight = root->right;
            while(minRight->left != NULL){
                minRight = minRight->left;
            }
            root->data = minRight->data;
            root->right = deleteNode(root->right, minRight->data);
            return root;
        }
    }
    return root;
}

void inorder(Node* root){
    if(root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main(){
    Node* root = NULL;
    
   
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);
    
   
    inorder(root);
  
    
    cout << "\nDeleting node 20 (leaf node)" << endl;
    root = deleteNode(root, 20);
    cout << "\nDeleting node 30 (node with one child)" << endl;
    root = deleteNode(root, 30);
    cout << "\nDeleting node 50 (node with two children)" << endl;
    root = deleteNode(root, 50);
    return 0;
}