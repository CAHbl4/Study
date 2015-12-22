#include <iostream>

using namespace std;

void main() {
	setlocale(LC_CTYPE, "Rus");

	/*

	*/

	//Код программы

	for (int x = 1;; x++)
	{
		if (x == 5) break;
		cout << x;
	}
	cout << "Bye!";


	cout << endl;
	system("pause");
}