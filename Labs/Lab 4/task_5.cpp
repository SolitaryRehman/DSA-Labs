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

    void DeleteNode(int delData) 
    {

        if (head == nullptr) 
        {
            cout << "List is empty, nothing to delete." << endl;
            return;
        }

        if (head->data == delData) 
        {
            node* toDelete = head;
            head = head->next;
            delete toDelete;
            cout << "Deleted " << delData << " from the list." << endl;
            return;
        }

        node* prev = head;
        node* curr = head->next;

        while (curr != nullptr) 
        {
            if (curr->data == delData) 
            {
                prev->next = curr->next;
                delete curr;
                cout << "Deleted " << delData << " from the list." << endl;
                return;
            }
            prev = curr;
            curr = curr->next;
        }

        cout << "Value " << delData << " not found, nothing deleted." << endl;
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

    cout << "--- Test A: empty list ---" << endl;
    List listA;
    listA.DeleteNode(5);
    listA.PrintList();

    cout << endl << "--- Test B: duplicate values ---" << endl;
    List listB;
    listB.AddNode(10);
    listB.AddNode(20);
    listB.AddNode(20);
    listB.AddNode(30);
    cout << "Before: ";
    listB.PrintList();
    listB.DeleteNode(20);
    cout << "After:  ";
    listB.PrintList();

    cout << endl << "--- Test C: delete first node ---" << endl;
    listB.DeleteNode(10);
    listB.PrintList();

    cout << endl << "--- Test D: delete last node ---" << endl;
    listB.DeleteNode(30);
    listB.PrintList();

    cout << endl << "--- Test E: missing value ---" << endl;
    listB.DeleteNode(99);
    listB.PrintList();

    cout << endl << "--- Test F: delete the only node ---" << endl;
    listB.DeleteNode(20);
    listB.PrintList();

    cout << endl << "--- Test G: delete a middle node ---" << endl;
    List listG;
    listG.AddNode(1);
    listG.AddNode(2);
    listG.AddNode(3);
    cout << "Before: ";
    listG.PrintList();
    listG.DeleteNode(2);
    cout << "After:  ";
    listG.PrintList();

    listA.ClearList();
    listB.ClearList();
    listG.ClearList();
    return 0;
}
