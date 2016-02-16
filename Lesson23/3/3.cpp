#include <iostream>
using namespace std;

/*
Напишите функцию быстрого возведения в степень, которая пользовалась бы следующими свойствами:

*/
int pow(int x);

void main() {
	setlocale(LC_CTYPE, "Rus");

	//Код программы

	cout << pow(2, 7);

	cout << endl;
	system("pause");
}

int pow(int x, int y)
{
	if (y == 1) return x;
	if (x % 2)
	{
		return x * (pow(x, y - 1));
	}
	else
	{
		return pow((pow(x, y / 2)), 2);
	}
}
