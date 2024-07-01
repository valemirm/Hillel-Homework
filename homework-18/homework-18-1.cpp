#include <iostream>
#include "String.hpp"


using namespace std;

// 1. Оголосіть клас Animal (Тварина), який містить змінну-член, яка є об'єктом класу String.

class Animal
{
    public:
    Animal(unsigned short age, String name) : itsAge(age), itsName(name) {}
    ~Animal() {}
    unsigned short GetAge() const { return itsAge; }
    void SetAge(unsigned short age) { itsAge = age; }
    String GetName() const { return itsName; }
    void SetName(String name) { itsName = name; }

    private:
    unsigned short itsAge;
    String itsName;
};

int main()
{
    
    return 0;
}