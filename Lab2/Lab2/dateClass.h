#pragma once
class Date
{
private:
	size_t day;
	size_t month;
	size_t year;
	const int monthDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	const int daysInYear[12] = { 31,59,90,120,151,181,212,243,273,304,334,365 };
	int cmp(const Date& lval, const Date& rval);

public:
	Date(const size_t& y, const size_t& m, const size_t& d);

	Date(const char *str);

	Date(const Date &d);
	size_t getYear() const;

	size_t getMonth() const;

	size_t getDay() const;

	void setYear(size_t y);

	void setMonth(size_t m);

	void setDay(size_t d);

	int lastDayInMonth(const int& month, const int& year);

	static bool isLeapYear(size_t year);

	bool operator < (const Date& oper1);

	bool operator > (const Date& oper1);

	bool operator == (const Date& oper1);

	int countLeapYears();

	long sum(Date dt);

	static int different(Date first, Date second);

	Date Date::operator + (int days);

	Date Date::operator - (size_t days);

	std::string toString();

	void display();

	static Date initializationDate();
};
