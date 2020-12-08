#ifndef ENCRYPTION_H
#define ENCRYPTION_H
#include <string>
#include <iomanip>
#include <sstream>
#include <vector>
using namespace std;

class Encryption
{
private:
	vector<int> key;		//used to decrypt and encrypt
public:
	Encryption();
	
	//functions
	string encryption(string line);
	string decryption(string line);
};
#endif