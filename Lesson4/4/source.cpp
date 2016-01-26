#include <iostream>

using namespace std;

void main() {
	setlocale(LC_CTYPE, "Rus");

	//Код программы

	int a = 50, b = 25;
	float c = 50.0, d = 25.0;
	
	cout << "a, b - int" << endl;
	cout << "sizeof (a + b) = " << sizeof(a + b) << endl;
	cout << "sizeof (a - b) = " << sizeof(a - b) << endl;
	cout << "sizeof (a * b) = " << sizeof(a * b) << endl;
	cout << "sizeof (a / b) = " << sizeof(a / b) << endl << endl;;

	cout << "c, d - float" << endl;
	cout << "sizeof (c + d) = " << sizeof(c + d) << endl;
	cout << "sizeof (c - d) = " << sizeof(c - d) << endl;
	cout << "sizeof (c * d) = " << sizeof(c * d) << endl;
	cout << "sizeof (c / d) = " << sizeof(c / d) << endl << endl;

	cout << "c - float, b - int" << endl;
	cout << "sizeof (c + b) = " << sizeof(c + b) << endl;
	cout << "sizeof (c - b) = " << sizeof(c - b) << endl;
	cout << "sizeof (c * b) = " << sizeof(c * b) << endl;
	cout << "sizeof (c / b) = " << sizeof(c / b) << endl << endl;

	system("pause");
}