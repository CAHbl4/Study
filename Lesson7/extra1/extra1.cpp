#include <iostream>

using namespace std;

enum colors { BLACK, BLUE, GREEN, CYAN, RED, MAGENTA, BROWN, LIGHTGREY, DARKGREY, LIGHTBLUE, LIGHTGREEN, LIGHCYAN, LIGHTRED, LIGHTMAGENTA, YELLOW, WHITE };
char name[][15] = { "BLACK", "BLUE", "GREEN", "CYAN", "RED", "MAGENTA", "BROWN", "LIGHTGREY", "DARKGREY", "LIGHTBLUE", "LIGHTGREEN", "LIGHCYAN", "LIGHTRED", "LIGHTMAGENTA", "YELLOW", "WHITE" };

void print_colors();
void set_bg(int c);
void set_text(int c);
bool check_color(int c);

void main() {
	setlocale(LC_CTYPE, "Rus");

	/*
	+--------------+-----+
	| BLACK        | 0   |
	| BLUE         | 1   |
	| GREEN        | 2   |
	| CYAN         | 3   |
	| RED          | 4   |
	| MAGENTA      | 5   |
	| BROWN        | 6   |
	| LIGHTGREY    | 7   |
	| DARKGREY     | 8   |
	| LIGHTBLUE    | 9   |
	| LIGHTGREEN   | 10  |
	| LIGHTCYAN    | 11  |
	| LIGHTRED     | 12  |
	| LIGHTMAGENTA | 13  |
	| YELLOW       | 14  |
	| WHITE        | 15  |
	| BLINK        | 128 |
	+--------------+-----+
	*/


	//Код программы

	int c, op;

	cout << "Список операций:" << endl;
	cout << "1. Сменить цвет фона" << endl;
	cout << "2. Сменить цвет текста" << endl;
	cout << "3. Вывести список цветов" << endl;
	cout << "0. Вывести список цветов" << endl;

	while (1) {
		cout << "Выберите операцию:" << endl;
		if (cin >> op) {
			if (op) {
				switch (op){
				case 1:
					cout << "Введите код цвета: ";
					if (cin >> c){
						if (check_color(c)){
							set_bg(c);
						}
						else {
							cout << "Неверный цвет";
						}
					}
					break;
				case 2:
					cout << "Введите код цвета: ";
					if (cin >> c){
						if (check_color(c)){
							set_text(c);
						}
						else {
							cout << "Неверный цвет";
						}
					}
					break;
				case 3:
					print_colors();
					break;
				default:
					cout << "Неверная операция";
					break;
				}
			}
			else break;
		}
		else {
			cin.clear();
			cin.sync();
			cout << "Ошибка ввода" << endl;
		}
	}

	cout << endl;
	system("pause");
}

void set_bg(int c) {

}

void set_text(int c) {

}

void print_colors() {
	cout << "Список цветов консоли: " << endl;
	for (int i = 0; i <= 15; i++) {
		cout << i << " " << name[i] << endl;
	}
}

bool check_color(int c) {
	if (c >= 0 && c <= 15) return 1;
	return 0;
}