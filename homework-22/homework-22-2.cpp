// 2. Напишіть виконання звичайної (не шаблонної) версії класу List.

#include <iostream>

class List
{
public:
	List() : head(0), tail(0), theCount(0) {}
	virtual ~List();
	void insert(int value);
	void append(int value);
	bool is_present(int value) const;
	bool is_empty() const { return head == 0; }
	int count() const { return theCount; }
private:
	class ListCell
	{
	public:
    	ListCell(int value, ListCell *cell = 0) : val(value), next(cell) {}
    	int val;
    	ListCell *next;
	};
	int val;
	ListCell *next;
	ListCell *head;
	ListCell *tail;
	int theCount;
};

// 3. Напишіть шаблонний варіант виконання. (оскільки тут вже оголошено як шаблон, завдання №2 окремо)

List::~List()
{
    ListCell *current = head;
    while (current != nullptr)
    {
        ListCell *next = current->next;
        delete current;
        current = next;
    }
}

void List::insert(int value)
{
    head = new ListCell(value, head);
    if (tail == nullptr)
    {
        tail = head;
    }
    theCount++;
}

void List::append(int value)
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

bool List::is_present(int value) const
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

int main()
{
	return 0;
}
