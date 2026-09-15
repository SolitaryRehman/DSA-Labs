#include <iostream>
using namespace std;

int main()
{
    int n;

    cout << "Enter number of marks: ";
    cin >> n;

    if (n < 1 || n > 10)
    {
        cout << "Invalid number of students." << endl;
        return 0;
    }

    int* marks = new int[n];

    cout << "Enter marks:" << endl;

    for (int i = 0; i < n; i++)
    {
        cin >> *(marks + i);
    }

    int* newMarks = new int[n + 1];

    for (int i = 0; i < n; i++)
    {
        *(newMarks + i) = *(marks + i);
    }

    cout << "Enter new mark: ";
    cin >> *(newMarks + n);

    delete[] marks;

    marks = newMarks;

    n = n + 1;

    cout << endl << "Marks:" << endl;

    for (int i = 0; i < n; i++)
    {
        cout << *(marks + i) << " ";
    }

    cout << endl;

    delete[] marks;
    marks = nullptr;

    return 0;
}