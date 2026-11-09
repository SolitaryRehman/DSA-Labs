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

// Inserts the value using a loop and returns the root.
Node* insertIterative(Node* root, int value) {
    // An empty tree means the new node becomes the root.
    if (root == nullptr) {
        return createNode(value);
    }

    Node* parent = nullptr;
    Node* current = root;

    // Walk down the tree while remembering the last node we passed.
    while (current != nullptr) {
        parent = current;
        if (value < current->data) {
            current = current->left;
        } else if (value > current->data) {
            current = current->right;
        } else {
            return root;  // Duplicate, so there is nothing to insert.
        }
    }

    // The parent now has an empty child slot where the value belongs.
    if (value < parent->data) {
        parent->left = createNode(value);
    } else {
        parent->right = createNode(value);
    }

    return root;
}

// Recursive version from Task 5, used here to compare against the iterative one.
Node* insertRecursive(Node* root, int value) {
    if (root == nullptr) {
        return createNode(value);
    }
    if (value < root->data) {
        root->left = insertRecursive(root->left, value);
    } else if (value > root->data) {
        root->right = insertRecursive(root->right, value);
    }
    return root;
}

void inorder(Node* root) {
    if (root == nullptr) {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preorder(Node* root) {
    if (root == nullptr) {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

// Searches for the key and prints how many nodes were compared.
bool searchAndCount(Node* root, int key) {
    int comparisons = 0;
    Node* current = root;

    while (current != nullptr) {
        comparisons++;
        if (current->data == key) {
            cout << "Search " << key << ": Found after comparing " << comparisons << " node(s)" << endl;
            return true;
        }
        if (key < current->data) {
            current = current->left;
        } else {
            current = current->right;
        }
    }

    cout << "Search " << key << ": Not found after comparing " << comparisons << " node(s)" << endl;
    return false;
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
    // Part 1: build the same tree with both insert functions and compare.
    Node* recursiveTree = nullptr;
    Node* iterativeTree = nullptr;

    int values[] = {40, 20, 60, 10, 30, 50, 70, 25, 20};
    for (int value : values) {
        recursiveTree = insertRecursive(recursiveTree, value);
        iterativeTree = insertIterative(iterativeTree, value);
    }

    cout << "--- Recursive insertion ---" << endl;
    cout << "Inorder:  ";
    inorder(recursiveTree);
    cout << endl << "Preorder: ";
    preorder(recursiveTree);
    cout << endl;

    cout << endl << "--- Iterative insertion ---" << endl;
    cout << "Inorder:  ";
    inorder(iterativeTree);
    cout << endl << "Preorder: ";
    preorder(iterativeTree);
    cout << endl;

    // Part 2: a skewed tree, where every value is larger than the last.
    Node* skewed = nullptr;
    int skewedValues[] = {10, 20, 30, 40, 50};
    for (int value : skewedValues) {
        skewed = insertIterative(skewed, value);
    }

    cout << endl << "--- Skewed tree (10, 20, 30, 40, 50) ---" << endl;
    cout << "Inorder:  ";
    inorder(skewed);
    cout << endl;
    searchAndCount(skewed, 50);

    // Every value went to the right, so the tree is really a linked list and
    // its height equals the number of nodes. Searching for 50 compares all 5
    // nodes. In a balanced tree the height is only about log2(n), so each time
    // the number of nodes grows, a balanced search adds just a few comparisons
    // while a skewed search adds one comparison per extra node.

    freeTree(recursiveTree);
    freeTree(iterativeTree);
    freeTree(skewed);
    return 0;
}
