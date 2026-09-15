#include <iostream>
using namespace std;

main ()
{
    int n;

    cout << "Enter the Number of Students: ";
    cin >> n;

     if (n <= 0 || n > 10)
    {
        cout << "Error: Invalid number of students." << endl;
        return 0;
    }

    cout << "Enter Marks:  ";
     
    int *marks = new int [n];

    for (int i = 0 ; i < n ; i++)
    {
        cin >> *(marks + i);
    }

    int total = 0;
    float average;
    int passcount = 0;

    cout << endl << "Marks:  " << endl ;
    
    for (int i = 0 ; i < n ; i++)
    {
        cout << *(marks + i) << "   ";
        total += *(marks + i) ;

        if ( *(marks + i) >= 50 )
        {
            passcount++;
        }
    }

    average = (float) total / n;

    cout << endl;
    cout << "Total: " << total << endl;
    cout << "Average: " << average << endl;
    cout << "Pass count: " << passcount << endl;

    delete[] marks;
    marks = nullptr;

    return 0;

}