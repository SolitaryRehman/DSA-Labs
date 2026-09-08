#include <iostream>
using namespace std;

int main()
{
    int numbers[5] = {2,4,6,8,10};

    cout << endl << "First Array: " << endl;
    
    for (int i = 0 ; i < 5 ; i++)
    {
        cout << numbers[i] << " ";
    }

    cout << endl;

    cout << "Second Array: " << endl;

    numbers[2] = 7;

     for (int i = 0 ; i < 5 ; i++)
    {
        cout << numbers[i] <<  " ";
    }

    cout << endl << "Prediction: " << endl << "2 4 7 8 10" << endl;

}