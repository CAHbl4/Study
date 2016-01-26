#include <iostream>

using namespace std;

void main() {
	setlocale(LC_CTYPE, "Rus");

	/*
	Часы бьют каждый час, столько раз, сколько времени. Написать программу, которая подсчитает, сколько раз пробьют часы с полуночи до полудня.

	*/

	//Код программы
	int count = 0;

	for (int i = 1; i <= 12; i++) {
		count += i;

	}
	cout << "Часы пробили " << count << " раз";

	cout << endl;
	system("pause");
}