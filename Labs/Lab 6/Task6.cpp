#include <iostream>
using namespace std;

const int SIZE = 5;

int items[SIZE];
int front = -1;
int rear = -1;

void enqueue(int value)
{
    if (rear == SIZE - 1)
    {
        cout << "Cannot add customer " << value << ": the queue is blocked (rear is at the last position)." << endl;
        return;
    }

    if (front == -1)
    {
        front = 0;
    }

    rear++;
    items[rear] = value;
    cout << "Customer with token " << value << " added to the queue." << endl;
}

void dequeue()
{
    if (front == -1)
    {
        cout << "No customers to serve: the queue is empty." << endl;
        return;
    }

    cout << "Serving customer with token " << items[front] << "." << endl;

    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        front++;
    }
}

void peekFront()
{
    if (front == -1)
    {
        cout << "No customers waiting: the queue is empty." << endl;
        return;
    }

    cout << "Next customer to be served has token " << items[front] << "." << endl;
}

void display()
{
    if (front == -1)
    {
        cout << "The queue is empty." << endl;
        return;
    }

    cout << "Customers waiting (front to rear): ";
    for (int i = front; i <= rear; i++)
    {
        cout << items[i] << " ";
    }
    cout << endl;
}

void showMenu()
{
    cout << endl;
    cout << "===== Customer Service Queue =====" << endl;
    cout << "1. Add customer" << endl;
    cout << "2. Serve next" << endl;
    cout << "3. View next" << endl;
    cout << "4. Display queue" << endl;
    cout << "5. Exit" << endl;
    cout << "Enter your choice: ";
}

int main()
{
    int choice;
    int token;

    do
    {
        showMenu();
        cin >> choice;
        cout << endl;

        switch (choice)
        {
            case 1:
                cout << "Enter customer token number: ";
                cin >> token;
                enqueue(token);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                peekFront();
                break;

            case 4:
                display();
                break;

            case 5:
                cout << "Exiting the program. Goodbye!" << endl;
                break;

            default:
                cout << "Invalid choice. Please enter a number from 1 to 5." << endl;
        }
    } while (choice != 5);

    return 0;
}
