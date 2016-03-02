#include <iostream>

using namespace std;

void main() {
	setlocale(LC_CTYPE, "Rus");

	/*

	*/

	//Код программы

	int a[5] = { 1, 3, 5, 8, 15 };
	int sum = 0;

	for (int i = 0; i < 5; i++)
	{
		sum += a[i];
	}

	cout << sum;

	cout << endl;
	system("pause");
}