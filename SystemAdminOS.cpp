//figure out what I need to include with this file
#include "DataFiles/SystemAdmin.h"
#include "DataFiles/DataStructs/Timer.h"
#include "DataFiles/Official.h"
#include <string>

//function declarations
void systemAdminLogin(string userID);
void configOfficial(systemAdmin &admin);
void configSystemAdmin(systemAdmin& admin);
void memberAssistance(systemAdmin& admin);



bool loop = true;
int option;

void systemAdminLogin(string userID)
{
	systemAdmin admin;
	admin.constructUser("InfoFiles/" + userID + ".txt");
	cout << "Last log on: " << admin.getLogin() << endl;
	cout << "Recent account activity: " << admin.getHistory() << endl;
	admin.setHistory(Time().timeNow());

	while (loop)
	{
		string input = "";
		cout << "[1] Configure System Admin Accounts\n[2] Configure Bank Official Accounts\n[3] Member Assistance\n[4] Return to Login";
		getline(cin, input);

		if (input.length() > 1)
		{
			cout << "Error: invalid input.\nPlease try again" << endl;
			continue;
		}
		else
		{
			option = stoi(input);
		}

		switch (option)
		{
		case 1:
		{
			configSystemAdmin(admin);
			break;
		}
		case 2:
		{
			configOfficial(admin);
			break;
		}
		case 3:
		{
			memberAssistance(admin);
			break;
		}
		case 4:
		{
			loop = false;
			admin.storeUserInfo();
			break;
		}
		default:
		{
			cout << "Error: invalid input.\nPlease try again." << endl;
			break;
		}
		}
	}
}

void configSystemAdmin(systemAdmin& admin)
{
	string input = "";
	cout << "[1] Create New Administrator\n[2] Delete Existing Administrator\n[3] Exit" << endl;
	getline(cin, input);

	if (input == "1")
	{
		string name, ID, password;
		cout << "Enter the new system administrator's full name: ";
		getline(cin, name);
		//include check to see if the ID is available
		cout << "Enter the new system administrator's user ID: ";
		getline(cin, ID);
		cout << "Enter the new system administrator's password: ";
		getline(cin, password);
		admin.createSystemAdmin(name, ID, password);
		admin.setHistory("Created new admin: " + ID);
		admin.storeUserInfo();
		cout << "Successful creation of system administrator account for " << name << endl;
	}
	else if (input == "2")
	{
		string ID;
		cout << "Enter the ID of the system administrator for removal: ";
		getline(cin, ID);
		//use controller to check the account information of the entered ID
		admin.delSystemAdmin(ID);
		admin.setHistory("Deleted system administrator: " + ID);
		admin.storeUserInfo();
		cout << "Completed removal of the system administrator account with the ID " << ID << endl;
	}
	else if (input == "3")
	{
		cout << "Returning to the system administrator operations list." << endl;
	}
	else
	{
		cout << "Error: invalid input.\nPlease try again.";
	}
}

void cofigOfficial(systemAdmin& admin)
{
	string input;
	int option;
	cout << "[1] Create New Bank official\n[2] Delete Existing Bank Offical\n[3] Set Status for Bank Official\n[4] Exit" << endl;
	getline(cin, input);
	if (input.length() > 1)
	{
		cout << "Error: invalid input.\nPlease try again." << endl;
	}
	else
	{
		option = stoi(input);
	}

	switch (option)
	{
	case 1:
	{
		string name, ID, password;
		cout << "Enter the bank official's full name: ";
		getline(cin, name);
		//have controller check for valid ID
		cout << "Enter the bank official's user ID: ";
		getline(cin, ID);
		cout << "Enter the bank official's password: ";
		getline(cin, password);
		admin.createOfficial(name, ID, password);
		admin.setHistory("Created new bank official: " + ID);
		admin.storeUserInfo();
		break;
	}
	case 2:
	{
		string ID;
		cout << "Enter the ID of the bank official for removal: ";
		getline(cin, ID);
		//need to get the account info of the official
		admin.delOfficial(ID);
		admin.setHistory("Deleted bank official: " + ID);
		admin.storeUserInfo();
		cout << "Completed removal of the bank official account with the ID " << ID << endl;
		break;
	}
	case 3:
	{
		string ID, option;
		cout << "Enter the ID of the bank official to set the status: ";
		getline(cin, ID);
		cout << "[1] Set as active official\n[2] Set as inactive official" << endl;
		getline(cin, option);
		if (option == "1")
		{
			admin.setActiveOfficial(ID);
			admin.setHistory("Set active status of official: " + ID);
		}
		else if (option == "2")
		{
			admin.setInactiveOfficial(ID);
			admin.setHistory("Set inactive status of official: " + ID);
		}
		else
		{
			cout << "Error: invalid input.\nPlease try again." << endl;
			break;
		}
		admin.storeUserInfo();
		break;
	}
	case 4:
	{
		cout << "Returning to the system administrator option list." << endl;
		break;
	}
	default:
	{
		cout << "Error: invalid input.\nPlease try again." << endl;
		break;
	}
	}
}

void memberAssist(systemAdmin& admin)
{
	//include the code to provide the member option from the admin login
}