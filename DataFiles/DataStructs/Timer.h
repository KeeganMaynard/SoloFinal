#ifndef TIMER_H
#define TIMER_H
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <Windows.h>
using namespace std;

class Time
{
private:
	int year;
	int month;
	int day;
public:
	//constructors and destructor
	Time();
	Time(int YEAR, int MONTH, int DAY);
	Time(string DAY);
	

	//setters and getters
	void setYear(int YEAR);
	int getYear();
	void setMonth(int MONTH);
	int getMonth();
	void setDay(int DAY);
	int getDay();

	//Functions
	string toString(int date);
	int toInt(string date);
	string timeNow();
};
#endif