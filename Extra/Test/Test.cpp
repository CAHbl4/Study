#include <iostream>

using namespace std;

void main() {
	setlocale(LC_CTYPE, "Rus");

	int k = 3;
	double mas[k] = { 1, 2, 3 };
	for (int i = 0; i<k; i++)
		mas[i++] += 4;
	for (int i = 0; i<k; i++)
		cout << mas[i];

	cout << endl;
	system("pause");
}