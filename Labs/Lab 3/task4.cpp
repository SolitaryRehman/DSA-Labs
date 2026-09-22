#include <iostream>
using namespace std;

struct Student 
{
    int roll_number;
    string name;
    float marks;
};

void displayStudent(const Student* s) 
{
    cout << "\n--- Student Details ---\n";

    cout << "Roll Number: " << s->roll_number << endl;
    cout << "Name: " << s->name << endl;
    cout << "Marks: " << s->marks << endl;
}

void updateMarks(Student* s, float new_marks) 
{
    s->marks = new_marks;
}

int main() 
{
    Student* ptr = new Student;
    float new_marks;

    cout << "Enter roll number: ";
    cin >> ptr->roll_number;
    cin.ignore();

    cout << "Enter full name: ";
    getline(cin, ptr->name);

    cout << "Enter marks: ";
    cin >> ptr->marks;

    displayStudent(ptr);

    cout << "\nEnter updated marks: ";
    cin >> new_marks;

    updateMarks(ptr, new_marks);

    displayStudent(ptr);

    delete ptr;
    ptr = nullptr;

    return 0;
}