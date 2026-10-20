// Task 3: Circular queue using an array (capacity 5)

#include <iostream>
using namespace std;

class CircularQueue
{

private:
    static const int CAPACITY = 5;
    int arr[CAPACITY];
    int front;
    int rear;

public:
    CircularQueue() : front(-1), rear(-1)
    {

    }

    bool IsEmpty() const
    {
        return front == -1;
    }

    // Circular full condition
    bool IsFull() const
    {
        return (rear + 1) % CAPACITY == front;
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
            rear = 0;
        }
        else
        {
            rear = (rear + 1) % CAPACITY;   // wrap around
        }

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
            front = -1;   // last value removed: reset both
            rear = -1;
        }
        else
        {
            front = (front + 1) % CAPACITY;
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

    // Each stored value is printed exactly once, even when rear < front
    void Display() const
    {
        if (IsEmpty())
        {
            cout << "Queue is empty.\n";
            return;
        }
        cout << "Queue (front to rear): ";

        int i = front;

        while (true)
        {
            cout << arr[i] << " ";

            if (i == rear)
            {
                break;
            }

            i = (i + 1) % CAPACITY;
        }

        cout << "\n";
    }

    void ShowIndices() const
    {
        cout << "front = " << front << ", rear = " << rear << "\n";
    }
};

int main()
{
    CircularQueue q;

    cout << "--- Enqueue 10, 20, 30, 40, 50 ---\n";
    q.Enqueue(10);
    q.Enqueue(20);
    q.Enqueue(30);
    q.Enqueue(40);
    q.Enqueue(50);
    q.Display();
    q.ShowIndices();

    cout << "\n--- Dequeue twice ---\n";
    q.Dequeue();
    q.Dequeue();

    cout << "\n--- Enqueue 60 and 70 (rear wraps around) ---\n";
    q.Enqueue(60);
    q.Enqueue(70);
    q.Display();
    q.ShowIndices();

    cout << "\n--- Attempt another insertion (queue is full) ---\n";
    q.Enqueue(80);
    q.Display();

    cout << "\n--- Empty the queue ---\n";

    for (int i = 0; i < 5; i++)
    {
        q.Dequeue();
    }

    q.Display();
    q.ShowIndices();

    cout << "\n--- One further dequeue on empty queue ---\n";
    q.Dequeue();

    cout << "\n--- Insert into the empty queue again ---\n";
    q.Enqueue(90);
    q.Display();
    q.ShowIndices();
    q.Peek();

    return 0;
}
