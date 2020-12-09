#include "Users.h"
using namespace std;

User::User()
{

}

User::User(string userName, string userID, string userPass, string userType, string login)
{
	name = userName;
	ID = userID;
	password = userPass;
	type = userType;
	loginReport = login;
	history = "No history for this account";
}

User::User(string userName, string userID, string userPass, string userType)
{
	name = userName;
	ID = userID;
	password = userPass;
	type = userType;
	loginReport = "This is the first login on this account.";
}

//User setters and getters
void User::setName(string newName)
{
	name = newName;
}

string User::getName()
{
	return name;
}

void User::setID(string newID)
{
	ID = newID;
}

string User::getID()
{
	return ID;
}

void User::setPass(string newPass)
{
	password = newPass;
}

string User::getPass()
{
	return password;
}

void User::setType(string newType)
{
	type = newType;
}

string User::getType()
{
	return type;
}

void User::setLogin(string report)
{
	loginReport = report;
}

void User::getLogin()
{
	return loginReport;
}

void User::setHistory(string activity)
{
	history = activity;
}

string User::getHistory()
{
	return history;
}

void User::storeUserInfo()
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
	}
	else
	{
		outFile.close();
		cout << "Error: the file " << ID << ".txt cannot be accessed at this time." << endl;
		return;
 	}
	outFile.close();
}

void User::constructUser(string fileID)
{
	Encryption::position = 0;
	ifstream inFile;
	inFile.open(fileID);
	if (inFile)
	{
		string text = "";
		vector<string> info = {};

		while (getline(inFile, text))
		{
			//split the text into substrings and push to the vector
		}
		//assign values to user variables from vector
	}
	else
	{
		cout << "Error: the file " << fileID << " cannot be accessed at this time." << endl;
	}
}