#ifndef MEMBER_H
#define MEMBER_H
#include "Users.h"
#include <fstream>
#include <vector>
using namespace std;

class Member : public User
{
private:
	string memberAddress;
	string memberPhone;
public:
	//constructors
	Member();
	Member(string userName, string userID, string userPass, string userType, string login, string address, string phone);
	Member(string userName, string userID, string userPass, string userType, string address, string phone);

	//setters and getters
	void setAddress(string address);
	string getAddress();
	void setPhone(string phone);
	string getPhone();

	//functions
	void displayData();
	void getHistory(vector<string> acntHist);
	void saveData();
	void constructMemeber(string fileID);
};
#endif