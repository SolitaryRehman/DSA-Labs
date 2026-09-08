#include <iostream>
using namespace std;
 
class Student 
{
    public:
        int roll_number;
        int marks;
    
        void display() 
        {
            cout << "Roll Number: " << roll_number << endl;
            cout << "Marks: " << marks << endl;
        }
};

int main ()
{
    Student s1, s2;
    s1.roll_number = 1;
    s1.marks = 75;
 
    s2.roll_number = 2;
    s2.marks = 90;

    cout << "Before Changing marks:" << endl;

    s1.display();
    s2.display();
    
    s1.marks = 80;

    cout << "After Changing marks:" << endl;

    s1.display();
    s2.display();


}