// Task 5: Deque using a circular array (capacity 5)

#include <iostream>
using namespace std;

class ArrayDeque
{

private:
    static const int CAPACITY = 5;
    int arr[CAPACITY];
    int front;
    int rear;

public:
    ArrayDeque() : front(-1), rear(-1)
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

    void InsertFront(int value)
    {
        if (IsFull())
        {
            cout << "Deque is full. Cannot insert " << value << " at front.\n";
            return;
        }
        if (IsEmpty())
        {
            front = 0;
            rear = 0;
        }
        else
        {
            front = (front + CAPACITY - 1) % CAPACITY;   // move backward
        }

        arr[front] = value;

        cout << "Inserted " << value << " at front\n";
    }

    void InsertRear(int value)
    {
        if (IsFull())
        {
            cout << "Deque is full. Cannot insert " << value << " at rear.\n";
            return;
        }
        if (IsEmpty())
        {
            front = 0;
            rear = 0;
        }
        else
        {
            rear = (rear + 1) % CAPACITY;   // move forward
        }

        arr[rear] = value;

        cout << "Inserted " << value << " at rear\n";
    }

    void DeleteFront()
    {
        if (IsEmpty())
        {
            cout << "Deque is empty. Cannot delete from front.\n";
            return;
        }
        cout << "Deleted " << arr[front] << " from front\n";

        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front = (front + 1) % CAPACITY;
        }
    }

    void DeleteRear()
    {
        if (IsEmpty())
        {
            cout << "Deque is empty. Cannot delete from rear.\n";
            return;
        }
        cout << "Deleted " << arr[rear] << " from rear\n";

        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            rear = (rear + CAPACITY - 1) % CAPACITY;
        }
    }

    void Display() const
    {
        if (IsEmpty())
        {
            cout << "Deque is empty.\n";
            return;
        }
        cout << "Deque (front to rear): ";

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
};

int main()
{
    ArrayDeque d;

    cout << "--- From empty: 20 at rear, 10 at front, 30 at rear ---\n";
    d.InsertRear(20);
    d.InsertFront(10);
    d.InsertRear(30);
    d.Display();

    cout << "\n--- Delete from rear, then from front ---\n";
    d.DeleteRear();
    d.DeleteFront();
    d.Display();

    cout << "\n--- Insert 5 at front, 30 and 40 at rear, 1 at front ---\n";
    d.InsertFront(5);
    d.InsertRear(30);
    d.InsertRear(40);
    d.InsertFront(1);
    d.Display();

    cout << "\n--- Further insertion at either end is rejected ---\n";
    d.InsertFront(99);
    d.InsertRear(99);
    d.Display();

    cout << "\n--- Run A: delete the only value from the front ---\n";
    ArrayDeque a;
    a.InsertRear(7);
    a.DeleteFront();
    a.Display();
    cout << "Deletion from empty:\n";
    a.DeleteFront();
    a.DeleteRear();

    cout << "\n--- Run B: delete the only value from the rear ---\n";
    ArrayDeque b;
    b.InsertFront(8);
    b.DeleteRear();
    b.Display();
    cout << "Deletion from empty:\n";
    b.DeleteRear();
    b.DeleteFront();

    return 0;
}
