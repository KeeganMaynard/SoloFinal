#ifndef SYSTEMADMIN_H
#define SYSTEMADMIN_H
#include "Users.h"
#include "Official.h"
#include "Member.h"
#include "Controller.h"
#include "DataStructs/Encryption.h"
using namespace std;

class systemAdmin : public User
{
protected:
	void clearData(string fileID);
public:
	//constructors
	systemAdmin();
	systemAdmin(string userName, string userID, string userPass, string userType, string login);
	systemAdmin(string userName, string userID, string userPass, string userType);

	//systemAdmin functions for officials
	void createOfficial(string name, string officialID, string password);
	void delOfficial(Official& official);
	void setActiveOfficial(Official& official);
	void setInactiveOfficial(Official& official);

	//systemAdmin functions for admins
	void createSystemAdmin(string name, string adminID, string password);
	void delSystemAdmin(string ID);

	//systemAdmin functions
	string returnUserID(string accountID);
	void resetPassword(string ID, string newPass);
};
#endif