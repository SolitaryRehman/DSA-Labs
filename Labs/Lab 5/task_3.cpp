#include <iostream>
using namespace std;

struct Node 
{
    int data;
    Node* next;

    Node(int v) 
    {
        data = v;
        next = nullptr;
    }
};

class CircularList 
{
    Node* head;
    Node* tail;

public:

    CircularList() 
    {
        head = nullptr;
        tail = nullptr;
    }

    ~CircularList() 
    {
        ClearList();
    }

    // Add at the tail and keep tail->next pointing back to head
    void AddNode(int value) 
    {
        Node* n = new Node(value);

        if (tail == nullptr) 
        {
            head = tail = n;
            n->next = n;        // a single node points to itself
        } 
        else 
        {
            n->next = head;
            tail->next = n;
            tail = n;
        }
    }

    // Stop when we come back around to head (not at nullptr)
    void PrintList() const 
    {
        if (head == nullptr) 
        {
            cout << "The list is empty.\n";
            return;
        }

        cout << "List: ";
        Node* cur = head;
        do 
        {
            cout << cur->data;
            cur = cur->next;
            if (cur != head) cout << ", ";
        } 
        while (cur != head);

        cout << "\n";
    }

    int CountNodes() const 
    {
        if (head == nullptr) 
        {
            return 0;
        }

        int count = 0;
        Node* cur = head;
        do 
        {
            count++;
            cur = cur->next;
        } 
        while (cur != head);

        return count;
    }

    void ClearList() 
    {
        if (head == nullptr) 
        {
            return;
        }

        tail->next = nullptr;   // break the circle so a normal loop can delete everything

        while (head != nullptr) 
        {
            Node* t = head;
            head = head->next;
            delete t;
        }
        tail = nullptr;
    }
};

int main() 
{
    CircularList list;

    cout << "--- Empty list ---\n";
    list.PrintList();
    cout << "Count: " << list.CountNodes() << "\n";

    cout << "\n--- One node ---\n";
    list.AddNode(10);
    list.PrintList();
    cout << "Count: " << list.CountNodes() << "\n";

    cout << "\n--- 10, 20, 30 ---\n";
    list.ClearList();
    list.AddNode(10);
    list.AddNode(20);
    list.AddNode(30);
    list.PrintList();
    cout << "Count: " << list.CountNodes() << "\n";

    // Why a nullptr loop never ends: the last node points back to the first,
    // so no node ever has next == nullptr. "while (cur != nullptr)" would
    // go around the circle forever. We stop when we are back at head.

    return 0;
}