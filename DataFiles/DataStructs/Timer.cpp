#include "Timer.h"
using namespace std;

Time::Time()
{
	year = 0;
	month = 0;
	day = 0;
}

Time::Time(int YEAR, int MONTH, int DAY)
{
	year = YEAR;
	month = MONTH;
	day = DAY;
}

Time::Time(string DAY)
{
	int date = stoi(DAY);
	year = date / 10000;
	month = (date - year * 10000) / 100;
	day = date % 100;
}

//Time setters and getters
void Time::setYear(int YEAR)
{
	year = YEAR;
}

int Time::getYear()
{
	return year;
}

void Time::setMonth(int MONTH)
{
	month = MONTH;
}

int Time::getMonth()
{
	return month;
}

void Time::setDay(int DAY)
{
	day = DAY;
}

int Time::getDay()
{
	return day;
}

//Time functions
string Time::toString(int date)
{
	string timeString;
	stringstream tString;
	tString << date;
	tString >> timeString;
	return timeString;
}

int Time::toInt(string date)
{
	int timeInt = 0;
	stringstream tInt;
	tInt << date;
	tInt >> timeInt;
	return timeInt;
}

string Time::timeNow()
{
	string currentTime;
	SYSTEMTIME systemTime;
	GetLocalTime(&systemTime);
	currentTime.append(toString(systemTime.wYear)).append("/");
	currentTime.append(toString(systemTime.wMonth)).append("/");
	currentTime.append(toString(systemTime.wDay)).append(" ");
	currentTime.append(toString(systemTime.wHour)).append(":");
	currentTime.append(toString(systemTime.wMinute));
	return currentTime;
}