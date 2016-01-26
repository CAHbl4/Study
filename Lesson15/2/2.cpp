#include <iostream>

using namespace std;

void main() {
	setlocale(LC_CTYPE, "Rus");

	/*

	*/

	//Код программы
	const int SIZE = 10;

	int arr[SIZE];
	for (int i = 0; i < SIZE; i++)
	{
		arr[i] = rand();
		cout << "arr[" << i << "] = " << arr[i] << endl;
	}
	
	int tmp;
	for (int i = 0; i < SIZE / 2; i++)
	{
		tmp = arr[i];
		arr[i] = arr[SIZE - i - 1];
		arr[SIZE - i - 1] = tmp;
	}
	cout << endl;
	for (int i = 0; i < SIZE; i++)
	{
		cout << "arr[" << i << "] = " << arr[i] << endl;
	}

	cout << endl;
	system("pause");
}