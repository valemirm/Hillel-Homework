#include <iostream>
#include <string>
using namespace std;

// 4. Змініть лістинг 15_1 таким чином, щоб клас String включав перевантажений оператор виведення (<<)

class String
{
public:
    String();
    String(const char *const);
    String(const String &);
    ~String();

    char &operator[](int offset);
    char operator[](int offset) const;
    String operator+(const String &);
    void operator+=(const String &);
    String &operator=(const String &);
    
    friend ostream& operator<<(ostream& os, const String& rhs); // перевантаження оператора виведення << 

    int GetLen() const { return itsLen; }
    const char *GetString() const { return itsString; }

private:
    String(int); 
    char *itsString;
    unsigned short itsLen;
};

ostream& operator<<(ostream& os, const String& rhs) // перевантаження оператора виведення << 
{
    os << rhs.itsString;
    return os;
}

String::String()
{
    itsString = new char[1];
    itsString[0] = '\0';
    itsLen = 0;
    // cout «"I tDefault string constructorl n";
    // ConstructorCount++;
}

String::String(int len)
{
    itsString = new char[len + 1];
    for (int i = 0; i <= len; i++)
   	 itsString[i] = '\0';
    itsLen = len;
    // cout << "\tString(int) constructor\n";
    // ConstructorCount++;
}

String::String(const char *const cString)
{
    itsLen = strlen(cString);
    itsString = new char[itsLen + 1];
    for (int i = 0; i < itsLen; i++)
   	 itsString[i] = cString[i];
    itsString[itsLen] = '\0';
    // cout << "\tString(char*) constructor\n";
    // ConstructorCount++;
}

String::String(const String &rhs)
{
    itsLen = rhs.GetLen();
    itsString = new char[itsLen + 1];
    for (int i = 0; i < itsLen; i++)
   	 itsString[i] = rhs[i];
    itsString[itsLen] = '\0';
    // cout << "\tString(String&) constructor\n";
    // ConstructorCount++;
}

String::~String()
{
    delete[] itsString;
    itsLen = 0;
    // cout <<"\tString destructor\n";
}

String &String::operator=(const String &rhs)
{
    if (this == &rhs)
   	 return *this;
    delete[] itsString;
    itsLen = rhs.GetLen();
    itsString = new char[itsLen + 1];
    for (int i = 0; i < itsLen; i++)
   	 itsString[i] = rhs[i];
    itsString[itsLen] = '\0';
    return *this;
    // cout <<"\tString operator=\n";
}

char &String::operator[](int offset)
{
    if (offset > itsLen)
   	 return itsString[itsLen - 1];
    else
   	 return itsString[offset];
}

char String::operator[](int offset) const
{
    if (offset > itsLen)
   	 return itsString[itsLen - 1];
    else
   	 return itsString[offset];
}

String String::operator+(const String &rhs)
{
    int totalLen = itsLen + rhs.GetLen();
    String temp(totalLen);
    int i, j;
    for (i = 0; i < itsLen; i++)
   	 temp[i] = itsString[i];
    for (j = 0; j < rhs.GetLen(); j++, i++)
   	 temp[i] = rhs[j];
    temp[totalLen] = '\0';
    return temp;
}

void String::operator+=(const String &rhs)
{
    unsigned short rhsLen = rhs.GetLen();
    unsigned short totalLen = itsLen + rhsLen;
    String temp(totalLen);
    int i, j;
    for (i = 0; i < itsLen; i++)
   	 temp[i] = itsString[i];
    for (j = 0; j < rhs.GetLen(); j++, i++)
   	 temp[i] = rhs[i - itsLen];
    temp[totalLen] = '\0';
    *this = temp;
}

// int String::ConstructorCount = 0;

