#include <iostream>
using namespace std;

/*
����������, �������� �� ����� (����������) ������� �����, ������� 10000, ������� ������.

*/

bool func(int a);
bool isSimple(int a);

void main() {
	setlocale(LC_CTYPE, "Rus");

	//��� ���������

	cout << (func(10000) ? "true": "false");

	cout << endl;
	system("pause");
}

bool func(int a) {
	int count = 0;
	for (int i = 0; i < a; i++)
	{
		if (isSimple(i)) {
			count++;
		}
	}
	return isSimple(count);
}

bool isSimple(int a) {
	for (int i = 2; i < a / 2; i++)
	{
		if (!(a % i)) return false;
	}
	return true;
}