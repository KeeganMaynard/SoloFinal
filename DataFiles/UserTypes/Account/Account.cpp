#include "Account.h"
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

void Account::initializer()
{
	//initialize accounts
	AccountVersion checkingAccount("Checking", 0.0, 0.0, 0.0, 0.0, 0.0, true);			//true sets the status of the account to good
	AccountVersion savingsAccount("Savings", 0.0, 0.0, 0.0, 1.5, 0.0, true);
	AccountVersion CD("Certificate of Deposit", 0.0, 0.0, 0.0, 3.0, 0.0, true);
	AccountVersion::setPenalty(30.00);

	ifstream inFile;
	inFile.open("fileID.txt");						//text file will store account numbers -- needs to be created
	if (inFile)
	{
		//read through the file to get the next account number for the accounts
	}
	else
	{
		//create the account numbers if the file is empty -- means there are no accounts
	}
	inFile.close();
}

AccountVersion::AccountVersion(string acntType, double monthlyFee, double serFee, double interest, double bal, bool acntStatus)
{
	if (acntType == "Default")    //check default for correct capitalization
	{
		//set default values for the account
		cout << "Default class, needs default information" << endl;
	}
	else
	{
		//open the corresponding account type .txt file
		//split the text into substrings and assign the variable based on the substrings
		//if the correct .txt file cannot be found make a new account type
		cout << "new account type needs to be created" << endl;
	}
}

//AccountVersion setters
void AccountVersion::setMonthFee(double fee)
{

}

void AccountVersion::setServiceFee(double fee)
{

}

void AccountVersion::setPenalty(double fee)
{

}

void AccountVersion::setIntRate(double rate)
{

}

void AccountVersion::setMinimum(double amount)
{

}

void AccountVersion::setStatus(bool goodBad)
{

}

void AccountVersion::setType(string acntType)
{

}

//AccountVersion getters
double AccountVersion::getMonthFee()
{

}

double AccountVersion::getServiceFee()
{

}

double AccountVersion::getPenalty()
{

}

double AccountVersion::getInterest()
{

}

double AccountVersion::getMinimum()
{

}

double AccountVersion::getStatus()
{

}

string AccountVersion::getType()
{

}

//AccountVersion functions
string AccountVersion::getNumbers(double nums)
{

}

double AccountVersion::roundBal(double amount, int change)
{

}

Account::Account(string acntType, string newHolderID, string newFirstName, string newLastName, string newPhone, string newAddress, time_t startTime, double newBalance) : AccountVersion(acntType)
{
	//new account constructor
}

Account::Account(string acntID) : AccountVersion("default")
{
	//existing account constructor
}

//Account setters and getters
void Account::setAccountID(string ID)
{

}

string Account::getAccountID()
{

}

void Account::setHolderID(string userID)
{

}

string Account::getHolderID()
{

}

void Account::setHolderFirstName(string first)
{

}

string Account::getHolderFirstName()
{

}

void Account::setHolderLastName(string last)
{

}

string Account::getHolderLastName()
{

}

void Account::setHolderPhone(string phoneNum)
{

}

string Account::getHolderPhone()
{

}

void Account::setHolderAddress(string addy)
{

}

string Account::getHolderAddress()
{

}

void Account::setClosedBy(string official)
{

}

string Account::getClosedBy()
{

}

void Account::setClosedDay(time_t day)
{

}

string Account::getClosedDay()
{

}

string Account::getOpenedDay()
{

}

void Account::setGoodStatus(bool good)
{

}

void Account::setBadStatus(bool bad)
{

}

//functions
void Account::deposit(double amount)
{

}

void Account::withdraw(double amount)
{

}

void Account::accountHistory(string opened, string current)
{

}

time_t Account::convertToTime(string day)
{

}

string Account::saveData()
{

}

void Account::constructAccount(string acntID)
{

}