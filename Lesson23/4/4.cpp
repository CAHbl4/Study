#include <iostream>
using namespace std;

/*
Сгенерировать десять массивов из случайных чисел. Вывести их и сумму их элементов на экран. 
Найти среди них один с максимальной суммой элементов. Указать какой он по счету, повторно вывести этот массив и сумму его элементов.

*/

void fill_rand(int arr[], int n, int left, int right);
int sum(int arr[], int n);
int get_max(int *arr, int n, int m);

void main() {
	setlocale(LC_CTYPE, "Rus");

	//Код программы

	int const N = 10, M = 10;
	int arr[N][M];

	for (int i = 0; i < N; i++)
	{
		fill_rand(&arr[i][0], M, -10, 20);
		cout << "Array " << i << ": ";
		for (int j = 0; j < M; j++)
		{
			cout.width(3);
			cout << arr[i][j] << " ";
		}
		cout << endl <<  "Sum of elements: " << sum(&arr[i][0], M) << endl;
	}
	int max = get_max(&arr[0][0], N, M);
	cout << "Array with max sum: " << max << endl;

	for (int j = 0; j < M; j++)
	{
		cout.width(3);
		cout << arr[max][j] << " ";
	}
	cout << endl << "Sum: " << sum(&arr[max][0], M);


	cout << endl;
	system("pause");
}

void fill_rand(int arr[], int n, int left, int right)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % (right - left + 1) + left;
	}
}

int sum(int arr[], int n)
{
	int result = 0;
	for (int i = 0; i < n; i++)
	{
		result += arr[i];
	}
	return result;
}

int get_max(int *arr, int n, int m)
{
	int result = 0;
	int tmp = sum(&arr[0], m);
	for (int i = 1; i < n; i++)
	{
		int tmp2 = sum(&arr[i * n], m);
		if (tmp2 > tmp)
		{
			result = i;
			tmp = tmp2;
		}
	}
	return result;
}
