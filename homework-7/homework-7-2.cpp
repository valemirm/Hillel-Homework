#include <iostream>
using namespace std;

// Створіть вкладений цикл for, що заповнює нулями масив розміром 10×10.

int main()
{
    for (int x = 0; x < 10; x++)
    {
        for (int y = 0; y < 10; y++)
        {
            cout << "0 ";
        }
        cout << "\n";
    }
    return 0;
}
   
