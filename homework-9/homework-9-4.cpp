#include <iostream>

using namespace std;

// Напишіть програму, яка створює блукаючий вказівник.

int main()
{
    short* pShort = new short;
    *pShort = 5;
    cout << "pShort: " << *pShort << endl;
    delete pShort;

    double* pDouble = new double;
    *pDouble = 5555555;
    cout << "pDouble: " << *pDouble << endl;

    *pShort = 300;
    cout << "pShort: " << *pShort << endl;
    cout << "pDouble: " << *pDouble << endl;
    delete pDouble;

    return 0;
}