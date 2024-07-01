#include <iostream>
#include <string>

using namespace std;

// 6. Виправте лістинг, наведений у вправі 5, та відкомпілюйте його.

class Animal;

void setValue(Animal &, int);   

class Animal
{
public:
	int GetWeight() const { return itsWeight; }
	int GetAge() const { return itsAge; }

    friend void setValue(Animal &, int);   // оголошення дружньої функції у оголошенні класу 

private:
	int itsWeight;
	int itsAge;
};

void setValue(Animal &theAnimal, int theWeight)
{
	theAnimal.itsWeight = theWeight;
}

int main()
{
	Animal peppy;
	setValue(peppy, 5);
	return 0;
}