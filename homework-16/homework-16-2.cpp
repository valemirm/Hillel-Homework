#include <iostream>
using namespace std;

// Змініть програму з попередньої вправи таким чином, щоб клас Саг теж став ADT, і зробіть від нього три нові класи:
// SportsCar (Спортивний автомобіль), Wagon (Фургон) та Coupe (Двомісний автомобіль-купе).
// У класі Car повинна заміщатися одна з віртуальних функцій, оголошених у класі Vehicle, з викликом базового класу.

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
    virtual void VehiclePurpose() { "Cars are used to traverse roads at high speed.\n"; }
    virtual void DriverLinceseCheck() = 0;
    virtual void AverageSeatNumber() = 0;
};

class SportsCar : public Car
{
public:
    SportsCar() {}
    virtual ~SportsCar() {}
    virtual void VehiclePurpose() { cout << "Sports car are used to traverse roads at high speeds. They are mainly designed for races.\n"; }
    virtual void DriverLinceseCheck() { cout << "The minimum driving license category needed to start driving a sports car is B.\nBut to participate in races you need an extra qualification.\n"; }
    virtual void AverageSeatNumber() { cout << "The average number of seats in a sport car is in range from 2 to 4.\n"; }
};

class Wagon : public Car
{
public:
    Wagon() {}
    virtual ~Wagon() {}
    virtual void VehiclePurpose() { cout << "Wagons are used to traverse roads and to carry freight, which a smaller car often cannot carry.\n"; }
    virtual void DriverLinceseCheck() { cout << "The minimum driving license category needed to start driving a wagon is B.\n"; }
    virtual void AverageSeatNumber() { cout << "The average number of seats in a wagon is in range from 5 to 7.\n"; }
};

class Coupe : public Car
{
public:
    Coupe() {}
    virtual ~Coupe() {}
    virtual void VehiclePurpose() { cout << "Coupes are used to traverse roads. Those cars are considered luxurios.\n"; }
    virtual void DriverLinceseCheck() { cout << "The minimum driving license category needed to start driving a coupe is B.\n"; }
    virtual void AverageSeatNumber() { cout << "The average number of seats in a coupe is in range from 2 to 4, but more often only 2.\n"; }
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
    Car *pCar = nullptr;
    bool fQuit = false;
    unsigned short choice;
    while (!fQuit)
    {
        cout << "Please choose, which vehicle will be created: (1) Sports car, (2) Wagon, (3) Coupe, (4) Bus, (0) Quit.\n";
        cin >> choice;
        switch (choice)
        {
        case 0:
            fQuit = true;
            break;
        case 1:
            pCar = new SportsCar;
            break;
        case 2:
            pCar = new Wagon;
            break;
        case 3: 
            pCar = new Coupe;
            break;
        case 4:
            pVehicle = new Bus;
            break;
        default:
            cout << "No such vehicle / or you have no driving license. Try again.\n";
            continue;
            break;
        }
        if (!fQuit && pVehicle == nullptr)
        {
            cout << "Your car information: \n";
            pCar->VehiclePurpose();
            pCar->DriverLinceseCheck();
            pCar->AverageSeatNumber();
            cout << "\n";
        }
        else if(!fQuit && pVehicle != nullptr)
        {
            cout << "Your vehicle information: \n";
            pVehicle->VehiclePurpose();
            pVehicle->DriverLinceseCheck();
            cout << "\n";
        }
        delete pCar;
        delete pVehicle;
        pCar = nullptr;
        pVehicle = nullptr;
    }
    return 0;
}