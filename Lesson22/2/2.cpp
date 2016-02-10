#include <iostream>
using namespace std;

/*
������� �������, ������������ ����������� �� ������ �� ����������� �������� �������������� (�������������) ������� �� n ���������.

*/

bool isSorted(int arr[], int n);
bool isSorted(float arr[], int n);

void main() {
	setlocale(LC_CTYPE, "Rus");

	//��� ���������

	const int N = 5;
	int arr[N];
	for (int i = 0; i < N; i++)
	{
		arr[i] = rand() % 10;
		cout << arr[i] << " ";
	}
	cout << endl;
	cout << isSorted(arr, N);
	

	cout << endl;
	system("pause");
}

bool isSorted(int arr[], int n) {
	int i = 1;
	while (i < n) {
		if (arr[i] < arr[i - 1]) {
			return false;
		}
		i++;
	}
	return true;
}

bool isSorted(float arr[], int n) {
	int i = 1;
	while (i < n) {
		if (arr[i] < arr[i - 1]) {
			return false;
		}
		i++;
	}
	return true;
}