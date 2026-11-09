#include <iostream>
#include <stack>
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

// Root, Left, Right without recursion.
void preorderIterative(Node* root) {
    if (root == nullptr) {
        return;
    }

    stack<Node*> s;
    s.push(root);

    while (!s.empty()) {
        Node* current = s.top();
        s.pop();
        cout << current->data << " ";

        // A stack gives back the last item pushed first. We want the left
        // child to be visited before the right one, so the right goes in first.
        if (current->right != nullptr) {
            s.push(current->right);
        }
        if (current->left != nullptr) {
            s.push(current->left);
        }
    }
}

// Left, Root, Right without recursion.
void inorderIterative(Node* root) {
    stack<Node*> s;
    Node* current = root;

    while (current != nullptr || !s.empty()) {
        // Go as far left as possible, remembering each node on the way down.
        while (current != nullptr) {
            s.push(current);
            current = current->left;
        }

        // The top of the stack is the next node to visit.
        current = s.top();
        s.pop();
        cout << current->data << " ";

        // After a node is visited, its right subtree comes next.
        current = current->right;
    }
}

// Recursive versions from Task 1, kept here only to compare the outputs.
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

    cout << "--- Seven-node tree ---" << endl;

    cout << "Preorder  (iterative): ";
    preorderIterative(root);
    cout << endl;
    cout << "Preorder  (recursive): ";
    preorder(root);
    cout << endl;

    cout << "Inorder   (iterative): ";
    inorderIterative(root);
    cout << endl;
    cout << "Inorder   (recursive): ";
    inorder(root);
    cout << endl;

    cout << endl << "--- Empty tree (nullptr) ---" << endl;
    cout << "Preorder  (iterative): ";
    preorderIterative(nullptr);
    cout << endl;
    cout << "Inorder   (iterative): ";
    inorderIterative(nullptr);
    cout << endl;

    freeTree(root);
    return 0;
}
