#pragma once
#include <stdio.h>
#include <sstream>
#include <math.h>
#include <string>
#include <iostream>
#include <string>
#include "HelpUtils.h"

class Session {
public:
	// ����� �����
	int course;
	// ������� ��������
	string LastName;
	// �������� ����������
	string Discipline;
	// ��� ������
	int group;
	// ����� �������
	int zachetka;
	// ������ �� ����������
	int markofdiscipline;

	// ����������� �� ���������
	Session()
	{
		int course = 0;
		string LastName = "";
		string Discipline = "";
		int group = 0;
		int zachetka = 0;
		int markofdiscipline = 0;
	}


	// ��������� ��������� "������"
	Session ChangeSession(Session &result)
	{
		if (InputNumber(0, 1, "�� ������ �������� ���� " + to_string(result.course) + " (0-���, 1 - ��)\n��� �����: ") == 1)
			result.course = InputNumber(1, 6, "������� ����� ���� (1 - 6): ");
		if (InputNumber(0, 1, "�� ������ �������� ������� �������� " + result.LastName + " (0 - ���, 1 - ��)\n��� �����: ") == 1)
			result.LastName = InputInformation("������� ����� ������� ��������: ");
		if (InputNumber(0, 1, "�� ������ �������� �������� ���������� " + result.Discipline + " (0 - ���, 1 - ��)\n��� �����: ") == 1)
			result.Discipline = InputInformation("������� ����� ����������: ");
		if (InputNumber(0, 1, "�� ������ �������� ��� ������ " + to_string(result.group) + " (0-���, 1 - ��)\n��� �����: ") == 1)
			result.group = InputNumber(0, 99, "������� ����� ��� ������ (0 - 99): ");
		if (InputNumber(0, 1, "�� ������ �������� ����� �������� ������ " + to_string(result.zachetka) + " (0-���, 1 - ��)\n��� �����: ") == 1)
			result.zachetka = InputNumber(0, 999999, "������� ����� ����� �������� ������ (000000 - 999999): ");
		if (InputNumber(0, 1, "�� ������ �������� ���������� " + to_string(result.markofdiscipline) + " (0 - ���, 1 - ��)\n��� �����: ") == 1)
			result.markofdiscipline = InputNumber(2, 5, "������� ������ �� ���������� (2 - 5): ");

		return result;
	}

	// ������������� �������� ��������� ��� ��������� "������"
	Session& operator = (Session c)
	{
		course = c.course;
		LastName = c.LastName;
		Discipline = c.Discipline;
		group = c.group;
		zachetka = c.zachetka;
		markofdiscipline = c.markofdiscipline;

		return (*this);
	}
};

// ������� ����� ��������� "c�����" �� �������
Session InputScreenSession()
{
	Session c;
	c.course = InputNumber(1, 6, "������� ����: ");
	c.LastName = InputInformation("������� ������� ��������: ");
	c.Discipline = InputInformation("������� ����������: ");
	c.group = InputNumber(0, 99, "������� ������ (0 - 100): ");
	c.zachetka = InputNumber(0, 999999, "������� ����� ������� (0 - 999999): ");
	c.markofdiscipline = InputNumber(2, 5, "������� ������ (2 - 5): ");
	return c;
}

// ������� ������ ��������� "c�����" �� �������
void OutputScreenSession(Session c)
{
	cout << "����: " << c.course << endl;
	cout << "������� ��������: " << c.LastName << endl;
	cout << "����������: " << c.Discipline << endl;
	cout << "��� ������: " << c.group << endl;
	cout << "����� �������� ������:" << c.zachetka << endl;
	cout << "������ �� ����������:" << c.markofdiscipline << endl;
}
bool IsEqual(Session c1, Session c2)
{
	return ((c1.zachetka == c2.zachetka) && (c1.Discipline == c2.Discipline) && (c1.LastName == c2.LastName));
}
// ������� ������ ��������� "c�����" �� �������
int OutputAverage(Session c)
{
	return c.markofdiscipline;
}


//������� ��������� "������" � ������
string ToString(Session c, int i)
{
	string result = "������ � " + to_string(i) + "\n" + "����: " + to_string(c.course) + "\n" + "������� ��������: " + c.LastName + "\n" + "����������: " + c.Discipline + "\n" + "��� ������: " + to_string(c.group) + "\n" + "����� �������� ������: "
		+ to_string(c.zachetka) + "\n" + "������ �� ����������: " + to_string(c.markofdiscipline) + "\n";
	return result;
}

//���������� ��������� "������" �� ������
Session ReadFromString(ifstream& input)
{
	Session result;
	string s;
	try
	{
		if (!input.eof())
		{
			getline(input, s);
		}
		if (!input.eof())
		{
			getline(input, s, '\n');
			string wrd = "����: ";
			result.course = atoi(s.substr(wrd.length(), s.length()).c_str());
		}
		if (!input.eof())
		{
			getline(input, s, '\n');
			string wrd = "������� ��������: ";
			result.LastName = s.substr(wrd.length(), s.length());
		}
		if (!input.eof())
		{
			getline(input, s, '\n');
			string wrd = "����������: ";
			result.Discipline = s.substr(wrd.length(), s.length());
		}
		if (!input.eof())
		{
			getline(input, s, '\n');
			string wrd = "��� ������: ";
			result.group = atoi(s.substr(wrd.length(), s.length()).c_str());
		}
		if (!input.eof())
		{
			getline(input, s, '\n');
			string wrd = "����� �������� ������: ";
			result.zachetka = atoi(s.substr(wrd.length(), s.length()).c_str());
		}
		if (!input.eof())
		{
			getline(input, s, '\n');
			string wrd = "������ �� ����������: ";
			result.markofdiscipline = atoi(s.substr(wrd.length(), s.length()).c_str());
		}
	}
	catch (...)
	{
		cout << "������ ������ � ����!" << endl;
	}
	return result;
}


// ����� ������� �������� �� ���������� ��������
// type_search - ��� ������
//1 - �� �����
//2 - �� �������
//3 - �� ����������
//4 - �� ���� ������
//5 - �� ������ �������
//6 - �� ������
bool SearchElement(Session m, Session n, int type_search)
{
	switch (type_search)
	{
	case 1:
		return (m.course == n.course);
	case 2:
		return (m.group == n.group);
	case 3:
		return (m.Discipline == n.Discipline);
	case 4:
		return (m.zachetka == n.zachetka);
	case 5:
		return (m.markofdiscipline == n.markofdiscipline);
	case 6:
		return (m.LastName == n.LastName);
	default:
		return false;
	}
}

// ���� �������� ������ � ����������� �� ���������� ���� 
// type_search - ��� ������
//1 - �� �����
//2 - �� �������
//3 - �� ����������
//4 - �� ���� ������
//5 - �� ������ �������
//6 - �� ������
Session InputChangeTypeSearch(int type_search)
{
	Session result;
	switch (type_search)
	{

	case 1:
		result.course = InputNumber(1, 6, "������� ����: ");
		return result;
	case 2:
		result.group = InputNumber(0, 99, "������� ��� ������: ");
		return result;
	case 3:
		result.Discipline = InputInformation("������� ����������: ");
		return result;
	case 4:
		result.zachetka = InputNumber(0, 999999, "������� ����� �������: ");
		return result;
	case 5:
		result.markofdiscipline = InputNumber(2, 5, "������� ������: ");
		return result;
	case 6:
		result.LastName = InputInformation("������� �������: ");
		return result;
	default:
		return result;
	}
}

// ��������� �������� � ����������� �� ���������� ���� ��� ����������
// type_search - ��� ������
//1 - �� �����
//2 - �� �������
//3 - �� ����������
//4 - �� ���� ������
//5 - �� ������ �������
//6 - �� ������
int Sorte(Session n, Session m, int type_search)
{
	switch (type_search)
	{
	case 1:
		if (n.course > m.course) return 1;
		else if (n.course < m.course) return -1;
		else return 0;
	case 2:
		if (n.group > m.group) return 1;
		else if (n.group < m.group) return -1;
		else return 0;
	case 3:
		if (n.Discipline > m.Discipline) return 1;
		else if (n.Discipline < m.Discipline) return -1;
		else return 0;
	case 4:
		if (n.zachetka > m.zachetka) return 1;
		else if (n.zachetka < m.zachetka) return -1;
		else return 0;
	case 5:
		if (n.markofdiscipline > m.markofdiscipline) return 1;
		else if (n.markofdiscipline < m.markofdiscipline) return -1;
		else return 0;
	case 6:
		if (n.LastName > m.LastName) return 1;
		else if (n.LastName < m.LastName) return -1;
		else return 0;

	default:
		return -2;
	}
}


