#include <iostream>
#include <limits>
using namespace std;

struct Student 
{
    int rollNumber;
    string name;
    float marks;
};

void displayStudent(const Student* s) 
{
    cout << "\n--- Student Details ---\n";
    cout << "Roll Number: " << s->rollNumber << endl;
    cout << "Name: " << s->name << endl;
    cout << "Marks: " << s->marks << endl;
}

void updateMarks(Student* s, float newMarks) 
{
    s->marks = newMarks;
}

void displayIfExists(const Student* s) 
{
    if (s != nullptr) 
    {
        displayStudent(s);
    } else 
    {
        cout << "\nNo record available\n";
    }
}

// Clears cin's fail state and throws away whatever bad input is left in the buffer.
void clearInputError() 
{
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// Reads an int safely. Returns false (and cleans up the stream) if the input wasn't a valid int.
bool readInt(const string& prompt, int& value) 
{
    cout << prompt;
    cin >> value;
    if (cin.fail()) 
    {
        clearInputError();
        cout << "\nInvalid input. Please enter a whole number.\n";
        return false;
    }
    return true;
}

// Reads a float safely. Returns false (and cleans up the stream) if the input wasn't a valid number.
bool readFloat(const string& prompt, float& value) 
{
    cout << prompt;
    cin >> value;
    if (cin.fail()) 
    {
        clearInputError();
        cout << "\nInvalid input. Please enter a number.\n";
        return false;
    }
    return true;
}

int main() 
{
    Student* ptr = nullptr;
    int choice;

    do {
        cout << "\n===== Student Record Menu =====\n";
        cout << "1. Create record\n";
        cout << "2. Display record\n";
        cout << "3. Update marks\n";
        cout << "4. Delete record\n";
        cout << "5. Exit\n";

        if (!readInt("Enter your choice: ", choice)) 
        {
            continue; // bad input already cleared, just re-show the menu
        }

        switch (choice) 
        {
            case 1: 
            {
                if (ptr != nullptr) 
                {
                    cout << "\nA record already exists. Delete it first.\n";
                    break;
                }

                ptr = new Student;

                if (!readInt("Enter roll number: ", ptr->rollNumber)) 
                {
                    delete ptr;
                    ptr = nullptr;
                    break;
                }
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // flush leftover newline before getline

                cout << "Enter full name: ";
                getline(cin, ptr->name);

                if (!readFloat("Enter marks: ", ptr->marks)) 
                {
                    delete ptr;
                    ptr = nullptr;
                    break;
                }

                cout << "\nRecord created successfully.\n";
                break;
            }
            case 2: 
            {
                displayIfExists(ptr);
                break;
            }
            case 3: 
            {
                if (ptr == nullptr) 
                {
                    cout << "\nNo record available\n";
                } 
                else 
                {
                    float newMarks;
                    if (readFloat("Enter updated marks: ", newMarks)) 
                    {
                        updateMarks(ptr, newMarks);
                        cout << "\nMarks updated successfully.\n";
                    }
                }
                break;
            }
            case 4: 
            {
                if (ptr == nullptr) 
                {
                    cout << "\nNo record available\n";
                } 
                else 
                {
                    delete ptr;
                    ptr = nullptr;
                    cout << "\nRecord deleted successfully.\n";
                }
                break;
            }
            case 5: 
            {
                if (ptr != nullptr) 
                {
                    delete ptr;
                    ptr = nullptr;
                }
                cout << "\nExiting program.\n";
                break;
            }
            default: 
            {
                cout << "\nInvalid choice. Please try again.\n";
                break;
            }
        }
    } 
    while (choice != 5);

    return 0;
}