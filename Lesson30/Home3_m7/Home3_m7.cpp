#include <stdio.h>
#include <windows.h>

/*
*
* a.matuzov, 3/20/2016 12:47:39 PM
*/

#define MAX_ELEMENTS	25

typedef int(*count_f)(int, void*);

int* read_array(int* arr, int* count);
int read_int(FILE* stream);
void print_array(int* arr, int count);
void do_work(int* arr, int count, int v);
int sum_dig(int x);
int count(int* arr, int count, count_f f, void* param);

int f13(int x, void* param);
char* Rus(const char* text);

void main() {

	//Code goes here
	int* arr = NULL;
	int count = 0, v;
	arr = read_array(arr, &count);
	scanf("%*c");

	printf(Rus("Выберите вариант задания(1-16): "));
	do
	{
		v = read_int(stdin);
		if (v < 0 || v > 16)
			printf(Rus("Неверный вариант. Повторите."));
	} while (v < 0 || v > 16);
	scanf("%*c");

	printf(Rus("Исходный массив:\n"));
	print_array(arr, count);
	do_work(arr, count, v);
	
}

/*
* Function:  read_array
* --------------------
* Читает целые числа в массив
*
*  arr:		Массив целых чисел
*  count:	Количество элементов в массиве
*
*  returns:	Указатель на массив
*/
int* read_array(int* arr, int* count)
{
	int n;
	int alloc = *count + 1;
	arr = (int*)realloc(arr, sizeof(int) * alloc);

	while (((n = read_int(stdin))) && *count <= MAX_ELEMENTS)
	{
			if (*count == alloc)
				arr = (int*)realloc(arr, sizeof(int) * (alloc += 5));
			*(arr + *count) = n;
			++(*count);
	}
	return (int*)realloc(arr, sizeof(int) * *count);
}

/*
* Function:  read_int
* --------------------
* Читает целое число с заданного потока
*
*  stream:     поток ввода
*
*  returns:    целое число
*/
int read_int(FILE* stream)
{
	int n, result, ch;
	do
	{
		result = fscanf(stream, "%d", &n);
		if (result == EOF)
		{
			fprintf(stderr, Rus("Неожиданный конец файла\n");
			exit(74);
		}
		if (result == 0)
		{
			do
			{
				ch = fgetc(stream);
			} while (ch <= '0' && ch >= '9');
			fprintf(stderr, Rus("Ожидалось целое\n"));
		}
	} while (!result);

	return n;
}

void print_array(int* arr, int count)
{
	int i;
	for (i = 0; i < count; ++i)
	{
		printf("%d ", *(arr + i));
	}
	puts("");
}

void do_work(int* arr, int n, int v)
{
	switch (v)
	{
	case 13:
		int param = 10;
		count_f f = &f13;
		int result = count(arr, n, f, &param);
		printf(Rus("Количество всех чисел, сумма цифр которых меньше %d = %d."), param, result);
		break;
	}
}


int sum_dig(int x)
{
	int sum = 0;
	while (x)
	{
		sum += x % 10;
		x /= 10;
	}
	return sum;
}


int count(int* arr, int count, count_f f, void* param)
{
	int i, result = 0;
	for (i = 0; i < count; ++i)
	{
		if ((*f)(*(arr + i), param))
			++result;
	}
	return result;
}

int f13 (int x, void* param)
{
	return sum_dig(x) < *(int*)param;
}


char bufRus[256];

char* Rus(const char* text)
{
	CharToOemA(text, bufRus);
	return bufRus;
}