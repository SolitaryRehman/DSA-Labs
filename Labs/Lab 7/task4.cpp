// Task 4: Rotating service turns using a circular queue

#include <iostream>
using namespace std;

class CircularQueue
{

private:
    static const int CAPACITY = 5;
    int arr[CAPACITY];
    int front;
    int rear;

    // Silent helpers: do the real work and report success or failure
    bool Insert(int value)
    {
        if (IsFull())
        {
            return false;
        }
        if (IsEmpty())
        {
            front = 0;
            rear = 0;
        }
        else
        {
            rear = (rear + 1) % CAPACITY;
        }

        arr[rear] = value;
        return true;
    }

    bool Remove(int& value)
    {
        if (IsEmpty())
        {
            return false;
        }

        value = arr[front];

        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front = (front + 1) % CAPACITY;
        }

        return true;
    }

public:
    CircularQueue() : front(-1), rear(-1)
    {

    }

    bool IsEmpty() const
    {
        return front == -1;
    }

    bool IsFull() const
    {
        return (rear + 1) % CAPACITY == front;
    }

    int Size() const
    {
        if (IsEmpty())
        {
            return 0;
        }
        return (rear - front + CAPACITY) % CAPACITY + 1;
    }

    void Enqueue(int value)
    {
        if (!Insert(value))
        {
            cout << "Queue is full. Cannot enqueue " << value << ".\n";
            return;
        }
        cout << "Enqueued: " << value << "\n";
    }

    void Dequeue()
    {
        int v;

        if (!Remove(v))
        {
            cout << "Queue is empty. Cannot dequeue.\n";
            return;
        }
        cout << "Dequeued: " << v << "\n";
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

    // Serve the front student, then send them to the back of the line
    void RotateTurn()
    {
        if (IsEmpty())
        {
            cout << "No students waiting. Nothing to rotate.\n";
            return;
        }

        int served;

        Remove(served);   // save and remove the front ID
        Insert(served);   // enqueue it at the rear (a slot was just freed)

        cout << "Served ID: " << served << "\n";
        cout << "Updated ";
        Display();
        cout << "Students in queue: " << Size() << "\n";
    }
};

int main()
{
    CircularQueue q;

    cout << "--- Enqueue student IDs 101, 102, 103 ---\n";
    q.Enqueue(101);
    q.Enqueue(102);
    q.Enqueue(103);
    q.Display();
    cout << "Students in queue: " << q.Size() << "\n";

    cout << "\n--- Five turns using a loop ---\n";

    for (int turn = 1; turn <= 5; turn++)
    {
        cout << "\nTurn " << turn << ":\n";
        q.RotateTurn();
    }

    cout << "\n--- Rotate on an empty queue ---\n";
    CircularQueue empty;
    empty.RotateTurn();

    cout << "\n--- Queue with a single student ---\n";
    CircularQueue single;
    single.Enqueue(201);
    single.RotateTurn();
    single.RotateTurn();

    return 0;
}
