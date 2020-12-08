#include "SystemAdmin.h"
using namespace std;

//constructors
systemAdmin::systemAdmin()
{
	
}

systemAdmin::systemAdmin(string userName, string userID, string userPass, string userType, string login) : Users(userName, userID, userPass, userType, login)
{

}

systemAdmin::systemAdmin(string userName, string userID, string userPass, string userType) : Users(userName, userID, userPass, userType)
{

}

//functions for officials
void systemAdmin::createOfficial(string name, string ID, string password)
{
	//encrypt the password
	//created new official and save the their information to appropriate files
}

void systemAdmin::delOfficial(Official& official)
{

}

void systemAdmin::setActiveOfficial(Official& official)
{

}

void systemAdmin::setInactiveOfficial(Official& official)
{

}

//functions for admins
void systemAdmin::createSystemAdmin(string name, string ID, string password)
{

}

void systemAdmin::delSystemAdmin(string ID)
{

}

//functions
string systemAdmin::returnUserID(string accountID)
{

}

void systemAdmin::resetPassword(string ID, string newPass)
{

}