#include <iostream>
using namespace std;

/*
������� �������, ������������ ������ ������� �������� �������������� (�������������) ������� �� n ���������, 
�������� �������� ����� ��������� ����� x. ���� ������ �������� � ������� ���, �� ������� ����� ������  �1.

*/

int indexOf(int arr[], int n, int x);
int indexOf(double arr[], int n, double x);

void main() {
	setlocale(LC_CTYPE, "Rus");

	//��� ���������

	

	cout << endl;
	system("pause");
}

int indexOf(int arr[], int n, int x) {
	int i = 0;
	while (i < n) {
		if (arr[i] == x) {
			return i;
		}
		i++;
	}
	return -1;
}

int indexOf(double arr[], int n, double x) {
	int i = 0;
	while (i < n) {
		if (arr[i] == x) {
			return i;
		}
		i++;
	}
	return -1;
}