#include <iostream>

using namespace std;

void main() {
	setlocale(LC_CTYPE, "Rus");

	/*
	������������ � ���������� ������ 5 ������ ��������. ����������, ������� �� ������� � ��������. ������� �������� ������, ���� ��� ������� ���� 4 ����� � ����.

	*/

	//��� ���������

	int arr[5];

	cout << "������� ������: ";
	for (int i = 0; i < 5; i++) {
		if (cin >> arr[i]);
		else { cout << "������ �����!"; system("pause"); return; }
	}

	int sum = 0;
	for (int i = 0; i < 5; i++) {
		sum += arr[i];
	}
	if (sum / 5 >= 4) { cout << "���� ������"; }
	else { cout << "��� �������"; }

	cout << endl;
	system("pause");
}