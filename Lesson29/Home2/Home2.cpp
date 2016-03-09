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
* второй вариант - адресация через указатели
*
* amatu, 09.03.2016 11:12:27
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
#define PRINT_WIDTH			3
#define HIGLIGHT_COLOR		FOREGROUND_RED | FOREGROUND_INTENSITY



char*	Rus(const char* text);
void	read_array(int* arr, int n);
void	print_array(int arr[][MAX_SIZE], int n, int zone, int width = PRINT_WIDTH);
int		get_zone(int i, int j, int n);
int		func(int arr[][MAX_SIZE], int n, int zone);
void	fill_rand(int arr[][MAX_SIZE], int length, int left, int right);

//Переменные для настройки консоли
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
WORD currentConsoleAttr = 0;
CONSOLE_SCREEN_BUFFER_INFO csbi;

void main() {
	//Записываем текущие параметры консоли
	if (GetConsoleScreenBufferInfo(hConsole, &csbi))
		currentConsoleAttr = csbi.wAttributes;

	static int arr[MAX_SIZE][MAX_SIZE];

	unsigned int n;
	printf(Rus("Введите размер матрицы N = "));
	scanf("%d", &n);

	fill_rand(arr, n*n, -10, 10);

	print_array(arr, n, TASK_ZONE);
	int sum = func(arr, n, TASK_ZONE);
	printf(Rus("Сумма квадратов отрицательных чисел = %d"), sum);
	
}

char bufRus[256];

char* Rus(const char* text)
{
	CharToOemA(text, bufRus);
	return bufRus;
}

void print_array(int arr[][MAX_SIZE], int n, int highlight, int width)
{
	int i, j;
	for (i = 0; i < n; ++i)
	{
		for (j = 0; j < n; ++j)
		{
			if (get_zone(i,j,n) & highlight)
			{
				SetConsoleTextAttribute(hConsole, HIGLIGHT_COLOR);
				printf("%*d", width, arr[i][j]);
				SetConsoleTextAttribute(hConsole, currentConsoleAttr);
			} else
				printf("%*d", width, arr[i][j]);
		}
		printf("\n");
	}
}

int get_zone(int i, int j, int n)
{
	int result = 0;
	if (i == j) 
		result += MAIN_DIAG;
	if (i > j)
		result += MAIN_DIAG_UP;
	if (i < j)
		result += MAIN_DIAG_DOWN;
	if (i + j == n - 1)
		result += SEC_DIAG;
	if (i + j < n - 1)
		result += SEC_DIAG_UP;
	if (i + j > n - 1)
		result += SEC_DIAG_DOWN;
	return result;
}

int func(int arr[][MAX_SIZE], int n, int zone)
{
	long sum = 0;
	int i, j;
	for (i = 0; i < n; ++i)
	{
		for (j = 0; j < n; ++j)
		{
			if(zone & get_zone(i,j,n))
			{
				if (arr[i][j] < 0)
					sum += pow(arr[i][j], 2);
			}
		}
	}
	return sum;
}

void fill_rand(int arr[][MAX_SIZE], int n, int left, int right)
{
	int i, j;
	for (i = 0; i < n; ++i)
	{
		for (j = 0; j < n; ++j)
		{
			arr[i][j] = rand() % (right - left + 1) + left;
		}
	}
}