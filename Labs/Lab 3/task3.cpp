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
    Student* ptr = new Student;

    cout << "Enter roll number: ";
    cin >> ptr->roll_number;
    cin.ignore();

    cout << "Enter full name: ";
    getline(cin, ptr->name);

    cout << "Enter marks: ";
    cin >> ptr->marks;

    cout << "\n--- Student Details ---\n";

    cout << "Roll Number: " << ptr->roll_number << endl;
    cout << "Name: " << ptr->name << endl;
    cout << "Marks: " << ptr->marks << endl;

    delete ptr;
    ptr = nullptr;

    return 0;
}