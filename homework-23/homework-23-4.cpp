#include <iostream>
#include <string>
using namespace std;

// 4. Змініть код вправи 3, щоб отримати трирівневий виклик функції.

class xException
{
    public:
    xException(string message) : errorMessage(message) {}
    virtual ~xException() {}
    string getError() const { return errorMessage; }
    virtual void printError() const { cout << "Caught a general error: " << xException::errorMessage << endl; }
    protected:
    string errorMessage;
};

class xMajor : public xException
{
    public: 
    xMajor(string message) : xException(message) {}
    ~xMajor() {}
    virtual void printError() const { cout << "Caught a major error: " << xMajor::errorMessage << endl; }
};

class xMinor : public xException
{
    public: 
    xMinor(string message) : xException(message) {}
    virtual ~xMinor() {}
    virtual void printError() const { cout << "Caught a minor error: " << xMinor::errorMessage << endl; }
};

void exceptionalFunc();

int main()
{

    try
    {
        exceptionalFunc();
    }
    catch(xMajor& xMajor)
    {
        xMajor.printError();
    }
    catch(xMinor& xMinor)
    {
        xMinor.printError();
    }
    catch(xException& xGeneral)
    {
        xGeneral.printError();
    }
    
    cout << "\nEnding programm!" << endl;
    
    return 0;
}

void exceptionalFunc()
{
    int someNum = 0;
    cout << "Type in a number: ";
    cin >> someNum;
    if(someNum < 0)
        throw xMajor("Number is negative!");
    else if(someNum == 0)
        throw xMinor("Number is equal 0!"); 
    else 
        throw xException("Number might be too big!");
}