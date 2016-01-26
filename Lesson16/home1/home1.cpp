#include <iostream>

using namespace std;

void main() {
	setlocale(LC_CTYPE, "Rus");

	/*
	Необходимо отсортировать первые две трети массива в порядке возрастания если среднее арифметическое 
	всех элементов больше нуля; иначе - лишь первую треть. остальную часть массива не сортировать а расположить в обратном порядке.
	*/

	//Код программы

	//Количество элементов массива
	const int N = 30;
	//Массив
	int arr[N];

	//Заполняем массив случайными числами
	for (int i = 0; i < N; i++)
	{
		arr[i] = rand() % 201 - 100;
	}

	//Выводим на экран исходный массив
	for (int i = 0; i < N; cout << arr[i] << ' ', i++);
	cout << endl;
	
	//Сумма элементов массива
	int sum = 0;

	//Находим сумму элементов
	for (int i = 0; i < N; i++)
	{
		sum += arr[i];
	}

	//Среднее арифметическое
	int avg = sum / N;
	cout << "Среднее арифметическое = " << avg << endl;

	//Если среднее арифмитическое больше нуля
	if (avg > 0) {

		//Сортируем 2/3 массива
		for (int i = 0; i < N * 2/3 - 1; i++)
		{
			int min = i;
			for (int j = i + 1; j < N * 2 / 3; j++)
			{
				if (arr[j] < arr[min]) min = j;
			}
			if (min != i) {
				int tmp = arr[i];
				arr[i] = arr[min];
				arr[min] = tmp;
			}
		}

		//Делаем реверс оставшейся части
		for (int i = N * 2 / 3; i < N * 5 / 6; i++)
		{
			int tmp = arr[i];
			arr[i] = arr[N - (i - N * 2 / 3) - 1];
			arr[N - (i - N * 2 / 3) - 1] = tmp;
		}
	}

	//Если среднее арифмитическое <= 0
	else {
		//Сортируем 1/3 массива
		for (int i = 0; i < N / 3 - 1; i++)
		{
			int min = i;
			for (int j = i + 1; j < N / 3; j++)
			{
				if (arr[j] < arr[min]) min = j;
			}
			if (min != i) {
				int tmp = arr[i];
				arr[i] = arr[min];
				arr[min] = tmp;
			}
		}

		//Делаем реверс оставшейся части
		for (int i = N / 3; i < N * 2 / 3; i++)
		{
			int tmp = arr[i];
			arr[i] = arr[N - (i - N / 3) - 1];
			arr[N - (i - N / 3) - 1] = tmp;
		}
	}

	//Выводим результат
	for (int i = 0; i < N; cout << arr[i] << ' ', i++);

	cout << endl;
	system("pause");
}