#include <iostream>

using namespace std;

void main() {
	setlocale(LC_CTYPE, "Rus");

	/*
	�������� ��������� ���������� 200$ + ������� �� ������, ������� �� 500$ - 3%, �� 500 �� 1000 � 5%, ����� 1000 � 8%.
	������������ ������ � ���������� ������� ������ ��� ���� ����������. 
	���������� �� ��������, ���������� ������� ���������, ��������� ��� ������ 200$, ������� ����� �� �����.

	*/

	//��� ���������

	int arr[3];

	for (int i = 0; i < 3; i++) {
		cout << "������� ������� ������ ��� " << i << " ���������: ";
		if (cin >> arr[i]);
		else { cout << "������ �����!"; system("pause"); return; }
	}
	
	int max = 0;
	for (int i = 0; i < 3; i++) {
		if (arr[i] > arr[max]) max = i;
	}

	for (int i = 0; i < 3; i++) {
		if (arr[i] < 500) arr[i] = arr[i] / 100 * 3;
		else if (arr[i] >= 500 && arr[i] < 1000) arr[i] = arr[i] / 100 * 5;
		else arr[i] = arr[i] / 100 * 8;
		arr[i] += 200;
		if (max == i) arr[i] += 200;
	}

	for (int i = 1; i <= 3; i++) {
		cout << "�������� ��������� " << i << ": " << arr[i - 1] << endl;
	}

	cout << endl;
	system("pause");
}