#include <iostream>
using namespace std;

main ()
{
    int sales[2][3];
    int (*rowPtr)[3] = sales;

    cout << "Enter sales for 2 branches across 3 days:" << endl;

    for (int r = 0 ; r < 2 ; r++)
    {
        for (int c = 0 ; c < 3 ; c++ )
        {
            cin >> *(*(rowPtr + r) + c);
        }
    }

    cout << endl << "Sales:" << endl;

    for (int r = 0; r < 2; r++)
    {
        for (int c = 0; c < 3; c++)
        {
            cout << *(*(rowPtr + r) + c) << "   ";
        }

        cout << endl;
    }

    cout << endl << "Branch Totals:" << endl;

    for (int r = 0; r < 2; r++)
    {
        int total = 0;

        for (int c = 0; c < 3; c++)
        {
            total += *(*(rowPtr + r) + c) ;
        }

        cout << "Branch " << r + 1 << " :  " << total <<  endl;
    }

    for (int c = 0; c < 3; c++)
    {
        int total = 0;

        for (int r = 0; r < 2; r++)
        {
            total += *(*(rowPtr + r) + c);
        }

        cout << "Day " << c + 1 << ":  " << total << endl;
    }

    return 0;

    // rowptr + 1 --->   points to the next row in the array

}