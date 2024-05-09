#include <iostream>
using namespace std;

unsigned long int Perimeter (unsigned short int length, unsigned short int width); 
// Завдання 1: прототип функції Perimeter

unsigned long int Perimeter (unsigned short int length, unsigned short int width) 
{
    return 2*(length + width);
}
// Завдання 2: визначення функції Perimeter, що приймає довжину та ширину та повертає периметр