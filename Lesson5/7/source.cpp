#define _USE_MATH_DEFINES
#include <iostream>
#include <math.h>

using namespace std;

float exp(float x, int y);

void main() {
	setlocale(LC_CTYPE, "Rus");

	/*������������ ������ � ���������� ������� ����������. 
	��������� ������� � ����� ����������.*/

	//��� ���������

	float d;

	cout << "������� �������: ";
	cin >> d;
	cout << "������� = " << M_PI * exp(d / 2, 2) << " ������ ���������� = " << M_PI * d;

	cout << endl;
	system("pause");
}

float exp(float x, int y) {
	int i;
	float result = 1.0;
	if (y < 0) {
		for (i = 0; i < -y; i++) {
			result *= x;
		}
		result = 1 / result;
	}
	else if (y > 0) {
		for (i = 0; i < y; i++) {
			result *= x;
		}
	}
	return result;
}