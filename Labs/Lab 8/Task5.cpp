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

// Inserts the value and returns the root of the updated subtree.
Node* insertRecursive(Node* root, int value) {
    // Empty spot found, so the new node goes here.
    if (root == nullptr) {
        return createNode(value);
    }

    if (value < root->data) {
        root->left = insertRecursive(root->left, value);
    } else if (value > root->data) {
        root->right = insertRecursive(root->right, value);
    }
    // If the value is already in the tree, nothing changes.

    return root;
}

Node* searchIterative(Node* root, int key) {
    Node* current = root;
    while (current != nullptr) {
        if (current->data == key) {
            return current;
        }
        if (key < current->data) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
    return nullptr;
}

void inorder(Node* root) {
    if (root == nullptr) {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void freeTree(Node* root) {
    if (root == nullptr) {
        return;
    }
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}

int main() {
    Node* root = nullptr;

    int values[] = {40, 20, 60, 10, 30, 50, 70};
    for (int value : values) {
        root = insertRecursive(root, value);
    }

    cout << "Inorder after the first seven inserts: ";
    inorder(root);
    cout << endl;

    root = insertRecursive(root, 25);
    cout << "Inorder after inserting 25:            ";
    inorder(root);
    cout << endl;

    root = insertRecursive(root, 20);
    cout << "Inorder after inserting 20 again:      ";
    inorder(root);
    cout << endl;

    cout << endl;
    cout << "Search 25: " << (searchIterative(root, 25) != nullptr ? "Found" : "Not found") << endl;

    freeTree(root);
    return 0;
}
