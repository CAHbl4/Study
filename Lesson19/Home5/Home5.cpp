#include <iostream>
using namespace std;

/*
5.	Написать функцию, выводящую на экран прямоугольник с высотой N и шириной K.
*/

void rect(int width, int height);

void main() {
	setlocale(LC_CTYPE, "Rus");

	//Код программы
	int width, height;

	cout << "Введите ширину: ";
	cin >> width;
	cout << "Введите высоту: ";
	cin >> height;

	rect(width, height);

	cout << endl;
	system("pause");
}

void rect(int width, int height) {
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			cout << "*";
		}
		cout << endl;
	}
}