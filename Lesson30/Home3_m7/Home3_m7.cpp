#include <stdio.h>
#include <windows.h>
#include <math.h>

/*
*
* a.matuzov, 3/20/2016 12:47:39 PM
*/

#define MAX_ELEMENTS	25
#define HALT			""

typedef int (*count_f)(int, void*);

int* read_array(int* arr, int* count);
int* parse_ints(int* nums, char* str, int* count);
int str_to_int(char *str);
int read_int(FILE* stream);
void print_array(int* arr, int count);
char* read_string(FILE* fp, size_t size);
void do_work(int* arr, int count, int v);
int sum_dig(int x);
int count(int* arr, int count, count_f f, void* param);


int f13(int x, void* param);
char* Rus(const char* text);

void main()
{
	//Code goes here
	int* arr = NULL;
	int count = 0, v;
	arr = read_array(arr, &count);

	printf(Rus("Выберите вариант задания(1-16): "));
	do
	{
		v = read_int(stdin);
		if (v < 0 || v > 16)
			printf(Rus("Неверный вариант. Повторите."));
	}
	while (v < 0 || v > 16);
	scanf("%*c");

	printf(Rus("Исходный массив:\n"));
	print_array(arr, count);
	do_work(arr, count, v);
	free(arr);
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
	char* s;

	while (((s = read_string(stdin, 10))) && strcmp(s, HALT) && *count < MAX_ELEMENTS)
	{
		arr = parse_ints(arr, s, count);
	}

	if (*count > MAX_ELEMENTS)
	{
		printf(Rus("Вы превысили лимит. Сохраненно только %d элементов"), MAX_ELEMENTS);
		*count = 25;
	}

	return (int*)realloc(arr, sizeof(int) * *count);
}


/*																																		
* Function:  parse_ints
* --------------------
* Парсит все целые из строки и сохраняет их в массив
*
*  nums:		Массив целых
*  str:			Строка для парсинга
*  count:		Текущее количество элементов в массиве
*
*  returns:		Указатель на новый адресс массива
*/
int* parse_ints(int* nums, char* str, int* count)
{
	int in_num = 0;
	int alloc = *count + 5;
	char tmp_c[20];
	int n = 0, i;
	nums = (int*)realloc(nums, sizeof(int) * alloc);
	for (i = 0; strlen(str); ++i)
	{
		if (*(str + i) < '0' || *(str + i) > '9')
		{
			if (in_num)
			{
				tmp_c[n] = '\0';
				if (*count == alloc)
					nums = (int*)realloc(nums, sizeof(int) * (alloc += 5));
				*(nums + *count) = str_to_int(tmp_c);
				++(*count);
				in_num = 0;
			}
		}
		else
		{
			if (!in_num)
			{
				n = 0;
				tmp_c[n++] = *(str + i);
				in_num = 1;
			}
			else
			{
				tmp_c[n++] = *(str + i);
			}
		}
	}

	return (int*)realloc(nums, sizeof(int) * *count);
}

int str_to_int(char *str)
{
	int i, j = 0;
	int tmp = 0;
	for (i =strlen(str) -1; i >= 0; --i)
	{
		tmp += (*(str+i) - '0') * pow(10, j++);
	}
	return tmp;
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
			fprintf(stderr, Rus("Неожиданный конец файла\n"));
			exit(74);
		}
		if (result == 0)
		{
			do
			{
				ch = fgetc(stream);
			}
			while (ch <= '0' && ch >= '9');
			fprintf(stderr, Rus("Ожидалось целое\n"));
		}
	}
	while (!result);

	return n;
}


/*
* Function:  read_string
* --------------------
* Читает строку с указанного потока
*
*  fp:		Поток ввода
*  count:	Начальный размер строки
*
*  returns:	Указатель на прочитанную строку
*/
char* read_string(FILE* fp, size_t size)
{
	char* str;
	char ch;
	size_t len = 0;
	str = (char*)calloc(size + 1, sizeof(char));
	while (EOF != (ch = fgetc(fp)) && ch != '\n')
	{
		str[len++] = ch;
		if (len == size)
		{
			str = (char*)realloc(str, sizeof(char) * (size += 16));
			if (!str)return str;
		}
	}
	str[len++] = '\0';

	return (char*)realloc(str, sizeof(char) * len);
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

int f13(int x, void* param)
{
	return sum_dig(x) < *(int*)param;
}


char bufRus[256];

char* Rus(const char* text)
{
	CharToOemA(text, bufRus);
	return bufRus;
}

