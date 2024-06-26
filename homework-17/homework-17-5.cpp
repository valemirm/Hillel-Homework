#include <iostream>
using namespace std;

// Додайте дві додаткові змінні-члени до класу з попередніх вправ. Додайте методи доступу, які повертають значення всіх цих змінних.
// Усі функції-члени повинні повертати значення однакового типу та мати однакову сигнатуру.
// Для доступу до цих методів використовуйте вказівник на функцію члена.

class Hotel
{
public:
    Hotel(int price, int size, int beds) : roomPrice(price), roomSize(size), howManyBeds(beds) { numOfRooms++; } // оновлений конструктор
    ~Hotel() { numOfRooms--; }
    int GetPrice() { return roomPrice; }
    void SetPrice(int price) { roomPrice = price; }
    int GetSize() { return roomSize; }              // геттер для roomSize
    void SetSize(int size) { roomSize = size; }     // сеттер для roomSize
    int GetBeds() { return howManyBeds; }           // геттер для howManyBeds
    void SetBeds(bool beds) { howManyBeds = beds; } // сеттер для howManyBeds
    static int GetNum() { return numOfRooms; }

private:
    int roomPrice;
    int roomSize;    // нова змінна
    int howManyBeds; // нова змінна
    static int numOfRooms;
};

int Hotel::numOfRooms = 0;

int main()
{
    bool fQuit = false;
    Hotel *SmallHotel = new Hotel(1000, 100, 1);
    int (Hotel::*pFunc)() = 0;
    int choice;
    while(!fQuit)
    {
        cout << "Welcome to Small Hotel! We currently have only " << Hotel::GetNum() << " room available. Which information do you need?\n";
        cout << "(1) Price, (2) Size, (3) How many beds is there, (0) I am not interested, bye!\n";
        cin >> choice;
        switch(choice)
        {
            case 1:
            pFunc = &Hotel::GetPrice;
            cout << "The price of this room is " << (SmallHotel->*pFunc)() << "$\n";
            break;
            case 2:
            pFunc = &Hotel::GetSize;
            cout << "The size of this room is " << (SmallHotel->*pFunc)() << " square meters.\n";
            break;
            case 3:
            pFunc = &Hotel::GetBeds;
            cout << "This room has " << (SmallHotel->*pFunc)() << " beds.\n";
            break;
            default:
            cout << "Goodbye! Please come again!\n";
            fQuit = true;
            break;
        }
    }
    delete SmallHotel;
    SmallHotel = nullptr;
    pFunc = 0;

    return 0;
}