#include <iostream>
using namespace std;

// Змініть клас Employee так, щоб можна було ініціалізувати дані-члени age, YearsofService і Salary у процесі "створення" службовця.

class Employee
{
public:
    Employee(unsigned short initialAge, unsigned short initialYears, unsigned int initialSalary);
    ~Employee();

    unsigned short getAge() const;
    void setAge(unsigned short Age);

    unsigned short getYearsOfService() const;
    void setYearsOfService(unsigned short Years);

    unsigned int getSalary() const;
    void setSalary(unsigned int Salary);

private:
    unsigned short age;
    unsigned short yearsOfService;
    unsigned int salary;
};

Employee::Employee(unsigned short initialAge, unsigned short initialYears, unsigned int initialSalary)
{
    age = initialAge;
    yearsOfService = initialYears;
    salary = initialSalary;
}

Employee::~Employee() {}

unsigned short Employee::getAge() const
{
    return age;
}

void Employee::setAge(unsigned short Age)
{
    age = Age;
}

unsigned short Employee::getYearsOfService() const
{
    return yearsOfService;
}

void Employee::setYearsOfService(unsigned short Years)
{
    yearsOfService = Years;
}

unsigned int Employee::getSalary() const
{
    return salary;
}

void Employee::setSalary(unsigned int Salary)
{
    salary = Salary;
}

int main()
{
    Employee Michael(41, 3, 45124);
    cout << "Michael's age: " << Michael.getAge() << endl;
    cout << "Michael's years of service: " << Michael.getYearsOfService() << endl;
    cout << "Michael's annual salary: " << Michael.getSalary() << endl;
    return 0;
}