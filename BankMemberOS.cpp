#include "DataFiles/Member.h"
#include "DataFiles/Users.h"
#include "DataFiles/DataStructs/Timer.h"
using namespace std;
#include <vector>

//function declarations
void memberLogin(string ID);
void alterAccount(Member& member);
string getAccount(vector<string> accountList);


void memberLogin(string ID)
{
	Member member;
	member.constructMemeber("InfoFiles/" + ID + ".txt");
	cout << "Last Login: " << member.getLogin() << endl;
	cout << "Recent History: " << member.getHistory() << endl;
	member.setLogin(Time().timeNow());

	bool run = true;

	while (run)
	{
		string input = "";
		cout << "[1] View Account(s)\n[2] Alter Account(s) Information\n[3] Open New Account\n[4] Exit" << endl;
		getline(cin, input);

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
			//view account(s) inforamtion
			break;
		}
		case 2:
		{
			//alter account info
			break;
		}
		case 3:
		{
			//open new account
			break;
		}
		case 4:
		{
			//exit
			run = false;
			cout << "Returning to bank login menu." << endl;
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