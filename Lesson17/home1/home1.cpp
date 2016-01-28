#include <iostream>
using namespace std;

/*
Создайте двухмерный массив. Заполните его случайными числами и покажите на экран. 
Выполните сортировку элементов в каждой строке массива. Полученный результат покажите на экран.
*/

void main() {
	setlocale(LC_CTYPE, "Rus");

	//Код программы

	//Размеры массива
	int const N = 10, M = 20;
	//Объявляем массив
	int arr[N][M];

	//Заполняем массив случайными числами
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			arr[i][j] = rand() % 100;
		}
	}

	//Выводим исходный массив на экран
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cout.width(2);
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;

	//Сортируем массив пузырьком
	//Перебираем в цикле каждый эллемент массива
	for (int i = 0; i < N; i++)
	{
		//Флаг сортировки
		bool sorted;
		int tmp;
		int j = 0;

		//Сортируем текущий элемент
		do {
			sorted = true;
			for (int k = 0; k < M - j - 1; k++) {
				if (arr[i][k] > arr[i][k + 1]) {
					tmp = arr[i][k];
					arr[i][k] = arr[i][k + 1];
					arr[i][k + 1] = tmp;
					sorted = false;
				}
			}
			j++;
		} while (!sorted);
	}

	cout << endl;

	//Выводим отсортированный массив
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cout.width(2);
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;

	cout << endl;
	system("pause");
}