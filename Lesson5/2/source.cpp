#include <iostream>

using namespace std;

void main() {
	setlocale(LC_CTYPE, "Rus");

	//��� ���������

	int I = 27;
	short S = 2;
	double F = 22.3;
	bool B = false;

	cout << I - F + S * B << "    " << sizeof(I - F + S * B);
	// �� ������ ����� 4.7

	cout << endl;
	system("pause");
}