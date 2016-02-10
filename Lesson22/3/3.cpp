#include <iostream>
using namespace std;

/*
Описать функцию, определяющую индекс первого элемента целочисленного (вещественного) массива из n элементов, 
значение которого равно заданному числу x. Если такого элемента в массиве нет, то считать номер равным  –1.

*/

int indexOf(int arr[], int n, int x);
int indexOf(double arr[], int n, double x);

void main() {
	setlocale(LC_CTYPE, "Rus");

	//Код программы

	

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