#include <iostream>

using namespace std;

bool check_date(int y, int m, int d);

void main() {
	setlocale(LC_CTYPE, "Rus");

	/*
	������������ ������ ������� ���� � ���� ��� ��������. ���������, ������� ������ ��� ������������.

	*/

	//��� ���������

	int d1, m1, y1; //������� ����
	int d2, m2, y2; //���� ��������

	cout << "������� ������� ���� (���� ����� ���): ";
	cin >> d1 >> m1 >> y1;

	if (check_date(y1, m1, d1)) {
		cout << "������� ���� �������� (���� ����� ���): ";
		cin >> d2 >> m2 >> y2;
		if (check_date(y2, m2, d2)) {
			if (y2 <= y1) {
				if (m1 == m2 && d1 == d2) cout << "� ��� ������� ���� ��������, ����������. ";
				if (y2 == y1 && (m2 < m1 || (m2 == m1 && d2 < d1))) cout << "��� ������ ����";
				else if (y2 == y1 && m2 == m1 && d2 == d1) cout << "�� �������� �������";
				else if (y2 == y1) cout << "�� ��� �� ��������";
				else if (y1 - y2 == 1 && (m2 < m1 || (m2 == m1 && d2 <= d1))) cout << "��� 1 ���";
				else if (y1 - y2 == 1) cout << "��� ������ ����";
				else if (m2 < m1 || (m2 == m1 && d2 <= d1)) {
					cout << "��� " << y1 - y2 << " ������ ���";
				}
				else cout << "��� " << y1 - y2 - 1 << " ������ ���";
			}
			else cout << "�� ��� �� ��������";

		}

		else cout << "�������� ����";

	}
	else cout << "�������� ����";

	cout << endl;
	system("pause");
}

bool check_date(int y, int m, int d) {			//������� �������� ���� �� ������������
	if (y > 0 && m > 0 && d > 0) {				//���� �� ����� ��������� ������� ��������
		switch (m)
		{
		case 1:	case 3:	case 5:	case 7: case 8: case  10: case 12:			//������, ����, ���, ����, ������, �������, �������
			if (d <= 31) return 1;
			break;
		case 2:													//�������
			if (!(y % 400) || !(y % 4) && (y % 100)) {			//���������� ������������
				if (d <= 29) return 1;
			}
			else {
				if (d <= 28) return 1;
			}

			break;
		case 4: case 6: case 9: case 11:		//������, ����, ��������, ������
			if (d <= 30) return 1;
			break;
		default:
			return 0;
			break;
		}
	}
	return 0;
}

