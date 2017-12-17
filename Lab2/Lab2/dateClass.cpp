
#include "stdafx.h"
#include <iostream>
#include <string>
#include "dateClass.h"

using namespace std;

int Date::cmp(const Date& lval, const Date& rval) {
	if (lval.getYear() != rval.getYear())
		return lval.getYear() - rval.getYear();
	if (lval.getMonth() != rval.getMonth())
		return lval.getMonth() - rval.getMonth();
	if (lval.getDay() != rval.getDay())
		return lval.getDay() - rval.getDay();
	return 0;
}

Date::Date(const size_t& y = 1970, const size_t& m = 1, const size_t& d = 1) {
	this->year = y;
	this->month = m;
	this->day = d;
}

Date::Date(const char *str) { // date in format "YYYY.MM.DD"
	string a;
	int n = 0, date[3];
	size_t len = strlen(str);
	for (int i = 0; i < len + 1; i++) {
		if (str[i] != '.' && str[i] != '\0') {
			a += str[i];
		}
		else {
			date[n] = atoi(a.c_str());
			n++;
			a = "";
		}
	}
	this->year = date[0];
	this->month = date[1];
	this->day = date[2];
}

Date::Date(const Date &d) {
	this->year = d.year;
	this->month = d.month;
	this->day = d.day;
}

size_t Date::getYear() const { return this->year; }

size_t Date::getMonth() const { return this->month; }

size_t Date::getDay() const { return this->day; }

void Date::setYear(size_t y) { this->year = (y >= 1970 && y<3000) ? y : 0; }

void Date::setMonth(size_t m) { this->month = (m >= 1 && m <= 12) ? m : 0; }

void Date::setDay(size_t d) { this->day = (d >= 1 && d<31) ? d : 0; }

bool Date::isLeapYear(size_t year) {
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int Date::lastDayInMonth(const int& month, const int& year)
{
	if (month == 2) return isLeapYear(year) ? 29 : 28;
	return monthDays[month - 1];
}

bool Date::operator < (const Date& oper1) {
	return cmp(*this, oper1) < 0;
}

bool Date::operator > (const Date& oper1) {
	return cmp(*this, oper1) > 0;
}

bool Date::operator == (const Date& oper1) {
	return cmp(*this, oper1) == 0;
}

int Date::countLeapYears() {
	size_t years = this->year;
	if (this->getMonth() <= 2)
		years--;
	return years / 4 - years / 100 + years / 400;
}

long Date::sum(Date dt) {
	long int tmp = dt.getYear() * 365 + dt.getDay() + dt.daysInYear[dt.getMonth()];
	return tmp += dt.countLeapYears();
}

int Date::different(Date first, Date second) {
	long int n1 = first.sum(first);
	long int n2 = second.sum(second);
	return abs((n2 - n1));
}

Date Date::operator + (int days) {
	size_t nMaxDays = lastDayInMonth(this->month, this->year);
	int nYear = this->year;
	int nMonth = this->month;
	int nDays = this->day + days;
	while (nDays > nMaxDays) {
		nDays -= nMaxDays;
		++nMonth;
		if (nMonth > 12) {
			nMonth = 1;
			++nYear;
		}
		nMaxDays = lastDayInMonth(nMonth, nYear);
	}
	return Date(nYear, nMonth, nDays);
}

Date Date::operator - (size_t days) {
	if (0 > (this->day - days)) {
		return Date(this->year, this->month, this->day - days);
	}
	size_t nYear = this->year;
	int nDays = days;
	nDays -= this->day;
	size_t nMonth = this->month - 1;
	if (nMonth < 1) {
		nMonth = 12;
		--nYear;
	}
	size_t nDaysInMonth = lastDayInMonth(nMonth, nYear);
	while (nDays >= 0) {
		nDays -= nDaysInMonth;
		if (nDays > 0) {
			--nMonth;
			if (nMonth < 1) {
				nMonth = 12;
				--nYear;
			}
		}
		nDaysInMonth = lastDayInMonth(nMonth, nYear);
	}
	return Date(nYear, nMonth, (0 < nDays ? nDays : -nDays));
}

std::string Date::toString() {
	return to_string(year) + string(".") + to_string(month) + string(".") + to_string(day);
}

void Date::display() {
	cout << "Date: "  << this->toString() << endl;
}

Date Date::initializationDate() {
	int answer;
	cout << "In which format do you want enter date?" << endl;
	cout << "1. Numbers" << endl;
	cout << "2. String" << endl;
	cin >> answer;
	switch (answer) {
	case 1: {
		size_t year, month, day;
		cout << "Type in a space year,month,day " << endl;
		cin >> year >> month >> day;
		Date obj(year, month, day);
		return obj;
		break;
	}
	case 2: {
		char str[80];
		cout << "Date in format 'year.month.day'" << endl;
		cin >> str;
		Date obj(str);
		return obj;
		break;
	}
	default: {
		cout << "Invalid input. Repeat enter." << endl;
	}
	}
}

