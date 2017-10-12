// 2.cpp: определяет точку входа для консольного приложения.
//
//Автор: Бабайцев Алексей
/*Задано множество точек на двумерной плоскости.
Найти 3 точки, которые составляют треугольник наибольшего периметра*/
#include "stdafx.h"
#include "math.h"
#include <stdio.h>
#include <iostream>


using namespace std;
void main(void)
{
	const int N = 6;
	int i, j, k, firstPoint, secondPoint, threePoint;
	double a, b, c, p, max = 0;
	bool flag = false;
	int X[N], Y[N];
	for (i = 0; i < N; i++) 
	{
		cout << "Input " << i + 1 << " point"<<endl;
		cin >> X[i] >> Y[i];
	}
	for (i = 0; i<N; i++)
	{
		for (j = i + 1; j<N; j++)
		{
			for (k = j + 1; k<N; k++)
			{
				if (((X[i]-X[k])*(Y[j]-Y[k])-((X[j]-X[k])*(Y[i]-Y[k]))==0))
					continue;

				a = sqrt((X[i] - X[j])*(X[i] - X[j]) + (Y[i] - Y[j])*(Y[i] - Y[j]));
				b = sqrt((X[i] - X[k])*(X[i] - X[k]) + (Y[i] - Y[k])*(Y[i] - Y[k]));
				c = sqrt((X[j] - X[k])*(X[j] - X[k]) + (Y[j] - Y[k])*(Y[j] - Y[k]));

				if ((a + b > c) && (a + c > b) && (b + c > a))
				{ 
					p = a + b + c;
					if (p > max)
					{
						max = p;
						firstPoint = i; secondPoint = j; threePoint = k;
						flag = true;
					}
				}
			}
		}
	}

	if (flag)
	{
		cout << firstPoint + 1 << ' ' << secondPoint + 1 << ' ' << threePoint + 1 << endl;
	}
	else
		cout << "Invalid point" << endl;
	system("pause");
}
