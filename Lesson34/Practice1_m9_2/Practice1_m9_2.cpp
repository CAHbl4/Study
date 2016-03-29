#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h>
#include <math.h>

/*
 * Вариант 8:
 * Напишите функцию для обращения одномерного массива в N-мерный. Должны выполняться соответствующие проверки.
 *
 * amatu, 3/29/2016 11:19:27 AM
 */
#define HALT			""

char* Rus(const char* text);
__int64* read_array(__int64* arr, size_t* count);
__int64* parse_ints(__int64* nums, char* str, size_t* count);
__int64 str_to_int(const char* str);
int is_digit(char);
char* read_string(FILE* fp, size_t size);
void print_array(__int64* arr, size_t count);
__int64 read_int(FILE* fp);
void flush_stream(FILE* fp);

void convert_dim(__int64* arr, size_t size, size_t dim);

void main() {

	__int64* arr = NULL;
	size_t count = 0;
	printf(Rus("Вводите числа и они будут записаны в массив.\n"));
	printf(Rus("Для прекращения ввода-<Enter> в начале строки.\n"));
	arr = read_array(arr, &count);

	printf(Rus("Исходный массив: "));
	print_array(arr, count);

	size_t dim = 1;
	while (dim)
	{
		printf(Rus("Введите размерность массива (2 - 3), 0 для выхода: "));
		dim = (size_t)read_int(stdin);
		convert_dim(arr, count, dim);
	}

	free(arr);
	system("pause");
}

char bufRus[256];

char* Rus(const char* text)
{
	CharToOemA(text, bufRus);
	return bufRus;
}


/*
 * Функция динамически выделяет память под указатели 2х и 3х мерного массива выводит результаты
 * на экран и освобождает память
 */
void convert_dim(__int64* arr, size_t size, size_t dim)
{
	size_t i, j, m, k;
	__int64** result2;
	__int64*** result3;

	if (dim < 2 && dim > 3) {
		printf(Rus("Неверная размерность"));
		return;
	}

	switch (dim)
	{
	case 2:
		printf(Rus("Введите количество элементов в строке: "));
		m = (size_t)read_int(stdin);
		if (size % m)
		{
			printf(Rus("Количество элементов не подходит к массиву.\n"));
			return;
		}
		result2 = (__int64**)malloc(sizeof(__int64 *) * size / m);
		for (i = 0; i < size / m; ++i)
		{
			*(result2 + i) = arr + m * i;
		}
		for (i = 0; i < size / m; ++i)
		{
			printf("Array[%d]:\n", i);
			print_array(*(result2 + i), m);
		}
		free(result2);
		return;
	case 3:
		printf(Rus("Введите количество элементов m: "));
		m = (size_t)read_int(stdin);
		printf(Rus("Введите количество элементов k: "));
		k = (size_t)read_int(stdin);
		if (size % (m * k))
		{
			printf(Rus("Количество элементов не подходит к массиву.\n"));
			return;
		}
		result3 = (__int64***)malloc(sizeof(__int64 ***) * size / m * k);
		for (i = 0; i < size / (m * k); ++i)
		{
			*(result3 + i) = (__int64**)malloc(sizeof(__int64*) * m);
			for (j = 0; j < m; ++j)
			{
				*(*(result3 + i) + j) = arr + (m * k * i) + k * j;
			}
		}
		for (i = 0; i < size / (m * k); ++i)
		{
			printf("Array[%d]:\n", i);
			for (j = 0; j < m; ++j)
			{
				print_array(*(*(result3 + i) + j), k);
			}
			free(*(result3 + i));
		}
		free(result3);
	}
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
__int64* read_array(__int64* arr, size_t* count)
{
	char* s;

	while (1)
	{
		s = read_string(stdin, 10);
		if (!strcmp(s, HALT))
		{
			break;
		}
		arr = parse_ints(arr, s, count);
		free(s);
	}

	return (__int64*)realloc(arr, sizeof(__int64) * *count);
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
__int64* parse_ints(__int64* nums, char* str, size_t* count)
{
	int in_num = 0;
	size_t alloc = *count + 5;
	char tmp_c[20];
	int n = 0, i;
	nums = (__int64*)realloc(nums, sizeof(__int64) * alloc);
	for (i = 0; i < (int)strlen(str) + 1; ++i)
	{
		if (!is_digit(*(str + i)))
		{
			if (in_num)
			{
				tmp_c[n] = '\0';
				if (*count == alloc)
					nums = (__int64*)realloc(nums, sizeof(__int64) * (alloc += 5));
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

	return (__int64*)realloc(nums, sizeof(__int64) * *count);
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
* Function:  str_to_int
* --------------------
* Конвертирует строку в целое число
*
*  str:			Строка для конвертации
*
*  returns:		Целое число
*/
__int64 str_to_int(const char* str)
{
	size_t i, j = 0;
	__int64 tmp = 0;
	__int8 sign = 1;

	if (*str == '-')
	{
		sign = -1;
		++str;
	}

	for (i = strlen(str); i--> 0;)
	{
		tmp += (*(str + i) - '0') * (__int64)pow(10, j++);
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

void print_array(__int64* arr, size_t count)
{
	size_t i;
	for (i = 0; i < count; ++i)
	{
		printf("%lld ", *(arr + i));
	}
	puts("");
}


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

void flush_stream(FILE* fp)
{
	fseek(fp, 0, SEEK_END);
}