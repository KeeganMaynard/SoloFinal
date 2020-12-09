#ifndef CONTROLLER_H
#define CONTROLLER_H
//need to include the avl tree
#include "Account/Account.h"
#include "Users.h"
#include <vector>
using namespace std;

struct memberData
{
	AVLtree<string> memberFirstName, memberLastName, memberPhone, memberAddress, userLog;			//names of files where information will be stored
	accountDict allFiles;																			//create a folder/file to store the information for different accounts
};

class Controller
{
public:
	//Constructor
	Controller();

	//all files
	memberData allFiles;
	vector<AccountVersion> list;			//check if list is correct

	//account functions
	void initialAccounts();
	void createType(string acntType, double monthlyFee, double serFee, double interest, double balance);				//balance is not correct, check which variable it is
	void alterType(string acntType, double monthlyFee, double serFee, double interest, double balance);					//balance is not correct, check which variable it is
	void displayTypes();
	void saveTypes();
	void constructTypes(string fileID);						//builds the account types from files

	//login functions
	string validLogin(string userID, string password);
	bool availableID(string userID);						//checks if the entered ID can be found in the files

	//systemAdmin functions
	void recordNewOfficial(string ID);						//saves the info of new officials to appropraite file
	void recordNewSystemAdmin(string ID);					//saves the info of a new system admin to appropriate file
	vector<string> getMemberLogin(string userID);

	//bank Official functions
	void recordNewMember(Member& member, Account& account);	//saves the info of a new member to appropraite file
	void updateMemberData(string accountID, string newData);

	//bank member functions
	void displayAllAccounts(string userID);
	void displayAccountData(string accountID);
	void changeFirstName(string userID, string currentFirst, string newFirst);
	void changeLastName(string userID, string currentLast, string newLast);
	void changeAddress(string userID, string currentAddress, string newAddress);
	void changePhone(string userID, string currentPhone, string newPhone);
	void newAccount(string userID, string acntType);
};

//fill the files with the user information
#endif