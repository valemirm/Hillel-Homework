#include <iostream>
#include <string> // для завдання 4

using namespace std;

template <typename T>
class List
{
public:
	List() : head(0), tail(0), theCount(0) {}
	virtual ~List();
	void insert(T value);
	void append(T value);
	bool is_present(T value) const;
	bool is_empty() const { return head == 0; }
	int count() const { return theCount; }

    // 6. Оголосіть дружній оператор operator== класу List.
    template <typename U>
    friend bool operator==(const List<U>& rhs, const List<U>& lhs);
    
private:
	class ListCell
	{
	public:
    	ListCell(T value, ListCell *cell = 0) : val(value), next(cell) {}
    	T val;
    	ListCell *next;
	};
	T val;
	ListCell *next;
	ListCell *head;
	ListCell *tail;
	int theCount;
};

// 7. Напишіть виконання дружнього оператора operator== для класу List.

template <typename U>
bool operator==(const List<U>& rhs, const List<U>& lhs)
{
    if (lhs.theCount != rhs.theCount) {
        return false;
    }

    typename List<U>::ListCell* currentLhs = lhs.head;
    typename List<U>::ListCell* currentRhs = rhs.head;

    while (currentLhs != nullptr && currentRhs != nullptr) {
        if (currentLhs->val != currentRhs->val) {
            return false;
        }
        currentLhs = currentLhs->next;
        currentRhs = currentRhs->next;
    }

    return currentLhs == nullptr && currentRhs == nullptr;
}

// 8. Чи має оператор operator== ту ж проблему, що у вправі 5?
// так, помилка досі існує, оскільки компілятор не бачить перевизначення оператора == у класі Cat 

template <typename T>
List<T>::~List()
{
    ListCell *current = head;
    while (current != nullptr)
    {
        ListCell *next = current->next;
        delete current;
        current = next;
    }
}

template <typename T>
void List<T>::insert(T value)
{
    head = new ListCell(value, head);
    if (tail == nullptr)
    {
        tail = head;
    }
    theCount++;
}

template <typename T>
void List<T>::append(T value)
{
    ListCell *newCell = new ListCell(value);
    if (tail != nullptr)
    {
        tail->next = newCell;
    }
    tail = newCell;
    if (head == nullptr)
    {
        head = tail;
    }
    theCount++;
}

template <typename T>
bool List<T>::is_present(T value) const
{
    ListCell *current = head;
    while (current != nullptr)
    {
        if (current->val == value)
        {
            return true;
        }
        current = current->next;
    }
    return false;
}

// 4. Оголосіть три списки об'єктів: типу Strings, типу Cat та типу int.

class Cat {};

int main()
{
    List<Cat> MyCat;
    List<string> MyString;
    List<int> MyInt;

    List<Cat> Cat_List;
    Cat Felix;
    Cat_List.append(Felix);
    cout << "Felix is "
    << (Cat_List.is_present(Felix) ? "" : "not ")
    << "present\n";
	return 0;
}
