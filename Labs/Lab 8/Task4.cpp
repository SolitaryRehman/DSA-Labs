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

// Returns the node holding the key, or nullptr if it is not in the tree.
Node* searchRecursive(Node* root, int key) {
    if (root == nullptr || root->data == key) {
        return root;
    }
    if (key < root->data) {
        return searchRecursive(root->left, key);
    }
    return searchRecursive(root->right, key);
}

// Same search, written as a loop.
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

// Prints every node that gets compared on the way to the key.
void printSearchPath(Node* root, int key) {
    cout << "Nodes compared for " << key << ": ";
    Node* current = root;
    while (current != nullptr) {
        cout << current->data << " ";
        if (current->data == key) {
            break;
        }
        if (key < current->data) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
    cout << endl;
}

void testSearch(Node* root, int key) {
    Node* r = searchRecursive(root, key);
    Node* i = searchIterative(root, key);

    cout << "Search " << key << " -> recursive: " << (r != nullptr ? "Found" : "Not found")
         << ", iterative: " << (i != nullptr ? "Found" : "Not found") << endl;
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
    // The same tree used in Task 1.
    Node* root = createNode(40);
    root->left = createNode(20);
    root->right = createNode(60);
    root->left->left = createNode(10);
    root->left->right = createNode(30);
    root->right->left = createNode(50);
    root->right->right = createNode(70);

    testSearch(root, 40);
    testSearch(root, 10);
    testSearch(root, 70);
    testSearch(root, 25);

    cout << endl;
    printSearchPath(root, 25);
    // 25 is compared with 40 (go left), 20 (go right) and 30 (go left).
    // The left child of 30 is empty, so the search ends and 25 is not found.

    cout << endl << "--- Empty tree ---" << endl;
    testSearch(nullptr, 40);

    freeTree(root);
    return 0;
}
