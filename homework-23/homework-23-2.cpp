#include <iostream>
#include <string>
using namespace std;

// 	2. Додайте у виняток, отриманий у вправі 1, змінну-член та метод доступу та використовуйте їх у блоці оператора catch.

class xException
{
    public:
    xException(string message) : errorMessage(message) {}
    ~xException() {}
    string getError() const { return errorMessage; }
    private:
    string errorMessage;
};

void exceptionalFunc();

int main()
{

    try
    {
        exceptionalFunc();
    }
    catch(xException& xMinor)
    {
        cout << "Caught an exception: " << xMinor.getError() << endl;
    }

    cout << "Ending programm!" << endl;
    
    return 0;
}

void exceptionalFunc()
{
    throw xException("Minor error!"); 
}