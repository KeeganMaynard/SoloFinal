#include "DataFiles/Official.h"
#include "DataFiles/Users.h"
#include "DataFiles/DataStructs/Timer.h"
#include "DataFiles/Account/Account.h"
using namespace std;

void officialLogin(string ID);
void memberSearch(Official& official);
void newMember(Official& official);
void newAccount(Official& official);

bool run = true;

void officialLogin(string ID)
{
	Official official;
	official.constructOfficial("InfoFiles/" + ID + ".txt");		//check the construct function -- make sure its the right one

	if (official.getStatus() == "bad")
	{
		cout << "This account is not active at this time." << endl;
	}
	else
	{
		cout << "Last Log in to this account: " << official.getLogin() << endl;
		cout << "Recent history of this account: " << official.getHistory() << endl;
		official.setLogin(Time().timeNow());
	}

	while (run)
	{
		string input;
		cout << "[1] Open or Close Member Account\n[2] Search Member Account\n[3] Deposit into Member Account\n[4] Withdraw from Member Account\n[5] Exit" << endl;
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
		case 1:
		{
			string decision;
			cout << "[1] Open an Account\n[2] Close an Account" << endl;
			getline(cin, decision);

			if (decision == "1")
			{
				string ID;
				cout << "Enter the user ID for this account: ";
				getline(cin, ID);
				//will need to get account information to build new account
				//official.addNewAccount(official, newAccount);
				//add check to make sure this ID is for a member
				//showcase the types of accounts available
				//user selects what type of account they want
				//new instance of member and create an account
			}
			else if (decision == "2")
			{
				//close account
			}
			else
			{
				cout << "Error: invalid input.\nPlease try again." << endl;
			}
			break;
		}
		case 2:
		{
			//this code will be abstracted out to the search function
			string input;
			cout << "Choose method to search account:" << endl;
			cout << "[1] Account ID\n[2] Member ID\n[3] Member First Name\n[4] Member Last Name\n[5] Member Phone Number\n[6] Member Address\n[7] Exit" << endl;
			getline(cin, input);
			//official.membersearch();		//function call is wrong

			if (input.length() > 1)
			{
				cout << "Error: invalid input.\nPlease try again." << endl;
			}
			else
			{
				int option = stoi(input);
			}

			switch (option)
			{
			case 1:
			{
				//search member by account ID
				break;
			}
			case 2:
			{
				//search member by member ID
				break;
			}
			case 3:
			{
				//search member by first name
				break;
			}
			case 4:
			{
				//search member by last name
				break;
			}
			case 5:
			{
				//search member by phone number
				break;
			}
			case 6:
			{
				//search member by address
				break;
			}
			case 7:
			{
				//exit
				cout << "Returning to Bank Official options menu." << endl;
				break;
			}
			default:
			{
				cout << "Error: invalid input.\nPlease try again." << endl;
				break;
			}
			}
			break;
		}
		case 3:
		{
			//deposit into member account with permission
			break;
		}
		case 4:
		{
			//withdraw from member account with permission
			break;
		}
		case 5:
		{
			//exit
			run = false;
			cout << "Returning to bank login." << endl;
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