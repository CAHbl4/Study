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

char* Rus(const char* text);
void read_array(int* arr, int N);
void print_array(int* arr, int N);
int func(int* arr, int N);
void fill_rand(int * arr, int length, int left, int right);

void main() {

	//Code goes here
	size_t N;
	scanf("%d", &N);

	int *parr = (int*)calloc(N * N, sizeof(int));

	fill_rand(parr, N*N, -10, 10);
	print_array(parr, N);

	printf(Rus("Сумму квадратов отрицательных чисел = %d"), func(parr, N));

	free(parr);
	
}

char bufRus[256];

char* Rus(const char* text)
{
	CharToOemA(text, bufRus);
	return bufRus;
}

void print_array(int * arr, int N)
{
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			printf("%5d", *(arr + i*N + j));
		}
		printf("\n");
	}
}

int func(int * arr, int N)
{
	long long sum = 0;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if(i + j + 1 < N )
			{
				printf("arr[%d][%d] = %d\n", i, j, *(arr + i*N + j));
				if (*(arr + i*N + j) < 0)
					sum += pow(*(arr + i*N + j), 2);
			}
		}
	}
	return sum;
}

void fill_rand(int * arr, int length, int left, int right)
{
	for (int i = 0; i < length; i++)
	{
		*(arr + i) = rand() % (right - left + 1) + left;
	}
}