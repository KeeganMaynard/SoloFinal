#ifndef LINKEDLIST_H
#define LINKEDLIST_H
using namespace std;

template <class T>
struct Node
{
	T value;
	Node<T>* next;
	Node<T>* prev;
};

template <class T>
class LinkedList
{
private:
	Node<T>* head;
	Node<T>* tail;
	int maximum;
	int currentCount;

public:
	LinkedList(int maximum = -1);
	LinkedList(const LinkedList& list);		//deep copy constructor
	~LinkedList();							//destructor

	//functions
	void push(T item);							//insert item to front of list
	void append(T item);						//insert item to end of list	
	void del(T item);							//delete item from list
	void delHead();								//deletes head value, called in del
	void delTail();								//deletes tail value, called in del
	bool search(T value);						//searches for value in list, returns true/false
	void peekFront(T& value);					//assigns parameter to the head
	void peekEnd(T& value);						//assigns parameter to the tail
	void display();								//displays all items in the list
	bool full();								//checks if list is full, returns true/false
	bool empty();								//checks if list is empty, returns true/false
	int size();									//returns the number of items in the list
	void clearAll();							//deletes all items in the list
	void operator = (const LinkedList& list);	//operator overload for deep copy
};
#endif