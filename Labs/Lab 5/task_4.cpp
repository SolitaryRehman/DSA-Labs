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

    void AddNode(int value) 
    {
        Node* n = new Node(value);

        if (tail == nullptr) 
        {
            head = tail = n;
            n->next = n;
        } 
        else 
        {
            n->next = head;
            tail->next = n;
            tail = n;
        }
    }

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

    // Remove the first node with this value. Search one full cycle only.
    bool DeleteNode(int value) 
    {
        if (head == nullptr) 
        {
            cout << "Cannot delete " << value << ": the list is empty.\n";
            return false;
        }

        Node* prev = tail;      // the node just before cur (tail comes just before head)
        Node* cur = head;

        do 
        {
            if (cur->data == value) 
            {
                if (cur == head && cur == tail) 
                {
                    // the only node
                    delete cur;
                    head = nullptr;
                    tail = nullptr;
                } 
                else 
                {
                    prev->next = cur->next;     // skip over cur

                    if (cur == head) 
                    {
                        head = cur->next;
                    }
                    if (cur == tail) 
                    {
                        tail = prev;
                    }

                    delete cur;
                }
                return true;
            }

            prev = cur;
            cur = cur->next;
        } 
        while (cur != head);    // one full cycle finished

        cout << "Value " << value << " not found. Nothing changed.\n";
        return false;
    }

    void ClearList() 
    {
        if (head == nullptr) 
        {
            return;
        }

        tail->next = nullptr;

        while (head != nullptr) 
        {
            Node* t = head;
            head = head->next;
            delete t;
        }
        tail = nullptr;
    }

    bool HeadAndTailAreNull() const 
    {
        return (head == nullptr && tail == nullptr);
    }
};

void Show(const CircularList& list) 
{
    list.PrintList();
    cout << "Count: " << list.CountNodes() << "\n";
}

int main() 
{
    CircularList list;

    cout << "--- Empty list ---\n";
    list.DeleteNode(10);
    Show(list);

    cout << "\n--- 10, 20, 30: delete 10, then 30, then 20 ---\n";
    list.AddNode(10);
    list.AddNode(20);
    list.AddNode(30);
    Show(list);

    cout << "Delete 10\n";
    list.DeleteNode(10);
    Show(list);

    cout << "Delete 30\n";
    list.DeleteNode(30);
    Show(list);

    cout << "Delete 20\n";
    list.DeleteNode(20);
    Show(list);

    if (list.HeadAndTailAreNull()) 
    {
        cout << "Head and tail are both nullptr.\n";
    }

    cout << "\n--- Missing value ---\n";
    list.AddNode(10);
    list.AddNode(20);
    list.AddNode(30);
    list.DeleteNode(99);
    Show(list);

    cout << "\n--- Middle node (20) ---\n";
    list.DeleteNode(20);
    Show(list);

    cout << "\n--- Duplicates: delete 20 once from 10, 20, 20, 30 ---\n";
    list.ClearList();
    list.AddNode(10);
    list.AddNode(20);
    list.AddNode(20);
    list.AddNode(30);
    Show(list);
    list.DeleteNode(20);
    Show(list);                 // 10, 20, 30

    list.ClearList();
    return 0;
}