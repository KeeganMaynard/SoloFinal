/*
In all honesty, I was really struggling with this part of the project, so I googled an encryption class and altered it to fit my needs
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
	static size_t position;				//sets the position in the text file
	
	//functions
	long long FNV1a(string input);
	string encryption(string line);
	string decryption(string line);
	string hasher(string input);
	string hexer(long long Input);
	int index(string input, int size);
};

size_t Encryption::position = 0;
string Encryption::locker = "%67#a9/k*g";
vector<int> Encryption::scrambler{ 0,3,4,1,2,1,0,3,4,2,1 };
#endif