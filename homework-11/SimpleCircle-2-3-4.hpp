// 2. Змініть SimpleCircle таким чином, щоб зберігати itsRadius в динамічній області пам'яті і фіксувати існуючі методи.

// 3. Створіть у класі SimpleCircle конструктор-копіювальник.

// 4. Перевантажте у класі SimpleCircle оператор присвоєння.

class SimpleCircle
{
    public:
    SimpleCircle();
    SimpleCircle(int valRadius); // змінено згідно Завдання 2 
    SimpleCircle(const SimpleCircle& rhs); // Завдання 3
    ~SimpleCircle(); // змінено згідно Завдання 2

    void SetRadius(int radius) { *Radius = radius; } // змінено згідно Завдання 2
    int GetRadius() const { return *Radius; } // змінено згідно Завдання 2

    SimpleCircle& operator++(); 
    SimpleCircle operator++(int); 
    SimpleCircle& operator=(const SimpleCircle& rhs); // Завдання 4 

    private: 
    int* Radius; // // змінено згідно Завдання 2
};

SimpleCircle::SimpleCircle() // змінено згідно Завдання 2
{
    Radius = new int;
    *Radius = 5;
}

SimpleCircle::SimpleCircle(int valRadius) // змінено згідно Завдання 2
{
    Radius = new int;
    *Radius = valRadius;
}

SimpleCircle::SimpleCircle(const SimpleCircle& rhs) // Завдання 3
{
    Radius = new int;
    *Radius = *(rhs.Radius);
}

SimpleCircle& SimpleCircle::operator=(const SimpleCircle& rhs) // Завдання 4 
{
    if (this == &rhs)
        return *this;
    else 
        delete Radius;
        Radius = new int;
        *Radius = *(rhs.Radius);
        return *this;
}

SimpleCircle::~SimpleCircle() // змінено згідно Завдання 2
{
    delete Radius;
    Radius = nullptr;
}

SimpleCircle& SimpleCircle::operator++() // змінено згідно Завдання 2
{
    ++(*Radius);
    return *this;
}

SimpleCircle SimpleCircle::operator++(int) // змінено згідно Завдання 2
{
    SimpleCircle temp(*this);
    (*Radius)++;
    return temp;
}