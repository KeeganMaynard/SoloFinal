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
	list.peekHead(item);
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
	list.peekHead(value);
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
	Encryption::position = 0;
	LinkedList<string> copy = list;
	string input = "";
	ofstream outFile("InfoFiles/Requests.txt");				//where the info will go
	if (outFile)
	{
		while (copy.empty() != true)
		{
			copy.peekHead(input);
			copy.delHead();
			outFile << Encryption::encryption(input) << endl;
		}
	}
	else
	{
		outFile.close();					//close before returning
		cout << "Error: the file Requests.txt cannot be accessed at this time." << endl;
		return;
	}
	outFile.close();
}

void Queue::constructQueue()
{
	list.clearAll();
	string input = "";
	ifstream inFile;
	inFile.open("InfoFiles/Requests.txt");					
	if (inFile)
	{
		while (getline(inFile, input))
		{
			//will need to remove the \r character
			input = input.substr(0, input.find("\r"));
			input = Encryption::decryption(input);
			list.append(input);
		}
	}
	else
	{
		inFile.close();					//close before returning
		cout << "Error: the file Requests.txt cannot be accessed at this time." << endl;
		return;
	}
	inFile.close();
}
#endif