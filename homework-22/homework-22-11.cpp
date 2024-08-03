// 	11. Змініть код із вправи 10 таким чином, щоб для відображення даних про кожного студента використовувався об'єкт функції.

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Student
{
public:
    Student();
    Student(const string &name, int age);
    Student(const Student &rhs);
    ~Student();

    void SetName(const string &name);
    string GetName() const;
    void SetAge(int age);
    int GetAge() const;
    Student &operator=(const Student &rhs);

    Student* GetNext() const;
    void SetNext(Student* nextNode);

private:
    string itsName;
    int itsAge;
    Student* next; 
};

Student::Student()
    : itsName("New Student"), itsAge(16), next(nullptr)
{
}

Student::Student(const string &name, int age)
    : itsName(name), itsAge(age), next(nullptr)
{
}

Student::Student(const Student &rhs)
    : itsName(rhs.GetName()), itsAge(rhs.GetAge()), next(nullptr)
{
}

Student::~Student()
{
}

void Student::SetName(const string &name)
{
    itsName = name;
}

string Student::GetName() const
{
    return itsName;
}

void Student::SetAge(int age)
{
    itsAge = age;
}

int Student::GetAge() const
{
    return itsAge;
}

Student &Student::operator=(const Student &rhs)
{
    if (this != &rhs)
    {
        itsName = rhs.GetName();
        itsAge = rhs.GetAge();
    }
    return *this;
}

Student* Student::GetNext() const
{
    return next;
}

void Student::SetNext(Student* nextNode)
{
    next = nextNode;
}

ostream& operator<<(ostream &os, const Student &rhs)
{
    os << rhs.GetName() << " is " << rhs.GetAge() << " years old";
    return os;
}


class SchoolClass
{
public:
    SchoolClass();
    ~SchoolClass();

    void push_back(const Student &student);
    void operator()(const Student &student) const {
        cout << student << endl;
    } // замість print 
    void increase_ages();

protected:
    Student* head;
    Student* tail;
    int count;
};

SchoolClass::SchoolClass()
    : head(nullptr), tail(nullptr), count(0)
{
}

SchoolClass::~SchoolClass()
{
    Student* current = head;
    while (current != nullptr)
    {
        Student* next = current->GetNext();
        delete current;
        current = next;
    }
}

void SchoolClass::push_back(const Student &student)
{
    Student* newStudent = new Student(student);
    if (tail != nullptr)
    {
        tail->SetNext(newStudent);
    }
    tail = newStudent;
    if (head == nullptr)
    {
        head = tail;
    }
    ++count;
}

void SchoolClass::increase_ages()
{
    Student* current = head;
    while (current != nullptr)
    {
        current->SetAge(current->GetAge() + 1);
        current = current->GetNext();
    }
}

int main()
{
    Student Harry;
    Student Sally("Sally", 15);
    Student Bill("Bill", 17);
    Student Peter("Peter", 16);

    SchoolClass schoolClass;

    schoolClass.push_back(Harry);
    schoolClass.push_back(Sally);
    schoolClass.push_back(Bill);
    schoolClass.push_back(Peter);

    cout << "SchoolClass:\n";
    schoolClass(Harry);
    schoolClass(Sally);
    schoolClass(Bill);
    schoolClass(Peter);


    schoolClass.increase_ages();

    cout << "SchoolClass after increasing age:\n";
    schoolClass(Harry);
    schoolClass(Sally);
    schoolClass(Bill);
    schoolClass(Peter);

    return 0;
}

template <class T>
void ShowVector(const vector<T> &v); 

template <class T>
void ShowVector(const vector<T> &v)
{
	cout << "max_size() = " << v.max_size();
	cout << "\tsize() = " << v.size();
	cout << "\tcapacity() = " << v.capacity();
	cout << "\t " << (v.empty() ? "empty" : "not empty");
	cout << "\n";
	for (int i = 0; i < v.size(); ++i)
		cout << v[i] << "\n";
	cout << endl;
}


