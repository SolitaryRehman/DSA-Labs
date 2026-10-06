#include <iostream>
using namespace std;

struct Node 
{
    int data;
    Node* next;

    Node(int v) 
    {
        data = v;
        next = nullptr;
    }
};

class LinkedStack 
{
    Node* top;

public:

    LinkedStack() 
    {
        top = nullptr;
    }

    ~LinkedStack() 
    {
        ClearStack();
    }

    bool IsEmpty() const 
    {
        return top == nullptr;
    }

    // New node goes in front of the old top
    void Push(int value) 
    {
        Node* n = new Node(value);
        n->next = top;
        top = n;
        cout << "Pushed " << value << "\n";
    }

    // Remove the front node
    void Pop() 
    {
        if (IsEmpty()) 
        {
            cout << "Underflow: stack is empty, nothing to pop.\n";
            return;
        }

        Node* t = top;
        cout << "Popped " << t->data << "\n";
        top = top->next;
        delete t;
    }

    void Peek() const 
    {
        if (IsEmpty()) 
        {
            cout << "Underflow: stack is empty, nothing to peek.\n";
            return;
        }

        cout << "Top is " << top->data << "\n";
    }

    void Display() const 
    {
        if (IsEmpty()) 
        {
            cout << "Stack is empty.\n";
            return;
        }

        cout << "Stack (top to bottom): ";
        for (Node* c = top; c != nullptr; c = c->next) 
        {
            cout << c->data;
            if (c->next) cout << ", ";
        }
        cout << "\n";
    }

    void ClearStack() 
    {
        while (top != nullptr) 
        {
            Node* t = top;
            top = top->next;
            delete t;
        }
    }
};

int main() 
{
    LinkedStack stack;
    int choice = 0;

    do 
    {
        cout << "\n1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\n";
        cout << "Choice: ";

        if (!(cin >> choice)) 
        {
            if (cin.eof()) 
            {
                break;          // input ended
            }

            // user typed letters instead of a number
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid choice. Enter a number from 1 to 5.\n";
            choice = 0;
            continue;
        }

        if (choice == 1) 
        {
            int v;
            cout << "Value to push: ";

            if (cin >> v) 
            {
                stack.Push(v);
            } 
            else 
            {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Invalid value. Nothing pushed.\n";
            }
        }
        else if (choice == 2) 
        {
            stack.Pop();
        }
        else if (choice == 3) 
        {
            stack.Peek();
        }
        else if (choice == 4) 
        {
            stack.Display();
        }
        else if (choice == 5) 
        {
            cout << "Exiting. Releasing remaining nodes.\n";
        }
        else 
        {
            cout << "Invalid choice. Enter a number from 1 to 5.\n";
        }
    } 
    while (choice != 5);

    stack.ClearStack();         // free anything still left before leaving

    return 0;
}