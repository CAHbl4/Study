#include <iostream>

using namespace std;

void main() {
	setlocale(LC_CTYPE, "Rus");

	/*
	���������� �������� ���������, ������� ��������� �� ������������ ����� ������ � �������� ����� ����, � �������� ���� ����� ���������.
	������ ������ ���� ������ � �������������� ����������� switch.
	*/

	//��� ���������

	enum month { jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec };
	int m;
	cout << "������� ����� ������: ";
	if (cin >> m) {
		if (m > 0 && m <= 12) {
			switch (m)
			{
			case dec: case jan: case feb: 
				cout << "����";
				break;
			case mar: case apr: case may:
				cout << "�����";
				break;
			case jun: case jul: case aug:
				cout << "����";
				break;
			case sep: case oct: case nov:
				cout << "�����";
				break;
			}

		}
		else cout << "� ���� 12 �������";
	}
	else cout << "������ �����";


	cout << endl;
	system("pause");
}