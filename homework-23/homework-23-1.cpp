#include <iostream>
using namespace std;

// 	1. Запишіть блок try та оператор catch для відстеження та обробки простого виключення.

class xException
{

};

void exceptionalFunc();

int main()
{

    try
    {
        exceptionalFunc();
    }
    catch(xException&)
    {
        cout << "Caught an exception!" << endl;
    }

    cout << "Ending programm!" << endl;
    
    return 0;
}

void exceptionalFunc()
{
    throw xException(); 
}