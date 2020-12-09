#ifndef USERS_H
#define USERS_H
#include "DataStructs/Timer.h"
#include <fstream>
using namespace std;

class User
{
protected:
	string name;			//variable to track the name of the user
	string ID;				//tracks the ID of the user
	string password;		//tracks the user password
	string type;			//tracks the type of user logged in
	string loginReport;		//tracks the last login time
	string history;			//tracks user activity

public:
	User();
	User(string userName, string userID, string userPass, string userType, string login);
	User(string userName, string userID, string userPass, string userType);

	//User setters and getters
	void setName(string newName);
	string getName();
	void setID(string newID);
	string getID();
	void setPass(string newPass);
	string getPass();
	void setType(string newType);
	string getType();
	void setLogin(string report);
	string getLogin();
	void setHistory(string activity);
	string getHistory();

	//virtual functions
	virtual void storeUserInfo();					//this is a virtual function because not all users have the same attributes
	virtual void constructUser(string fileID);		//virtual for the same reason
};
#endif