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
	//convert day to an int, then assign to private members with calculations
}

//Time setters and getters
void Time::setYear(int YEAR)
{

}

int Time::getYear()
{

}

void Time::setMonth(int MONTH)
{

}

int Time::getMonth()
{

}

void Time::setDay(int DAY)
{

}

int Time::getDay()
{

}

//Time functions
string Time::toString(int date)
{

}

int Time::toInt(string date)
{

}

string Time::timeNow()
{

}