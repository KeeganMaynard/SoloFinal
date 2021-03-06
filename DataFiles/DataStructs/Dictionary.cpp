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
	LinkedList<dictEntry>* temp = new LinkedList<dictEntry>[maximum * 2];
	int tempLocals;
	int tempCollisions;

	for (int i = 0; i < maximum; i++)
	{
		while (dictionary[i].empty() == false)
		{
			dictEntry entry;
			dictionary[i].peekHead(entry);
			dictionary[i].delHead();

			int index = Encryption::index(entry.key, maximum * 2);
			if (temp[index].empty())
			{
				tempLocals++;
			}
			temp[index].append(entry);
			//implement check for collisions
		}
	}

	maximum = maximum * 2;
	delete[] dictionary;
	dictionary = temp;
	temp = nullptr;
	usedLocals = tempLocals;
	collisionCount = tempCollisions;
}

void accountDict::insert(dictEntry newEntry)
{
	int index = Encryption::index(newEntry.key, maximum);

	if (dictionary[index].empty())
	{
		usedLocals++;
	}

	dictionary[index].append(newEntry);
	totalKeys++;
	updateFactor();

	//need to implement code to check for collisions and load threshold
}

void accountDict::del(string keyID)
{
	if (isEmpty())
	{
		cout << "There are no accounts to remove." << endl;
	}
	else
	{
		int index = Encryption::index(keyID, maximum);
		dictEntry toDel(keyID);
		dictionary[index].del(toDel);
		totalKeys--;
	}
}

void accountDict::update(string keyID, string newData)
{
	int index = Encryption::index(keyID, maximum);
	dictEntry oldData(keyID), newInfo(key, newData);
	dictionary[index].del(oldData);
	dictionary[index].append(newInfo);
}

void accountDict::display()
{
	for (int i = 0; i < maximum; i++)
	{
		if (!dictionary[i].empty())
		{
			cout << "Key: " << i << " Size: " << dictionary[i].getCount() << endl;
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
	int index = Encryption::index(keyID, maximum);
	dictEntry entry(keyID);
	bool present = dictionary[index].search(entry);

	if (present == false)
	{
		return "false";
	}
	else
	{
		return entry.data;
	}
}

bool accountDict::inDict(string keyID)
{
	int index = Encryption::index(keyID, maximum);
	dictEntry entry(keyID);
	bool present = dictionary[index].search(entry);
	return present;
}

void accountDict::saveEntry(string fileID)
{
	Encryption::position = 0;
	ofstream outFile(fileID);
	dictEntry storedInfo;
	if (outFile)
	{
		for (int i = 0; i < maximum; i++)
		{
			while (!dictionary[i].empty())
			{
				dictionary[i].peekHead(storedInfo);
				dictionary[i].delHead();
				string text = storedInfo.key + " " + storedInfo.data;
				outFile << Encryption::encryption(text) << endl;
			}
		}
	}
	else
	{
		outFile.close();		//close the file before returning 
		cout << "Error: cannot write to " << fileID << " at this time" << endl;
		return;
	}
	outFile.close();
}

void accountDict::constructDict(string fileID)
{
	Encryption::position = 0;
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
			LinkedList<dictEntry> temp;

			for (int x = 0; x < size; x++)
			{
				dictEntry oldEntry;
				dictionary[x].peekHead(oldEntry);
				dictionary[x].delHead();

				//implement account object to append to temp
			}

			dictionary[i] = temp;
		}
	}
}
