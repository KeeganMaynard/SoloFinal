#include "Official.h"
using namespace std;

//constructors
Official::Official()
{

}

Official::Official(string userName, string userID, string userPass, string userType, string login) : User(userName, userID, userPass, userType, login)
{

}

Official::Official(string userName, string userID, string userPass, string userType) : User(userName, userID, userPass, userType)
{

}

//setters and getters
void Official::setOfficialStatus(string newStatus)
{

}

string Official::getStatus()
{

}

//functions for members
void Official::addNewMember(Member& member)
{

}

void Official::searchMemberAccountID(string accountID)
{

}

void Official::searchMemberID(string ID)
{

}

void Official::searchMemberFirstName(string first)
{

}

void Official::searchMemberLastName(string last)
{

}

void Official::searchMemberPhone(string phoneNum)
{

}

void Official::searchMemberAddress(string addy)
{

}

void Official::addNewAccount(Member& member, Account& account)
{

}

//functions
void Official::saveData()
{

}

void Official::constructOfficial(string fileID)
{

}