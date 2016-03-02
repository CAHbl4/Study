#include <iostream>
#include <bitset>

using namespace std;

void main() {
	setlocale(LC_CTYPE, "Rus");

	//Код программы
	int i, x;

	for (i = -16; i < 16; i++) {
		bitset<4> x(i);
		cout << i << "\t" << x << endl;
	}


	cout << endl;
	system("pause");
}