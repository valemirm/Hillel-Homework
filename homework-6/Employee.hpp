// Мій компілятор не побачив створений Employee.cpp, у якому містились визначення методів, тому переніс їх сюди. 

class Employee
{
public:
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