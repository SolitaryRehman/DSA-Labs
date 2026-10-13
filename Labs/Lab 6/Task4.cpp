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
    cout << "===== Task 4: Inserting into a Queue =====" << endl << endl;

    cout << "--- Display on an empty queue ---" << endl;
    display();

    cout << endl << "--- Insert 10, 20, 30 ---" << endl;
    enqueue(10);
    enqueue(20);
    enqueue(30);

    display();

    cout << endl << "--- Fill the queue, then attempt one more insertion ---" << endl;
    enqueue(40);
    enqueue(50);
    
    display();
    enqueue(60);

    return 0;
}
