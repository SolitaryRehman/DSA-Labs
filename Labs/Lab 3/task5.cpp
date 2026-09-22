#include <iostream>
using namespace std;

struct Student 
{
    int roll_number;
    string name;
    float marks;
};

void displayIfExists(const Student* s) 
{
    if (s != nullptr) 
    {
        cout << "\n--- Student Details ---\n";

        cout << "Roll Number: " << s->roll_number << endl;
        cout << "Name: " << s->name << endl;
        cout << "Marks: " << s->marks << endl;
    } 
    else 
    {
        cout << "\nNo record available\n";
    }
}

int main() 
{
    Student* ptr = nullptr;

    cout << "\nChecking before allocation:";
    displayIfExists(ptr);

    ptr = new Student;

    cout << "\nEnter roll number: ";
    cin >> ptr->roll_number;
    cin.ignore();
    
    cout << "Enter full name: ";
    getline(cin, ptr->name);

    cout << "Enter marks: ";
    cin >> ptr->marks;

    cout << "\nChecking after allocating and entering a record:";
    displayIfExists(ptr);

    delete ptr;
    ptr = nullptr;

    cout << "\nChecking after deleting the record:";
    displayIfExists(ptr);

    return 0;
}