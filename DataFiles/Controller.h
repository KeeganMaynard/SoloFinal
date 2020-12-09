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
	accountDict accountFile;																			//create a folder/file to store the information for different accounts
};

class Controller
{
public:
	//Constructor
	Controller();

	//all files
	static memberData allFiles;
	static vector<AccountVersion> list;			//check if list is correct

	//account functions
	static void initialAccounts();
	static void createType(string acntType, double monthlyFee, double serFee, double interest, double balance);				//balance is not correct, check which variable it is
	static void alterType(string acntType, double monthlyFee, double serFee, double interest, double balance);					//balance is not correct, check which variable it is
	static void displayTypes();
	static void saveTypes();
	static void constructTypes(string fileID);						//builds the account types from files

	//login functions
	static string validLogin(string userID, string password);
	static bool availableID(string userID);						//checks if the entered ID can be found in the files

	//systemAdmin functions
	static void recordNewOfficial(string ID);						//saves the info of new officials to appropraite file
	static void recordNewSystemAdmin(string ID);					//saves the info of a new system admin to appropriate file
	static vector<string> getMemberLogin(string userID);

	//bank Official functions
	static void recordNewMember(Member& member, Account& account);	//saves the info of a new member to appropraite file
	static void updateMemberData(string accountID, string newData);

	//bank member functions
	static void displayAllAccounts(string userID);
	static void displayAccountData(string accountID);
	static void changeFirstName(string userID, string currentFirst, string newFirst);
	static void changeLastName(string userID, string currentLast, string newLast);
	static void changeAddress(string userID, string currentAddress, string newAddress);
	static void changePhone(string userID, string currentPhone, string newPhone);
	static void newAccount(string userID, string acntType);
};

memberData Controller::allFiles = memberData();
vector<AccountVersion> Controller::list = {};
#endif