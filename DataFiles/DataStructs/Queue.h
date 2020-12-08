#ifndef QUEUE_H
#define QUEUE_H
#include "LinkedList.h"
#include "Encryption.h"
#include <iostream>
#include <fstream>
using namespace std;

class Queue
{
private:
	LinkedList<string> list;
	int maximum
public:
	Queue(int max = -1);					//chech why this is not working correctly
	void enqueue(string value);
	bool dequeue(string& value);
	bool isEmpty();							//not empty() becasue LinkedList.h has empty function name
	bool isFull();							//same reason as above -- check this one
	bool peek(string& value);
	void clearQueue();
	void displayQueue();
	void saveQueue();
	void constructQueue();
};

Queue::Queue(int max)
{
	maximum = max;
	list = LinkedList<string>(maximum);
}

void Queue::enqueue(string value)
{

}

bool Queue::dequeue(string& value)
{

}

bool Queue::isEmpty()
{

}

bool Queue::isFull()
{

}

bool Queue::peek(string& value)
{

}

void Queue::clearQueue()
{

}

void Queue::displayQueue()
{

}

void Queue::saveQueue()
{

}

void Queue::constructQueue()
{

}
#endif