#include <iostream>
using namespace std;

// Організуйте цикл for, лічильник якого змінюється від 100 до 200 з кроком 2.

int main()
{
    int x;
    for (x = 100; x < 200; x += 2)
    {
        cout << x << endl;
    }
    cout << "Done! x = " << x << endl;
    return 0;
}