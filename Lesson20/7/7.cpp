#include <iostream>
using namespace std;

/*
Напишите функцию, которая сортирует массив методом пузырька и выводит отсортированный массив на экран.

*/

void sort(int a[], int n) {
	bool sorted;
	int j = 0;
	do {
		sorted = true;
		for (int i = 0; i < n - j - 1; i++)
		{
			if (a[i] > a[i + 1]) {
				int tmp = a[i];
				a[i] = a[i + 1];
				a[i + 1] = tmp;
				sorted = false;
			}
		}
		j++;
	} while (!sorted);

	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}

}


void main() {
	setlocale(LC_CTYPE, "Rus");

	//Код программы

	int i, a[5];
	for (i = 0; i < 5; i++) {
		a[i] = rand() % 10;
		cout << a[i] << " ";
	}
	cout << endl;
	
	sort(a, 5);

	cout << endl;
	system("pause");
}