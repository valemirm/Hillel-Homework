#include <iostream>
using namespace std;

// Напишіть коротку програму, яка оголошує клас з однією звичайною змінною-членом та однією статичною змінною-членом.
// Створіть конструктор, який виконує ініціалізацію змінної-члена та збільшення статичної змінної-члена.
// Потім оголосіть деструктор, який зменшує на одиницю значення статичної змінної.

class Hotel
{
public:
    Hotel(int price) : roomPrice(price) { numOfRooms++; }
    ~Hotel() { numOfRooms--; }
    int GetPrice() { return roomPrice; }
    void SetPrice(int price) { roomPrice = price; }
    static int GetNum() { return numOfRooms; }

private:
    static int numOfRooms;
    int roomPrice;
};

int Hotel::numOfRooms = 0;

int main()
{
    const int MaxRooms = 10;
    int i;
    Hotel *SmallHotel[MaxRooms];
    cout << "Constructing rooms...\n\n";
    for (i = 0; i < MaxRooms; i++)
    {
        SmallHotel[i] = new Hotel((i+1)*100);
        cout << "Small hotel has " << SmallHotel[i]->GetNum() << " room(s) now.\n";
    }
    cout << "\nRooms are done! Now selling rooms...\n\n";
    for (i = 0; i < MaxRooms; i++)
    {
        cout << "Room #" << i+1 << " costs " << SmallHotel[i]->GetPrice() << " $ per one night.\n";
        delete SmallHotel[i];
        SmallHotel[i] = nullptr;
    }

    return 0;
}