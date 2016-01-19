#include <iostream>

using namespace std;

void main() {
	setlocale(LC_CTYPE, "Rus");

	/*

	*/

	//Код программы

	int a[100];
	int n;
	int i;

	cout << "Сколько элементов массива: ";
	cin >> n;
	for (int i = 0; i < n; i++) {
		cout << "A[" << i << "] = ";
		cin >> a[i];
	}

	cout << endl;
	system("pause");
}