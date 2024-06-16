// Оголосіть клас вузла Node, який підтримує цілі числа.

class Node
{
public:
	Node() {}
	virtual ~Node() {}
	virtual Node *Insert(int *theValue) = 0;
	virtual void Show() = 0;
};