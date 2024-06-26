#include <iostream>
using namespace std;

// Використовуючи програмний блок із вправи 1, напишіть коротку виконувальну програму, яка створює три об'єкти,
// а потім виводить значення їх змінних-членів та статичної змінної-члена класу.
// Потім послідовно видаляйте об'єкти та виводьте на екран значення статичної змінної-члена.

class Hotel
{
public:
    Hotel(int price) : roomPrice(price) { numOfRooms++; }
    ~Hotel() { numOfRooms--; }
    int GetPrice() const { return roomPrice; }
    void SetPrice(int price) { roomPrice = price; }
    static int numOfRooms;

private:
    int roomPrice;
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
        cout << "There are " << Hotel::numOfRooms << " room(s) ready for sale now!\n\n"; // облік наявних об'єктів
    }
    for (i = 0; i < MaxRooms; i++)
    {
        cout << "Selling a room #" << i+1 << endl; // повідомлення про видалення 
        delete SmallHotel[i];
        SmallHotel[i] = nullptr;
        cout << "There are " << Hotel::numOfRooms << " room(s) ready for sale now!\n\n"; // облік наявних об'єктів
    }

    return 0;
}