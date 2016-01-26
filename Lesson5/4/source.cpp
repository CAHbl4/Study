#include <iostream>

using namespace std;

void main() {
	setlocale(LC_CTYPE, "Rus");

	//Код программы
	int i;

	for (i = 1; i <= 256; i++) {
		cout << i << " " << (char)i;
		if (i % 8) cout << "\t";
		else cout << endl;
	}

	cout << endl;
	system("pause");
}