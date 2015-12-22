#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

void main() {
	setlocale(LC_CTYPE, "Rus");
	streamsize def_precision = cout.precision();
	streamsize def_width = cout.width();
	char def_fill = cout.fill();

	/*
	������������ ������ � ���������� ������� �����. ��������� ��� �� ���� ������ ����� ������� � ������� �� �����. 
	������������� ���������� �� ��������, ����� ����� 12,341 ����������� �� 12,34, � ����� 12,349 � �� 12,35.
	*/

	//��� ���������

	double f, d;

	cout << "������� �����: ";
	cin >> f;

	cout << "������� ����������� ����� <math.h>: " << round(f * 100) / 100 << endl;

	cout << "������� ����������� ����� ����� ������ cout: " << fixed << setprecision(2) << f << endl;
	cout << resetiosflags(ios_base::fixed) << setprecision(def_precision);		//���������� ������������� �����

	d = f - (int)f;													//�������� ������� �����
	d = d < 0 ? (int)(-d * 1000) : (int)(d * 1000);				//���������� ���� � �������� 3 ����� ����� �������
	d = (int)d % 10 < 5 ? (int)d / 10 : (int)d / 10 + 1;		//��������� �� 2� ������

	cout << "������� �������� ��������: " << (int)f << "." << setw(2) << setfill('0') << d << endl;		//������ ��������� ��������
	cout << setw(def_width) << setfill(def_fill);			//���������� ������������� �����

	f = f < 0 ? (int)f - d / 100.0 : (int)f + d / 100.0;		//"��������" ����� ������ � ������ �����

	cout << "������� ���������� ��������: " << f << endl;;

	cout << endl;
	system("pause");
}