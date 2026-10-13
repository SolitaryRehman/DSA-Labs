#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

Node* top = nullptr;

void push(int value)
{
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = top;
    top = newNode;
    cout << "Pushed " << value << " onto the stack." << endl;
}

void pop()
{
    if (top == nullptr)
    {
        cout << "Stack Underflow: cannot pop, stack is empty." << endl;
        return;
    }

    Node* temp = top;
    cout << "Popped " << temp->data << " from the stack." << endl;
    top = top->next;
    delete temp;
}

void peek()
{
    if (top == nullptr)
    {
        cout << "Stack is empty: nothing to peek." << endl;
        return;
    }

    cout << "Top element is " << top->data << "." << endl;
}

void display()
{
    if (top == nullptr)
    {
        cout << "Stack is empty." << endl;
        return;
    }

    cout << "Stack (top to bottom): ";
    Node* current = top;

    while (current != nullptr)
    {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

void releaseAll()
{
    while (top != nullptr)
    {
        Node* temp = top;
        top = top->next;
        delete temp;
    }
}

int main()
{
    cout << "===== Task 2: Linked List Stack =====" << endl << endl;

    push(5);
    push(15);
    push(25);

    display();

    pop();
    peek();

    display();

    cout << endl << "--- Remove remaining nodes, then test an empty pop ---" << endl;
    pop();
    pop();
    pop();

    peek();

    cout << endl << "--- Release any remaining nodes before exit ---" << endl;
    push(100);
    push(200);
    
    display();
    releaseAll();
    display();

    return 0;
}
