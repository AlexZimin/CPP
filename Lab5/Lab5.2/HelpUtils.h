#pragma once
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <fstream>
#include <istream>
#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
using namespace std;

template <class Type>
Type InputNumber(Type min, Type max, string message)
{
	Type n;
	do
	{
		cout << message;
		while ((!(cin >> n)) || cin.get() != '\n')
		{
			cout << "������������ ���� !!  ��������� ����!\n";
			cin.clear();  // ��������������� ����� ���� �� � ��������� ���������
			cin.sync();   // ������� ����� �� ��������� ��������
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << message;
		}
	} while ((n < min) || (n > max));
	return n;
}

// ���� ����������
string InputInformation(string messge)
{
	string a;
	cout << messge;
	cin >> a;
	return a;
}

// �������� ������� �� ������������ � ����� �����
bool CorrectSymbol(char c)
{
	switch (c)
	{
	case '.':
	case '*':
	case '?':
	case '<':
	case '>':
	case ':':
	case '|':
	case '/':
		return false;
	default:
		return true;
	}
}


// �������� ����� ����� �� �����������
bool CorrectName(string name)
{
	int i = 0;
	bool goodsm = true;
	for (int i = 0; (i < name.length() && goodsm); i++)
		goodsm = CorrectSymbol(name[i]);
	return goodsm;
}

// ���� ����� �����
string InputFileName()
{

	string filename;
	do
	{
		cout << "������� ��� ����� (��� ����������, ��� ����� 20 ��������? ����� ��������):  ";
		cin >> filename;
		if (filename.length() > 20)
			filename.erase(filename.begin(), filename.begin() + 20);
		if (CorrectName(filename))
		{
			filename = filename + ".txt";
			break;
		}
		else
			cout << "�������� ��� �����\n";
	} while (true);

	return filename;
}



