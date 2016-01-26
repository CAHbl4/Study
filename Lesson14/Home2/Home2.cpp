#include <iostream>

using namespace std;

/*
Пользователь вводит прибыль фирмы за год (12 месяцев). Затем пользователь вводит диапазон
(например, 3 и 6 – поиск между 3-м и 6-м месяцем). Необходимо определить месяц, в котором
прибыль была максимальна и месяц, в котором прибыль была минимальна с учетом выбранного диапазона.
*/

//Структура для одного элемента массива
struct elem
{
	//Индекс
	int key;
	//Значение
	int value;
};

//Описание функций

elem getMin(int *arr, int num, int start = 0, int end = -1);
elem getMax(int *arr, int num, int start = 0, int end = -1);
void printMonth(int i);
int getMonth();

void main() {
	setlocale(LC_CTYPE, "Rus");


	//Обьявляем массив
	int arr[12];

	cout << "Введите прибыль за месяц." << endl;

	int i = 0;

	//Заполняем массив
	while (i != 12) {
		//Выводим приглашение на ввод
		cout << i + 1 << ". ";
		printMonth(i + 1);
		cout << ": ";

		//Проверка корректности ввода
		if (cin >> arr[i]) i++;
		else {
			//Очистка буфера ввода при некорректном вводе
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cout << "Ошибка ввода. Повторите." << endl;
		}
	}

	//i1 - начало периода, i2 - конец периода
	int i1 = -1, i2 = -1;

	//Вводим начало и конец периода
	while (1) {

		//Функция getMonth() возвращает -1 при некорректном вводе
		while (i1 == -1) {
			cout << "Введите начало периода (1-12): ";
			i1 = getMonth();
		}

		while (i2 == -1) {
			cout << "Введите конец периода (1-12): ";
			i2 = getMonth();
		}

		//Проверка на корректность дипазона
		if (i1 > i2) {
			i1 = i2 = -1;
			cout << "Месяц начала периода должен быть меньше конца. Повторите ввод" << endl;
		}
		else break;
	}

	//Получаем минимальное значение на выбранном диапазоне
	elem min = getMin(arr, 12, i1, i2);
	
	//Получаем максимальное значение на выбранном диапазоне
	elem max = getMax(arr, 12, i1, i2);


	//Выводим результаты
	cout << "Минимальная прибыль за период: ";
	printMonth(min.key + 1);
	cout << " - " << min.value;

	cout << endl;

	cout << "Максимальная прибыль за период: ";
	printMonth(max.key + 1);
	cout << " - " << max.value;

	cout << endl;
	system("pause");
}

//Функция вывода месяца на экран.
void printMonth(int i) {
	switch (i)
	{
	case 1: cout << "Январь"; break;
	case 2: cout << "Февраль"; break;
	case 3: cout << "Март"; break;
	case 4: cout << "Апрель"; break;
	case 5: cout << "Май"; break;
	case 6: cout << "Июнь"; break;
	case 7: cout << "Июль"; break;
	case 8: cout << "Август"; break;
	case 9: cout << "Сентябрь"; break;
	case 10: cout << "Октябрь"; break;
	case 11: cout << "Ноябрь"; break;
	case 12: cout << "Декабрь"; break;
	}
}

//Функция ввода месяца с клавиатуры. Функция возвращает -1 при некорректном вводе
int getMonth() {
	int m = -1;

	//Проверка на ввод чисел
	if (cin >> m) {

		//Проверка на корректность месяца
		if (!(m >= 1 && m <= 12)) {
			cout << "Месяц должен быть в пределах 1 - 12. Повторите ввод" << endl;
			m = -1;
		}
	}
	else
	{
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout << "Ошибка ввода. Повторите." << endl;
	}
	return m;
}

//Функция нахождения минимального элемента массива
elem getMin(int *arr, int num, int start, int end) {

	//Если не задан параметр конца диапазона при вызове функции приравниваем его к последнему элементу
	if (end = -1) end = num - 1;

	//Объявляем структуру и присваеваем ей первый элемент диапазона
	elem min = { start, arr[start] };

	//Ищем в цикле меньший элмемент начиная со второго элемента диапазона
	for (int i = start + 1; i <= end; i++)
	{
		if (arr[i] < min.value) min = { i, arr[i] };
	}

	return min;
}

//Функция нахождения максимального элемента массива
elem getMax(int *arr, int num, int start, int end) {
	if (end = -1) end = num - 1;

	//Объявляем структуру и присваеваем ей нулевой элемент массива
	elem max = { start, arr[start] };

	//Ищем в цикле максимальный элмемент начиная со второго
	for (int i = start + 1; i <= end; i++)
	{
		if (arr[i] > max.value) max = { i, arr[i] };
	}

	return max;
}