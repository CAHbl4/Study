#include <iostream>

using namespace std;

void main() {
	setlocale(LC_CTYPE, "Rus");

	//Код программы

	int A = 3; int B = 2;

	cout << A / B << "\t" << sizeof(A / B) << endl;
	cout << (float)A / B << "\t" << sizeof((float)A / B) << endl;
	cout << A / (float)B << "\t" << sizeof(A / (float)B) << endl;
	cout << (double)(A / B) << "\t" << sizeof((double)(A / B)) << endl;

	cout << endl;
	system("pause");
}