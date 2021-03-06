// Lab4.cpp: определяет точку входа для консольного приложения.
//

//2B
#include "stdafx.h"
#include <iostream>
#include "HeadFunctions.h"

//проверка корректности символа
bool CorrectCh(char ch)
{
	return ch != '?' && ch != '<' && ch != '>' && ch != '*' &&
		ch != '|' && ch != '/' && ch != ':';
}

//проверка корректности имени файла
bool CorrectFileName(std::string filename)
{
	for (int i = 0; i < filename.length(); ++i)
	{
		if (!CorrectCh(filename[i]))
			return false;
	}
	return true;
}

//функция ввода файла
bool InputFile(std::string &filename)
{
	std::cout << "Введите имя файла: ";
	std::cin >> filename;
	if (!CorrectFileName(filename))
	{
		std::cout << "Введено некорректное имя файла" << std::endl;
		return false;
	}
	return true;
}

//главное меню
void MainMenu()
{
	std::fstream *filein = nullptr;
	std::deque<int> queue;
	std::string filename;
	int ans, last = 11, M, N, k;
	for (;;) {
		std::cout << "Выберите пункт меню" << std::endl;
		do {
			std::cout << "1 - Загрузить файл случайными числами с помощью цикла" << std::endl;
			std::cout << "2 - Загрузить файл случайными числами с помощью generate" << std::endl;
			std::cout << "3 - Создать очередь из файла" << std::endl;
			std::cout << "4 - Преобразование очереди " << std::endl;
			std::cout << "5 - Преобразование очереди (через итераторы)" << std::endl;
			std::cout << "6 - Преобразование очереди через trasform" << std::endl;
			std::cout << "7 - Преобразование очереди через for_each" << std::endl;
			std::cout << "8 - Сумма чисел" << std::endl;
			std::cout << "9 - Среднее арифметическое чисел" << std::endl;
			std::cout << "10 - Вывод на консоль" << std::endl;
			std::cout << "11 - Вывод в файл" << std::endl;
			std::cout << "0 - Выход" << std::endl;
			std::cin >> ans;
		} while (ans < 0 || ans > last);
		switch (ans)
		{
		case 0:
			if (filein != nullptr)
				(*filein).close();
			queue.clear();
			return;
		case 1:
		case 2:
			if (!InputFile(filename))
				break;
			std::cout << "Введите диапазон: ";
			std::cin >> M;
			std::cout << "Введите кол-во: ";
			std::cin >> N;
			if (N < 1) {
				std::cout << "Введено отрицательное значенеи кол-ва" << std::endl;
				break;
			}
			ans == 1 ? filein = RandomNumsCycle(filename, M, N) : filein = RandomNumsGenerate(filename, M, N);
			if (filein != nullptr)
				std::cout << "Файл создан" << std::endl;
			break;


		case 3:
			if (!InputFile(filename))
				break;
			if (filein == nullptr)
				filein = new std::fstream();
			(*filein).open(filename, std::fstream::in);
			if (!(*filein).is_open()) {
				std::cout << "Файла не существует" << std::endl;
				break;
			}
			queue = DequeFromFile(filein);
			(*filein).close();
			std::cout << "Очередь загружена" << std::endl;
			break;
		case 4:
		case 5:
		case 6:
		case 7:
			std::cout << "Введите номер элемента: ";
			std::cin >> k;
			try {
				if (4 == ans) {
					queue = Modify(queue, k);
				}
				else if (5 == ans) {
					queue = Modify(queue.begin(), queue.end(), k);
				}
				else if (6 == ans) {
					ModifyTransform(queue, k);
				}
				else {
					ModifyForEach(queue, k);
				}
				std::cout << "Очередь изменена" << std::endl;
			}
			catch (const char* msg) {
				std::cout << msg << std::endl;
			}
			break;
		case 8:
			std::cout << Sum(queue) << std::endl;
			break;
		case 9:
			try {
				std::cout << ArithmeticMean(queue) << std::endl;
			}
			catch (const char* msg) {
				std::cout << msg << std::endl;
			}
			break;
		case 10:
			Print(queue);
			std::cout << std::endl;
			break;
		case 11:
			if (!InputFile(filename))
				break;
			if (!SaveToFile(queue, filename))
				std::cout << "Не удалось сохранить в файл" << std::endl;
			break;
		}
		system("pause");
	}
	if (filein != nullptr)
		delete filein;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	MainMenu();
	return 0;
}