#include <iostream>

using namespace std;

void main() {
	setlocale(LC_CTYPE, "Rus");

	/*
	���������, ������� ���������� ����������� �������� ������� f(x)=x(x-1)2(x-1)3 �� ��������� [-0,3; 0,5] � ��������� 0,001.

	*/

	//��� ���������
	double f, min = .0, val = .0;
	for (double x = -0.3; x <= 0.5; x += 0.001) {
		f = x * (x - 1) * 2 * (x - 1) * 3;
		if (f < min) { min = f; val = x; }
	}
	cout << "����������� ��������: " << min << " ��� �������� x = " << val;


	cout << endl;
	system("pause");
}