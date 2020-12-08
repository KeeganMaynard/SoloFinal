#include "Member.h"
using namespace std;

//constructors
Member::Member()
{

}

Member::Member(string userName, string userID, string userPass, string userType, string login, string address, string phone) : User(userName, userID, userPass, userType, login)
{

}

Member::Member(string userName, string userID, string userPass, string userType, string address, string phone) : User(userName, userID, userPass, userType)
{

}

//setters and getters
void Member::setAddress(string address)
{

}

string Member::getAddress()
{

}

void Member::setPhone(string phone)
{

}

string Member::getPhone()
{

}

//functions
void Member::displayData()
{

}

void Member::getHistory(vector<string> acntHist)
{

}

void Member::saveData()
{

}

void Member::constructMemeber(string fileID)
{

}