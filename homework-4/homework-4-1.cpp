#include <iostream>
using namespace std;

int main()
{
    int a, b;
    cout << "Please enter two numbers.\n";
    cout << "a: ";
    cin >> a; 
    cout << "b: ";
    cin >> b;
    if (a >= b) {
        a = b;
        cout << "a is now equal to b.\n";
        cout << "a: " << a << endl;
        cout << "b: " << b << endl;
    } else {
        b = a;
        cout << "b is now equal to a.\n";
        cout << "a: " << a << endl;
        cout << "b: " << b << endl;
    }
    return 0;
}