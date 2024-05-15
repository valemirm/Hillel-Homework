#include <iostream>
using namespace std;

// 1. Напишіть програму, яка запитує число та показник ступеня.
// Напишіть рекурсивну функцію, яка зводить число в ступінь шляхом багаторазового множення числа на себе, тобто
// якщо число дорівнює 2, а показник ступеня дорівнює 4, то ця функція має повернути число 16.

int powerCalculus(int num, int power);

int main()
{
    int num, power, result;
    cout << "Please enter your number: ";
    cin >> num;
    cout << "Please enter the power to calculate to: ";
    cin >> power;
    result = powerCalculus(num, power);
    cout << num << " to power of " << power << " equals: " << result;
    return 0;
}

int powerCalculus(int num, int power)
{   
    if (power == 0)
    {
        return 1;
    } 
    else 
    {
        return num * powerCalculus(num, power - 1);
    } 
}