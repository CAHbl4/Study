#include <iostream>

using namespace std;

void main() {
	setlocale(LC_CTYPE, "Rus");

	/*
	Найти элемент массива, который чаще других встречается в массиве.

	*/

	//Код программы

	const int N = 20;

	int arr[N];
	int arrCount[N];

	for (int i = 0; i < N; i++)
	{
		arr[i] = rand();
		arrCount[i] = 1;
	}

	for (int i = 0; i < N; cout << arr[i] << ' ', i++);
	cout << endl;

	for (int i = 0; i < N; i++)
	{
		for (int j = i + 1; j < N; j++)
		{
			if (arr[i] == arr[j]) arrCount[i]++;
		}
	}

	int max = 1;
	for (int i = 0; i < N - 1; i++)
	{
		if (arrCount[max] < arrCount[i]) max = arrCount[i];
	}

	if (max == 1) cout << "Каждый элемент массива встречаетя один раз";
	else {
		for (int i = 0; i < N; i++)
		{
			if (arrCount[i] == max) {
				cout << "arr[" << i << "] = " << arr[i] << " - " << arrCount[i] << " раз" << endl;
			}
		}
	}


	cout << endl;
	system("pause");
}