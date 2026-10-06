#include <iostream>
using namespace std;

class ArrayStack 
{
    int items[5];
    int top;

public:

    ArrayStack() 
    {
        top = -1;               // -1 means the stack is empty
    }

    bool IsEmpty() const 
    {
        return top == -1;
    }

    bool IsFull() const 
    {
        return top == 4;        // last valid index of an array of 5
    }

    void Push(int value) 
    {
        if (IsFull()) 
        {
            cout << "Overflow: stack is full, cannot push " << value << ".\n";
            return;
        }

        top++;
        items[top] = value;
        cout << "Pushed " << value << "\n";
    }

    void Pop() 
    {
        if (IsEmpty()) 
        {
            cout << "Underflow: stack is empty, nothing to pop.\n";
            return;
        }

        cout << "Popped " << items[top] << "\n";
        top--;
    }

    void Peek() const 
    {
        if (IsEmpty()) 
        {
            cout << "Underflow: stack is empty, nothing to peek.\n";
            return;
        }

        cout << "Top is " << items[top] << "\n";
    }

    // Show from top to bottom
    void Display() const 
    {
        if (IsEmpty()) 
        {
            cout << "Stack is empty.\n";
            return;
        }

        cout << "Stack (top to bottom): ";
        for (int i = top; i >= 0; i--) 
        {
            cout << items[i];
            if (i > 0) cout << ", ";
        }
        cout << "\n";
    }
};

int main() 
{
    ArrayStack s;

    s.Push(10);
    s.Push(20);
    s.Push(30);
    s.Push(40);
    s.Push(50);
    s.Display();

    s.Push(60);                 // sixth push is rejected

    s.Pop();                    // removes 50
    s.Peek();                   // shows 40
    s.Display();

    cout << "\n--- Empty the stack ---\n";
    while (!s.IsEmpty()) 
    {
        s.Pop();
    }

    s.Pop();                    // one extra pop: underflow
    s.Peek();
    s.Display();

    return 0;
}