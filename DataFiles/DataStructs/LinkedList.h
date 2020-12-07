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
	LinkedList(int max = -1);
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

template <class T>
LinkedList<T>::LinkedList(int max)
{
	head = nullptr;
	tail = nullptr;
	maximum = max;
	currentCount = 0;
}

template <class T>
LinkedList<T>::LinkedList(const LinkedList& list)
{
	head = nullptr;
	tail = nullptr;
	maximum = list.maximum;
	currentCount = 0;

	Node<T>* nodePtr = list.head;
	while (nodePtr != nullptr)
	{
		append(nodePtr->value);
		nodePtr = nodePtr->next;
	}
}

template <class T>
LinkedList<T>::~LinkedList()
{
	Node<T>* nodePtr = head;
	Node<T>* delNode = nullptr;

	while (nodePtr != nullptr)
	{
		delNode = nodePtr;
		nodePtr = nodePtr->next;
		delete delNode;
	}

	delNode = nullptr;

	head = nullptr;
	tail = nullptr;
}

template <class T>
void LinkedList<T>::push(T item)
{

}

template <class T>
void LinkedList<T>::append(T item)
{

}

template <class T>
void LinkedList<T>::del(T item)
{

}

template <class T>
void LinkedList<T>::delHead()
{

}

template <class T>
void LinkedList<T>::delTail()
{

}

template <class T>
bool LinkedList<T>::search(T value)
{

}

template <class T>
void LinkedList<T>::peekFront(T& value)
{

}

template <class T>
void LinkedList<T>::peekEnd(T& value)
{

}

template <class T>
void LinkedList<T>::display()
{

}

template <class T>
bool LinkedList<T>::full()
{

}

template <class T>
bool LinkedList<T>::empty()
{

}

template <class T>
int LinkedList<T>::size()
{

}

template <class T>
void LinkedList<T>::clearAll()
{

}

template <class T>
void LinkedList<T>::operator = (const LinkedList& list)
{

}
#endif