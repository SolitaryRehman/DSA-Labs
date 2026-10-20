// Task 2: Queue using singly linked nodes
#include <iostream>
using namespace std;

class LinkedQueue {
private:
    struct node {
        int data;
        node* next;
    };
    node* front;
    node* rear;

    // Objects that own nodes must not be copied
    LinkedQueue(const LinkedQueue&);
    LinkedQueue& operator=(const LinkedQueue&);

public:
    LinkedQueue() : front(nullptr), rear(nullptr) {}

    ~LinkedQueue() { ClearQueue(); }

    bool IsEmpty() const { return front == nullptr; }

    void Enqueue(int value) {
        node* n = new node;
        n->data = value;
        n->next = nullptr;
        if (IsEmpty()) {
            front = rear = n;
        } else {
            rear->next = n;   // insert at rear, no traversal
            rear = n;
        }
        cout << "Enqueued: " << value << "\n";
    }

    void Dequeue() {
        if (IsEmpty()) {
            cout << "Queue is empty. Cannot dequeue.\n";
            return;
        }
        node* temp = front;
        cout << "Dequeued: " << temp->data << "\n";
        front = front->next;
        if (front == nullptr) rear = nullptr;   // last node removed: reset rear
        delete temp;
    }

    void Peek() const {
        if (IsEmpty()) {
            cout << "Queue is empty. Nothing to peek.\n";
            return;
        }
        cout << "Front value: " << front->data << "\n";
    }

    void Display() const {
        if (IsEmpty()) {
            cout << "Queue is empty.\n";
            return;
        }
        cout << "Queue (front to rear): ";
        for (node* cur = front; cur != nullptr; cur = cur->next)
            cout << cur->data << " ";
        cout << "\n";
    }

    void ClearQueue() {
        while (front != nullptr) {
            node* temp = front;
            front = front->next;
            delete temp;
        }
        rear = nullptr;
    }
};

int main() {
    LinkedQueue q;

    cout << "--- Enqueue 10, 20, 30 ---\n";
    q.Enqueue(10);
    q.Enqueue(20);
    q.Enqueue(30);
    q.Display();

    cout << "\n--- Dequeue once ---\n";
    q.Dequeue();
    q.Display();

    cout << "\n--- Peek ---\n";
    q.Peek();

    cout << "\n--- Remove the remaining nodes (including the only node) ---\n";
    q.Dequeue();
    q.Dequeue();
    q.Display();

    cout << "\n--- Dequeue and Peek on empty queue ---\n";
    q.Dequeue();
    q.Peek();

    cout << "\n--- Enqueue after the queue became empty ---\n";
    q.Enqueue(40);
    q.Enqueue(50);
    q.Display();
    q.Peek();

    cout << "\n--- Release all remaining nodes before exit ---\n";
    q.ClearQueue();
    q.Display();

    return 0;
}
