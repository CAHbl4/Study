#include <iostream>

using namespace std;

void main() {
	setlocale(LC_CTYPE, "Rus");

	/*
	Сортировка пузырьклм
	*/

	//Код программы

	const int LEN = 10;
	int arr[LEN];
	for (int i = 0; i < LEN; i++)
	{
		arr[i] = rand() % 101;
	}

	bool sorted;
	int tmp;
	int j = 0;

	do {
		sorted = 1;
		for (int i = 0; i < LEN - j - 1; i++) {
			if (arr[i] > arr[i + 1]) {
				tmp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = tmp;
				sorted = 0;
				for (int i = 0; i < LEN; cout << arr[i] << ' ', i++);
				cout << endl;
			}
		}
		j++;
	} while (!sorted);

	cout << endl;
	system("pause");
}