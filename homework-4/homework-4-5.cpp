#include <iostream>
using namespace std;

// Умова if присвоює значенню змінної с різницю між a та b. 
// Оскільки різниця між ними є 0, а 0 в логіці відповідає значенню false, то вираз з cout не виведеться і буде пуста консоль.

int main()
{
	int a = 1, b = 1, c;
	if (c = (a - b)) 
    	cout << "The value of c is: " << c;

	return 0;
}
