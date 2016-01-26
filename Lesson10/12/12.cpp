#include <iostream>

using namespace std;

void main() {
	setlocale(LC_CTYPE, "Rus");

	/*
	Нарисовать прямоугольный треугольник из символов ^. Высоту ввести с клавиатуры. Отступить от левого края экрана на 8 позиций (табуляция).


	*/

	//Код программы

	int height = 0;
	cout << "Введите высоту: ";
	cin >> height;
	for (int i = 0; i < height; i++)
	{
		cout << "\t";
		for (int j = height - i; j <= height; j++)
		{
			cout << '^';
		}
		cout << endl;
	}


	cout << endl;
	system("pause");
}