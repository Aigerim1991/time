#include "stdafx.h"
#include "Date.h"
#include <Windows.h>
#include <ctime>
#include <iostream>

using namespace std;

Date::Date()
{
	printf("Введите дату Вашего рождения (ДД.ММ.ГГГГ): ");
	int d, m, y;
	scanf_s("%d.%d.%d", &d, &m, &y);
	milliSec = 0;
	day = d;
	month = m;
	year = y;
	convertToSec();
}
Date::Date(int date_day, int date_month, int date_year)
{
	day = date_day;
	month = date_month;
	year = date_year;
	convertToSec();
}
void Date::convertToSec()
{
	struct tm newtime;
	char am_pm[] = "AM";
	__time64_t long_time;
	char time_buffer[26];
	errno_t err;

	//Конвертация времени в 64-битную систему
	_time64(&long_time);

	//Конвертация в местное время
	err = _localtime64_s(&newtime, &long_time);

	if (err)
	{
		printf("Invalid argument to _localtime64_s.\n");
		exit(1);
	}

	//Вечернее время
	if (newtime.tm_hour > 12)
	{
		strcpy_s(am_pm, sizeof(am_pm), "PM");
		printf("%d:%d %s\n", newtime.tm_hour, newtime.tm_min, am_pm);
		milliSec = newtime.tm_hour * 3600000 + newtime.tm_min * 60000 + newtime.tm_sec * 1000;
		printf("Millisec = %lld millisec.\n", milliSec);
	}
	//Буднее время
	else
	{
		strcpy_s(am_pm, sizeof(am_pm), "AM");
		printf("%d:%d %s\n", newtime.tm_hour, newtime.tm_min, am_pm);
		milliSec = newtime.tm_hour * 3600000 + newtime.tm_min * 60000 + newtime.tm_sec * 1000;
		printf("Millisec = %lld millisec.\n", milliSec);
	}
	time_t rawtime = time(NULL);
	
}

void Date::localTime()
{
	struct tm newtime;
	__time64_t long_time;
	errno_t err;

	//Конвертация времени в 64-битную систему
	_time64(&long_time);

	//Конвертация в местное время
	err = _localtime64_s(&newtime, &long_time);

	if (err)
	{
		printf("Invalid argument to _localtime64_s.\n");
		exit(1);
	}

	printf("%d/%d/%d\n", newtime.tm_mday, newtime.tm_mon + 1, 1900 + newtime.tm_year);
	

}

int Date::daysFromBirthDate()
{
	struct tm newtime;
	__time64_t long_time;
	errno_t err;

	//Конвертация времени в 64-битную систему
	_time64(&long_time);

	//Конвертация в местное время
	err = _localtime64_s(&newtime, &long_time);

	if (err)
	{
		printf("Invalid argument to _localtime64_s.\n");
		exit(1);
	}

	printf("%d/%d/%d\n", newtime.tm_mday, newtime.tm_mon + 1, 1900 + newtime.tm_year);
	
}

//void Date::show()
//{
//	time_t rawtime = time(NULL);
//	struct tm * timeinfo = localtime(&rawtime);
//	rawtime = mktime(timeinfo);
//	milliSec = rawtime;
//	struct tm * timeinfo = localtime(&rawtime);
//	timeinfo->tm_year = year - 1900;
//	timeinfo->tm_mon = month - 1;
//	timeinfo->tm_mday = day;
//	rawtime = mktime(timeinfo);
//int myDate = this->milliSec;
//	localTime();
//	
//	milliSec = rawtime;
//	time_t rawtime = milliSec;
//	struct tm * ptm = localtime(&rawtime);
//	ptm = gmtime(&rawtime);
//	cout << ptm->tm_mday << "." << ptm->tm_mon + 1 << "." << ptm->tm_year + 1900 << endl;
//}

int Date::operator-(Date obj)
{
	return int(((((this->milliSec - obj.milliSec) / 60)) / 60) / 24);
}

Date Date::operator+(int days)
{
	return Date(this->day + days, this->month, this->year);
}
void Date::operator+=(int days)
{
	this->milliSec += days * 86400;
}

Date::~Date()
{
}