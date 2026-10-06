#include <iostream>
using namespace std;

class List 
{
private:
    struct node 
    {
        int data;
        node* next;
    };

    node* head;

public:
    List() 
    {
        head = nullptr;
    }

    ~List() 
    {
        ClearList();
    }

    void AddNode(int addData) 
    {
        node* newNode = new node;
        newNode->data = addData;
        newNode->next = nullptr;

        if (head == nullptr) 
        {
            head = newNode;
            return;
        }

        node* curr = head;
        while (curr->next != nullptr) 
        {
            curr = curr->next;
        }
        curr->next = newNode;
    }

    int CountNodes() 
    {
        int count = 0;
        node* curr = head;
        while (curr != nullptr)
        {
            count++;
            curr = curr->next;
        }
        return count;
    }

    void PrintList() 
    {
        if (head == nullptr) 
        {
            cout << "The list is empty." << endl;
            return;
        }

        node* curr = head;
        while (curr != nullptr) 
        {
            cout << curr->data;
            if (curr->next != nullptr) {
                cout << " -> ";
            }
            curr = curr->next;
        }
        cout << endl;
    }

    void ClearList() 
    {
        node* curr = head;
        while (curr != nullptr) 
        {
            node* nextNode = curr->next;
            delete curr;
            curr = nextNode;
        }
        head = nullptr;
    }
};

int main() 
{
    List myList;
    int n;

    cout << "How many numbers do you want to add? ";
    cin >> n;

    for (int i = 1; i <= n; i++) 
    {
        int value;
        cout << "Enter number " << i << ": ";
        cin >> value;
        myList.AddNode(value);
    }

    cout << endl << "Your list: ";
    myList.PrintList();
    cout << "Total nodes: " << myList.CountNodes() << endl;

    myList.ClearList();
    return 0;
}
