#include <iostream>
using namespace std;

const int SIZE = 5;

int items[SIZE];
int front = -1;
int rear = -1;

void enqueue(int value)
{
    if (rear == SIZE - 1)
    {
        cout << "Queue is full: cannot insert " << value << "." << endl;
        return;
    }

    if (front == -1)
    {
        front = 0;
    }

    rear++;
    items[rear] = value;
    cout << "Inserted " << value << " into the queue." << endl;
}

void dequeue()
{
    if (front == -1)
    {
        cout << "Queue is empty: cannot remove." << endl;
        return;
    }

    cout << "Removed " << items[front] << " from the queue." << endl;

    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        front++;
    }
}

void peekFront()
{
    if (front == -1)
    {
        cout << "Queue is empty: nothing to peek." << endl;
        return;
    }

    cout << "Front element is " << items[front] << "." << endl;
}

void display()
{
    if (front == -1)
    {
        cout << "Queue is empty." << endl;
        return;
    }

    cout << "Queue (front to rear): ";
    for (int i = front; i <= rear; i++)
    {
        cout << items[i] << " ";
    }
    cout << endl;
}

int main()
{
    cout << "===== Task 5: Removing from a Queue =====" << endl << endl;

    cout << "--- Insert 10, 20, 30 ---" << endl;
    enqueue(10);
    enqueue(20);
    enqueue(30);

    cout << endl << "--- Remove once, then peek and display ---" << endl;
    dequeue();
    peekFront();
    display();

    cout << endl << "--- Remove all remaining items, then try another removal ---" << endl;
    dequeue();
    dequeue();
    dequeue();

    cout << endl << "--- Insert 40 to check the queue works after reset ---" << endl;
    enqueue(40);
    peekFront();
    display();

    return 0;
}
