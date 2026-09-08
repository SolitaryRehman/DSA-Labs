#include <iostream>
using namespace std;

int main()
{
    int numbers[8];
    cout << endl << "enter 8 integers seperated by spaces: ";

    for (int i = 0; i < 8 ; i++)
    {
        cin >> numbers[i]; 
    }

    int max = numbers[0] ;
    int min = numbers[0] ;

    int max_ind = 0;
    int min_ind = 0;

    for (int i = 0 ; i < 8 ; i++ )
    {
        if (numbers[i] > max)
        {
            max = numbers[i];
            max_ind = i;
        }
    }

    cout << "Highest Number: " << max;
    cout << "  Index: " << max_ind;

    for (int i = 0 ; i < 8 ; i++ )
    {
        if (numbers[i] < min)
        {
            min = numbers[i];
            min_ind = i;
        }
    }

    cout << endl << "Lowest Number: " << min;
    cout << "  Index: " << min_ind;


}