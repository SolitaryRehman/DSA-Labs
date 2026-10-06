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

    void InsertAtBeginning(int addData) 
    {
        node* newNode = new node;
        newNode->data = addData;
        newNode->next = head;
        head = newNode;
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

    void SearchNode(int searchData) 
    {
        node* curr = head;
        int position = 1;

        while (curr != nullptr) 
        {
            if (curr->data == searchData) 
            {
                cout << "Found " << searchData << " at position "
                     << position << endl;
                return;
            }
            curr = curr->next;
            position++;
        }
        cout << "Value not found" << endl;
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

    void PrintSecondNode() 
    {
        if (head == nullptr || head->next == nullptr)
        {
            cout << "There is no second node (fewer than two nodes)." << endl;
            return;
        }
        cout << "Second node: " << head->next->data << endl;
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

void ShowMenu() 
{
    cout << endl;
    cout << "===== Singly Linked List Menu =====" << endl;
    cout << "1. Insert at beginning" << endl;
    cout << "2. Insert at end" << endl;
    cout << "3. Search by value" << endl;
    cout << "4. Delete by value" << endl;
    cout << "5. Display all nodes" << endl;
    cout << "6. Count nodes" << endl;
    cout << "7. Display second node" << endl;
    cout << "8. Exit" << endl;
    cout << "Enter your choice: ";
}

int main() 
{
    List myList;
    int choice = 0;
    int value;

    while (choice != 8) 
    {
        ShowMenu();
        cin >> choice;

        switch (choice) 
        {
            case 1:
                cout << "Enter value to insert at beginning: ";
                cin >> value;
                myList.InsertAtBeginning(value);
                cout << "Inserted " << value << " at the beginning." << endl;
                break;

            case 2:
                cout << "Enter value to insert at end: ";
                cin >> value;
                myList.AddNode(value);
                cout << "Inserted " << value << " at the end." << endl;
                break;

            case 3:
                cout << "Enter value to search: ";
                cin >> value;
                myList.SearchNode(value);
                break;

            case 4:
                cout << "Enter value to delete: ";
                cin >> value;
                myList.DeleteNode(value);
                break;

            case 5:
                myList.PrintList();
                break;

            case 6:
                cout << "Number of nodes: " << myList.CountNodes() << endl;
                break;

            case 7:
                myList.PrintSecondNode();
                break;

            case 8:

                myList.ClearList();
                cout << "All nodes released. Goodbye!" << endl;
                break;

            default:

                cout << "Invalid choice, please pick a number from 1 to 8." << endl;
                break;
        }
    }

    return 0;
}
