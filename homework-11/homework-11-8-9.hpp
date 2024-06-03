// 8. Запишіть оголошення класу Square, успадкованого від класу Rectangle, який, у свою чергу, виготовлений від класу Shape.

class Shape {};

class Rectangle : public Shape {};

class Square : public Rectangle {};

// 9. Припустимо, що у попередньому прикладі об'єкт класу Shape не використовує параметри, об'єкт класу Rectangle приймає два параметри (length і width),
// а об'єкт класу Square - один параметр (length); запишіть конструктор класу Square.

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

class Square : public Rectangle {
    public:

    Square(int initialLength) : Rectangle(initialLength, initialLength) {}
    ~Square() {}
};

