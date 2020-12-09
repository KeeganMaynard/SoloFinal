#include "Official.h"
using namespace std;

//constructors
Official::Official()
{

}

Official::Official(string userName, string userID, string userPass, string userType, string login) : User(userName, userID, userPass, userType, login)
{
	officialStatus = "active";
}

Official::Official(string userName, string userID, string userPass, string userType) : User(userName, userID, userPass, userType)
{
	officialStatus = "active";
}

//setters and getters
void Official::setOfficialStatus(string newStatus)
{
	officialStatus = newStatus;
}

string Official::getStatus()
{
	return officialStatus;
}

//functions for members
void Official::addNewMember(Member& member)
{
	string memberID = member.getID(), hashedPass = member.getPass();
	vector<string> memberData = { hashedPass, "member" };
	//controller function call to add the member to the avl tree
}

void Official::searchMemberAccountID(string accountID)
{
	//controller will have to be working for this function
}

void Official::searchMemberID(string ID)
{
	//controller will have to be working for this function
}

void Official::searchMemberFirstName(string first)
{
	//controller will have to be working for this function
}

void Official::searchMemberLastName(string last)
{
	//controller will have to be working for this function
}

void Official::searchMemberPhone(string phoneNum)
{
	//controller will have to be working for this function
}

void Official::searchMemberAddress(string addy)
{
	//controller will have to be working for this function
}

void Official::addNewAccount(Member& member, Account& account)
{
	//controller will have to be working for this function
}

//functions
void Official::saveData()
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
		outFile << Encryption::encryption(officialStatus) << endl;
	}
	else
	{
		outFile.close();
		cout << "Error: the file " << ID << ".txt cannot be accessed at this time." << endl;
		return;
	}
	outFile.close();
}

void Official::constructOfficial(string fileID)
{
	Encryption::position = 0;
	ifstream inFile;
	inFile.open(fileID);
	if (inFile)
	{
		string text = "";
		vector<string> userData = {};

		while (getline(inFile, text))
		{
			//split the file up into substrings and push substrings to the vector
		}
		//assign user variables from the elements of the vector
	}
	else
	{
		inFile.close();
		cout << "Error: the file " << fileID << " cannot be accessed at this time." << endl;
		return;
	}
	inFile.close();
}