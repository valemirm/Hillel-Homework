#include <iostream>

using namespace std;

// Напишіть програму, яка призводить до витоку пам'яті.

int main()
{
    int* pInt = new int;
    *pInt = 10;
    cout << "Value of dereferenced pInt: " << *pInt << endl;
    cout << "No delete? \nReturning from main with memory leak..." << endl; 

    return 0;
}