#include <iostream>
#include <string>
using namespace std;

//3. Успадкуйте новий виняток від виключення, отриманого у вправі 2. Змініть блок оператора catch таким чином, щоб у ньому відбувалася обробка як похідного, так і базового виключення.

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
    else 
        throw xException("Number might be too big!");
}