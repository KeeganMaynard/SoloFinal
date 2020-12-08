#include "Encryption.h"
using namespace std;

long long Encryption::FNV1a(string input)
{
	input = input + locker;
	//values are based on the psuedocode for FNV
	long long FNVoffset = 14695981039346656037;
	long long FNVset = 1099511628211;

	long long hashValue = FNVoffset;
	for (int i = 0; i < input.length(); i++)
	{
		hashValue = hashValue ^ int(input[i]);
		hashValue *= FNVset;
	}

	return hashValue;
}

string Encryption::encryption(string line)
{
	string toEncrypt = "";

	for (int i = 0; i < line.length(); i++)
	{
		int ascii = line[i] + 129 + scrambler[position % scrambler.size()];		//adding 129 will give valid ascii value, scrambler offsets the value
		postition++;
		char asciiValue = ascii;
		toEncrypt += asciiValue;
	}

	return toEncrypt;
}

string Encryption::decryption(string line)
{
	string toDecrypt = "";

	for (int i = 0; i < line.length(); i++)
	{
		int ascii = line[i] - 129 - scrambler[position % scrambler.size()];		//does the opposite of encryption
		position++;
		char asciiValue = ascii;
		toDecrypt += asciiValue;
	}

	return toDecrypt;
}

string Encryption::hasher(string input)
{
	long long hashConvert = FNV1a(input);
	string hexConvert = hex(hashConvert);

	return hexConvert;
}

string Encryption::hexer(long long input)
{
	stringstream streamValue;
	streamValue << hex << input;
	string hexValue = streamValue.str();

	return hexValue;
}

int Encryption::index(string input, int size)
{
	long long hashedInput = FNV1a(input);

	return (hashedInput % size);
}