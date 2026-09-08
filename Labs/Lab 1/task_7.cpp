#include <iostream>
using namespace std;

int main() 
{
    int numbers[10];

    cout << "Enter 10 integers separated by spaces: ";

    for (int i = 0; i < 10; i++) 
    {
        cin >> numbers[i];
    }

    
    int writeIndex = 0;

    for (int i = 0; i < 10; i++) 
    {
        bool alreadySeen = false;

        for (int j = 0; j < writeIndex; j++) 
        {
            if (numbers[j] == numbers[i]) 
            {
                alreadySeen = true;
                break;
            }
        }

        if (!alreadySeen) 
        {
            numbers[writeIndex] = numbers[i];
            writeIndex++;
        }
    }

    cout << "Unique values: ";

    for (int i = 0; i < writeIndex; i++) 
    {
        cout << numbers[i] << " ";
    }

    cout << endl << "Count: " << writeIndex << endl;

}