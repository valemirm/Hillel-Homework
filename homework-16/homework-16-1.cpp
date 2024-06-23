#include <iostream>
using namespace std;

// // Напишіть програму, яка виробляє класи Саг (Легковий автомобіль) та Bus (Автобус) від класу Vehicle (Машина).
// Опишіть клас Vehicle як абстрактний тип даних із двома чистими віртуальними функціями.
// Класи Саг та Bus не повинні бути абстрактними.

class Vehicle
{
public:
    Vehicle() {}
    virtual ~Vehicle() {}
    virtual void VehiclePurpose() = 0;
    virtual void DriverLinceseCheck() = 0;
};

class Car : public Vehicle
{
public:
    Car() {}
    virtual ~Car() {}

    virtual void VehiclePurpose() { cout << "Car is used to traverse roads quickly for a certain number of people.\n"; }
    virtual void DriverLinceseCheck() { cout << "The minimum driving license category needed to start driving a car is A.\n"; }
};

class Bus : public Vehicle
{
public:
    Bus() {}
    virtual ~Bus() {}

    virtual void VehiclePurpose() { cout << "Bus is used to traverse roads quickly for quite large number of people.\n"; }
    virtual void DriverLinceseCheck() { cout << "The minimum driving license category needed to start driving a bus is D.\n"; }
};

int main()
{
    Vehicle *pVehicle = nullptr;
    bool fQuit = false;
    unsigned short choice = 0;
    while (!fQuit)
    {
        cout << "Please choose, which vehicle will be created: (1) Car, (2) Bus (0) Quit.\n";
        cin >> choice;
        switch (choice)
        {
        case 1:
            pVehicle = new Car;
            break;
        case 2:
            pVehicle = new Bus;
            break;
        case 0:
            fQuit = true;
            break;
        default:
            cout << "No such vehicle / or you have no driving license. Try again.\n";
            continue;
            break;
        }
        if (!fQuit)
        {
            cout << "Your vehicle information: \n";
            pVehicle->VehiclePurpose();
            pVehicle->DriverLinceseCheck();
            cout << "\n";
            delete pVehicle;
            pVehicle = nullptr;
        }
    }
    return 0;
}