#include <iostream>
using namespace std;

struct AVLNode {
    int data;
    AVLNode* left;
    AVLNode* right;
    int height;
};

int getHeight(AVLNode* node) {
    if (node == NULL) return -1;
    return node->height;
}

int maximum(int a, int b) {
    if (a > b)
        return a;
    else
        return b;
}

AVLNode* createNode(int value) {
    AVLNode* tmp = new AVLNode();
    tmp->data    = value;
    tmp->left    = NULL;
    tmp->right   = NULL;
    tmp->height  = 0;
    return tmp;
}

AVLNode* rotateLeft(AVLNode* curr) {
    AVLNode* temp  = curr;
    curr           = curr->right;
    AVLNode* temp2 = curr->left;
    curr->left     = temp;
    temp->right    = temp2;

    temp->height = maximum(getHeight(temp->left), getHeight(temp->right)) + 1;
    curr->height = maximum(getHeight(curr->left), getHeight(curr->right)) + 1;

    return curr;
}

AVLNode* rotateRight(AVLNode* curr) {
    AVLNode* temp  = curr;
    curr           = curr->left;
    AVLNode* temp2 = curr->right;
    curr->right    = temp;
    temp->left     = temp2;

    temp->height = maximum(getHeight(temp->left), getHeight(temp->right)) + 1;
    curr->height = maximum(getHeight(curr->left), getHeight(curr->right)) + 1;

    return curr;
}

AVLNode* rotateLeftRight(AVLNode* node) {
    node->left = rotateLeft(node->left);
    return rotateRight(node);
}

AVLNode* rotateRightLeft(AVLNode* node) {
    node->right = rotateRight(node->right);
    return rotateLeft(node);
}

AVLNode* insertAVL(AVLNode* node, int value) {
    if (node == NULL)
        return createNode(value);

    if (value < node->data)
        node->left  = insertAVL(node->left,  value);
    else
        node->right = insertAVL(node->right, value);

    node->height = maximum(getHeight(node->left), getHeight(node->right)) + 1;

    int bf = getHeight(node->left) - getHeight(node->right);

    if (bf == 2) {
        if (value < node->left->data)
            node = rotateRight(node);
        else
            node = rotateLeftRight(node);
    }

    if (bf == -2) {
        if (value > node->right->data)
            node = rotateLeft(node);
        else
            node = rotateRightLeft(node);
    }

    return node;
}

void inorder(AVLNode* node) {
    if (node == NULL) return;
    inorder(node->left);
    cout << node->data << " ";
    inorder(node->right);
}

int main() {
    AVLNode* root = NULL;

    root = insertAVL(root, 88);
    root = insertAVL(root, 52);
    root = insertAVL(root, 96);
    root = insertAVL(root, 92);
    root = insertAVL(root, 102);
    root = insertAVL(root, 110);

    cout << "Inorder (sorted hona chahiye): ";
    inorder(root);
    cout << endl;

    cout << "Root: " << root->data << endl;

    return 0;
}
