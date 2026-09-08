#include <iostream>
using namespace std;

int main()
{
    int numbers [5];
    int total = 0;

    cout << "Enter 5 numbers seperated by spaces: " ;
    
    for ( int i = 0 ; i < 5 ; i++)
    {
        cin >> numbers[i];
    }

    for (int i = 0 ; i < 5 ; i++)
    {
        total += numbers[i]; 
    }

    cout << endl << "Total = " << total << endl;
}