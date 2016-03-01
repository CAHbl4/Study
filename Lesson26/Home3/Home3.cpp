#include <iostream>
#include <windows.h>
using namespace std;

/*
3.	Написать функцию, принимающую в качестве аргумента, указатели на два массива (А и В) и размеры массивов. 
Функция проверяет, является ли массив В подмножеством массива А и возвращает указатель на начало найденного фрагмента, 
либо возвращает 0 в противном случае.
*/

//Заполняет массив псевдо-случайными числами в заданном диапазоне
void fill_rand(int* arr, int length, int left, int right);

//Выводит элементы массива разделенные пробелами в одну линию
void print_arr(int* arr, int size);

//Функция для нахождения подмножества в массиве a
int* contains(int* a, int* b, int n, int m);

void main()
{
	setlocale(LC_CTYPE, "Rus");

	//Переменные для настройки консоли
	HANDLE hConsole;
	WORD currentConsoleAttr = 0;
	CONSOLE_SCREEN_BUFFER_INFO csbi;

	//Получаем хэндл консоли
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	//Записываем текущие параметры консоли
	if (GetConsoleScreenBufferInfo(hConsole, &csbi))
		currentConsoleAttr = csbi.wAttributes;

	//Размеры массивов
	int n = 100, m = 3;

	//Выделяем память для массивов
	int* a = new int[n];
	int* b = new int[m];

	//Заполняем массивы случайными числами от 0 до 3
	fill_rand(a, n, 0, 3);
	fill_rand(b, m, 0, 3);

	//Получаем указатель на начало подмножества в массиве a
	int* ptr = contains(a, b, n, m);

	//Если указатель не пустой
	if (ptr)
	{
		//Выводим на экран массив а
		cout << "Массив A" << endl;
		for (int i = 0; i < n; i++)
		{
			//Если добрались в цикле до начала подмножества
			if (a + i == ptr)
			{
				//Меняем цвет консоли
				SetConsoleTextAttribute(
					hConsole,
					FOREGROUND_RED | FOREGROUND_INTENSITY);
			}
			//Если добрались до конца подмножества
			if (a + i == ptr + m)
			{
				//Меняем цвет на начальный
				SetConsoleTextAttribute(
					hConsole,
					currentConsoleAttr);
			}
			cout << a[i] << " ";
		}
		cout << endl << endl;

		//Выводим на экран массив b
		cout << "Массив B" << endl;
		print_arr(b, m);
		cout << endl;

		//Выводим адрес указателя
		cout << "Массив B является подмножеством массива A, "
			<< "начало подмножества в массиве находится по адресу 0x"
			<< ptr;
	}
	else
	{
		//Выводим на экран массив а
		cout << "Массив A" << endl;
		print_arr(a, n);
		cout << endl;

		//Выводим на экран массив b
		cout << "Массив B" << endl;
		print_arr(a, m);
		cout << endl;

		cout << "Массив B не является подмножеством массива A";
	}

	delete[] a , b;
	cout << endl;
	system("pause");
}

int* contains(int* a, int* b, int n, int m)
{
	//Флаг указывающий что подмножество найдено
	bool contain;

	//Запускаем цикл поиска от начала массива до конца минус размер искомого подмножества
	for (int i = 0; i < n - m + 1; i++)
	{
		contain = true;
		//Во втором цикле поочередно сравниваем элементы a с элементами b
		for (int j = 0; j < m; j++)
		{
			//Если элементы не совпадают
			if (*(a + i + j) != *(b + j))
			{
				//Значит на текущем шаге подмножество не найдено
				contain = false;
				//Прерываем цикл
				break;
			}
		}
		//Если подмножество было найдено возвращаем указатель на первый элемент подмножества
		if (contain) return a + i;
	}

	//Возвращаем пустой указатель если подмножество не найдено
	return nullptr;
}

void fill_rand(int* arr, int length, int left, int right)
{
	for (int i = 0; i < length; i++)
	{
		*(arr + i) = rand() % (right - left + 1) + left;
	}
}

void print_arr(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		std::cout << arr[i] << " ";
	}
	cout << endl;
}