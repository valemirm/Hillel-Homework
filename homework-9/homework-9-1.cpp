#include <iostream>

using namespace std;

//  Напишіть програму, яка оголошує змінну типу int, посилання на значення типу int і вказівник на значення типу int.
//  Використовуйте вказівник та посилання для керування значенням змінної типу int.

int main()
{
    int myVar = 1;
    int& rVar = myVar;
    int* pVar = &myVar;
    
    cout << "Value of variable myVar: " << myVar << endl;
    cout << "Value of dereferened pointer pVar: " << *pVar << endl;
    cout << "Value of reference to myVar named rVar: " << rVar << endl;
    cout << "\nChanging values using pointer...\n\n";
    *pVar = 8;
    cout << "Value of variable myVar: " << myVar << endl;
    cout << "Value of dereferened pointer pVar: " << *pVar << endl;
    cout << "Value of reference to myVar named rVar: " << rVar << endl;
    cout << "\nChanging values using reference...\n\n";
    rVar = 16;
    cout << "Value of variable myVar: " << myVar << endl;
    cout << "Value of dereferened pointer pVar: " << *pVar << endl;
    cout << "Value of reference to myVar named rVar: " << rVar << endl;

    return 0;
}