#include <iostream>

using namespace std;

// 2. Напишіть програму, яка пропонує користувачеві ввести повне ім'я з наступним виведенням цього імені на екран.

int main()
{
    char Name[255];
    cout << "Enter your name: \n";
    cin.get(Name, 255);
    cout << "Hello " << Name << endl;

    return 0;
}