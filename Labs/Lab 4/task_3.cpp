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

    void PrintSecondNode() 
    {

        if (head == nullptr || head->next == nullptr) 
        {
            cout << "There is no second node (fewer than two nodes)." << endl;
            return;
        }
        cout << "Second node: " << head->next->data << endl;
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

    cout << "--- Test 1: empty list ---" << endl;
    List emptyList;
    emptyList.PrintList();
    emptyList.PrintSecondNode();
    emptyList.SearchNode(20);

    cout << endl << "--- Test 2: one-node list ---" << endl;
    List oneNode;
    oneNode.AddNode(10);
    oneNode.PrintList();
    oneNode.PrintSecondNode();

    cout << endl << "--- Test 3: list 10, 20, 30, 20 ---" << endl;
    List bigList;
    bigList.AddNode(10);
    bigList.AddNode(20);
    bigList.AddNode(30);
    bigList.AddNode(20);
    bigList.PrintList();
    bigList.PrintSecondNode();
    bigList.SearchNode(20);
    bigList.SearchNode(99);

    emptyList.ClearList();
    oneNode.ClearList();
    bigList.ClearList();
    return 0;
}
