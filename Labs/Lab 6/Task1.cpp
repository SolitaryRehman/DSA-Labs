#include <iostream>
using namespace std;

const int SIZE = 5;

int items[SIZE];
int top = -1;

void push(int value)
{
    if (top == SIZE - 1)
    {
        cout << "Stack Overflow: cannot push " << value << ", stack is full." << endl;
        return;
    }

    top++;
    items[top] = value;
    cout << "Pushed " << value << " onto the stack." << endl;
}

void pop()
{
    if (top == -1)
    {
        cout << "Stack Underflow: cannot pop, stack is empty." << endl;
        return;
    }

    cout << "Popped " << items[top] << " from the stack." << endl;
    top--;
}

void peek()
{
    if (top == -1)
    {
        cout << "Stack is empty: nothing to peek." << endl;
        return;
    }

    cout << "Top element is " << items[top] << "." << endl;
}

void display()
{
    if (top == -1)
    {
        cout << "Stack is empty." << endl;
        return;
    }

    cout << "Stack (top to bottom): ";
    for (int i = top; i >= 0; i--)
    {
        cout << items[i] << " ";
    }
    cout << endl;
}

int main()
{
    cout << "===== Task 1: Array Stack =====" << endl << endl;

    push(10);
    push(20);
    push(30);

    display();

    pop();
    peek();

    display();

    cout << endl << "--- Fill the stack, then test a sixth insertion ---" << endl;

    push(40);
    push(50);
    push(60);
    push(70);

    display();

    cout << endl << "--- Remove all values, then pop again ---" << endl;
    
    while (top != -1)
    {
        pop();
    }
    pop();
    peek();

    display();

    return 0;
}
