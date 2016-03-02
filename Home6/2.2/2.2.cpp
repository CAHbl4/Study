#include <iostream>

using namespace std;

bool check_date(int y, int m, int d);

void main() {
	setlocale(LC_CTYPE, "Rus");

	/*
	Пользователь вводит текущую дату и дату его рождения. Посчитать, сколько полных лет пользователю.

	*/

	//Код программы

	int d1, m1, y1; //Текущая дата
	int d2, m2, y2; //Дата рождения

	cout << "Введите текущую дату (день месяц год): ";
	cin >> d1 >> m1 >> y1;

	if (check_date(y1, m1, d1)) {
		cout << "Введите дату рождения (день месяц год): ";
		cin >> d2 >> m2 >> y2;
		if (check_date(y2, m2, d2)) {
			if (y2 <= y1) {
				if (m1 == m2 && d1 == d2) cout << "У вас сегодня День Рождения, поздравляю. ";
				if (y2 == y1 && (m2 < m1 || (m2 == m1 && d2 < d1))) cout << "Вам меньше года";
				else if (y2 == y1 && m2 == m1 && d2 == d1) cout << "Вы родились сегодня";
				else if (y2 == y1) cout << "Вы еще не родились";
				else if (y1 - y2 == 1 && (m2 < m1 || (m2 == m1 && d2 <= d1))) cout << "Вам 1 год";
				else if (y1 - y2 == 1) cout << "Вам меньше года";
				else if (m2 < m1 || (m2 == m1 && d2 <= d1)) {
					cout << "Вам " << y1 - y2 << " полных лет";
				}
				else cout << "Вам " << y1 - y2 - 1 << " полных лет";
			}
			else cout << "Вы еще не родились";

		}

		else cout << "Неверная дата";

	}
	else cout << "Неверная дата";

	cout << endl;
	system("pause");
}

bool check_date(int y, int m, int d) {			//Функция проверки даты на корректность
	if (y > 0 && m > 0 && d > 0) {				//Дата не может содержать нулевые значения
		switch (m)
		{
		case 1:	case 3:	case 5:	case 7: case 8: case  10: case 12:			//Январь, Март, Май, Июль, Август, Октябрь, Декабрь
			if (d <= 31) return 1;
			break;
		case 2:													//Февраль
			if (!(y % 400) || !(y % 4) && (y % 100)) {			//Определяем високосность
				if (d <= 29) return 1;
			}
			else {
				if (d <= 28) return 1;
			}

			break;
		case 4: case 6: case 9: case 11:		//Апрель, Июнь, Сентябрь, Ноябрь
			if (d <= 30) return 1;
			break;
		default:
			return 0;
			break;
		}
	}
	return 0;
}

