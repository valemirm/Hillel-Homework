// 1. Перевантажте оператори преінкремента та постінкремента для використання у вашому класі SimpleCircle зі змінною itsRadius.

class SimpleCircle
{
    public:
    SimpleCircle();
    SimpleCircle(int valRadius); 
    ~SimpleCircle() {}

    void SetRadius(int radius) { Radius = radius; }
    int GetRadius() const { return Radius; }

    SimpleCircle& operator++(); 
    SimpleCircle operator++(int); 

    private: 
    int Radius;
};

SimpleCircle::SimpleCircle() : Radius(5)
{
}

SimpleCircle::SimpleCircle(int valRadius)
{
    Radius = valRadius;
}

SimpleCircle& SimpleCircle::operator++() 
{
    ++Radius;
    return *this;
}

SimpleCircle SimpleCircle::operator++(int) 
{
    SimpleCircle temp(*this);
    Radius++;
    return temp;
}