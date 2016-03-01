#include <iostream>
using namespace std;

/*
5.	Даны два массива: А[M] и B[N] (M и  N вводятся с клавиатуры). Необходимо создать третий массив минимально возможного размера, в котором нужно собрать элементы обоих массивов.
*/

//Заполняет массив псевдо-случайными числами в заданном диапазоне
void fill_rand(int* arr, int length, int left, int right);

//Выводит элементы массива разделенные пробелами в одну линию
void print_arr(int* arr, int size);

//Создает набор элементов из массива
void create_set(int* arr, int* size);

void main()
{
	setlocale(LC_CTYPE, "Rus");

	//Размеры массивов
	int n, m;
	cout << "Введите размеры n, m: ";
	cin >> n >> m;

	//Создаем массивы
	int* a = new int[n];
	int* b = new int[m];

	//Заполняем массивы случайными числами и выводим на экран
	fill_rand(a, n, 0, 10);
	cout << "Массив A:" << endl;
	print_arr(a, n);
	cout << endl;
	fill_rand(b, m, 0, 10);
	cout << "Массив B:" << endl;
	print_arr(b, m);
	cout << endl;

	//Размер нового массива
	int size = n + m;

	//Создаем новый массив
	int* c = new int[size];

	int i = 0, j = 0;

	//Помещаем в новый массив элементы из исходных массивов
	for (i = 0; i < n; i++)
	{
		c[j++] = a[i];
	}
	for (i = 0; i < m; i++)
	{
		c[j++] = b[i];
	}

	//Создаем набор
	create_set(c, &size);

	cout << "Уникальные элементы обоих массивов: " << endl;
	print_arr(c, size);
	cout << endl;

	delete[] a , b , c;

	cout << endl;
	system("pause");
}
/*
В процессе работы функции уникальные элементы перемещаются в начало массива, в конце функция переписвает в казателе размер массива
*/
void create_set(int* arr, int* size)
{
	int i, j;

	int new_size = 1;

	//Запускаем цикл по исходному массиву
	for (i = 1; i < *size; i++)
	{
		//Запускаем цикл от начала массива до текущего количества уникальных элементов
		for (j = 0; j < new_size; j++)
		{
			//Если текущий элемент уже есть в наборе прервыаем цикл
			if (arr[i] == arr[j])
				break;
		}

		//Если мы дошли до конца набора и совпадений не было копируем текущий элемент в конец набора
		if (j == new_size)
			arr[new_size++] = arr[i];
	}
	*size = new_size;
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
		cout << arr[i] << " ";
	}
	cout << endl;
}

