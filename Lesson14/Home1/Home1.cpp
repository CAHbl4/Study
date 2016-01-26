#include <iostream>

using namespace std;

/*
В одномерном массиве, заполненном случайными числами, определить минимальный и максимальный элементы.
*/

//Структура для одного элемента массива
struct elem
{
	//Индекс
	int key;
	//Значение
	int value;
};

//Описание функций для нахождения минимального и максимального элементов
//Пытался находить длинну массива внутри функции, но передаваемый массив превращается в ссылку и sizeof() не работает.
//Поэтому пока будем передавать в функцию количество элементов
elem getMin(int *arr, int num);
elem getMax(int *arr, int num);

void main() {
	setlocale(LC_CTYPE, "Rus");

	//Количество элементов массива
	const int NUM = 20;

	//Создаем массив
	int arr[NUM];

	//Заполняем массив псевдослучайными числами
	for (int i = 0; i < NUM; i++)
	{
		arr[i] = rand();
	}

	//Находим максимальный и минимальный элементы
	elem min = getMin(arr, NUM);
	elem max = getMax(arr, NUM);

	//Выводим результаты на экран
	cout << "Минимальный элемент arr[" << min.key << "] = " << min.value << endl;
	cout << "Максимальный элемент arr[" << max.key << "] = " << max.value << endl;

	cout << endl;
	system("pause");
}


//Функция нахождения минимального элемента массива
elem getMin(int *arr, int num) {

	//Объявляем структуру и присваеваем ей нулевой элемент массива
	elem min = { 0, arr[0] };

	//Ищем в цикле меньший элмемент начиная со второго
	for (int i = 1; i < num - 1; i++)
	{
		if (arr[i] < min.value) min = { i, arr[i] };
	}

	return min;
}

//Функция нахождения максимального элемента массива
elem getMax(int *arr, int num) {

	//Объявляем структуру и присваеваем ей нулевой элемент массива
	elem max = { 0, arr[0] };

	//Ищем в цикле максимальный элмемент начиная со второго
	for (int i = 1; i < num - 1; i++)
	{
		if (arr[i] > max.value) max = { i, arr[i] };
	}

	return max;
}