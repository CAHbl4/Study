#include <iostream>

using namespace std;

void main() {
	setlocale(LC_CTYPE, "Rus");

	/*
	Нарисовать контур прямоугольника из символов *. Размеры ввести с клавиатуры.

	*/

	//Код программы

	int width, height;

	cout << "Введите ширину и высоту прямоугольника. Ширина должна быть меньше 120: ";
	if (cin >> width >> height) {
		if (width >= 120) {
			cout << "Ширина должна быть меньше 120";
		}
		else {
			for (int h = 1; h <= height; h++, cout << endl) {
				for (int w = 1; w <= width; w++) {
					if (h == 1 || h == height) cout << '*';
					else {
						if (w == 1 || w == width) cout << '*';
						else cout << ' ';
					}
				}
			}
		}
	}
	else  cout << "Ошибка ввода";

	cout << endl;
	system("pause");
}