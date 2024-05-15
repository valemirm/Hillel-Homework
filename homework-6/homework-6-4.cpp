#include <iostream>
#include "Employee.hpp"

using namespace std;

// Напишіть програму з використанням класу Employee, яка створює два об'єкти класу Employee; встановлює дані-члени age, Years0fService та Salary, а потім виводить їх значення.

int main()
{
    Employee Michael;
    Employee Jim;
    Michael.setAge(41);
    Michael.setYearsOfService(7);
    Michael.setSalary(48000);
    Jim.setAge(27);
    Jim.setYearsOfService(2);
    Jim.setSalary(31000);
    cout << "Michael is " << Michael.getAge() << " years old." << endl;
    cout << "He works for company for " << Michael.getYearsOfService() << " years." << endl;
    cout << "His current annual salary is " << Michael.getSalary() << "$\n\n";
    cout << "Jim is " << Jim.getAge() << " years old." << endl;
    cout << "He works for company for " << Jim.getYearsOfService() << " years." << endl;
    cout << "His current annual salary is " << Jim.getSalary() << "$\n\n";

    return 0;
}