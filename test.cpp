#include <iostream>
using namespace std;
class Node
{
	friend class List;
private:
	int value;
	Node *next;
	Node(int v, Node* n) : value(v), next(n) {}
};

class List
{
private:
	Node *head,
		 *tail;
	int size;
public:
	List(int);
	void pushBack(int);
	void popFront();
	void insert(int);
	void print();
	~List();
};

List::List(int v)
{
	head = tail = new Node(v, NULL);
	size = 1;
}

void List::pushBack(int value)
{
	Node* newNode = new Node(value, NULL);
	if (head == NULL) 
	{
		head = newNode;
	}
	else
	{
		tail->next = newNode;
	}
	tail = newNode;
	size++;
}

void List::popFront()
{
	if (head != NULL)
	{
		Node* removal = head;
		head = head->next;
		delete removal;
		size--;
	}
}

void List::insert(int value)
{
	Node* insert = new Node(value, NULL);
	Node* scan;
	if (head != NULL)
	{
		if (head->value > value) {
			insert->next = head;
			head = insert;
		}
		else if (tail->value < value) {
			tail->next = insert;
			tail = insert;
		}
		else {
			scan = head;
			while (scan->next->value < insert->value)
			{
				scan = scan->next;
			}
			insert->next = scan->next;
			scan->next = insert;
		}
	}
	else {
		head = insert;
		tail = insert;
		head->next = NULL;
	}
	size++;
}

void List::print()
{
	Node* scan = head;
	while (scan != NULL)
	{
		cout << scan->value << endl;
		scan = scan->next;
	}
}
List::~List()
{
	while (head != NULL)
	{
		popFront();
	}
}