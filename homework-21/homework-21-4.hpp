// Спроектуйте інтерфейси до класів до програми, що ви описали у вправі 3, яка стосується резервування готельних номерів.
#include <string>
using std::string;

class Hotel 
{
    public:
    Hotel () {}
    Hotel(string hotelName, string hotelLocation, unsigned int availableRooms) {}
    ~Hotel() {}
    virtual string GetName() const;                         // отримання назви готелю
    virtual string GetLocation() const;                     // отримання розташування готелю
    virtual string GetAvailableDate() const;                // отримання доступних дат для заселення
    virtual unsigned int GetRoomsAvailable() const;         // отримання кількість кімнат для заселення в доступні дати

    protected:
    string name;
    string location;
    unsigned int numOfRoomsAvailable;
    string availableDate;
};

class CheckDate
{
    public:
    bool CheckMeetingDate() const;      // перевірка чи є в певну дату зустріч/конференція
    bool CheckHotelDate() const;        // перевірка чи є в дату конференції доступні кімнати у готелі 
};

class Guest
{
    public:
    Guest() {}
    Guest(string guestName, string guestEMail) {}
    ~Guest() {}
    virtual string GetName() const;             // отримання імені гостя
    virtual void SetName(string nameSet);       // введення імені гостя
    virtual string GetEMail() const;            // отримання електронної пошти гостя
    virtual void SetEMail(string emailSet);     // введення електронної пошти гостя

    protected:
    string name;
    string email;
};

class Reservation
{
    public:
    Reservation(Guest guest, Hotel hotel, string checkIn, string checkOut) {}
    ~Reservation() {}
    virtual Guest GetGuest() const = 0;         // отримання даних гостя
    virtual Hotel GetHotel() const = 0;         // отримання даних готелю   
    virtual string GetCheckIn() const = 0;      // отримання дати заселення у готель
    virtual string GetCheckOut() const = 0;     // отримання дати виселення з готелю

    private:
    Guest InvitedGuest;
    Hotel HotelType;
    string checkInDate;
    string checkOutDate;
};