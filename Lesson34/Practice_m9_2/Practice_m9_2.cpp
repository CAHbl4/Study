#include <stdio.h>
#include <windows.h>
#include <math.h>

/*
*
* amatu, 3/29/2016 11:19:27 AM
*/
#define HALT			""

char* Rus(const char* text);
int* read_array(int* arr, size_t* count);
int* parse_ints(int* nums, char* str, size_t* count);
int str_to_int(char* str);
int is_digit(char);
char* read_string(FILE* fp, size_t size);
void print_array(int* arr, int count);
__int64 read_int(FILE* fp);
void flush_stream(FILE* fp);

void* convert_dim(int* arr, size_t size, size_t dim);

void main() {

	int* arr = NULL;
	size_t count = 0;
	printf(Rus("Вводите числа и они будут записаны в массив."));
	printf(Rus("Для прекращения ввода-<Enter> в начале строки.\n"));
	arr = read_array(arr, &count);

	printf(Rus("Исходный массив: "));
	print_array(arr, count);

	size_t dim = 1;
	while (dim)
	{
		printf(Rus("Введите размерность массива (1 - 3), 0 для выхода: "));
		dim = read_int(stdin);
		convert_dim(arr, count, dim);
	}


	system("pause");
}

char bufRus[256];

char* Rus(const char* text)
{
	CharToOemA(text, bufRus);
	return bufRus;
}

void* convert_dim(int* arr, size_t size, size_t dim)
{
	size_t i, j, m, k;
	int** result2;
	int*** result3;

	if (dim > 3) {
		printf(Rus("Неверная размерность"));
		return NULL;
	}

	switch (dim)
	{
	case 1:
		return arr;
	case 2:
		printf(Rus("Введите количество элементов в строке: "));
		m = read_int(stdin);
		if (size % m)
		{
			printf(Rus("Количество элементов не подходит к массиву"));
			return NULL;
		}
		result2 = (int**)malloc(sizeof(int *) * size / m);
		for (i = 0; i < size / m; ++i)
		{
			*(result2 + i) = arr + m * i;
		}
		return (void*)result2;
	case 3:
		printf(Rus("Введите количество элементов m: "));
		m = read_int(stdin);
		printf(Rus("Введите количество элементов k: "));
		k = read_int(stdin);
		if (size % m * k)
		{
			printf(Rus("Количество элементов не подходит к массиву"));
			return NULL;
		}
		result3 = (int***)malloc(sizeof(int ***) * size / m * k);
		for (i = 0; i < size / m * k; ++i)
		{
			*(result3 + i) = (int**)malloc(sizeof(int*) * m);
			for (j = 0; j < m; ++j)
			{
				*(*(result3 + i) + j) = arr + (m * i + k * j);
			}
		}
		for (i = 0; i < size / m * k; ++i)
		{
			printf("Array[%d]:\n", i);
			for (j = 0; j < m; ++j)
			{
				print_array(*(*(result3 + i) + j), k);
				printf("\n");
			}
		}
		return (void*)result3;
	default:
		return NULL;
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
int* read_array(int* arr, size_t* count)
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
int* parse_ints(int* nums, char* str, size_t* count)
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

void print_array(int* arr, int count)
{
	int i;
	for (i = 0; i < count; ++i)
	{
		printf("%d ", *(arr + i));
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