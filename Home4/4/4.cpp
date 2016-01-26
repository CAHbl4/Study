#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

void main() {
	setlocale(LC_CTYPE, "Rus");

	/*
	Пользователь указывает цену одой минуты исходящего звонка с одного мобильного оператора другому,
	а также продолжительность разговора в минутах и секундах.
	Необходимо вычислить сумму на которую был произведен звонок.
	*/

	//Код программы

	float price, lenght, sum;
	int m, s;

	cout << "Введите цену за минуту = ";
	cin >> price;
	cout << "Введите время (мин.сек) = ";
	cin >> lenght;

	m = (int)lenght;
	s = round((lenght - m) * 100);
	sum = (m + s / 60.0) * price;

	cout << fixed << setprecision(2);
	cout << "Вы разговаривали " << m << " мин. " << s << " сек. Стоимость звонка составила " << sum << " руб.";

	cout << endl;
	system("pause");
}