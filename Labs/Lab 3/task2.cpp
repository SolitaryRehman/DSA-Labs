#include <iostream>
using namespace std;

struct Student 
{
    int roll_number;
    string name;
    float marks;
};

int main() 
{
    Student s;
    Student* ptr = &s;

    float new_marks;

    cout << "Enter roll number: ";
    cin >> ptr -> roll_number;
    cin.ignore();

    cout << "Enter full name: ";
    getline(cin, ptr -> name);

    cout << "Enter marks: ";
    cin >> ptr -> marks;

    cout << "\n--- Student Details ---\n";

    cout << "Roll Number: " << ptr -> roll_number << endl;
    cout << "Name: " << ptr -> name << endl;
    cout << "Marks: " << ptr -> marks << endl;

    cout << "\nEnter updated marks: ";
    cin >> new_marks;
    ptr->marks = new_marks;

    cout << "\n--- Updated Student Details ---\n";

    cout << "Roll Number: " << ptr -> roll_number << endl;
    cout << "Name: " << ptr -> name << endl;
    cout << "Marks: " << ptr -> marks << endl;

    return 0;
}