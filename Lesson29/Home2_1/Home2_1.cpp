#include <stdio.h>
#include <windows.h>

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
UINT8	read_array(int arr[][MAX_SIZE], size_t n);
void	print_array(int arr[][MAX_SIZE], size_t n, UINT16 zone, UINT8 width);
UINT64	func_v13(int arr[][MAX_SIZE], size_t n, UINT16 zone);
UINT16	get_zone(size_t i, size_t j, size_t n);
__int64 read_int(FILE* fp);
char*	Rus(const char* text);
void	flush_stream(FILE* fp);

size_t	num_char_count(__int64 num);
__int64 pow(__int64 x, __int64 y);

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
	size_t n;
	printf(Rus("Введите размер матрицы (%d...%d). N: "), MIN_SIZE, MAX_SIZE);
	do
	{
		n = (size_t)read_int(stdin);
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
	UINT8 tmp, width = 1;
	for (i = 0; i < n; ++i)
	{
		for (j = 0; j < n; ++j)
		{
			printf("arr[%d][%d]: ", i, j);
			arr[i][j] = read_int(stdin);
			tmp = num_char_count(arr[i][j]);
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
*  n:		Порядок матрицы
*
*  returns:	Битовая маска положения
*/
UINT16 get_zone(size_t i, size_t j, size_t n)
{
	UINT16 result = 0;
	if (i == j)
		result |= MAIN_DIAG;
	if (i < j)
		result |= MAIN_DIAG_UP;
	if (i > j)
		result |= MAIN_DIAG_DOWN;
	if (i + j == n - 1)
		result |= SEC_DIAG;
	if (i + j < n - 1)
		result |= SEC_DIAG_UP;
	if (i + j > n - 1)
		result |= SEC_DIAG_DOWN;
	return result;
}


/**
* Returns the integer readed from given stream
*/
__int64 read_int(FILE* fp)
{
	__int64 n = 0;
	__int8 result;
	char ch;
	do
	{
		result = fscanf(fp, "%lld", &n);
		if (result == EOF)
		{
			fprintf(stderr, "Unexpected EOF\n");
			exit(74);
		}
		if (result == 0)
		{
			do
			{
				ch = fgetc(fp);
			} while (ch <= '0' && ch >= '9');
			fprintf(stderr, "Incorrect symbol\n");
		}
	} while (!result);

	flush_stream(fp);

	return n;
}


/**
* Flushes the given stream
*/
void flush_stream(FILE* fp)
{
	fseek(fp, 0, SEEK_END);
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


size_t num_char_count(__int64 num)
{
	size_t count = 0;
	if (num < 0)
		++count;
	do {
		++count;
		num /= 10;
	} while (num);
	return count;
}


__int64 pow(__int64 base, __int64 exp)
{
	__int64 result = 1;
	while (exp)
	{
		if (exp & 1)
			result *= base;
		exp >>= 1;
		base *= base;
	}

	return result;
}