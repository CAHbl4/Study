#include <iostream>
using namespace std;

/*
5.	Даны два массива: А[M] и B[N] (M и  N вводятся с клавиатуры). Необходимо создать третий массив минимально возможного размера, в котором нужно собрать элементы обоих массивов.
*/

//Fills an array with random() numbers
void fill_rand(int* arr, int length, int left, int right);

//Prints the elements of the array separated by a space in one line
void print_arr(int* arr, int size);

//Create set of elements from array
void create_set(int* arr, int* size);

void main()
{
	setlocale(LC_CTYPE, "Rus");

	int n, m;
	cout << "Введите размеры n, m: ";
	cin >> n >> m;

	int* a = new int[n];
	int* b = new int[m];

	fill_rand(a, n, 0, 10);
	cout << "Массив A:" << endl;
	print_arr(a, n);
	cout << endl;

	fill_rand(b, m, 0, 10);
	cout << "Массив B:" << endl;
	print_arr(b, m);
	cout << endl;

	int size = n + m;
	int* c = new int[size];

	int i = 0, j = 0;

	for (i = 0; i < n; i++)
	{
		c[j++] = a[i];
	}

	for (i = 0; i < m; i++)
	{
		c[j++] = b[i];
	}

	create_set(c, &size);

	cout << "Уникальные элементы обоих массивов: " << endl;
	print_arr(c, size);
	cout << endl;

	delete[] a , b , c;

	cout << endl;
	system("pause");
}

void create_set(int* arr, int* size)
{
	int i, j;

	int new_size = 1;

	for (i = 1; i< *size; i++) {

		for (j = 0; j< new_size; j++)
		{

			if (arr[i] == arr[j])
				break;
		}

		/* if none of the values in index[0..j] of array is not same as array[i],
		then copy the current value to corresponding new position in array */

		if (j == new_size)
			arr[new_size++] = arr[i];
	}
	*size = new_size;
}

void fill_rand(int * arr, int length, int left, int right)
{
	for (int i = 0; i < length; i++)
	{
		*(arr + i) = rand() % (right - left + 1) + left;
	}
}

void print_arr(int * arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		std::cout << arr[i] << " ";
	}
	cout << endl;
}
