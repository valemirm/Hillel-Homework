#include <iostream>
using namespace std;

// Організуйте цикл do… while, лічильник якого змінюється від 100 до 200 з кроком 2.

int main()
{
    int x = 100;
    do
    {
        cout << x << endl;
        x += 2;
    } while (x < 200);
    cout << "Done! x = " << x << endl;
    return 0;
}