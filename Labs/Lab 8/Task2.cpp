#include <iostream>
#include <queue>
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

// Visits the tree one level at a time, from left to right.
void levelOrder(Node* root) {
    if (root == nullptr) {
        return;
    }

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* current = q.front();
        q.pop();
        cout << current->data << " ";

        // Children go in left first, so they come out in the same order.
        if (current->left != nullptr) {
            q.push(current->left);
        }
        if (current->right != nullptr) {
            q.push(current->right);
        }
    }
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
    Node* root = createNode(40);
    root->left = createNode(20);
    root->right = createNode(60);
    root->left->left = createNode(10);
    root->left->right = createNode(30);
    root->right->left = createNode(50);
    root->right->right = createNode(70);

    cout << "Level-order (seven-node tree): ";
    levelOrder(root);
    cout << endl;
    cout << "Expected:                      40 20 60 10 30 50 70" << endl;

    cout << endl << "Level-order (empty tree):      ";
    levelOrder(nullptr);
    cout << endl;

    Node* single = createNode(99);
    cout << endl << "Level-order (single node):     ";
    levelOrder(single);
    cout << endl;

    freeTree(root);
    freeTree(single);
    return 0;
}
