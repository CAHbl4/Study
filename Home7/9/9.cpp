#include <iostream>

using namespace std;

bool check_date(int y, int m, int d); //������� �� 6� ������������ �������
bool is_leap(int y);

void main() {
	setlocale(LC_CTYPE, "Rus");

	/*
	�������� ���������, ������� ��������� ���� ���������� ���. ���������� � ������� ��� ������� � ����������. ��������� ������������ �����.

	*/

	//��� ���������

	int y, m, d;
	cout << "������� ������� ���� (���� ����� ���): ";
	if (cin >> d >> m >> y) {
		if (check_date(y, m, d)) {
			if (check_date(y, m, d + 1))
				cout << "������ " << d + 1 << "." << m << "." << y;
			else if (check_date(y, m + 1, 1))
				cout << "������ " << 1 << "." << m + 1 << "." << y;
			else if (check_date(y + 1, 1, 1))
				cout << "������ " << 1 << "." << 1 << "." << y + 1;
		}
		else cout << "�������� ����";
	}
	else cout << "������ �����";

	cout << endl;
	system("pause");
}

bool is_leap(int y) {													//������� ����������� ������������
	if (!(y % 400) || !(y % 4) && (y % 100)) return 1;
	return 0;
}

bool check_date(int y, int m, int d) {									//������� �������� ���� �� ������������
	if (y > 0 && m > 0 && d > 0) {										//���� �� ����� ��������� ������� ��������
		switch (m)
		{
		case 1:	case 3:	case 5:	case 7: case 8: case  10: case 12:		//������, ����, ���, ����, ������, �������, �������
			if (d <= 31) return 1;
			break;
		case 2:															//�������
			if (is_leap(y)) {											//���������� ������������
				if (d <= 29) return 1;
			}
			else {
				if (d <= 28) return 1;
			}

			break;
		case 4: case 6: case 9: case 11:								//������, ����, ��������, ������
			if (d <= 30) return 1;
			break;
		default:
			return 0;
			break;
		}
	}
	return 0;
}