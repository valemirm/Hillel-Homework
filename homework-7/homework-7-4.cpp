#include <iostream>
using namespace std;

// Організуйте цикл while, лічильник якого змінюється від 100 до 200 з кроком 2.

int main()
{
    int x = 100;
    while (x < 200)
    {
        cout << x << endl;
        x += 2;
    }
    cout << "Done! x = " << x << endl;
    return 0;
}