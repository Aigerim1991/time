// ConsoleApplication54.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <clocale>
#include <string>
#include <stdio.h>
#include "Date.h"

	using namespace std;
//1. ������� ����� Date.
//2. � �������� ������� ���������� ���������� ��� �������� ������� � ��������� �������(�������������).
//3. ������� ����������� �� ���������.
//4. �������� ����������� ��� ����� ���� � ���� Date(����, �����, ���).
//5. ������� �����, �� ������������ ��������, ��� ��������� �������� ���������� �������.
//6. �������� ����� ��� ������ � ������� ������� � ���� ��.��.����.
//7. ����������� �������� ���������, ��� ����������� �������� ���� ���.������������ ���������� ����.
//8. ����������� �������� �������� ��� ���������� ���� �� ������������ ���������� ����.
//9. ����������� �������� ������������ �������� ��� ���������� ���� �� ������������ ���������� ����.

int main()
{
	setlocale(LC_ALL, "rus");
	Date cur(4, 5, 2017);
	Date bh(4,7,1991);


	/*cur.show();*/
	cout << "� ������ ��� �������� ������ " << (cur - bh) << " ����\n";

	cur = cur + 5;
	cur += 5;

	//cur.show();	// 14.05.2017

	Date birthDate;
	cout << "� ������ ��� �������� ������ " << birthDate.daysFromBirthDate() << " ����\n";

	cin.get(); cin.get();

    return 0;
}

