#include <iostream>
using namespace std;

// Створіть у програмі з вправи 3 вказівник на функцію-член для доступу до значення нестатичної змінної-члена
// і скористайтеся ним для виведення цих значень на друк.

class Hotel
{
public:
    Hotel(int price) : roomPrice(price) { numOfRooms++; }
    ~Hotel() { numOfRooms--; }
    int GetPrice() const { return roomPrice; }
    void SetPrice(int price) { roomPrice = price; }
    static int GetNum() { return numOfRooms; }

private:
    int roomPrice;
    static int numOfRooms;
};

int Hotel::numOfRooms = 0;

int main()
{
    const int MaxRooms = 3;
    Hotel* SmallHotel[MaxRooms];
    int i;
    int (*pFunc)() = 0; 
    pFunc = &Hotel::GetNum; // вказівник на функцію-член Hotel::GetNum()
    for (i = 0; i < MaxRooms; i++)
    {
        SmallHotel[i] = new Hotel((i+1)*100);
        cout << "Building a room #" << i+1 << endl;
        cout << "Price of Room #" << i+1 << " is " << SmallHotel[i]->GetPrice() << "$ \n";
        cout << "There are " << pFunc() << " room(s) ready for sale now!\n\n"; // використання вказівника на функцію-член 
    }
    for (i = 0; i < MaxRooms; i++)
    {
        cout << "Selling a room #" << i+1 << endl;
        delete SmallHotel[i];
        SmallHotel[i] = nullptr;
        cout << "There are " << pFunc() << " room(s) ready for sale now!\n\n";
    }

    return 0;
}