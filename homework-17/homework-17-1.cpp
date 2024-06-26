#include <iostream>

// Напишіть коротку програму, яка оголошує клас з однією звичайною змінною-членом та однією статичною змінною-членом.
// Створіть конструктор, який виконує ініціалізацію змінної-члена та збільшення статичної змінної-члена.
// Потім оголосіть деструктор, який зменшує на одиницю значення статичної змінної.

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

    return 0;
}