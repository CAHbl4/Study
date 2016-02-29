#include <iostream>
#include "functions.h"
using namespace std;

/*
5.	Даны два массива: А[M] и B[N] (M и  N вводятся с клавиатуры). Необходимо создать третий массив минимально возможного размера, в котором нужно собрать элементы обоих массивов.
*/

int* create_set(int* a, int* b, int n, int m, int* size);
void qsort(int* arr, int n);

void main()
{
	setlocale(LC_CTYPE, "Rus");

	int n, m;
	cout << "Введите размеры n, m: ";
	cin >> n >> m;

	int* a = new int[n];
	int* b = new int[m];

	fill_rand(a, n, 0, 100);
	cout << "Массив A:" << endl;
	print_arr(a, n);
	cout << endl;

	fill_rand(b, m, 0, 100);
	cout << "Массив B:" << endl;
	print_arr(b, m);
	cout << endl;

	int size;
	int* c = create_set(a, b, n, m, &size);

	cout << "Уникальные элементы обоих массивов: " << endl;
	print_arr(c, size);
	cout << endl;

	delete[] a , b , c;

	cout << endl;
	system("pause");
}

int* create_set(int* a, int* b, int n, int m, int* size)
{
	qsort(a, n);
	qsort(b, m);
	int* tmp = new int[n + m];
	*size = 0;
	int i = 0, j = 0;

	tmp[(*size)++] = a[i] < b[j] ? a[i++] : b[j++];

	while (i < n || j < m)
	{
		if (i < n)
		{
			while (a[i] == tmp[*size - 1]) i++;
		}
		if (j < m)
		{
			while (b[j] == tmp[*size - 1]) j++;
		}

		if (i < n && j < m)
		{
			if (a[i] < b[j] && a[i] != tmp[*size - 1])
			{
				tmp[(*size)++] = a[i++];
			}
			else if (b[j] < a[i] && b[j] != tmp[*size - 1])
			{
				tmp[(*size)++] = b[j++];
			}
			else if (a[i] == b[j] && a[i] != tmp[*size - 1])
			{
				tmp[(*size)++] = a[i++];
				j++;
			}
			else
			{
				i++;
				j++;
			}
		}
		else if (i < n)
		{
			tmp[(*size)++] = a[i++];
		}
		else if (j < m)
		{
			tmp[(*size)++] = b[j++];
		}
	}

	int* result = new int[*size];
	for (int i = 0; i < *size; i++)
	{
		result[i] = tmp[i];
	}
	delete[] tmp;
	return result;
}

void qsort(int* arr, int n)
{
	int l = 0, r = n - 1;
	int m = *(arr + n / 2);
	int tmp;

	do
	{
		while (*(arr + l) < m) l++;
		while (*(arr + r) > m) r--;

		if (l <= r)
		{
			tmp = *(arr + l);
			*(arr + l) = *(arr + r);
			*(arr + r) = tmp;
			l++;
			r--;
		}
	}
	while (l <= r);


	if (r > 0) qsort(arr, r + 1);
	if (n > l) qsort(arr + l, n - l);
}

