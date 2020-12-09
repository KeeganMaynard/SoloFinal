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
	inFile.open("InfoFiles/AvailableAcntNumbers.txt");						
	if (inFile)
	{
		//need encryption included in the .h file to read the .txt files
	}
	else
	{
		//create the account numbers if the file is empty -- means there are no accounts
	}
	inFile.close();
}

AccountVersion::AccountVersion(string acntType, double monthlyFee, double serFee, double interest, double bal, bool acntStatus)
{
	if (acntType == "default")    
	{
		monthFee = 0.0;
		serviceFee = 0.0;
		intRate = 0.0;
		balance = 0.0;
		accountType = "";
	}
	else
	{
		//need to include Encryption.h
		//open the corresponding account type .txt file
		//split the text into substrings and assign the variable based on the substrings
		//if the correct .txt file cannot be found make a new account type
	}
}

//AccountVersion setters and getters
void AccountVersion::setMonthFee(double fee)
{
	monthFee = fee;
}

double AccountVersion::getMonthFee()
{
	return monthFee;
}

void AccountVersion::setServiceFee(double fee)
{
	serviceFee = fee;
}

double AccountVersion::getServiceFee()
{
	return serviceFee;
}

void AccountVersion::setPenalty(double fee)
{
	penalty = fee;
}

double AccountVersion::getPenalty()
{
	return penalty;
}

void AccountVersion::setIntRate(double rate)
{
	intRate = rate;
}

double AccountVersion::getInterest()
{
	return intRate;
}

void AccountVersion::setMinimum(double amount)
{
	balance = amount;
}

double AccountVersion::getMinimum()
{
	return balance;
}

void AccountVersion::setStatus(bool goodBad)
{
	accountStatus = goodBad;
}

double AccountVersion::getStatus()
{
	return accountStatus;
}

void AccountVersion::setType(string acntType)
{
	accountType = acntType;
}

string AccountVersion::getType()
{
	return accountType;
}

//AccountVersion functions
string AccountVersion::getNumbers(double nums)
{
	string display = to_string(nums);
	return display.substr(0, display.length() - 4);		//removes the extra decimals to represent monetary value
}

double AccountVersion::roundBal(double amount, int change)
{
	double factor = pow(10, change);
	amount = amount * factor;

	int temp = amount;		//removes the decimals
	int higherTemp = temp + 1;

	double roundDown = abs(amount - temp);
	double roundUp = abs(amount - higherTemp);
	temp = (roundDown < roundUp) ? temp : higherTemp;
	amount = temp / factor;

	return amount;
}

Account::Account(string acntType, string newHolderID, string newFirstName, string newLastName, string newPhone, string newAddress, time_t startTime, double newBalance) : AccountVersion(acntType)
{
	if (acntType == "checking")
	{
		accountID = nextCheckingAccountID;
		nextCheckingAccountID = incrementAccountID(nextCheckingAccountID);
	}
	else if (acntType == "savings")
	{
		accountID = nextSavingsAccountID;
		nextSavingsAccountID = incrementAccountID(nextSavingsAccountID);
	}
	else
	{
		accountID = nextCDAccountID;
		nextCDAccountID = incrementAccountID(nextCDAccountID);
	}
	//if time permits, implement test if it is a new account type

	//set the account holder information
	//set the dates of events

	goodStatus = true;				
	badStatus = false;				//not restricted

	//set the balance of the account
	moneyAmount = newBalance;
}

Account::Account(string acntID) : AccountVersion("default")
{
	if (acntID != "")
	{
		constructAccount(acntID);
		calcInterest();
	}
}

//Account setters and getters
void Account::setAccountID(string ID)
{
	accountID = ID;
}

string Account::getAccountID()
{
	return accountID;
}

void Account::setHolderID(string userID)
{
	holderID = userID;
}

string Account::getHolderID()
{
	return holderID;
}

void Account::setHolderFirstName(string first)
{
	holderFirstName = first;
}

string Account::getHolderFirstName()
{
	return holderFirstName;
}

void Account::setHolderLastName(string last)
{
	holderLastName = last;
}

string Account::getHolderLastName()
{
	return holderLastName;
}

void Account::setHolderPhone(string phoneNum)
{
	holderPhone = phoneNum;
}

string Account::getHolderPhone()
{
	return holderPhone;
}

void Account::setHolderAddress(string addy)
{
	holderAddress = addy;
}

string Account::getHolderAddress()
{
	return holderAddress;
}

void Account::setClosedBy(string official)
{
	closedBy = official;
}

string Account::getClosedBy()
{
	return closedBy;
}

void Account::setClosedDay(time_t day)
{
	closed = day;
}

string Account::getClosedDay()
{
	return to_string(closed);
}

string Account::getOpenedDay()
{
	return to_string(opened);
}

void Account::setGoodStatus(bool good)
{
	goodStatus = good;
}

void Account::setBadStatus(bool bad)
{
	badStatus = bad;
}

//functions
void Account::deposit(double amount)
{
	moneyAmount += roundBal(amount, 2);
	recordTransaction("Deposit", amount);
}

void Account::withdraw(double amount)
{
	double tempAmount = moneyAmount;
	moneyAmount = tempAmount - roundBal(amount, 2);
	recordTransaction("Withdraw", amount);
}

void Account::accountHistory(string opened, string current)
{
	//implement if time allows
}

time_t Account::convertToTime(string day)
{
	string time = ctime(&day);
	return time.substr(0, time.find("\n"));
}

string Account::saveData()
{
	//implement if time allows
}

void Account::constructAccount(string acntID)
{
	//implement if time allows
}

void Account::setBalance(double amount)
{

}

void Account::recordTransaction(string type, double amount)
{

}

void Account::calcInterest()
{

}

string Account::convertTime(time_t time)
{

}

string Account::incrementAccountID(string currentID)
{

}

bool Account::availableID(string ID)
{

}

time_t Account::getMaturityDay()
{
	return maturity;
}

time_t Account::getTerm()
{

}

double Account::getBalance()
{
	return moneyAmount;
}

bool Account::getGoodStatus()
{
	return goodStatus;
}

bool Account::getBadStatus()
{
	return badStatus;
}