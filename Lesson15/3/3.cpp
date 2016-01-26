#include <iostream>

using namespace std;

void main() {
	setlocale(LC_CTYPE, "Rus");

	/*

	*/

	//Код программы

	const int SIZE = 10;

	int arr[SIZE] = {4, -5, 3, 10, -4, -6, 8, -10, 1, 0};
	for (int i = 0; i < SIZE; i++)
	{
		cout << arr[i] << " ";
	}

	int tmp;
	for (int i = 0; i < SIZE / 4; i++)
	{
		tmp = arr[i];
		arr[i] = arr[SIZE / 2 - i - 1];
		arr[SIZE / 2- i - 1] = tmp;
	}

	for (int i = SIZE / 2; i < SIZE * 3 / 4; i++)
	{
		tmp = arr[i];
		arr[i] = arr[SIZE + SIZE/ 2 - i - 1];
		arr[SIZE + SIZE / 2 - i - 1] = tmp;
	}
	cout << endl;

	for (int i = 0; i < SIZE; i++)
	{
		cout << arr[i] << " ";
	}

	cout << endl;
	system("pause");
}