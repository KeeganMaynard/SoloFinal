#include "Controller.h"
using namespace std;

//constructors
Controller::Controller()
{

}

//account functions
void Controller::initialAccounts()
{

}

void Controller::createType(string acntType, double monthlyFee, double serFee, double interest, double balance)
{

}

void Controller::alterType(string acntType, double monthlyFee, double serFee, double interest, double balance)
{

}

void Controller::displayTypes()
{

}

void Controller::displayTypes()
{

}

void Controller::saveTypes()
{

}

void Controller::constructTypes(string fileID)
{

}

//login functions
string Controller::validLogin(string userID, string password)
{

}

bool Controller::availableID(string userID)
{

}

//SystemAdmin functions
void Controller::recordNewOfficial(string ID)
{

}

void Controller::recordNewSystemAdmin(string ID)
{

}

vector<string> Controller::getMemberLogin(string userID)
{

}

//bank official functions
void Controller::recordNewMember(Member& member, Account& account)
{

}

void Controller::updateMemberData(string accountID, string newData)
{

}

//bank member functions
void Controller::displayAllAccounts(string userID)
{

}

void Controller::displayAccountData(string accountID)
{

}

void Controller::changeFirstName(string userID, string currentFirst, string newFirst)
{

}

void Controller::changeLastName(string userID, string currentLast, string newLast)
{

}

void Controller::changeAddress(string userID, string currentAddress, string newAddress)
{

}

void Controller::changePhone(string userID, string currentPhone, string newPhone)
{

}

void Controller::newAccount(string userID, string acntType)
{

}