#include <iostream>
using namespace std;

main ()
{
    int sales[5];
    int *p = sales;

    int total = 0;

    cout << "Enter 5 Non-Negative integers: ";

    for (int i = 0 ; i < 5 ; i++)
    {
        cin >> *(p+i);
        
        total += *(p+i) ;
    }

    cout << endl << "The Values:  " << endl;

    for (int i = 0 ; i < 5 ; i++)
    {
        cout << *(p+i) << "  ";
    }

    cout << endl << "Total:  " << total << endl;

    *(p+2) += 2;
    total  += 2;
    
    cout << endl << "The New Values:  " << endl;

    for (int i = 0 ; i < 5 ; i++)
    {
        cout << *(p+i) << "  ";
    }

    cout << endl << "New Total:  " << total << endl;
    
    //  p       -->  Address of the first element
    //  &p      -->  Address of the pointer variable p itself
    //  *p      -->  Value at the address stored in p, first term
    //  *(p+2)  -->  Value at 3rd term meaning sales[2]
    //  *(p+5)  -->  Because it exceeds the length of the array so we can't use to modify it


}