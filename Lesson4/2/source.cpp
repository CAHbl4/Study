#include <iostream>

using namespace std;

void main() {
	setlocale(LC_CTYPE, "Rus");

	//Код программы

	char symbol = 'a';
	// объявление переменной типа char и инициализация её символом 'a'
	cout << "symbol = " << symbol << endl;
	// печать символа, содержащегося в переменной symbol

	cout << sizeof(char) << '\n' << sizeof(symbol);

	system("pause");
}