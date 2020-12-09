#include "SystemAdminOS.cpp"
#include "BankOfficialOS.cpp"
#include "BankMemberOS.cpp"
//include statements for all user types
#include "DataFiles/Users.h"
#include "DataFiles/SystemAdmin.h"
#include "DataFiles/Official.h"
#include "DataFiles/Member.h"
//include statements for accounts
#include "DataFiles/Account/Account.h"
//include statements for data structs
#include "DataFiles/DataStructs/AVL.h"
#include "DataFiles/DataStructs/Dictionary.h"
#include "DataFiles/DataStructs/Encryption.h"
#include "DataFiles/DataStructs/LinkedList.h"
#include "DataFiles/DataStructs/Node.h"
#include "DataFiles/DataStructs/Queue.h"
#include "DataFiles/DataStructs/Timer.h"
#include "DataFiles/Controller.h"
#include <iostream>
using namespace std;

void initialize();
void closeBank();

int main()
{
	initialize();		//performs startup of accounts

	bool openBank = true;

	cout << "Bear Bank interface booting... complete." << endl;

	while (openBank)
	{
		string input = "";
		cout << "[1] Login To Your Account\n[2] Create Bear Bank Account\n[3] Exit Bear Bank" << endl;
		getline(cin, input);
		if (input.length() > 1)
		{
			cout << "Error: invalid input.\nPlease try again." << endl;
			continue;
		}
		else
		{
			int option = stoi(input);
		}

		switch (option)
		{
		case 1:			//login to account
		{
			string ID, password, type;
			cout << "Enter your userID: ";
			getline(cin, ID);
			cout << "Enter you password: ";
			getline(cin, password);
			type = Controller::validLogin(ID, password);

			if (type == "false")
			{
				cout << "Error: invalid input.\nPlease try again" << endl;
			}
			else
			{
				if (type == "systemAdmin")
				{
					systemAdminLogin(ID);
				}
				else if (type == "official")
				{
					officialLogin(ID);
				}
				else
				{
					memberLogin(ID);
				}
			}
			break;
		}
		case 2:			//creating an account
		{
			string first, last, phoneNum, address, memberID, password;
			bool userID;
			cout << "Enter your first name: ";
			getline(cin, first);
			cout << "Enter your last name: ";
			getline(cin, last);
			cout << "Enter your phone number: ";
			getline(cin, phoneNum);
			cout << "Enter your address: ";
			getline(cin, address);
			cout << "Enter your desired member ID: ";
			getline(cin, memberID);
			userID = Controller::availableID(memberID);

			while (userID == false)
			{
				cout << "Error: that ID is already in use." << endl;
				cout << "Enter different member ID: ";
				getline(cin, memberID);
				userID = Controller::availableID(memberID);
			}

			cout << "Enter your desired password: ";
			getline(cin, password);
			
			//create member object
			Member user(first + " " + last, memberID, Encryption::hasher(password), "member", address, phoneNum);
			user.setHistory("Created new account.");
			user.saveData();

			//create official to enter new member into dictionary
			Official official;
			official.constructUser("InfoFiles/BankOfficial.txt");
			official.addNewMember(user);
			official.setHistory("Created account for: " + memberID);
			official.saveData();

			//build the new member account
			cout << "Select Account Type:\n[1] Checking\n[2] Savings\n[3] Certificate of Deposit" << endl;
			//get the input and build the account from it -- do if there is time
			break;
		}
		case 3:			//exit
		{
			openBank = false;
			cout << "Thank you for using Bear Bank." << endl;
			break;
		}
		default:
		{
			cout << "Error: invalid input.\nPlease try again." << endl;
			break;
		}
		}
	}

	closeBank();		//saves info before closing the bank
	return 0;
}

void initialize()
{
	//Controller.h is causing errors, commented out for now, this is where the controller will build avl trees and the account dictionary from the text files
	//I think there is an error reading the file names with the avl tree names
	/*
	Controller::allFiles.accountFile.--(InfoFiles/Accounts.txt);		//need the function for building my dictionary
	Controller::allFiles.memberFirstName.constructTree(InfoFiles/FirstNames.txt);
	Controller::allFiles.memberLastName.constructTree(InfoFiles/LastNames.txt);
	Controller::allFiles.memberAddress.constructTree(InfoFiles/Addresses.txt);
	Controller::allFiles.memberPhone.constructTree(InfoFiles/PhoneNumbers.txt);
	Controller::allFiles.userLog.constructTree(InfoFiles/Users.txt);
	*/

	Queue accountQueue;			//where new account requests are stored
	accountQueue.constructQueue();
	accountQueue.saveQueue();

	//Controller::allFiles.accountFile.updateMemberData();
}

void closeBank()
{
	//has the same issues as initialize()
	/*
	Controller functions to save the info to the .txt files would go here
	Didn't include becasue I was running low on time and was trying to implement as much code as possible
	*/
}
