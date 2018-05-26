#pragma once
class Date
{
private:
	//int milliSec;
	int day, month, year;
	long long milliSec;
	/*int SYSyear;
	int SYSmonth;
	int SYSday;*/
public:
	Date();
	Date(int date_day, int date_month, int date_year);
	void convertToSec();
	void localTime();
	int daysFromBirthDate();
	//void show();
	//void SystemDateMillisec();

	//Date DayMonthYear();
	//void DayMonthYearS();
	int operator-(Date obj);
	Date operator+(int days);
	void operator+=(int days);
	~Date();

};

