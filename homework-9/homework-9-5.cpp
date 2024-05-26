#include <iostream>

using namespace std;

// Виправте програму з вправи 4, щоб виправити блукаючий вказівник.

int main()
{
    short* pShort = new short;
    *pShort = 5;
    cout << "pShort: " << *pShort << endl;
    delete pShort;
    pShort = new short;

    double* pDouble = new double;
    *pDouble = 5555555;
    cout << "pDouble: " << *pDouble << endl;

    *pShort = 300;
    cout << "pShort: " << *pShort << endl;
    cout << "pDouble: " << *pDouble << endl;
    delete pShort;
    delete pDouble;

    return 0;
}