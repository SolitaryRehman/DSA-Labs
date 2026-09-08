#include <iostream>
using namespace std;

int main()
{
    int numbers[6];
    cout << endl << "enter 6 integers seperated by spaces: ";

    for (int i = 0; i < 6 ; i++)
    {
        cin >> numbers[i]; 
    }

    int start = 0;
    int end = 5;

    int temp;

    while (start < end)
    {
        numbers[temp] = numbers[start];
        numbers[start] = numbers[end];
        numbers[end] = numbers[temp];

        start++;
        end--;
    }

    cout << endl << "Reversed array: ";

    for (int i = 0; i < 6; i++) 
    {
        cout << numbers[i] << " ";
    }

    cout << endl;

}