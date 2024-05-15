#include <iostream>
#include <cmath>
using namespace std;

// На основі програми з вправи 3 створіть метод класу Employee, який повідомляє, скільки тисяч доларів заробляє службовець, округляючи відповідь до 10 доларів.

class Employee
{
public:
    unsigned short getAge() const;
    void setAge(unsigned short Age);

    unsigned short getYearsOfService() const;
    void setYearsOfService(unsigned short Years);

    unsigned int getSalary() const;
    void setSalary(unsigned int Salary);

    double roundSalary();

private:
    unsigned short age;
    unsigned short yearsOfService;
    unsigned int salary;
};

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

double Employee::roundSalary()
{
    double salaryThousands = salary / 1000.0;
    return round(salaryThousands * 100.0) / 100.0;
}

int main()
{
    Employee Michael;
    Michael.setSalary(42536);
    cout << "Michael's salary not rounded: " << Michael.getSalary() << " $" << endl;
    cout << "Michael's salary rounded: " << Michael.roundSalary() << " thousand $" << endl;
    return 0;
} 