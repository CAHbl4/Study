#include <stdio.h>
#include <windows.h>

/*
* Практическая работа №1
* 
* Вариант 7: Определить, есть ли в массиве простые числа. Если да, то вывести их на экран.
*
* Первый вариант решения - используется обычная адресация элементов массива.
*
* Александр Матузов, 2 марта 2016
*/

//Начальный размер массива
#define SIZE	30

//Перевод строки в кодировку консоли
char* Rus(const char* text);

//Чтение массива с клавиатуры
int read_array(int arr[], int n);

//Вывод массива на экран
void print_array(int arr[], int n);

//Определение является ли число простым
int is_prime(int a);

//Вывод всех простых чисел на экран
void print_primes(int arr[], int n);


int main(void)
{

	//Здесь будем хранить количество введеных элементов
	int n;

	int arr[SIZE];

	//Читаем с клавиатуры элементы массива и сохраняем их количество
	if ((n = read_array(arr, SIZE))) {

		//Выводим на экран исходный массив
		printf(Rus("Исходный массив:\n"));
		print_array(arr, n);

		//Выводим на экран все простые числа
		printf(Rus("Простые числа:\n"));
		print_primes(arr, n);
	}
	return 0;
}

/*
* Function:  read_array
* --------------------
* Читает целые числа с клавиатуры и сохраняет их в массив
*
*  arr:		массив для сохранения
*  n:		размер массива
*
*  returns: количество сохраненных элементов
*/
int read_array(int arr[], int n)
{
	int num, ch, i = 0;

	printf(Rus("Вводите целые числа до заполнения массива или s для завершения ввода. Размер массива: %d\n"), n);

	// i != size
	do
	{
		//Если мы смогли прочитать целое число
		if (scanf("%d", &num))
		{
			//Сохраняем его в массив
			arr[i++] = num;
		}
		else
		{
			//Если в буфере не целое - читаем один символ
			if ((ch = getchar()) == (int)'s')
			{
				//Выходим из цикла если введен 's'
				break;
			}
			printf(Rus("%c - некорректный символ, вводите целые числа.\n"), ch);
		}
	}
	while (i != n);

	return i;
}

/*
* Function:  is_prime
* --------------------
* Проверяет является ли число простым
*
*  n:		число для проверки
*
*  returns: 1 если число простое и 0 если нет
*/
int is_prime(int n)
{
	if (n < 2) return 0;
	int i;
	for (i = 2; i < n / 2; i++)
	{
		if (!(n % i)) return 0;
	}
	return 1;
}

/*
* Function:  print_primes
* --------------------
* Печатает все простые числа из массива
*
*  arr:		массив
*  n:		количество элементов для проверки
*
*/
void print_primes(int arr[], int n)
{
	int i, have_primes = 0;
	if (n > 0) {
		for (i = 0; i < n; i++)
		{
			if (is_prime(arr[i]))
			{
				have_primes = 1;
				printf("%d ", arr[i]);
			}
		}
		if (!have_primes) printf(Rus("В массиве нет простых чисел"));
	} else
	{
		printf(Rus("Неверный размер массива"));
	}
	printf("\n");
}

/*
* Function:  print_array
* --------------------
* Печатает все элементы массива
*
*  arr:		массив
*  n:		количество элементов
*
*/
void print_array(int arr[], int n)
{
	int i;
	if (n > 0) {
	for (i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	}
	else
	{
		printf(Rus("Неверный размер массива"));
	}
	printf("\n");
}


char bufRus[256];
/*
* Function:  Rus
* --------------------
* Переводит строку в кодировку консоли
*
*  text:	исходная строка
*
*  returns: Строка в кодировке консоли
*/
char* Rus(const char* text)
{
	CharToOemA(text, bufRus);
	return bufRus;
}