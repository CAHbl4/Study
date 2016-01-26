#include <iostream>

/*
Напишите программу, которая выполняет поэлементную сумму двух массивов и результат заносит в третий массив.
*/

using namespace std;

void main() {
	setlocale(LC_CTYPE, "Rus");

	//Размер массивов
	const int N = 10;

	//Массивы с данными
	int a[N], b[N];

	//Результирующий массив
	int c[N];

	printf_s("a[%d]\tb[%d]\tc[%d]\n", N, N, N);

	//Заполняем массивы a, b случайными числами и присваеваем сумму в массив c, выводим результаты на экран
	for (int i = 0; i < N; i++)
	{
		a[i] = rand() % 201 - 100;
		b[i] = rand() % 201 - 100;
		c[i] = a[i] + b[i];
		printf_s("%5d\t%5d\t%5d\n", a[i], b[i], c[i]);
	}


	cout << endl;
	system("pause");
}