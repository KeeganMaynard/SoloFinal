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
	void dequeue(string& value);
	bool isEmpty();							//not empty() becasue LinkedList.h has empty function name
	bool isFull();							//same reason as above -- check this one
	void peek(string& value);
	void clearQueue();
	void displayQueue();
	void saveQueue();
	void constructQueue();
};

Queue::Queue(int max)
{
	max = (max < 1) ? -1 : max;
	list = LinkedList<string>(max);
}

void Queue::enqueue(string value)
{
	list.append(value);
}

void Queue::dequeue(string& value)
{
	list.peekFront(item);
	list.delHead();
}

bool Queue::isEmpty()
{
	return list.empty();
}

bool Queue::isFull()
{
	return list.full();
}

void Queue::peek(string& value)
{
	list.peekFront(value);
}

void Queue::clearQueue()
{
	list.clearAll();
}

void Queue::displayQueue()
{
	list.display();
}

void Queue::saveQueue()
{
	//deep copy the linked list
	string input = "";
	ofstream outFile("FileID.txt");				//will need to determine which file to write to
	if (outFile)
	{
		//while the deep copy link list is not empty
			//get the value of the first element and assign it to the string input
			//delete the first element
			//outFile << input << endl;
	}
	else
	{
		outFile.close()					//close before returning
		cout << "Error: the file FileID.txt cannot be accessed at this time." << endl;		//figure out file to write to
		return;
	}
	outFile.close();
}

void Queue::constructQueue()
{
	//clear the list
	string input = "";
	ifstream inFile;
	inFile.open("FileID.txt");					//figure out the name
	if (inFile)
	{
		while (getline(inFile, input))
		{
			//create substrings of the text
			//decrypt the substrings
			//append the substrings to the end of the linked list
		}
	}
	else
	{
		inFile.close();					//close before returning
		cout << "Error: the file FileID.txt cannot be accessed at this time." << endl;
		return;
	}
	inFile.close();
}
#endif