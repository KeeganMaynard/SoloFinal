#ifndef OFFICIAL_H
#define OFFICIAL_H
#include "Users.h"
#include "Member.h"
#include "Account/Account.h"
using namespace std;

class Official : public User
{
private:
	string officialStatus;
public:
	Official();
	Official(string userName, string userID, string userPass, string userType, string login);
	Official(string userName, string userID, string userPass, string userType);

	//setters and getters
	void setOfficialStatus(string newStatus);
	string getStatus();

	//official functions for members
	void addNewMember(Member& member);
	void searchMemberAccountID(string accountID);
	void searchMemberID(string ID);
	void searchMemberFirstName(string first);
	void searchMemberLastName(string last);
	void searchMemberPhone(string phoneNum);
	void searchMemberAddress(string addy);
	void addNewAccount(Member& member, Account& account);			//add another account to an existing user

	//functions
	void saveData();
	void constructOfficial(string fileID);

};
#endif