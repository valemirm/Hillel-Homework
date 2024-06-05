class Shape {};

class Rectangle : public Shape {
    public:

    Rectangle() : length(1), width(1) {}
    Rectangle(int initialLength = 1, int initialWidth = 1) : length(initialLength), width(initialWidth) {}
    ~Rectangle() {}
    
    void SetLength(int lengthChange) { length = lengthChange; }
    int GetLength() const { return length; }
    void SetWidth(int widthChange) { width = widthChange; }
    int GetWidth() const { return width; }

    protected:
    int length;

    private:
    int width;
};

// 1. Запишіть віртуальний конструктор-копіювальник для класу Square.

class Square : public Rectangle {
    public:

    Square(int initialLength) : Rectangle(initialLength, initialLength) {}
    virtual ~Square() {}

    virtual Square* clone() const { return new Square(*this); }
};