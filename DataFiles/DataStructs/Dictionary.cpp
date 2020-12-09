#include "Dictionary.h"
using namespace std;

//operator overload functions to correctly save or display entry information
ostream& operator << (ostream& op, dictEntry entry)
{
	op << entry.key << ": " << entry.data;
	return op;
}

bool dictEntry::operator==(const dictEntry& values)
{
	bool valid = (key == values.key) ? true : false;
	return valid;
}

bool dictEntry::operator!=(const dictEntry& values)
{
	bool valid = (key == values.key) ? true : false;
	return valid;
}

dictEntry::dictEntry()
{
	key = "";
	data = "";
}

dictEntry::dictEntry(string keyValue)
{
	key = keyValue;
	data = "default";
}

dictEntry::dictEntry(string keyValue, string dataInfo)
{
	key = keyValue;
	data = dataInfo;
}

accountDict::accountDict()
{
	maximum = 10; //default value
	usedLocals = 0;
	totalKeys = 0;
	factor = 0.0;
	threshold = .9;	//default value
	collisionCount = 0;
	dictionary = new LinkedList<dictEntry>[maximum];
}

accountDict::~accountDict()
{
	delete[] dictionary;		//LinkedList.h has its own destructor
	dictionary = nullptr;
}

void accountDict::updateFactor()
{
	double allKeys = totalKeys;		//convert to double to retain the decimals
	factor = allKeys / maximum;
}

void accountDict::resize()
{
	//deep copy the linked list into a temporary linked list 
	//assign temporary variables to store the number of usedLocals and collisionCounter
	//for loop of each index in the the array
		//while the linked list at each each index is not empty, assign the value from the old linked list to the new one and then delete it from the old
	//reset the variables with the new information
}

void accountDict::insert(dictEntry newEntry)
{
	//get the location to store newEntry
	//test if the location is empty
	//increment usedLocals
	//append the new value to the linked list at the location
	//increment totalKeys
	//update the load factor - updateFactor()
	//check the dictionary for collisions and load threshold
}

void accountDict::del(string keyID)
{
	if (isEmpty())
	{
		cout << "There are no accounts to remove." << endl;
	}
	else
	{
		//get the location of the keyID in the linked list
		//get the value of the keyID from the linked list
		//remove the keyID from the linked list
		totalKeys--;
	}
}

void accountDict::update(string keyID, string newData)
{
	//get the location of the keyID in the linked list
	//assign variables to store the value of the old entry and the new entry
	//remove the old entry
	//append the new entry
}

void accountDict::display()
{
	for (int i = 0; i < maximum; i++)
	{
		if (!dictionary[i].empty())
		{
			//display information to make these numbers make sense - index: i and the size of index i
			dictionary[i].display();
		}
	}
}

bool accountDict::isEmpty()
{
	bool empty = (totalKeys == 0) ? true : false;
	return empty;
}

string accountDict::search(string keyID)
{
	//get the location of the keyID in the linked list
	//get the value of the keyID
	//check if the keyID is in the linked list - inDict()
	//if not found in the linked list, return a string that conveys that 
	//if found, return all the information of the keyID
}

bool accountDict::inDict(string keyID)
{
	//get the location of the keyID in the linked list
	//get the value of the keyID
	//assign a bool to be assigned the value of the search for this value
	//return that bool variable
}

void accountDict::saveEntry(string fileID)
{
	ofstream outFile(fileID);
	dictEntry storedInfo;
	if (outFile)
	{
		for (int i = 0; i < maximum; i++)
		{
			while (!dictionary[i].empty())
			{
				//assign storedInfo to the entry
				//delete the entry
				//save storedInfo by writing it to the text file
			}
		}
	}
	else
	{
		outFile.close()			//close the file before returning 
		cout << "Error: cannot write to " << fileID << " at this time" << endl;
		return;
	}
	outFile.close();
}

void accountDict::constructDict(string fileID)
{
	ifstream inFile;
	inFile.open(fileID);
	if (inFile)
	{
		string line = "";
		while (getline(cin, line))
		{
			//split the text into substrings
			//decrypt the substrings
			//fill the dictionary with the entry info
			//insert the entry
		}
	}
	else
	{
		inFile.close();			//close the inFile before returning
		cout << "Error: the file " << fileID << "cannot be accessed at this time." << endl;
		return;
	}
	inFile.close();
}

void accountDict::refreshDict()
{
	for (int i = 0; i < maximum; i++)
	{
		if (!dictionary[i].empty())
		{
			int size = 0;		//set the size of the dictionary
			//create a temprorary linked list

			for (int x = 0; x < size; x++)
			{
				//rebuild the dictionary so that interest can be calculated with the time difference
			}

			//deep copy the new list back into the dictionary
		}
	}
}

string accountDict::hashEntry(string text)
{
	//code to hash the account keys so that they can be stored in the linked list
}