#include <iostream>
using namespace std;

/*
Написать функцию, которая принимает целое шестизначное число и проверяет равна ли сумма
первых трех цифр сумме последних трех цифр(счастливый билет). Функция возвращает истину,
если число счастливое (суммы равны) и ложь, если не счастливое (суммы не равны).

*/

bool luckyTicket(int a);

void main() {
	setlocale(LC_CTYPE, "Rus");

	//Код программы

	int a;

	cout << "Введите 6-ти значное число: ";
	cin >> a;

	cout << "Билет " << (luckyTicket(a) ? "счастливый" : "не счастливый");

	cout << endl;
	system("pause");
}

bool luckyTicket(int a) {
	int sumRight = 0, sumLeft = 0;
	if (a > 99999 && a < 1000000) {
		for (int i = 0; i < 6; i++)
		{
			if (i < 3) {
				sumRight += a % 10;
			}
			else {
				sumLeft += a % 10;
			}
			a /= 10;
		}
		return sumRight == sumLeft;
	}
	else return false;
}