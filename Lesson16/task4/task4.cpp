#include <iostream>

using namespace std;

void main() {
	setlocale(LC_CTYPE, "Rus");

	/*
	�������� ��������� �����������. ������� ��� ���������� �������. ���� ������ ������ ������ ICQ, ������ � ���������� ������.
	������� �������� �������. ������������� � ������� ������� ������� �� ������� ICQ, � ����� �� ������� ���������.

	*/

	//��� ���������

	const int N = 10;
	int arrIcq[N];
	int arrPhone[N];

	for (int i = 0; i < N; i++)
	{
		arrIcq[i] = rand() % 1001 + rand() % 1001 * 1000 + rand() % 1001 * 1000 * 1000;
		arrPhone[i] = rand() % 1001 + rand() % 1001 * 1000 + rand() % 101 * 1000 * 100;
	}

	cout << "�������� ������� �� ICQ" << endl;
	cout << "  ICQ: ";
	for (int i = 0; i < N; printf_s("%9d ", arrIcq[i]), i++);
	cout << endl;
	cout << "Phone: ";
	for (int i = 0; i < N; printf_s("%9d ", arrPhone[i]), i++);
	cout << endl << endl;


	for (int i = 0; i < N - 1; i++)
	{
		int min = i;
		for (int j = i + 1; j < N; j++)
		{
			if (arrIcq[j] < arrIcq[min]) min = j;
		}
		if (min != i) {
			int tmp = arrIcq[i];
			int tmp2 = arrPhone[i];
			arrIcq[i] = arrIcq[min];
			arrPhone[i] = arrPhone[min];
			arrIcq[min] = tmp;
			arrPhone[min] = tmp2;
		}
	}

	cout << "���������� �� ICQ" << endl;
	cout << "  ICQ: ";
	for (int i = 0; i < N; printf_s("%9d ", arrIcq[i]), i++);
	cout << endl;
	cout << "Phone: ";
	for (int i = 0; i < N; printf_s("%9d ", arrPhone[i]), i++);
	cout << endl << endl;

	for (int i = 0; i < N - 1; i++)
	{
		int min = i;
		for (int j = i + 1; j < N; j++)
		{
			if (arrPhone[j] < arrPhone[min]) min = j;
		}
		if (min != i) {
			int tmp = arrIcq[i];
			int tmp2 = arrPhone[i];
			arrIcq[i] = arrIcq[min];
			arrPhone[i] = arrPhone[min];
			arrIcq[min] = tmp;
			arrPhone[min] = tmp2;
		}
	}

	cout << "���������� �� Phone" << endl;
	cout << "  ICQ: ";
	for (int i = 0; i < N; printf_s("%9d ", arrIcq[i]), i++);
	cout << endl;
	cout << "Phone: ";
	for (int i = 0; i < N; printf_s("%9d ", arrPhone[i]), i++);
	cout << endl << endl;


	cout << endl;
	system("pause");
}
