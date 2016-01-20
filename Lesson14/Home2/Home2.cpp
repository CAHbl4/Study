#include <iostream>

using namespace std;

/*
������������ ������ ������� ����� �� ��� (12 �������). ����� ������������ ������ ��������
(��������, 3 � 6 � ����� ����� 3-� � 6-� �������). ���������� ���������� �����, � �������
������� ���� ����������� � �����, � ������� ������� ���� ���������� � ������ ���������� ���������.
*/

//��������� ��� ������ �������� �������
struct elem
{
	//������
	int key;
	//��������
	int value;
};

//�������� �������

elem getMin(int *arr, int num, int start = 0, int end = -1);
elem getMax(int *arr, int num, int start = 0, int end = -1);
void printMonth(int i);
int getMonth();

void main() {
	setlocale(LC_CTYPE, "Rus");


	//��������� ������
	int arr[12];

	cout << "������� ������� �� �����." << endl;

	int i = 0;

	//��������� ������
	while (i != 12) {
		//������� ����������� �� ����
		cout << i + 1 << ". ";
		printMonth(i + 1);
		cout << ": ";

		//�������� ������������ �����
		if (cin >> arr[i]) i++;
		else {
			//������� ������ ����� ��� ������������ �����
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cout << "������ �����. ���������." << endl;
		}
	}

	//i1 - ������ �������, i2 - ����� �������
	int i1 = -1, i2 = -1;

	//������ ������ � ����� �������
	while (1) {

		//������� getMonth() ���������� -1 ��� ������������ �����
		while (i1 == -1) {
			cout << "������� ������ ������� (1-12): ";
			i1 = getMonth();
		}

		while (i2 == -1) {
			cout << "������� ����� ������� (1-12): ";
			i2 = getMonth();
		}

		//�������� �� ������������ ��������
		if (i1 > i2) {
			i1 = i2 = -1;
			cout << "����� ������ ������� ������ ���� ������ �����. ��������� ����" << endl;
		}
		else break;
	}

	//�������� ����������� �������� �� ��������� ���������
	elem min = getMin(arr, 12, i1, i2);
	
	//�������� ������������ �������� �� ��������� ���������
	elem max = getMax(arr, 12, i1, i2);


	//������� ����������
	cout << "����������� ������� �� ������: ";
	printMonth(min.key + 1);
	cout << " - " << min.value;

	cout << endl;

	cout << "������������ ������� �� ������: ";
	printMonth(max.key + 1);
	cout << " - " << max.value;

	cout << endl;
	system("pause");
}

//������� ������ ������ �� �����.
void printMonth(int i) {
	switch (i)
	{
	case 1: cout << "������"; break;
	case 2: cout << "�������"; break;
	case 3: cout << "����"; break;
	case 4: cout << "������"; break;
	case 5: cout << "���"; break;
	case 6: cout << "����"; break;
	case 7: cout << "����"; break;
	case 8: cout << "������"; break;
	case 9: cout << "��������"; break;
	case 10: cout << "�������"; break;
	case 11: cout << "������"; break;
	case 12: cout << "�������"; break;
	}
}

//������� ����� ������ � ����������. ������� ���������� -1 ��� ������������ �����
int getMonth() {
	int m = -1;

	//�������� �� ���� �����
	if (cin >> m) {

		//�������� �� ������������ ������
		if (!(m >= 1 && m <= 12)) {
			cout << "����� ������ ���� � �������� 1 - 12. ��������� ����" << endl;
			m = -1;
		}
	}
	else
	{
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout << "������ �����. ���������." << endl;
	}
	return m;
}

//������� ���������� ������������ �������� �������
elem getMin(int *arr, int num, int start, int end) {

	//���� �� ����� �������� ����� ��������� ��� ������ ������� ������������ ��� � ���������� ��������
	if (end = -1) end = num - 1;

	//��������� ��������� � ����������� �� ������ ������� ���������
	elem min = { start, arr[start] };

	//���� � ����� ������� �������� ������� �� ������� �������� ���������
	for (int i = start + 1; i <= end; i++)
	{
		if (arr[i] < min.value) min = { i, arr[i] };
	}

	return min;
}

//������� ���������� ������������� �������� �������
elem getMax(int *arr, int num, int start, int end) {
	if (end = -1) end = num - 1;

	//��������� ��������� � ����������� �� ������� ������� �������
	elem max = { start, arr[start] };

	//���� � ����� ������������ �������� ������� �� �������
	for (int i = start + 1; i <= end; i++)
	{
		if (arr[i] > max.value) max = { i, arr[i] };
	}

	return max;
}