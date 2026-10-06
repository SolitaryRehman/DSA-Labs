#include <iostream>
using namespace std;

struct Node 
{
    int data;
    Node* next;
    Node* prev;

    Node(int v) 
    {
        data = v;
        next = nullptr;
        prev = nullptr;
    }
};

class DoublyLinkedList 
{
    Node* head;
    Node* tail;
    int size;

public:

    DoublyLinkedList() 
    {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    ~DoublyLinkedList() 
    {
        ClearList();
    }

    void AddNode(int value) 
    {
        Node* n = new Node(value);

        if (tail == nullptr) 
        {
            head = tail = n;
        } 
        else 
        {
            tail->next = n;
            n->prev = tail;
            tail = n;
        }
        size++;
    }

    // Insert value before the node at positions
    bool InsertBefore(int position, int value) 
    {
        if (position < 1 || position > size) 
        {
            cout << "Invalid position " << position << ". Nothing changed.\n";
            return false;
        }

        // walk to the node at that position
        Node* cur = head;
        for (int i = 1; i < position; i++) 
        {
            cur = cur->next;
        }

        Node* n = new Node(value);
        n->next = cur;
        n->prev = cur->prev;

        if (cur->prev != nullptr) 
        {
            cur->prev->next = n;
        } 
        else 
        {
            head = n;       // inserting before the head, so new nodee is the new heads
        }

        cur->prev = n;
        size++;
        return true;
    }

    // Delete only the first node that has this value
    bool DeleteNode(int value) 
    {
        if (head == nullptr) 
        {
            cout << "Cannot delete " << value << ": the list is empty.\n";
            return false;
        }

        Node* cur = head;
        while (cur != nullptr && cur->data != value) 
        {
            cur = cur->next;
        }

        if (cur == nullptr) 
        {
            cout << "Value " << value << " not found. Nothing changed.\n";
            return false;
        }

        if (cur->prev != nullptr) 
        {
            cur->prev->next = cur->next;
        } 
        else 
        {
            head = cur->next;   // deleting the head
        }

        if (cur->next != nullptr) 
        {
            cur->next->prev = cur->prev;
        } 
        else 
        {
            tail = cur->prev;   // deleting the tail
        }

        delete cur;
        size--;
        return true;
    }

    void PrintForward() const 
    {
        if (head == nullptr) 
        {
            cout << "The list is empty.\n";
            return;
        }

        cout << "Forward: ";
        for (Node* c = head; c != nullptr; c = c->next) 
        {
            cout << c->data;
            if (c->next) cout << ", ";
        }
        cout << "\n";
    }

    void PrintReverse() const 
    {
        if (tail == nullptr) 
        {
            cout << "The list is empty.\n";
            return;
        }

        cout << "Reverse: ";
        for (Node* c = tail; c != nullptr; c = c->prev) 
        {
            cout << c->data;
            if (c->prev) cout << ", ";
        }
        cout << "\n";
    }

    void PrintBoth() const 
    {
        PrintForward();
        PrintReverse();
    }

    void ClearList() 
    {
        while (head != nullptr) 
        {
            Node* t = head;
            head = head->next;
            delete t;
        }
        tail = nullptr;
        size = 0;
    }
};

int main() 
{
    DoublyLinkedList list;

    cout << "--- Empty list ---\n";
    list.PrintBoth();
    list.DeleteNode(5);
    list.InsertBefore(1, 5);

    cout << "\n--- 10, 20, 30 then insert 15 before position 2, delete 20 ---\n";
    list.AddNode(10);
    list.AddNode(20);
    list.AddNode(30);
    list.InsertBefore(2, 15);
    list.DeleteNode(20);
    list.PrintBoth();                   // 10, 15, 30

    cout << "\n--- Insert before head ---\n";
    list.InsertBefore(1, 5);
    list.PrintBoth();                   // 5, 10, 15, 30

    cout << "\n--- Invalid positions ---\n";
    list.InsertBefore(0, 1);
    list.InsertBefore(-3, 1);
    list.InsertBefore(5, 1);
    list.PrintBoth();

    cout << "\n--- Delete head (5) ---\n";
    list.DeleteNode(5);
    list.PrintBoth();

    cout << "\n--- Delete tail (30) ---\n";
    list.DeleteNode(30);
    list.PrintBoth();

    cout << "\n--- Missing value (99) ---\n";
    list.DeleteNode(99);
    list.PrintBoth();

    cout << "\n--- Delete until empty ---\n";
    list.DeleteNode(15);
    list.DeleteNode(10);                // the only node
    list.PrintBoth();

    cout << "\n--- Delete from empty list ---\n";
    list.DeleteNode(10);

    return 0;
}