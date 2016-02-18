#include <iostream>
using namespace std;

/*
Дан массив чисел, необходимо ввести в него и вывести из него числа с помощью указателей.

*/

void main() {
	setlocale(LC_CTYPE, "Rus");

	//Код программы

	const int SZ = 5;
	int arr[5];
	int *ptr = arr;
	for (size_t i = 0; i < SZ; i++)
	{
		*(ptr + i) = i;
		cout << *(ptr + i) << " " ;
	}

	cout << endl;
	system("pause");
}