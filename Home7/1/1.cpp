#include <iostream>

using namespace std;

void main() {
	setlocale(LC_CTYPE, "Rus");

	/*
	��������� ���������� �� ������. ������������ ������ ���������� ����� ��� ������ � � ���� �� ������ ������������, ��, ��� ������������� �� ���� ����.
	*/

	//��� ���������

	int d;

	cout << "������� ����� ��� ������: ";
	cin >> d;

	switch (d)
	{
	case 1:
		cout << "������� ���� ��� ��������������� ������";
		break;
	case 2: case 3:
		cout << "������� 2 ���� \"���������������� �� ��\"";
		break;
	case 4: case 5:
		cout << "������� 2 ���� \"ITe\"";
		break;
	case 6: case 7:
		cout << "������� ��������";
		break;
	default:
		cout << "�������� ����";
		break;
	}

	cout << endl;
	system("pause");
}