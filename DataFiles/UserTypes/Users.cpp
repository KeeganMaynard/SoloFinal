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

}

string User::getName()
{

}

void User::setID(string newID)
{

}

string User::getID()
{

}

void User::setPass(string newPass)
{

}

string User::getPass()
{

}

void User::setType(string newType)
{

}

string User::getType()
{

}

void User::setLogin(string report)
{

}

void User::getLogin()
{

}

void User::setHistory(string activity)
{

}

string User::getHistory()
{

}

void User::storeUserInfo()
{

}

void User::constructUser(string fileID)
{

}