#include <iostream>
using namespace std;

/*
Описать функцию, определяющую упорядочены ли строго по возрастанию элементы целочисленного (вещественного) массива из n элементов.

*/

bool isSorted(int arr[], int n);
bool isSorted(float arr[], int n);

void main() {
	setlocale(LC_CTYPE, "Rus");

	//Код программы

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