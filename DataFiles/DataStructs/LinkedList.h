#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>
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
	bool search(T& value);						//searches for value in list, returns true/false
	void peekHead(T& value);					//assigns parameter to the head
	void peekTail(T& value);					//assigns parameter to the tail
	void display();								//displays all items in the list
	bool full();								//checks if list is full, returns true/false
	bool empty();								//checks if list is empty, returns true/false
	int getCount();								//returns the number of items in the list
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
	if (full())
	{
		cout << "The list is at maximim capacity." << endl;
	}
	else
	{
		Node<T>* newNode = new Node<T>;
		newNode->value = item;
		newNode->next = nullptr;

		if (head == nullptr)
		{
			head = newNode;
			head->next = nullptr;
			tail = newNode;
			tail->next = nullptr;
		}
		else
		{
			Node<T>* oldHead = head;
			head = newNode;
			oldHead->prev = head;
			head->next = oldHead;
		}
	}
}

template <class T>
void LinkedList<T>::append(T item)
{
	if (full())
	{
		cout << "The list is at maximum capacity." << endl;
	}
	else
	{
		Node<T>* newNode = new Node<T>;
		newNode->value = item;
		newNode->next = nullptr;

		if (head == nullptr)
		{
			head = newNode;
			head->prev = nullptr;
			tail = newNode;
			tail->next = nullptr;
			tail->prev = nullptr;
		}
	}
}

template <class T>
void LinkedList<T>::del(T item)
{
	if (empty())
	{
		cout << "The list is empty." << endl;
	}
	else
	{
		Node<T>* nodePtr = head;
		while (nodePtr->value != item)
		{
			nodePtr = nodePtr->next;
			if (nodePtr == nullptr)
			{
				cout << "The value does not exist in the list." << endl;
				return;
			}
		}
		if (nodePtr == head)
		{
			delHead();
		}
		else if (nodePtr == tail)
		{
			delTail();
		}
		else
		{
			Node<T>* past = nodePtr->prev;
			past->next = nodePtr->next;
			delete nodePtr;
			nodePtr = nullptr;
			currentCount--;
		}

	}
}

template <class T>
void LinkedList<T>::delHead()
{
	Node<T>* delNode = head;
	if (delNode == tail)
	{
		delete delNode;
		head = nullptr;
		tail = nullptr;
	}
	else
	{
		head = delNode->next;
		head->prev = nullptr;
		delete delNode;
	}

	delNode = nullptr;
	currentCount--;
}

template <class T>
void LinkedList<T>::delTail()
{
	Node<T>* delNode = tail;
	if (delNode == head)
	{
		delete delNode;
		head = nullptr;
		tail = nullptr;
	}
	else
	{
		tail = delNode->prev;
		tail->next = nullptr;
		delete delNode;
	}

	delNode = nullptr;
	currentCount--;
}

template <class T>
bool LinkedList<T>::search(T& value)
{
	if (!empty())
	{
		Node<T>* nodePtr = head;
		while (nodePtr->value != value)
		{
			nodePtr = nodePtr->next;
			if (nodePtr == nullptr)
			{
				return false;
			}
		}
		value = nodePtr->value;
		return true;
	}
	else
	{
		return false;
	}
}

template <class T>
void LinkedList<T>::peekHead(T& value)
{
	value = head->value;
}

template <class T>
void LinkedList<T>::peekTail(T& value)
{
	value = tail->value;
}

template <class T>
void LinkedList<T>::display()
{
	if (!empty())
	{
		Node<T>* nodePtr = head;
		while (nodePtr != nullptr)
		{
			cout << nodePtr->value << " ";
			nodePtr = nodePtr->next;
		}
		cout << endl;
	}
	else
	{
		cout << "The list is empty." << endl;
	}
}

template <class T>
bool LinkedList<T>::full()
{
	bool status = (currentCount == maximum) ? true : false;
	return status;
}

template <class T>
bool LinkedList<T>::empty()
{
	bool status = (currentCount == 0) ? true : false;
	return status
}

template <class T>
int LinkedList<T>::getCount()
{
	return currentCount;
}

template <class T>
void LinkedList<T>::clearAll()
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
	currentCount = 0;
}

template <class T>
void LinkedList<T>::operator = (const LinkedList& list)
{
	clearAll();
	maximum = list.maximum;

	Node<T>* nodePtr = list.head;
	while (nodePtr != nullptr)
	{
		append(nodePtr->value);
		nodePtr = nodePtr->next;
	}
}
#endif