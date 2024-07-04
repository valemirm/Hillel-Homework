#include <iostream>
#include <fstream>

using namespace std;


// 1. Напишіть програму, яка зчитує ім'я файлу як аргумент командного рядка і відкриває файл для читання.
// Розробіть алгоритм аналізу всіх символів, що зберігаються у файлі, і виведіть на екран лише текстові символи та розділові знаки (пропускайте всі недруковані символи).
// Перед завершенням програми закрийте файл.

int main(int argc, char** argv)
{
    if (argc != 2)
    {
        cout << "Error, please enter only one file name!" << endl;
        return (1);
    }

    ifstream printFile(argv[1]);
    if (!printFile)
    {
        cout << "Cannot open a file: " << argv[1] << endl;
        return (1);
    }
    char ch;
    while (printFile.get(ch))
    {
        if (isprint(ch) || isspace(ch))
        {
            cout << ch; 
        }
    }

    printFile.close();
    return 0;
}

// test.txt використовувався для перевірки 