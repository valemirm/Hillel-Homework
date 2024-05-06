#include <iostream>
using namespace std;

int main()
{
int a, b, c;
cout << "Please enter three numbers. \n";
cout << "a: ";
cin >> a;
cout << "\nb: ";
cin >> b;
cout << "\nc: ";
cin >> c;

// При послідовному введенні 20, 10 та 50 очікувалось отримати вираз блоку else. 
// Але у блоці if значенню с присвоюється різниця між а та b, що перебиває введене значення с, отже завжди буде виводитись вираз а мінус b дорівнює с.
// Для того щоб порівняти введені значення треба поставити == замість = у строці 19, тоді програма буде дійсно перевіряти, чи різниця між а та b дорівнює с.

if (c = (a - b))
{
     cout << "\na: ";
     cout << a;
     cout << " minus b: ";
     cout << b;
     cout << " equals c: ";
     cout << c << endl;
} else
     cout << "a - b does not equal c: " << endl;

return 0;
}
