#include <iostream>

using namespace std;

void main() {
	setlocale(LC_CTYPE, "Rus");

	/*

	*/

	//Код программы

	int a = 347;

	short arr[10];

	for (int i = 9; i >= 0; i--)
	{
		arr[i] = a % 10;
		a /= 10;
	}

	for (int i = 0; i < 10; i++)
	{
		cout << arr[i] << " ";
	}

	char arr[5];
	a = 357;

	char tmp, tmp2;
	for (int i = 9; i >= 0; i -= 2)
	{
		tmp = a % 10;
		a /= 10;
		tmp2 = a % 10;
		tmp2 = tmp2 << 4;
		arr[i / 2] = tmp | tmp2;
	}

	cout << endl;
	system("pause");
}