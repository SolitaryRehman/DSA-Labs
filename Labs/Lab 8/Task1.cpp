#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int value) {
    Node* node = new Node;
    node->data = value;
    node->left = nullptr;
    node->right = nullptr;
    return node;
}

// Left, Root, Right
void inorder(Node* root) {
    if (root == nullptr) {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Root, Left, Right
void preorder(Node* root) {
    if (root == nullptr) {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

// Left, Right, Root
void postorder(Node* root) {
    if (root == nullptr) {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

// Frees every node so the program leaves no memory behind.
void freeTree(Node* root) {
    if (root == nullptr) {
        return;
    }
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}

void printAll(Node* root) {
    cout << "Inorder:    ";
    inorder(root);
    cout << endl;

    cout << "Preorder:   ";
    preorder(root);
    cout << endl;

    cout << "Postorder:  ";
    postorder(root);
    cout << endl;
}

int main() {
    // Build the seven-node tree by linking the nodes directly.
    Node* root = createNode(40);
    root->left = createNode(20);
    root->right = createNode(60);
    root->left->left = createNode(10);
    root->left->right = createNode(30);
    root->right->left = createNode(50);
    root->right->right = createNode(70);

    cout << "--- Seven-node tree ---" << endl;
    printAll(root);

    cout << endl << "--- Empty tree (nullptr) ---" << endl;
    printAll(nullptr);

    cout << endl << "--- Single-node tree ---" << endl;
    Node* single = createNode(99);
    printAll(single);

    freeTree(root);
    freeTree(single);
    return 0;
}
