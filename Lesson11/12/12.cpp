#include <iostream>

using namespace std;

void main() {
	setlocale(LC_CTYPE, "Rus");

	/*
	Вывести на экран соответствие между символами и их численными обозначениями в таблице ASCII

	*/

	//Код программы

	for (int i = 0; i < 256; i++) {
		if (!(i % 8) && i > 0) cout << endl;
		cout << i << " ";
		switch (i)
		{
		case 9: case 10: case 13:
			cout << ' ';
			break;
		default:
			cout << (char)i;
			break;
		}
		cout << "\t";
	}


	cout << endl;
	system("pause");
}