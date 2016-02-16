#include <iostream>
using namespace std;

/*
Описать функцию Leng(xA, yA, xB, yB) вещественного типа, находящую длину отрезка AB на плоскости по координатам его концов.

*/

double length(int x1, int y1, int x2, int y2);

void main() {
	setlocale(LC_CTYPE, "Rus");

	//Код программы
	int x1, y1, x2, y2;
	cout << "Введите x1, y1, x2, y2: ";

	cin >> x1 >> y1 >> x2 >> y2 ;
	try {
		if (cin.fail()) {
			throw "error";
		}
		cout << "Длинна отрезка: " << length(x1, y1, x2, y2);
	}
	catch (char* error) {
		cout << error << endl;
	}

	cout << endl;
	system("pause");
}

double length(int x1, int y1, int x2, int y2)
{
	return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}
