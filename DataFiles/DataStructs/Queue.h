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
public:
	Queue(int max = -1);
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
#endif