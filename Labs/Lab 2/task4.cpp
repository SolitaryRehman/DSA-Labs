#include <iostream>
using namespace std;

int main()
{
    int rows, cols;

    cout << "Enter number of students: ";
    cin >> rows;

    cout << "Enter number of subjects: ";
    cin >> cols;

    if (rows <= 0 || rows > 100 || cols <= 0 || cols > 10)
    {
        cout << "Invalid rows or columns." << endl;
        return 0;
    }

    int** marks = new int*[rows];

    for (int r = 0; r < rows; r++)
    {
        marks[r] = new int[cols];
    }

    cout << "Enter marks:" << endl;

    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < cols; c++)
        {
            cin >> *(*(marks + r) + c);
        }
    }

    cout << endl << "Marks:" << endl;

    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < cols; c++)
        {
            cout << *(*(marks + r) + c) << "   ";
        }

        cout << endl;
    }

    int bestTotal = 0;
    int bestStudent = 1;

    for (int c = 0; c < cols; c++)
    {
        bestTotal += *(*(marks + 0) + c);
    }

    for (int r = 1; r < rows; r++)
    {
        int total = 0;

        for (int c = 0; c < cols; c++)
        {
            total += *(*(marks + r) + c);
        }

        if (total > bestTotal)
        {
            bestTotal = total;
            bestStudent = r + 1;
        }
    }

    cout << endl;
    cout << "Student with highest total: Student " << bestStudent << endl;
    cout << "Highest total: " << bestTotal << endl;

    for (int r = 0; r < rows; r++)
    {
        delete[] marks[r];
    }

    delete[] marks;

    marks = nullptr;

    return 0;
}