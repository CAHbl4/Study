#include <iostream>

using namespace std;

void main() {
	setlocale(LC_CTYPE, "Rus");

	/*
	8. �������� ���������, ������� ����� ���������� � ���������� ����� (� ��������� �� 1 �� 999), ������������� �������� �������,
	���������� ����� "�����" � ���������� �����. ��������, 12 ������, 21 �����.

	11. �������� ���������, ������� ����� ���������� � ���������� ����� (� ��������� �� 1 �� 999), ������������� �������� �������,
	���������� ����� "�����" � ���������� �����. ��������, 12 ������, 21 �����.

	12. �������� ���������, ������� ��������� ����� 3-�������� ����� � ���������� � ������� ��������� ������������� ����� �����.
	��������: ������������ ���� 431, ��������� ������� ��������� �������� ����.
	*/

	//��� ���������

	int a;
	cout << "������� ����� � ��������� �� 1 �� 999: ";
	if (cin >> a && a > 0 && a < 1000) {

		switch (a / 100)
		{
		case 9: cout << "��������� "; break;						//� ���������� ��� ��� ����� ���������� � ������� ��� ����� �� ����������
		case 8: cout << "��������� "; break;
		case 7: cout << "������� "; break;
		case 6: cout << "�������� "; break;
		case 5: cout << "������� "; break;
		case 4: cout << "��������� "; break;
		case 3: cout << "������ "; break;
		case 2: cout << "������ "; break;
		case 1: cout << "��� "; break;
		default:
			break;
		}
		switch (a % 100 / 10) {
		case 9: cout << "��������� "; break;
		case 8: cout << "����������� "; break;
		case 7: cout << "��������� "; break;
		case 6: cout << "���������� "; break;
		case 5: cout << "��������� "; break;
		case 4: cout << "����� "; break;
		case 3: cout << "�������� "; break;
		case 2: cout << "�������� "; break;
		}
		if (a > 100 ? a % 100 / 10 == 1 : a / 10 == 1) {
			switch (a % 10) {
			case 9: cout << "������������ ������"; break;
			case 8: cout << "������������ ������"; break;
			case 7: cout << "���������� ������"; break;
			case 6: cout << "����������� ������"; break;
			case 5: cout << "���������� ������"; break;
			case 4: cout << "������������ ������"; break;
			case 3: cout << "���������� ������"; break;
			case 2: cout << "���������� ������"; break;
			case 1: cout << "���������� ������"; break;
			case 0: cout << "������ ������"; break;
			}
		}
		else {
			switch (a % 10) {
			case 9: cout << "������ ������"; break;
			case 8: cout << "������ ������"; break;
			case 7: cout << "���� ������"; break;
			case 6: cout << "����� ������"; break;
			case 5: cout << "���� ������"; break;
			case 4: cout << "������ �����"; break;
			case 3: cout << "��� �����"; break;
			case 2: cout << "��� �����"; break;
			case 1: cout << "���� �����"; break;
			case 0: cout << "������"; break;
			}
		}
	}
	else cout << "������ �����";

	cout << endl;
	system("pause");
}