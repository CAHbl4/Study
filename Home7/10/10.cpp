#include <iostream>

using namespace std;

bool check_date(int y, int m, int d);
int date_day(int y, int m, int d);
bool is_leap(int y);

void main() {
	setlocale(LC_CTYPE, "Rus");

	/*
	�������� ���������, �������������� ����� �������� ���� ����. ��������� ������ ���������� ��� ������ ���� ������ ��������, 
	������� ���� � ������ ���������, ��� �� ������ �����-�� ����. ��������� ������������ �����.

	*/

	//��� ���������
	int y1, m1, d1;
	int y2, m2, d2;

	cout << "������� ���� �������� (���� ����� ���): ";
	if (cin >> d1 >> m1 >> y1) {
		if (check_date(y1, m1, d1)) {
			cout << "������� ������� ���� (���� ����� ���): ";
			if (cin >> d2 >> m2 >> y2) {
				if (check_date(y2, m2, d2)) {
					cout << "�� ������ " << date_day(y2, m2, d2) - date_day(y1, m1, d1) + 1 << " ����.";
				}
				else cout << "�������� ����";
			}
			else cout << "������ �����";
		}
		else cout << "�������� ����";
	}
	else cout << "������ �����";


	cout << endl;
	system("pause");
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

bool is_leap(int y) {													//������� ����������� ������������
	if (!(y % 400) || !(y % 4) && (y % 100)) return 1;
	return 0;
}

int date_day(int y, int m, int d) {										//������� �������� ���������� ���� �� ������ ����� �� ����
	int days;															//������������ ���������� ����
	int count_leap = 0;													//���������� ���������� ���
	int count_regular = 0;												//���������� ������� ���

	for (int i = 0; i < y; i++) is_leap(i) ? count_leap++ : count_regular++;		//������� ���������� ������� � ����������

	days = count_regular * 365 + count_leap * 366;						//������� ��� � ����� �����

	for (int i = 1; i < m; i++) {										//���������� ��� ����� �������
		switch (i)
		{
		case 1:	case 3:	case 5:	case 7: case 8: case  10: case 12:		//������, ����, ���, ����, ������, �������, �������
			days += 31;
			break;
		case 2:															//�������
			if (is_leap(y)) {											//���������� ������������
				days += 29;
			}
			else {
				days += 28;
			}
			break;
		case 4: case 6: case 9: case 11:								//������, ����, ��������, ������
			days += 30;
			break;
		default:
			break;
		}
	}

	days += d;															//���������� ��� �������� ������
	return days;
}