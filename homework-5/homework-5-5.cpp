#include <iostream>
using namespace std;

// Напишіть функцію, яка приймає два параметри типу unsigned short int і повертає результат ділення першого параметра на другий.
// Функція не повинна виконувати операцію поділу, якщо друге число дорівнює нулю, але в цьому випадку вона має повернути значення -1.

float divisionOfTwoNumbers (unsigned short int firstNum, unsigned short int secondNum);

int main()
{
    return 0;
}

float divisionOfTwoNumbers (unsigned short int firstNum, unsigned short int secondNum)
{
    if (secondNum != 0)
    {
        return static_cast<float>(firstNum)/secondNum;
    } else {
        return -1.0f;
    }
}

