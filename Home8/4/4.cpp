#include <iostream>

using namespace std;

void main() {
	setlocale(LC_CTYPE, "Rus");

	/*
	�������� ���������, ������� � ��������������  ����������� switch-case ����������,
	����� ���� (������� ����, �������, �����������) �������� ��������� ����� ��� ������.

	*/

	//��� ���������
	enum days { mon = 1, tue, wed, thu, fri, sat, sun };
	int d;
	cout << "������� ����� ���: ";
	if (cin >> d) {
		if (d && d <= 7) {
			switch (d)
			{
			case mon: case tue: case wed: case thu: case fri: 
				cout << "������� ����"; break;
			case sat: cout << "�������"; break;
			case sun: cout << "�����������"; break;
			}
		}
		else cout << "� ������ 7 ����";
	}
	else cout << "������ �����";


	cout << endl;
	system("pause");
}