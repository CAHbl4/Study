#include <iostream>

/*
В одномерном массиве, состоящем из N вещественных чисел вычислить:
• Сумму отрицательных элементов.
• Произведение элементов, находящихся между min и max элементами.
• Произведение элементов с четными номерами.
• Сумму элементов, находящихся между первым и последним отрицательными элементами.

*/

using namespace std;

void main() {
	setlocale(LC_CTYPE, "Rus");

	//Размер массива
	const int N = 10;

	//Массив
	double arr[N];

	cout << "Элементы массива: ";

	//Заполнение массива случайными элементами от -100.00 до 100.00
	for (int i = 0; i < N; i++)
	{
		arr[i] = rand() % 201 - 100 + (float)(rand() % 100) / 100;
		cout << arr[i] << " ";
	}
	cout << endl;

	//Сумма отрицательных элементов
	double sumNegative = .0;

	//Суммируем все отрицательные элементы
	for (int i = 0; i < N; i++)
	{
		if (arr[i] < 0) sumNegative += arr[i];
	}
	cout << "Сумма отрицательных чисел: " << sumNegative << endl;

	//Индексы элементов с наибольшим и наименьшим значением
	int minKey = 0, maxKey = 0;

	//Находим минимальное и максимальное значение
	for (int i = 0; i < N; i++)
	{
		if (arr[i] < arr[minKey]) minKey = i;
		if (arr[i] > arr[maxKey]) maxKey = i;
	}
	cout << "Минимальный элемент arr[" << minKey << "] = " << arr[minKey] << endl;
	cout << "Максимальный элемент arr[" << maxKey << "] = " << arr[maxKey] << endl;

	//Произведение элементов, находящихся между min и max элементами
	double minMaxMult = 1;
	
	//Считаем произведение, с помощью тернарного оператора определяем больший и меньший индекс
	for (int i = (minKey < maxKey ? minKey : maxKey); i <= (minKey > maxKey ? minKey : maxKey); i++) {
		minMaxMult *= arr[i];
	}
	cout << "Произведение элементов, находящихся между min и max элементами: " << minMaxMult << endl;

	// Произведение элементов с четными номерами
	double evenMult = 1.;

	//Считаем произведение четных элементов массива
	for (int i = 0; i < N; i += 2)
	{
		evenMult *= arr[i];
	}
	cout << "Произведение элементов с четными номерами: " << evenMult << endl;

	//Индексы первого и последнего отрицательного элемента массива
	int firstNegativekey, lastNegativeKey;

	//Находим индекс первого отрицательного эллемента
	for (int i = 0; i < N; i++)
	{
		if (arr[i] < 0) {
			firstNegativekey = i;
			break;
		}
	}
	cout << "Первый отрицательный элемент arr[" << firstNegativekey << "] = " << arr[firstNegativekey] << endl;

	//Находим индекс последнего отрицательного элемента массива
	for (int i = N - 1; i >= 0; i--)
	{
		if (arr[i] < 0) {
			lastNegativeKey = i;
			break;
		}
	}
	cout << "Последний отрицательный элемент arr[" << lastNegativeKey << "] = " << arr[lastNegativeKey] << endl;

	//Сумма элементов, находящихся между первым и последним отрицательными элементами
	double sumFirstLastNegative = .0;

	//Считаем сумму
	for (int i = firstNegativekey; i <= lastNegativeKey; i++)
	{
		sumFirstLastNegative += arr[i];
	}

	cout << "Сумма элементов, находящихся между первым и последним отрицательными элементами: " << sumFirstLastNegative;

	cout << endl;
	system("pause");
}