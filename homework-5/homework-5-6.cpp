#include <iostream>
using namespace std;

// Напишіть програму, яка запитує у користувача два числа і викликає функцію, записану при виконанні вправи 5.
// Виведіть результат або повідомлення про помилку, якщо функція поверне значення, що дорівнює - 1.

float divisionOfTwoNumbers (unsigned short int firstNum, unsigned short int secondNum);

int main()
{
    unsigned short int firstNum, secondNum;
    float result;
    cout << "Please enter your first number: ";
    cin >> firstNum;
    cout << "Now enter your second number: ";
    cin >> secondNum;
    result = divisionOfTwoNumbers(firstNum, secondNum);
    if (result == -1.0f)
    {
        cout << "Error! The second number cannot be 0!" << endl;
    } else {
        cout << "The result of division is: " << result << endl;
    }
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
