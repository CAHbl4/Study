#include <iostream>

using namespace std;

void main() {
	setlocale(LC_CTYPE, "Rus");

	/*
	Старинная задача. Сколько можно купить быков, коров и телят, если плата за быка 10 рублей,
	за корову – 5 рублей, за теленка - 0,5 рубля. Есть на 100 рублей, надо купить 100 голов скота.

	*/

	//Код программы
	int bull = 1, cow = 1, calf = 1;

	for (; bull < 10; bull++) {
		for (; cow < 20; cow++) {
			calf = 100 - (bull + cow);
			if (bull * 20 + cow * 10 + calf == 200) {
				cout << "Быков: " << bull << endl;
				cout << "Коров: " << cow << endl;
				cout << "Телят: " << calf << endl;
			}
		}

	}


	cout << endl;
	system("pause");
}