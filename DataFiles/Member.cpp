#include "Member.h"
using namespace std;

//constructors
Member::Member()
{

}

Member::Member(string userName, string userID, string userPass, string userType, string login, string address, string phone) : User(userName, userID, userPass, userType, login)
{
	memberAddress = address;
	memberPhone = phone;
}

Member::Member(string userName, string userID, string userPass, string userType, string address, string phone) : User(userName, userID, userPass, userType)
{
	memberAddress = address;
	memberPhone = phone;
}

//setters and getters
void Member::setAddress(string address)
{
	memberAddress = address;
}

string Member::getAddress()
{
	return memberAddress;
}

void Member::setPhone(string phone)
{
	memberPhone = phone;
}

string Member::getPhone()
{
	return memberPhone;
}

//functions
void Member::displayData()
{

}

void Member::getAccountHistory(vector<string> acntHist)
{
	string accountID = "";
	bool present = false;
	cout << "Eneter the account ID: ";
	getline(cin, accountID);

	for (int i = 1; i < acntHist.size(); i++)
	{
		if (accountID == acntHist[i])
		{
			present = true;
			break;
		}
	}
	if (present != true)
	{
		cout << "Error: invalid input.\nPlease try again." << endl;
	}

	//if time permitts, build the code to display account history
}

void Member::saveData()
{
	Encryption::position = 0;
	ofstream outFile("InfoFiles/" + ID + ".txt");
	if (outFile)
	{
		outFile << Encryption::encryption(ID) << endl;
		outFile << Encryption::encryption(name) << endl;
		outFile << Encryption::encryption(password) << endl;
		outFile << Encryption::encryption(type) << endl;
		outFile << Encryption::encryption(loginReport) << endl;
		outFile << Encryption::encryption(history) << endl;
		outFile << Encryption::encryption(memberAddress) << endl;
		outFile << Encryption::encryption(memberPhone) << endl;
	}
	else
	{
		outFile.close();
		cout << "Error: the file " << ID << ".txt cannot be accessed at this time." << endl;
		return;
	}
	outFile.close();
}

void Member::constructMemeber(string fileID)
{
	Encryption::position = 0;
	ifstream inFile;
	inFile.open(fileID);
	if (inFile)
	{
		string text = "";
		vector<string> memberData = {};

		while (getline(inFile, text))
		{
			//split the text into substrings and push them to the vector
		}
		//assign user variables from vector elements
	}
	else
	{
		inFile.close();
		cout << "Error: the file " << fileID << " cannot be accessed at this time." << endl;
		return;
	}
	inFile.close();
}