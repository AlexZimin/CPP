// Lab3.cpp : Defines the entry point for the console application.
//
//Бабайцев Алексей
/*Реализовать шаблон класса динамический массив (Vector<X>), хранящий элементы
произвольного типа. Класс должен содержать:
Инициализация массива;
Добавление элемента в начало массива;
Добавление элемента в конец массива;
Показ всех элементов массива.
a)
Удаление всех элементов массива;
Определение количества элементов массива;
Проверка массива на пустоту;
Удаление первого элемента;
Удаление последнего элемента;*/
#include "stdafx.h"
#include <iostream>
#include <string>
#include "vector.cpp"
using namespace std;

int main()
{
	TArray<string> A;
	TArray<string> B;
	int n;
	cout << "Enter count elements" << endl;
	cin >> n;
	cout << "Enter elements" << endl;
	for (int i = 0; i < n; i++) {
		string t;
		cin >> t;
		A.pushBack(t);
		B.pushFront(t);
	}
	cout << "----Test show(), pushFront(), pushBack()----" << endl;
	A.show();
	B.show();
	cout << "----Test popFront() and popBack()----" << endl;
	while (A.length())
	{
		cout <<" " << A.popFront() << endl;
	}
	cout << "----------" << endl;
	while (B.length())
	{
		cout << " " << B.popBack() << endl;
	}
	cout << "----Test isEmpty()-----" << endl;
	cout << "Array A isEmpty? : " << A.isEmpty() << endl;
	cout << "Array B isEmpty? : " << B.isEmpty() << endl;
	cout << "--------" << endl;
	system("pause");
	return 0;
}


