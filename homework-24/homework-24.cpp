#include <string>
#include <iostream>
using namespace std;

// front() – Повертає значення першого елемента в списку.  
// back() – Повертає значення останнього елемента в списку.
// push_front() – додає новий елемент на початку списку.
// push_back() – додає новий елемент у кінець списку.
// pop_front() – видаляє перший елемент списку та зменшує розмір списку на 1.
// pop_back() – видаляє останній елемент списку та зменшує розмір списку на 1.
// insert() – вставляє нові елементи в список перед елементом у вказаній позиції.
// size() – повертає кількість елементів у списку.
// begin() – функція begin() повертає ітератор, що вказує на перший елемент списку.
// end() – функція end() повертає ітератор, що вказує на теоретичний останній елемент, який слідує за останнім елементом.

// print() - виводить на екран усі елементи списку.

template <typename T>
class ListPlus
{
    public:
    ListPlus() : head(nullptr), tail(nullptr), count(0) {}
    ~ListPlus();


    T front() const;
    T back() const;
    void push_front(T newVal);
    void push_back(T newVal);
    void pop_front();
    void pop_back();
    void insert(int position, T newVal);
    int size() const { return count; }
    
    T* begin() const { return head ? &(head->value) : nullptr; }
    T* end() const { return nullptr; }
    void print();

    private:
    class CellPlus
    {
        public:
        CellPlus(T val, CellPlus* cell = 0) : value(val), next(cell) {}
        ~CellPlus() {}
        T value;
        CellPlus* next;
    };
    CellPlus* head;
    CellPlus* tail;
    int count;

    
    class xError
    {
        public:
        xError(string message) : errorMessage(message) {}
        ~xError() {}
        void printError() const { cout << "Error occured: " << xError.errorMessage << endl; }
        private: 
        string errorMessage;
    };
}; 

template <typename T>
ListPlus<T>::~ListPlus()
{
    CellPlus* current = head;
    while(current != nullptr)
    {
        CellPlus* next = current->next;
        delete current;
        current = next;
    }
}

template <typename T>
T ListPlus<T>::front() const
{
    if (head == nullptr)
    {
        throw xError("List is empty");
    }
    return head->value;
}

template <typename T>
T ListPlus<T>::back() const
{
    if (tail == nullptr)
    {
        throw xError("List is empty");
    } 
    return tail->value;
}

template <typename T>
void ListPlus<T>::push_front(T newVal)
{
    CellPlus* newCell = new CellPlus(newVal, head);
    head = newCell;
    if (tail == nullptr)
    {
        tail = head;
    }
    ++count;
}

template <typename T>
void ListPlus<T>::push_back(T newVal)
{
    CellPlus* newCell = new CellPlus(newVal, nullptr);
    if (tail != nullptr)
    {
        tail->next = newCell;
    }
    tail = newCell;
    if (head == nullptr)
    {
        head = tail;
    }
    ++count;
}

template <typename T>
void ListPlus<T>::pop_front()
{
    if (head == nullptr)
    {
        throw xError("List is empty, nothing to delete!");
    }
    CellPlus* temp = head;
    head = head->next;
    if (head == nullptr)
    {
        tail = nullptr;
    }
    delete temp;
    --count;
}

template <typename T>
void ListPlus<T>::pop_back()
{
    if (tail == nullptr)
    {
        throw xError("List is empty, nothing to delete!");
    }
    if (tail == head)
    {
        delete tail;
        head = nullptr;
        tail = nullptr;
    }
    else
    {
        CellPlus* current = head;
        while (current->next != tail)
        {
            current = current->next;
        }
        delete tail;
        tail = current;
        tail->next = nullptr;
    }
    --count;
}

template <typename T>
void ListPlus<T>::insert(int position, T newVal)
{
    if (position < 0 || position > count)
    {
        throw xError("Wrong position number!");
    }
    if (position == 0)
    {
        push_front(newVal);
        return;
    }
    CellPlus* newCell = new CellPlus(newVal);
    CellPlus* current = head;
    for (int i = 0; i < position - 1; ++i)
    {
        current = current->next;
    }

    newCell->next = current->next;
    current->next = newCell;

    if (newCell->next == nullptr)
    {
        tail = newCell;
    }
    ++count;
}

template <typename T>
void ListPlus<T>::print()
{
    CellPlus* current = head;
    while (current != nullptr)
    {
        cout << current->value << " ";
        current = current->next;
    }
    cout << "\n";
}

int main()
{
    ListPlus<int> Test;

    cout << "Current values of the list are: " << endl;
    Test.print();

    Test.push_front(10);
    Test.push_back(20);

    cout << "After adding two values: " << endl;
    Test.print();

    Test.insert(1, 12);
    Test.insert(2, 14);
    Test.insert(3, 16);
    Test.insert(4, 18);

    cout << "After adding another four values: " << endl;
    Test.print();   

    cout << "Current list size is: " << Test.size() << endl;
    cout << "Current first member is: " << *Test.begin() << endl;

    Test.pop_front();
    Test.pop_back();

    cout << "After deleting first and second values: " << endl;
    Test.print();   
    cout << "Current list size is: " << Test.size() << endl;

    return 0;
}

