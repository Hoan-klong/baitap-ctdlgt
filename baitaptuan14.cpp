#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    int height;

    Node(int x) {
        data = x;
        left = right = NULL;
        height = 1;
    }
};

int getHeight(Node* root) {
    if (root == NULL) return 0;
    return root->height;
}

int getBalance(Node* root) {
    if (root == NULL) return 0;
    return getHeight(root->left) - getHeight(root->right);
}

Node* rotateRight(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    return x;
}

Node* rotateLeft(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    return y;
}

Node* insertAVL(Node* root, int x) {
    if (root == NULL)
        return new Node(x);

    if (x < root->data)
        root->left = insertAVL(root->left, x);
    else if (x > root->data)
        root->right = insertAVL(root->right, x);
    else
        return root;

    root->height = 1 + max(getHeight(root->left), getHeight(root->right));

    int balance = getBalance(root);

    // Left Left
    if (balance > 1 && x < root->left->data)
        return rotateRight(root);

    // Right Right
    if (balance < -1 && x > root->right->data)
        return rotateLeft(root);

    
    if (balance > 1 && x > root->left->data) {
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }

 
    if (balance < -1 && x < root->right->data) {
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }

    return root;
}

void inorder(Node* root) {
    if (root == NULL) return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preorder(Node* root) {
    if (root == NULL) return;

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root) {
    if (root == NULL) return;

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main() {
    int a[] = {32, 51, 27, 83, 96, 11, 45, 75, 66};
    int n = sizeof(a) / sizeof(a[0]);

    Node* root = NULL;

    for (int i = 0; i < n; i++) {
        root = insertAVL(root, a[i]);
    }

    cout << " giua LNR tang dan: ";
    inorder(root);

    cout << "\n truoc NLR: ";
    preorder(root);

    cout << "\n sau LRN: ";
    postorder(root);

    cout << endl;

    return 0;
}