/*
Hashing algorithm is FNV1a, which was chosen becasue I found it when I was researching built in hashing functions for the project
*/
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
	static string locker;
	static vector<int> scrambler;		//used to decrypt and encrypt
public:
	Encryption();
	
	//functions
	FNV1a(string input);
	string encryption(string line);
	string decryption(string line);
};
#endif