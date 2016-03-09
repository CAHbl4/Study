#include <stdio.h>
#include <windows.h>
#include <math.h>


/*
* Задана квадратная матрица порядка N. Вычислить сумму квадратов
* отрицательных чисел, лежащих выше побочной диагонали
* Программа должна выполнять ввод и вывод матрицы и
* дополнительных данных, выполнять необходимые действия и выводить
* результаты.
* Первый вариант решения - обычная адресация элементов массива;
*
* a.matuzov, 09.03.2016 11:12:27
*/

//Битовые маски для зон матрицы
#define MAIN_DIAG			1
#define SEC_DIAG			2
#define MAIN_DIAG_UP		4
#define MAIN_DIAG_DOWN		8
#define SEC_DIAG_UP			16
#define SEC_DIAG_DOWN		32

//Настраиваемые параметры задания
#define MAX_SIZE			7
#define MIN_SIZE			4
#define TASK_ZONE			SEC_DIAG_UP

//Настройки вывода
#define HIGHLIGHT_COLOR		FOREGROUND_RED | FOREGROUND_INTENSITY


//Объявления функций
UINT8	read_array	(int arr[][MAX_SIZE], size_t n);
void	print_array	(int arr[][MAX_SIZE], size_t n, UINT16 zone, UINT8 width);
UINT64	func_v13	(int arr[][MAX_SIZE], size_t n, UINT16 zone);
UINT16	get_zone	(size_t i, size_t j, size_t n);
int		read_int	();
char*	Rus			(const char* text);

//Переменные для настройки консоли
HANDLE	hConsole;
WORD	currentConsoleAttr = 0;


void main()
{
	//Сохраняем текущие параметры консоли
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (GetConsoleScreenBufferInfo(hConsole, &csbi))
		currentConsoleAttr = csbi.wAttributes;

	//Объявляем массив
	static int arr[MAX_SIZE][MAX_SIZE];

	//Читаем с клавиатуры размер матрицы
	UINT8 n;
	printf(Rus("Введите размер матрицы (%d...%d). N: "), MIN_SIZE, MAX_SIZE);
	do
	{
		n = (UINT8)read_int();
		if (n < MIN_SIZE || n > MAX_SIZE)
			printf(Rus("Неверный размер. Размер должен быть в диапазоне "
				"от %d до %d. Повторите ввод: \n"), MIN_SIZE, MAX_SIZE);
	} while (n < MIN_SIZE || n > MAX_SIZE);

	//Заполняем матрицу
	printf(Rus("Вводите элементы массива до заполнения\n"));
	UINT8 width = read_array(arr, n);

	//Выводим матрицу
	print_array(arr, n, TASK_ZONE, width);

	//Считаем значение из задания
	UINT64 sum = func_v13(arr, n, TASK_ZONE);

	printf(Rus("Сумма квадратов отрицательных чисел = %d\n"), sum);
}


/*
* Function:  read_array
* --------------------
* Заполняет матрицу значениями с клавиатуры и возвращает ширину ячеек для вывода
*
*  arr:		Матрица
*  n:		Порядок матрицы
*
*  returns: Размер самого длинного элемента + 1
*/
UINT8 read_array(int arr[][MAX_SIZE], size_t n)
{
	size_t i, j;
	UINT8 tmp = 0, width = 1;
	for (i = 0; i < n; ++i)
	{
		for (j = 0; j < n; ++j)
		{
			printf("arr[%d][%d]: ", i, j);
			arr[i][j] = read_int();
			if (arr[i][j])
			{
				tmp = (UINT8)(floor(log10(abs(arr[i][j]))) + 1);
				if (arr[i][j] < 0)
					++tmp;
			}
			if (tmp > width)
				width = tmp;
		}
	}
	return (UINT8)(width + 1);
}


/*
* Function:  print_array
* --------------------
* Печатает все элементы матрицы и подсвечивает элементы на заданном участке
*
*  arr:		Матрица
*  n:		Порядок матрицы
*  zone:	Участок для подсветки в виде битовой маски
*  width:	Ширина ячеек
*/
void print_array(int arr[][MAX_SIZE], size_t n, UINT16 zone, UINT8 width)
{
	size_t i, j;
	for (i = 0; i < n; ++i)
	{
		for (j = 0; j < n; ++j)
		{
			if (get_zone(i, j, n) & zone)
			{
				SetConsoleTextAttribute(hConsole, HIGHLIGHT_COLOR);
				printf("%*d", width, arr[i][j]);
				SetConsoleTextAttribute(hConsole, currentConsoleAttr);
			}
			else
				printf("%*d", width, arr[i][j]);
		}
		printf("\n");
	}
}


/*
* Function:  func_v13
* --------------------
* Вычисляет сумму квадратов отрицательных чисел, на заданном участке матрицы
*
*  arr:		Матрица
*  n:		Порядок матрицы
*  zone:	Участок для подсчета в виде битовой маски
*
*  returns:	сумму квадратов отрицательных чисел
*/
UINT64 func_v13(int arr[][MAX_SIZE], size_t n, UINT16 zone)
{
	UINT64 sum = 0;
	size_t i, j;
	for (i = 0; i < n; ++i)
	{
		for (j = 0; j < n; ++j)
		{
			if (zone & get_zone(i, j, n))
			{
				if (arr[i][j] < 0)
					sum += (UINT64)pow(arr[i][j], 2);
			}
		}
	}
	return sum;
}


/*
* Function:  get_zone
* --------------------
* Вычисляет битовую маску положения относительно диагоналей для элемента матрицы
*
*  i:		Строка матрицы
*  j:		Столбец матрицы
*
*  returns:	Битовая маска положения
*/
UINT16 get_zone(size_t i, size_t j, size_t n)
{
	UINT16 result = 0;
	if (i == j)
		result |= MAIN_DIAG;
	if (i > j)
		result |= MAIN_DIAG_UP;
	if (i < j)
		result |= MAIN_DIAG_DOWN;
	if (i + j == n - 1)
		result |= SEC_DIAG;
	if (i + j < n - 1)
		result |= SEC_DIAG_UP;
	if (i + j > n - 1)
		result |= SEC_DIAG_DOWN;
	return result;
}


/*
* Function:  read_int
* --------------------
* Читает целое число с консоли
*
*  returns: целое число
*/
int read_int()
{
	int n;
	int result;
	do
	{
		result = scanf("%d", &n);
		if (result == EOF)
		{
			printf(Rus("Неверный ввод. Повторите: \n"));
		}
		if (result == 0)
		{
			while (fgetc(stdin) != '\n');
			printf(Rus("Введите целое число: \n"));
		}
	} while (result == EOF || result == 0);
	return n;
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