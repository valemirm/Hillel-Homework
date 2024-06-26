#include <iostream>
using namespace std;

// Змініть програму з вправи 2 таким чином, щоб доступ до статичної змінної-члена здійснювався за допомогою статичної функції-члена.
// Зробіть статичну змінну-член закритою.

class Hotel
{
public:
    Hotel(int price) : roomPrice(price) { numOfRooms++; }
    ~Hotel() { numOfRooms--; }
    int GetPrice() const { return roomPrice; }
    void SetPrice(int price) { roomPrice = price; }
    static int GetNum() { return numOfRooms; } // статична функція-член 

private:
    int roomPrice;
    static int numOfRooms; // в приватній секції 
};

int Hotel::numOfRooms = 0;

int main()
{
    const int MaxRooms = 3;
    Hotel* SmallHotel[MaxRooms];
    int i;
    for (i = 0; i < MaxRooms; i++)
    {
        SmallHotel[i] = new Hotel((i+1)*100);
        cout << "Building a room #" << i+1 << endl;
        cout << "Price of Room #" << i+1 << " is " << SmallHotel[i]->GetPrice() << "$ \n";
        cout << "There are " << Hotel::GetNum() << " room(s) ready for sale now!\n\n"; // використання функції-члена, замість звернення до статичної змінної напряму
    }
    for (i = 0; i < MaxRooms; i++)
    {
        cout << "Selling a room #" << i+1 << endl;
        delete SmallHotel[i];
        SmallHotel[i] = nullptr;
        cout << "There are " << Hotel::GetNum() << " room(s) ready for sale now!\n\n";
    }

    return 0;
}