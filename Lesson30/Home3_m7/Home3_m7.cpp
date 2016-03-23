#include <stdio.h>
#include <windows.h>
#include <math.h>

/*
* Домашнее задание №3 к модулю  №7
* Вариант 13: Посчитать количество всех чисел, сумма цифр которых меньше 10.
*
* a.matuzov, 3/20/2016 12:47:39 PM
*/

#define MAX_ELEMENTS	25
#define HALT			""

typedef int (*count_f)(int, void*);

int* read_array(int* arr, int* count);
int* parse_ints(int* nums, char* str, int* count);
int str_to_int(char* str);
void print_array(int* arr, int count);
int is_digit(char);
char* read_string(FILE* fp, size_t size);
int sum_digit(int x);
int count_nums(int* arr, int count, count_f f, void* param);


int f13(int x, void* param);
char* Rus(const char* text);

void main()
{
	int* arr = NULL;
	int count = 0;
	printf(Rus("Вводите числа. Сохранены будут только первые %d целых чисел.\n"), MAX_ELEMENTS);
	printf(Rus("Для прекращения ввода-<Enter> в начале строки.\n"));
	arr = read_array(arr, &count);

	printf(Rus("Исходный массив:\n"));
	print_array(arr, count);

	int param = 10;
	count_f f = &f13;
	int result = count_nums(arr, count, f, &param);
	printf(Rus("Количество всех чисел, сумма цифр которых меньше %d = %d.\n"), param, result);

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
	char* s;

	while (*count < MAX_ELEMENTS)
	{
		s = read_string(stdin, 10);
		if (!strcmp(s, HALT))
		{
			break;
		}
		arr = parse_ints(arr, s, count);
		free(s);
	}

	if (*count > MAX_ELEMENTS)
	{
		printf(Rus("Вы превысили лимит. Сохраненно только %d элементов\n"), MAX_ELEMENTS);
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
*  returns:		Указатель на новый адрес массива
*/
int* parse_ints(int* nums, char* str, int* count)
{
	int in_num = 0;
	int alloc = *count + 5;
	char tmp_c[20];
	int n = 0, i;
	nums = (int*)realloc(nums, sizeof(int) * alloc);
	for (i = 0; i < (int)strlen(str) + 1; ++i)
	{
		if (!is_digit(*(str + i)))
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
			if (*(str + i) == '-' && is_digit(*(str + i + 1)))
			{
				n = 0;
				tmp_c[n++] = *(str + i);
				in_num = 1;
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


/*
* Function:  read_int
* --------------------
* Конвертирует строку в целое число
*
*  str:			Строка для конвертации
*
*  returns:		Целое число
*/
int str_to_int(char* str)
{
	int i, j = 0;
	int tmp = 0;
	int sign = 1;

	if (*str == '-')
	{
		sign = -1;
		++str;
	}

	for (i = strlen(str) - 1; i >= 0; --i)
	{
		tmp += (*(str + i) - '0') * (int)pow(10, j++);
	}
	return tmp * sign;
}


/*
* Function:  is_digit
* --------------------
* Возвращает единицу если переданный символ является числом
*
*  c:		Символ для проверки
*
*  returns:	Результат проверки
*/
int is_digit(char c)
{
	return (c >= '0' && c <= '9');
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
			if (!str)
				return str;
		}
	}
	str[len++] = '\0';

	return (char*)realloc(str, sizeof(char) * len);
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
void print_array(int* arr, int count)
{
	int i;
	for (i = 0; i < count; ++i)
	{
		printf("%d ", *(arr + i));
	}
	puts("");
}


/*
* Function:  sum_digit
* --------------------
* Считает суммы цифр в заданном числе
*
*  x:		Число для подсчета
*
*  returns:	Сумма цифр
*/
int sum_digit(int x)
{
	int sum = 0;
	while (x)
	{
		sum += x % 10;
		x /= 10;
	}
	return sum;
}


/*
* Function:  count_nums
* --------------------
* Считает количество чисел в массиве удовлетворящих условию
*
*  arr:		Массив для подсчета
*  count:	Количество элементов в массиве
*
*  returns:	Сумма цифр
*/
int count_nums(int* arr, int count, count_f f, void* param)
{
	int i, result = 0;
	for (i = 0; i < count; ++i)
	{
		if ((*f)(*(arr + i), param))
			++result;
	}
	return result;
}


/*
* Function:  f13
* --------------------
* Функция возвращает 1 если сцумма цифр числа меньше переданного параметра
*
*  ч:		Число для проверки
*  param:	Число для сравнения
*
*  returns:	Резултат проверки
*/
int f13(int x, void* param)
{
	return sum_digit(x) < *(int*)param;
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