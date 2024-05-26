#include <iostream>

using namespace std;

// Виправте програму із вправи 6.

int main()
{
    int* pInt = new int;
    *pInt = 10;
    cout << "Value of dereferenced pInt: " << *pInt << endl;
    delete pInt;
    cout << "Clearing pInt... \nReturning from main without memory leak..." << endl; 

    return 0;
}