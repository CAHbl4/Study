#include <iostream>
using namespace std;

/*
‘ункци€ принимает указатель на массив, его размер и указатель на переменную. 
ќпределить, €вл€етс€ ли переменна€ €чейкой массива (т.е значение указател€ совпадает с одним из адресов €чеек массива).
‘ункц€ должна вернуть логическое значение.

*/

bool contain(int *arr, int size, int *a);

void main() {
	setlocale(LC_CTYPE, "Rus");

	// од программы

	int size = 10;
	int *arr = new int[size];
	int a;
	int *ptr_a = &a;
	int *ptr_b = &arr[size - 1];
	
	cout << contain(arr, size, ptr_a) << endl;
	cout << contain(arr, size, ptr_b) << endl;

	cout << endl;
	system("pause");
}

bool contain(int * arr, int size, int * a)
{
	for (int i = 0; i < size; i++)
	{
		if (arr + i == a)
		{
			return true;
		}
	}
	return false;
}
