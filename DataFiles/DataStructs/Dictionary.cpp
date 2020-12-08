#include "Dictionary.h"
using namespace std;

//operator overload functions should be define at the top so that they apply to the functions below
//will try to include those later

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

}

void accountDict::resize()
{

}

void accountDict::insert(dictEntry newEntry)
{

}

void accountDict::del(string keyID)
{

}

void accountDict::update(string keyID, string newData)
{

}

void accountDict::display()
{

}

bool accountDict::isEmpty()
{

}

string accountDict::search(string keyID)
{

}

bool accountDict::inDict(string keyID)
{

}

void accountDict::saveEntry(string fileID)
{

}

void accountDict::constructDict(string fileID)
{

}

void accountDict::refreshDict()
{

}

string accountDict::hashEntry(string text)
{

}