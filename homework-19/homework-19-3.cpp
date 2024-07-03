#include <iostream>

using namespace std;

// 3. Перепишіть лістинг 16.9, відмовившись від використання методів putback() та ignore().

int main()
{
    char ch;
    cout << "Enter a phrase: ";
    
    while (cin.get(ch)) 
    {
        if (ch == '!')
        {
            cout << '$'; 
        }
        else if (ch == '#')
        {
            while (cin.peek() == '#')
            {
                cin.get(ch); 
            }
        }
        else
        {
            cout << ch; 
        }
        if (ch == '\n') 
        {
            break;
        }
    }
    return 0;
}

// int main()
// {
//     char ch;
//     cout << "enter a phrase: ";
//     while (cin.get(ch))
//     {
//         if (ch == '!')
//             cin.putback('$');
//         else
//             cout << ch;
//         while (cin.peek() == '#')
//             cin.ignore(1, '#');
//     }
//     return 0;
// }