#include <iostream>

using namespace std;

void main() {
	setlocale(LC_CTYPE, "Rus");

	/*
	���������� ������ �������������� �� �������� *. ������� ������ � ����������.

	*/

	//��� ���������

	int width, height;

	cout << "������� ������ � ������ ��������������. ������ ������ ���� ������ 120: ";
	if (cin >> width >> height) {
		if (width >= 120) {
			cout << "������ ������ ���� ������ 120";
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
	else  cout << "������ �����";

	cout << endl;
	system("pause");
}