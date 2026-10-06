
// Lab 04 - Task 1: Creating and traversing a singly linked list

#include <iostream>
using namespace std;

class List {
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

    void CreateThreeNodes() 
    {
        
        if (head != nullptr) 
        {
            cout << "List already has nodes, not creating again." << endl;
            return;
        }

        node* tail = nullptr;  

        for (int i = 1; i <= 3; i++) 
        {
            int value;
            cout << "Enter integer " << i << ": ";
            cin >> value;

            node* newNode = new node;
            newNode->data = value;
            newNode->next = nullptr; 

            if (head == nullptr) 
            {
                head = newNode;
            } else 
            {    
                tail->next = newNode;
            }
            tail = newNode;
        }
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
            if (curr->next != nullptr) 
            {
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

    cout << "List before creating nodes:" << endl;
    myList.PrintList();

    cout << endl;
    myList.CreateThreeNodes();

    cout << endl << "List after creating nodes:" << endl;
    myList.PrintList();

    // Clean up before we leave
    myList.ClearList();
    return 0;
}
