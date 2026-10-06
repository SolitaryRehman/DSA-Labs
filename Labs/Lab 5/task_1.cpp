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

public:

    // constrcutor -- when creation
    DoublyLinkedList() 
    {
        head = nullptr;
        tail = nullptr;
    }

    // destructor --- runs autoo when the list is finished
    ~DoublyLinkedList() 
    {
        ClearList();
    }

    // Append at the tail in O(1), keeping next and prev links correct.
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

    void ClearList() 
    {
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
    DoublyLinkedList list;
    int count;
    
    cout << "Enter number of nodes (non-negative): ";
    
    if (!(cin >> count) || count < 0) 
    {
        cout << "Invalid count.\n";
        return 1;
    }
    
    for (int i = 1; i <= count; i++) 
    {
        int v;
        cout << "Enter value " << i << ": ";
        if (!(cin >> v)) 
        { 
            cout << "Invalid value.\n"; 
            return 1; 
        }
        
        list.AddNode(v);
    }

    list.PrintForward();
    list.PrintReverse();
    list.ClearList();
    list.PrintForward();   // shows the empty message after clearing
    
    return 0;
}