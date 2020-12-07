#ifndef DICTIONARY_H
#define DICTIONARY_H
#include "LinkedList.h"
#include "Encryption.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct dictEntry
{
	string key;
	string data;

	dictEntry();
	dictEntry(string keyValue);
	dictEntry(string keyValue, dataInfo);
	
	//operator overloads to insert entries into linked list
	bool operator == (const dictEntry& values);
	bool operator != (const dictEntry& values);
};

class accountDict
{
private:
	LinkedList<dictEntry>* dictionary;

	int maximum;
	int usedLocals;
	int totalKeys;
	double factor;				//tracks the load factor of the dictionary
	float threshold;			//tracks the load threshold of the dictionary
	int collisionCount;

protected:
	void updateFactor();		//used to update the factor when entries are inserted
	void resize();				//used to resize the dictionary when the threshold is reached

public:
	accountDict();
	~accountDict();
	void insert(dictEntry newEntry);
	void del(string keyID);
	void update(string keyID, string newData);
	void display();
	bool isEmpty();					//not empty() becasue LinkedList.h has empty as function name
	string search(string keyID);	//used to return all information
	bool inDict(string keyID);		//used to see if key is in the dictionary
	void saveEntry(string fileID);
	void constructDict(string fileID);
	void refreshDict();

};
#endif