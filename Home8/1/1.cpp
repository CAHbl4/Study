#include <iostream>

using namespace std;

void main() {
	setlocale(LC_CTYPE, "Rus");

	/*
	�������� ���������, ������� �� ���������� ������������� ����� ������� �������� ������. 
	��������� ������������ ����� ������.

	*/

	//��� ���������
	enum month { jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec };
	int m;
	cout << "������� ����� ������: ";
	if (cin >> m) {
		if (m && m <= 12) {
			switch (m)
			{
			case jan: cout << "������"; break;
			case feb: cout << "�������"; break;
			case mar: cout << "����"; break;
			case apr: cout << "������"; break;
			case may: cout << "���"; break;
			case jun: cout << "����"; break;
			case jul: cout << "����"; break;
			case aug: cout << "������"; break;
			case sep: cout << "��������"; break;
			case oct: cout << "�������"; break;
			case nov: cout << "������"; break;
			case dec: cout << "�������"; break;
			}
		}
		else cout << "� ���� 12 �������";
	}
	else cout << "������ �����";


	cout << endl;
	system("pause");
}