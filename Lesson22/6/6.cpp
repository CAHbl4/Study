#include <iostream>
using namespace std;

/*
���� p � q - ������� ����� � q = p+2, �� ��� ���������� �������� ���������� ������� ��� ����������� (twin primes). 
��������, 3 � 5 - ����� ������� �����. ����������� ��� ������� ����� ��������, ������� N.

*/

bool isSimple(int a);

void main() {
	setlocale(LC_CTYPE, "Rus");

	//��� ���������
	const int N = 100;

	for (int i = 1; i < N - 2; i++)
	{
		if (isSimple(i) && isSimple(i + 2)) {
			cout << i << " " << i + 2 << endl;
		}
	}
	
	cout << endl;
	system("pause");
}

bool isSimple(int a) {
	for (int i = 2; i < a / 2; i++)
	{
		if (!(a % i)) return false;
	}
	return true;
}