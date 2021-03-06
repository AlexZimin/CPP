// Lab2.cpp : Defines the entry point for the console application.
//
//Бабайцев Алексей
/*Создать класс Date для работы с датами в формате “год.месяц.день”. Дата
представляется структурой с тремя полями типа unsigned int: для года месяца и дня.
Класс должен включать не менее трех функций инициализации : числами, строкой вида
“год.месяц.день”(например, “2016.04.07”) и датой.Обязательно должны быть
реализованы : вычисление даты чрез заданное количество дней, вычитание заданного
количества дней из даты, определение високосности года, присвоение и получение
отдельных частей(год, месяц, день), сравнение дат(до, после, равно), вычисление
количества дней между датами.*/

#include "stdafx.h"
#include <iostream>
#include "dateClass.h"
using namespace std;

int main() {
	int answer;
	cout << "Select an action" << endl;
	cout << "1. Date in N days" << endl;
	cout << "2. Subtraction of N days from the date" << endl;
	cout << "3. Determination leap year" << endl;
	cout << "4. Comparasion dates" << endl;
	cout << "5. Calculating the number of days between dates" << endl;
	cout << "6. Test all function" << endl;
	cin >> answer;
	switch (answer) {
	case 1: {
		cout << "Enter date and number days" << endl;
		Date firstDate = Date::initializationDate();
		cout << "Enter N" << endl;
		int n;
		cin >> n;
		Date result = firstDate + n;
		cout << "Result: ";
		result.display();
		break;
	}
	case 2: {
		cout << "Enter date and number days" << endl;
		Date firstDate = Date::initializationDate();
		cout << "Enter N" << endl;
		int n;
		cin >> n;
		Date result = firstDate - n;
		cout << "Result: ";
		result.display();
		break;
	}
	case 3: {
		cout << "Enter year" << endl;
		size_t year;
		cin >> year;
		bool result = Date::isLeapYear(year);
		cout << "Result: " << result << endl;
		break;
	}
	case 4: {
		cout << "Enter 2 dates:" << endl;
		Date firstDate = Date::initializationDate();
		Date secondDate = Date::initializationDate();
		if (firstDate == secondDate) {
			cout << "Dates equal" << endl;
		}
		else {
			cout << "Dates not equal" << endl;
			if (firstDate < secondDate) {
				cout << "First less second" << endl;
			}
			else {
				cout << "First more second" << endl;
			}
		}
		break;
	}
	case 5: {
		cout << "Enter first date: " << endl;
		Date firstDate = Date::initializationDate();
		cout << "Enter second date: " << endl;
		Date secondDate = Date::initializationDate();
		int result = Date::different(firstDate, secondDate);
		cout << result << endl;
		break;
	}
	case 6: {
		cout << "Test section:" << endl;
		cout << "1. Date in N days" << endl;
		Date firstDate(2017, 11, 21);
		firstDate.display();
		int n = 365;
		cout << "Entered N: " << n << endl;
		Date result1 = firstDate + n;
		result1.display(); // must be 2018.11.21
		cout << "-----------------------" << endl;
		cout << "2. Subtraction of N days from the date" << endl;
		Date secondDate("1975.1.1");
		secondDate.display();
		int m = 1826;
		cout << "Entered N: " << m << endl;
		Date result2 = secondDate - m;
		cout << "Result: ";
		result2.display(); //must be 1970.1.1
		cout << "-----------------------" << endl;
		cout << "3. Determination leap year" << endl;
		int year1 = 2017;
		int year2 = 2000;
		bool result3 = Date::isLeapYear(year1);
		bool result4 = Date::isLeapYear(year2);
		cout << "Result: " << year1 << " -> " << result3 << endl;//must be False
		cout << "Result: " << year2 << " -> " << result4 << endl;//must be True
		cout << "-----------------------" << endl;
		cout << "4. Comparasion dates" << endl;
		Date thridDate(2017, 11, 12);
		Date fourDate("1970.1.1");
		thridDate.display();
		fourDate.display();
		if (thridDate == fourDate) {
			cout << "Dates equal" << endl;
		}
		else {
			cout << "Dates not equal" << endl;
			if (thridDate < fourDate) {
				cout << "First less second" << endl;
			}
			else {
				cout << "First more second" << endl;
			}
		}
		cout << "-----------------------" << endl;
		cout << "5. Calculating the number of days between dates" << endl;
		Date fiveDate(1975, 1, 1);
		Date sixDate(1970, 1, 1);
		fiveDate.display();
		sixDate.display();
		int result5 = Date::different(fiveDate, sixDate);
		cout << result5 << endl; //must be 1826
	}
	default: {
		cout << "Invalid input. Repeat enter" << endl;
	}
	}

	system("pause");
	return 0;
}