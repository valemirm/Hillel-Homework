#include <iostream>

using namespace std;

// Напишіть невелику програму і оголосіть змінну типу int і вказівник на цей тип.
// Збережіть адресу змінної в вказівнику. Використовуючи вказівник, надайте змінній якесь значення.

int main()
{
    int myVar = 0;
    int* pVar = &myVar;

    cout << "Value of myVar: " << myVar << endl;
    cout << "Value of pVar: " << pVar << endl;
    cout << "Value of dereferenced pointer *pVar assigned to myVar: " << *pVar << "\n\n";
    cout << "Changing values via pVar..." << "\n\n";
    *pVar = 23;
    cout << "New value of *pVar: " << *pVar << endl;
    cout << "New value of myVar: " << myVar << endl;

    return 0;
}