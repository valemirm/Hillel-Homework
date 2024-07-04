#include <iostream>
using namespace std;

// 2. Напишіть програму, яка виведе задані аргументи командного рядка у зворотному порядку, відкинувши ім'я програми.

int main(int argc, char** argv)
{
    for (int i = argc-1; i > 0; --i)
    {
        cout << argv[i] << endl;
    }
    return 0;
}