#include <iostream>

using namespace std; 

// 1. Напишіть програму, яка використовує чотири стандартні об'єкти класу iostream - cin, cout, cerr і clog.

int main()
{
    int num;
    clog << "Start of program..." << endl;
    cout << "Please enter a number: ";
    cin >> num;
    cerr << "Error occured, exiting." << endl;
    clog << "End of program..." << endl;

    return 0;
}