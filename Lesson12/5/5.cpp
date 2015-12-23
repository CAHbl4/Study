#include <iostream>

using namespace std;

void main() {
	setlocale(LC_CTYPE, "Rus");

	/*
	Старинная задача. Сколько можно купить быков, коров и телят, если плата за быка 10 рублей,
	за корову – 5 рублей, за теленка - 0,5 рубля. Есть на 100 рублей, надо купить 100 голов скота.

	*/

	//Код программы
	int bull = 0, cow = 0, calf = 0;

	for (int count = 0; count < 100; count++) {
		if ((100 - bull * 10) / 0.5 > (100 - count)) bull++;
		else if ((100 - cow * 5) / 0.5 > (100 - count)) cow++;
		else calf++;
	}

	cout << "Быков: " << bull << endl;
	cout << "Коров: " << cow << endl;
	cout << "Телят: " << calf << endl;

	cout << endl;
	system("pause");
}