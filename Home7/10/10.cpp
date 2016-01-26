#include <iostream>

using namespace std;

bool check_date(int y, int m, int d);
int date_day(int y, int m, int d);
bool is_leap(int y);

void main() {
	setlocale(LC_CTYPE, "Rus");

	/*
	Напишите программу, подсчитывающую число прожитых Вами дней. Программа должна предложить Вам ввести дату вашего рождения, 
	текущую дату и выдать сообщение, что Вы живете такой-то день. Проверять корректность ввода.

	*/

	//Код программы
	int y1, m1, d1;
	int y2, m2, d2;

	cout << "Введите дату рождения (День Месяц Год): ";
	if (cin >> d1 >> m1 >> y1) {
		if (check_date(y1, m1, d1)) {
			cout << "Введите текущую дату (День Месяц Год): ";
			if (cin >> d2 >> m2 >> y2) {
				if (check_date(y2, m2, d2)) {
					cout << "Вы живете " << date_day(y2, m2, d2) - date_day(y1, m1, d1) + 1 << " день.";
				}
				else cout << "Неверная дата";
			}
			else cout << "Ошибка ввода";
		}
		else cout << "Неверная дата";
	}
	else cout << "Ошибка ввода";


	cout << endl;
	system("pause");
}

bool check_date(int y, int m, int d) {									//Функция проверки даты на корректность
	if (y > 0 && m > 0 && d > 0) {										//Дата не может содержать нулевые значения
		switch (m)
		{
		case 1:	case 3:	case 5:	case 7: case 8: case  10: case 12:		//Январь, Март, Май, Июль, Август, Октябрь, Декабрь
			if (d <= 31) return 1;
			break;
		case 2:															//Февраль
			if (is_leap(y)) {											//Определяем високосность
				if (d <= 29) return 1;
			}
			else {
				if (d <= 28) return 1;
			}

			break;
		case 4: case 6: case 9: case 11:								//Апрель, Июнь, Сентябрь, Ноябрь
			if (d <= 30) return 1;
			break;
		default:
			return 0;
			break;
		}
	}
	return 0;
}

bool is_leap(int y) {													//Функция определения високосности
	if (!(y % 400) || !(y % 4) && (y % 100)) return 1;
	return 0;
}

int date_day(int y, int m, int d) {										//Функция подсчета количества дней от начала эпохи до даты
	int days;															//Возвращаемое количество дней
	int count_leap = 0;													//Количество високосных лет
	int count_regular = 0;												//Количество обычных лет

	for (int i = 0; i < y; i++) is_leap(i) ? count_leap++ : count_regular++;		//Считаем количество обычных и високосных

	days = count_regular * 365 + count_leap * 366;						//Считаем дни в целых годах

	for (int i = 1; i < m; i++) {										//Прибавляем дни целых месяцев
		switch (i)
		{
		case 1:	case 3:	case 5:	case 7: case 8: case  10: case 12:		//Январь, Март, Май, Июль, Август, Октябрь, Декабрь
			days += 31;
			break;
		case 2:															//Февраль
			if (is_leap(y)) {											//Определяем високосность
				days += 29;
			}
			else {
				days += 28;
			}
			break;
		case 4: case 6: case 9: case 11:								//Апрель, Июнь, Сентябрь, Ноябрь
			days += 30;
			break;
		default:
			break;
		}
	}

	days += d;															//Прибавляем дни текущего месяца
	return days;
}