#include <iostream>
using namespace std;

struct Student 
{
    string name;
    int roll_number;
    float marks;
};

int main ()
{
    Student s ;

    cout << "Enter Full Name:   ";
    getline (cin, s.name);

    cout << endl << "Enter Roll Number:     ";
    cin >> s.roll_number;

    cout << endl << "Enter Marks:   ";
    cin >> s.marks;

    cout << endl << "<--- Student Details --->" << endl << endl;

    cout << "Roll Number: " << s.roll_number << endl;
    cout << "Name: " << s.name << endl;
    cout << "Marks: " << s.marks << endl;

    return 0;
}