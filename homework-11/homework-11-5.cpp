#include <iostream>
#include "SimpleCircle-2-3-4.hpp"
using namespace std;

// 5. Напишіть програму, яка створює два об'єкти класу SimpleCircle.
// Для створення одного об'єкта використовуйте конструктор, заданий за замовчуванням, а другому екземпляру при оголошенні надайте значення 9.
// З кожним із об'єктів використовуйте оператор інкремента та виведіть отримані значення на друк.
// Нарешті, надайте значення одного об'єкта іншому об'єкту та виведіть результат на друк.

int main()
{
    SimpleCircle circleOne;
    SimpleCircle circleTwo(9);

    cout << "Radius of circleOne is: " << circleOne.GetRadius() << endl;
    cout << "Radius of circleTwo is: " << circleTwo.GetRadius() << endl;
    cout << "Incrementing with post-increment...\n";
    circleOne++;
    circleTwo++;
    cout << "New radius of circleOne is: " << circleOne.GetRadius() << endl;
    cout << "New radius of circleTwo is: " << circleTwo.GetRadius() << endl;
    cout << "Incrementing with pre-increment...\n";
    ++circleOne;
    ++circleTwo;
    cout << "New radius of circleOne is: " << circleOne.GetRadius() << endl;
    cout << "New radius of circleTwo is: " << circleTwo.GetRadius() << endl;
    cout << "Assigning circleTwo to circleOne...\n";
    circleOne = circleTwo;
    cout << "Final radius of circleOne is: " << circleOne.GetRadius() << endl;
    cout << "Final radius of circleTwo is: " << circleTwo.GetRadius() << endl;

    return 0;
}