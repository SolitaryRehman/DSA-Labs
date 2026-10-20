// Task 6: Deque using doubly linked nodes, with a menu

#include <iostream>
using namespace std;

class LinkedDeque
{

private:
    struct node
    {
        int data;
        node* next;
        node* prev;
    };

    node* front;
    node* rear;

    // Objects that own nodes must not be copied
    LinkedDeque(const LinkedDeque&);
    LinkedDeque& operator=(const LinkedDeque&);

public:
    LinkedDeque() : front(nullptr), rear(nullptr)
    {

    }

    ~LinkedDeque()
    {
        ClearDeque();
    }

    bool IsEmpty() const
    {
        return front == nullptr;
    }

    void InsertFront(int value)
    {
        node* n = new node;
        n->data = value;
        n->prev = nullptr;   // front->prev must be nullptr
        n->next = front;

        if (IsEmpty())
        {
            rear = n;
        }
        else
        {
            front->prev = n;
        }

        front = n;

        cout << "Inserted " << value << " at front\n";
    }

    void InsertRear(int value)
    {
        node* n = new node;
        n->data = value;
        n->next = nullptr;   // rear->next must be nullptr
        n->prev = rear;

        if (IsEmpty())
        {
            front = n;
        }
        else
        {
            rear->next = n;
        }

        rear = n;

        cout << "Inserted " << value << " at rear\n";
    }

    void DeleteFront()
    {
        if (IsEmpty())
        {
            cout << "Deque is empty. Cannot delete from front.\n";
            return;
        }

        node* temp = front;
        cout << "Deleted " << temp->data << " from front\n";

        front = front->next;

        if (front == nullptr)
        {
            rear = nullptr;   // last node removed
        }
        else
        {
            front->prev = nullptr;
        }

        delete temp;
    }

    void DeleteRear()
    {
        if (IsEmpty())
        {
            cout << "Deque is empty. Cannot delete from rear.\n";
            return;
        }

        node* temp = rear;
        cout << "Deleted " << temp->data << " from rear\n";

        rear = rear->prev;

        if (rear == nullptr)
        {
            front = nullptr;   // last node removed
        }
        else
        {
            rear->next = nullptr;
        }

        delete temp;
    }

    void Display() const
    {
        if (IsEmpty())
        {
            cout << "Deque is empty.\n";
            return;
        }
        cout << "Deque (front to rear): ";

        for (node* cur = front; cur != nullptr; cur = cur->next)
        {
            cout << cur->data << " ";
        }

        cout << "\n";
    }

    void ClearDeque()
    {
        while (front != nullptr)
        {
            node* temp = front;
            front = front->next;
            delete temp;
        }

        rear = nullptr;
    }
};

int main()
{
    LinkedDeque d;
    int choice;
    int value;

    do
    {
        cout << "\n===== Linked Deque Menu =====\n";
        cout << "1. Insert at front\n";
        cout << "2. Insert at rear\n";
        cout << "3. Delete from front\n";
        cout << "4. Delete from rear\n";
        cout << "5. Display\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            d.InsertFront(value);
            break;

        case 2:
            cout << "Enter value: ";
            cin >> value;
            d.InsertRear(value);
            break;

        case 3:
            d.DeleteFront();
            break;

        case 4:
            d.DeleteRear();
            break;

        case 5:
            d.Display();
            break;

        case 0:
            if (!d.IsEmpty())
            {
                cout << "Exiting with nodes remaining. Releasing them: ";
                d.Display();
            }

            d.ClearDeque();
            cout << "All nodes released. Goodbye.\n";
            break;

        default:
            cout << "Invalid choice. Please enter a number from 0 to 5.\n";
        }

    } while (choice != 0);

    return 0;
}
