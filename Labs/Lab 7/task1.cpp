// Task 1: Linear queue using an array (capacity 5)

#include <iostream>
using namespace std;

class ArrayQueue 
{

private:
    static const int CAPACITY = 5;
    int arr[CAPACITY];
    int front;
    int rear;

public:
    ArrayQueue() : front(-1), rear(-1) 
    {

    }

    bool IsEmpty() const 
    { 
        return front == -1; 
    }

    // Linear queue: full when rear reaches the last index
    bool IsFull() const 
    { 
        return rear == CAPACITY - 1;
    }

    void Enqueue(int value) 
    {
        if (IsFull())
        {
            cout << "Queue is full. Cannot enqueue " << value << ".\n";
            return;
        }
        if (IsEmpty()) 
        {
            front = 0;
        }

        rear++;
        arr[rear] = value;

        cout << "Enqueued: " << value << "\n";
    }

    void Dequeue() 
    {
        if (IsEmpty()) 
        {
            cout << "Queue is empty. Cannot dequeue.\n";
            return;
        }
        cout << "Dequeued: " << arr[front] << "\n";

        if (front == rear) 
        {
            front = -1;   // last value removed: reset indices
            rear = -1;
        } 
        else 
        {
            front++;
        }
    }

    void Peek() const 
    {
        if (IsEmpty()) 
        {
            cout << "Queue is empty. Nothing to peek.\n";
            return;
        }
        cout << "Front value: " << arr[front] << "\n";
    }

    void Display() const 
    {
        if (IsEmpty()) 
        {
            cout << "Queue is empty.\n";
            return;
        }
        cout << "Queue (front to rear): ";

        for (int i = front; i <= rear; i++)
        {
            cout << arr[i] << " ";
        }
            cout << "\n";
    }
};

int main() 
{
    ArrayQueue q;

    cout << "--- Enqueue 10, 20, 30, 40, 50 ---\n";
    q.Enqueue(10);
    q.Enqueue(20);
    q.Enqueue(30);
    q.Enqueue(40);
    q.Enqueue(50);
    q.Display();

    cout << "\n--- Dequeue twice ---\n";
    q.Dequeue();
    q.Dequeue();

    cout << "\n--- Attempt to enqueue 60 (rear == 4, so full) ---\n";
    q.Enqueue(60);

    cout << "\n--- Display and Peek ---\n";
    q.Display();
    q.Peek();

    cout << "\n--- Empty the queue ---\n";
    q.Dequeue();
    q.Dequeue();
    q.Dequeue();
    q.Display();

    cout << "\n--- Dequeue from empty queue ---\n";
    q.Dequeue();
    q.Peek();

    cout << "\n--- Enqueue 70 (indices were reset, so reuse works) ---\n";
    q.Enqueue(70);
    q.Display();
    q.Peek();

    return 0;
}
