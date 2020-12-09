#include "SystemAdmin.h"
using namespace std;

//constructors
systemAdmin::systemAdmin()
{
	
}

systemAdmin::systemAdmin(string userName, string userID, string userPass, string userType, string login) : Users(userName, userID, userPass, userType, login)
{
	//values passed in from user class
}

systemAdmin::systemAdmin(string userName, string userID, string userPass, string userType) : Users(userName, userID, userPass, userType)
{
	//values inherited from user class
}

//functions for officials
void systemAdmin::createOfficial(string name, string officialID, string password)
{
	password = Encryption::hasher(password);
	Official newOfficial(name, ID, password, "official");
	newOfficial.setHistory("Official account created by: " + ID);
	newOfficial.saveData();
	//Controller function to add the official to the dictionary
}

void systemAdmin::delOfficial(Official& official)
{
	clearData("InfoFiles/" + official.getID() + ".txt");
	//controller function call to delete the official from the dictionary
}

void systemAdmin::setActiveOfficial(Official& official)
{
	official.setOfficialStatus("active");
	official.setHistory("Status set as active by: " + ID);
	official.saveData();
}

void systemAdmin::setInactiveOfficial(Official& official)
{
	official.setOfficialStatus("inactive");
	official.setHistory("Status set as inactive by: " + ID);
	official.saveData();
}

//functions for admins
void systemAdmin::createSystemAdmin(string name, string adminID, string password)
{
	password = Encryption::hasher(password);
	systemAdmin newAdmin(name, adminID, password);
	newAdmin.setHistory("System admin account created by: " + ID);
	newAdmin.storeUserInfo();
	//controller function call to add the new admin to the dictionary
}

void systemAdmin::delSystemAdmin(string ID)
{
	clearData("InfoFiles/" + ID + ".txt");
	//controller function call to remove admin from dictionary
}

//functions
string systemAdmin::returnUserID(string accountID)
{
	//controller class is still causing problems

}

void systemAdmin::resetPassword(string ID, string newPass)
{
	//controller class is still causing an unknow error
	//vector<string> userData = Controller::allFiles.
}

void systemAdmin::clearData(string fileID)
{
	ofstream outFile(fileID);
	if (outFile)
	{
		outFile.clear();
	}
	else
	{
		outFile.close();
		cout << "Error: the file " << fileID << " cannot be accessed at this time." << endl;
		return;
	}

	outFile.close();
}