#include <iostream>

using namespace std;

// Виправте програму із вправи 8.

class Cat
{
public:
    Cat(int age) { itsAge = age; }
    ~Cat() {}
    int GetAge() const { return itsAge; }

private:
    int itsAge;
};

Cat* MakeCat(int age);

int main()
{
    int age = 7;
    Cat* Boots = MakeCat(age);
    cout << "Boots is: " << Boots->GetAge() << " years old" << endl;
    delete Boots;

    return 0;
}

Cat* MakeCat(int age)
{
    Cat* pCat = new Cat(age);
    return pCat;
}