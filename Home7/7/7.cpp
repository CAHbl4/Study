#include <iostream>

using namespace std;

void main() {
	setlocale(LC_CTYPE, "Rus");

	/*
	�������� ��������� ��� ���������� �������� ����������� ��������� ��� �������� ���������� a=false, b=true, c=false, d=true;
	�) a||b&&!a&&d
	�) a&&b||!c||d

	*/

	//��� ���������

	bool a = false, b = true, c = false, d = true;

	cout << "��������� ����������� ��������� a||b&&!a&&d ��� a=false, b=true, c=false, d=true �����: " << (a || b && !a && d ? "true" : "false"); //�� � ����� ��� � ����� ������� ���������
	cout << endl;
	cout << "��������� ����������� ��������� a&&b||!c||d ��� a=false, b=true, c=false, d=true �����: " << (a && b || !c || d ? "true" : "false");

	cout << endl;
	system("pause");
}