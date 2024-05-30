// 1. Представте оголошення класу SimpleCircle (просте коло) з єдиною зміною-членом його Radius (радіус).
// У класі повинні використовуватися конструктор та деструктор, задані за умовчанням, а також метод встановлення радіусу.

class SimpleCircle
{
    public:
    SimpleCircle();
    SimpleCircle(int valRadius); // Додано згідно 3 пункту завдання
    ~SimpleCircle() {}

    void SetRadius(int radius) { Radius = radius; }
    int GetRadius() const { return Radius; }

    private: 
    int Radius;
};

// 2. Використовуючи клас, створений у вправі 1, за допомогою конструктора, заданого за замовчуванням, ініціалізуйте змінну його Radius значенням 5.

SimpleCircle::SimpleCircle() : Radius(5)
{
}

// 3. Додайте до класу новий конструктор, який надає значення свого параметра змінної його Radius.

SimpleCircle::SimpleCircle(int valRadius)
{
    Radius = valRadius;
}