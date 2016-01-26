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


	//��� ���������

	int c, op;

	cout << "������ ��������:" << endl;
	cout << "1. ������� ���� ����" << endl;
	cout << "2. ������� ���� ������" << endl;
	cout << "3. ������� ������ ������" << endl;
	cout << "0. ������� ������ ������" << endl;

	while (1) {
		cout << "�������� ��������:" << endl;
		if (cin >> op) {
			if (op) {
				switch (op){
				case 1:
					cout << "������� ��� �����: ";
					if (cin >> c){
						if (check_color(c)){
							set_bg(c);
						}
						else {
							cout << "�������� ����";
						}
					}
					break;
				case 2:
					cout << "������� ��� �����: ";
					if (cin >> c){
						if (check_color(c)){
							set_text(c);
						}
						else {
							cout << "�������� ����";
						}
					}
					break;
				case 3:
					print_colors();
					break;
				default:
					cout << "�������� ��������";
					break;
				}
			}
			else break;
		}
		else {
			cin.clear();
			cin.sync();
			cout << "������ �����" << endl;
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
	cout << "������ ������ �������: " << endl;
	for (int i = 0; i <= 15; i++) {
		cout << i << " " << name[i] << endl;
	}
}

bool check_color(int c) {
	if (c >= 0 && c <= 15) return 1;
	return 0;
}