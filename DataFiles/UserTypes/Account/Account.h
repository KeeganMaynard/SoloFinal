#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <string>
#include <ctime>
using namespace std;

class AccountVersion
{
private:
	string accountType;
	double monthFee;
	double serviceFee;
	double penalty;
	double intRate;
	double balance;
	bool accountStatus;

public:
	AccountVersion(string accountType, double monthlyFee, double serFee, double nsfFee, double interest, double bal, bool actStatus);
	//setters
	void setMonthFee(double fee);
	void setServiceFee(double fee);
	void setPenalty(double fee);
	void setIntRate(double rate);
	void setMinimum(double amount);				//minimum balance of the account
	void setStatus(bool goodBad);				//accounts will have good or bad status
	void setType(string actType);				//sets the type of account - checking, saving, CD
	//getters
	double getMonthFee();
	double getServiceFee();
	double getPenalty();
	double getInterest();
	double getMinimum();
	bool getStatus();
	string getType();
	//functions
	string getNumbers(double nums);							//presents the numbers from roundBal function
	double roundBal(double amount, int change);				//rounds the values of the account to represent actual monetary values
};

class Account : public AccountVersion
{
private:
	//account information
	string accountID;
	string holderID;
	string holderFirstName;
	string holderLastName;
	string holderPhone;
	string holderAddress;
	string closedBy;						//tracks which official closed the account
	double moneyAmount;						//tracks the balance of the account
	bool goodStatus;
	bool badStatus;
	time_t opened;							//tracks the day the account was opened
	time_t closed;							//tracks the day the account will/was closed
	time_t maturity;						//tracks the day the account will mature
	time_t lastInterest;					//tracks the last time interest was calculated

	//information for the bank
	string nextCheckingAccountID;
	string nextSavingsAccountID;
	string nextCDAccountID;

	//functions
	void setBalance(double amount);
	void recordTransaction(string type, double amount);					//saves/update the files with the transaction information
	void calcInterest();
	string convertTime(time_t time);									//converts the time to a string to write to files or display to the user
	string incrementAccountID(string currentID);						//increments the account number for the next new user to use
	bool availableID(string ID);										//checks if the account ID is already in use

	 void initializer();												//initializes the original accounts when the program starts

public:
	//new account constructor
	Account(string acctType, string newHolderID, string newFirstName, string newLastName, string newPhone, string newAddress, time_t startTime, double newBalance);
	//exisiting account constructor
	Account(string acntID);
	//setters
	void setAccountID(string ID);
	void setHolderID(string userID);
	void setHolderFirstName(string first);
	void setHolderLastName(string last);
	void setHolderPhone(string phoneNum);
	void setHolderAddress(string addy);
	void setClosedBy(string official);
	void setClosedDay(time_t day);						//sets the day the account was closed
	void setGoodStatus(bool good);
	void setBadStatus(bool bad);
	
	//getters
	//account holder info getters
	string getAccountID();
	string getHolderID();
	string getHolderFirstName();
	string getHolderLastName();
	string getHolderPhone();
	string getHolderAddress();
	//account info getters
	string getClosedBy();
	string getOpenedDay();
	string getClosedDay();
	time_t getMaturityDay();
	time_t getTerm();
	double getBalance();
	bool getGoodStatus();
	bool getBadStatus();

	//functions
	void deposit(double amount);
	void withdraw(double amount);
	void accountHistory(string opened, string current);		//displays account history from open to present day (when the function is called)
	time_t convertToTime(string day);						//converts a string to time
	string saveData();										//saves account information to the appropriate file
	void constructAccount(string acntID);					//builds the account from a file
};
#endif