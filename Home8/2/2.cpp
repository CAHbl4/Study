#include <iostream>

using namespace std;

void main() {
	setlocale(LC_CTYPE, "Rus");

	/*
	�������� ���������, ������� �� ���������� ������������� ����� ������� �������� ��� ������.
	��������� ������������ ����� ������.

	*/

	//��� ���������
	enum days { mon = 1, tue, wed, thu, fri, sat, sun};
	int d;
	cout << "������� ����� ���: ";
	if (cin >> d) {
		if (d && d <= 7) {
			switch (d)
			{
			case mon: cout << "�����������"; break;
			case tue: cout << "�������"; break;
			case wed: cout << "�����"; break;
			case thu: cout << "�������"; break;
			case fri: cout << "�������"; break;
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