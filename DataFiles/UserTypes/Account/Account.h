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
#endif