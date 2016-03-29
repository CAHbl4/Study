#include <stdio.h>
#include <windows.h>

/*
* Вариант 6:
* Написать программу, которая поэлементно суммирует два динамических двумерных массива,
* заполненных случайными числами и сохраняет результат в третьем массиве. Размеры исходных массивов задаются пользователем.
*
*
* amatu, 3/29/2016 9:52:23 AM
*/

char* Rus(const char* text);
__int64 read_int(FILE* fp);
void flush_stream(FILE* fp);
void* free_ptr_ptr(void **ptr, size_t count);

int** create_array(size_t n, size_t m);
void fill_rand(int** arr, size_t n, size_t m, int left, int right);
void sum_arr(int** arr1, int** arr2, int** arr3, size_t n, size_t m);
void print_arr(int** arr, size_t n, size_t m);

void* convert_dim(int* arr, size_t size, size_t dim, size_t* dim_p);


void main() {
	size_t n, m;
	printf(Rus("Введите размер N массивов: "));
	n = (size_t)read_int(stdin);

	printf(Rus("Введите размер M массивов: "));
	m = (size_t)read_int(stdin);
	int** arr1 = create_array(n, m);
	int** arr2 = create_array(n, m);
	int** arr3 = create_array(n, m);

	fill_rand(arr1, n, m, -20, 20);
	fill_rand(arr2, n, m, -20, 20);

	printf(Rus("Исходный массив 1:\n"));
	print_arr(arr1, n, m);
	printf(Rus("Исходный массив 2:\n"));
	print_arr(arr2, n, m);

	sum_arr(arr1, arr2, arr3, n, m);

	printf(Rus("Результирующий массив 3:\n"));
	print_arr(arr3, n, m);

	free_ptr_ptr((void**)arr1, n);
	free_ptr_ptr((void**)arr2, n);
	free_ptr_ptr((void**)arr3, n);
	system("pause");
}


void sum_arr(int** arr1, int** arr2, int** arr3, size_t n, size_t m)
{
	size_t i, j;
	for (i = 0; i < n; ++i)
	{
		for (j = 0; j < m; ++j)
		{
			*(*(arr3 + i) + j) = *(*(arr1 + i) + j) + *(*(arr2 + i) + j);
		}
	}
}


int** create_array(size_t n, size_t m)
{
	int** result = (int**)malloc(sizeof(int*) * n);
	size_t i;
	for (i = 0; i < n; ++i)
	{
		*(result + i) = (int*)malloc(sizeof(int) * m);
	}
	return result;
}


char bufRus[256];

char* Rus(const char* text)
{
	CharToOemA(text, bufRus);
	return bufRus;
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

void* free_ptr_ptr(void **ptr, size_t count)
{
	size_t i;
	for (i = 0; i < count; ++i)
	{
		free(*(ptr + i));
	}
	free(ptr);
	return NULL;
}

void fill_rand(int** arr, size_t n, size_t m, int left, int right)
{
	size_t i, j;
	for (i = 0; i < n; ++i)
	{
		for (j = 0; j < m; ++j)
		{
			*(*(arr + i) + j) = rand() % (right - left + 1) + left;
		}
	}
}

void print_arr(int** arr, size_t n, size_t m)
{
	size_t i, j;
	for (i = 0; i < n; ++i)
	{
		for (j = 0; j < m; ++j)
		{
			printf("%4d", *(*(arr + i) + j));
		}
		printf("\n");
	}
}