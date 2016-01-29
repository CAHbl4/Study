#include <iostream>
using namespace std;

/*
В одномерном массиве int A[10] положительные элементы уменьшить в двое, а отрицательные элементы заменить на значения их индексов
*/

void main() {
	setlocale(LC_CTYPE, "Rus");

	//Код программы

	int const N = 10;
	int arr[N];

	for (int i = 0; i < N; i++)
	{
		arr[i] = rand() % 21 - 10;
		cout.width(4);
		cout << arr[i];
	}
	cout << endl;

	for (int i = 0; i < N; i++)
	{
		if (arr[i] >= 0) {
			arr[i] /= 2;
		}
		else {
			arr[i] = i;
		}
		cout.width(4);
		cout << arr[i];
	}

	cout << endl;
	system("pause");
}