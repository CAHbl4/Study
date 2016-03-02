#include <iostream>

using namespace std;

bool check_date(int y, int m, int d);
int date_day(int y, int m, int d);
bool is_leap(int y);

void main() {
	setlocale(LC_CTYPE, "Rus");

	/*
	Пользователь вводит две даты (день, месяц, год в виде целых чисел).
	Необходимо определить и вывести количество дней между этими двумя датами.
	Для расчетов учитывать высокосные года, а также корректное число дней в месяцах (март – 31, сентябрь – 30, февраль невисокосного года – 28 и т.д.).

	*/

	//Код программы

	int y1, m1, d1;			//Первая дата
	int y2, m2, d2;			//Вторая дата

	cout << "Введите первую дату (день месяц год): ";
	cin >> d1 >> m1 >> y1;

	if (check_date(y1, m1, d1)) {		//Проверяем на корректность первую дату
		cout << "Введите вторую дату (день месяц год): ";
		cin >> d2 >> m2 >> y2;
		if (check_date(y2, m2, d2)) {		//Проверяем на корректность вторую дату
			int days1 = date_day(y1, m1, d1);			//Количество дней от начала эпохи
			int days2 = date_day(y2, m2, d2);

			cout << "Между " << d1 << "." << m1 << "." << y1
				<< " и " << d2 << "." << m2 << "." << y2
				<< " прошло " << (days1 > days2 ? days1 - days2 : days2 - days1) << " д.";			//Вывод на экран
		}
		else cout << "Неверная дата";
	}
	else cout << "Неверная дата";


	cout << endl;
	system("pause");
}

bool is_leap(int y) {													//Функция определения високосности
	if (!(y % 400) || !(y % 4) && (y % 100)) return 1;
	return 0;
}

bool check_date(int y, int m, int d) {			//Функция проверки даты на корректность
	if (y > 0 && m > 0 && d > 0) {				//Дата не может содержать нулевые значения
		switch (m)
		{
		case 1:	case 3:	case 5:	case 7: case 8: case  10: case 12:			//Январь, Март, Май, Июль, Август, Октябрь, Декабрь
			if (d <= 31) return 1;
			break;
		case 2:													//Февраль
			if (is_leap(y)) {			//Определяем високосность
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

int date_day(int y, int m, int d) {				//Функция подсчета количества дней от начала эпохи до даты
	int days;							//Возвращаемое количество дней
	int count_leap = 0;						//Количество високосных лет
	int count_regular = 0;					//Количество обычных лет

	for (int i = 0; i < y; i++) is_leap(i) ? count_leap++ : count_regular++;		//Считаем количество обычных и високосных

	days = count_regular * 365 + count_leap * 366;		//Считаем дни в целых годах

	for (int i = 1; i < m; i++) {			//Прибавляем дни целых месяцев
		switch (i)
		{
		case 1:	case 3:	case 5:	case 7: case 8: case  10: case 12:		//Январь, Март, Май, Июль, Август, Октябрь, Декабрь
			days += 31;
			break;
		case 2:						//Февраль
			if (is_leap(y)) {			//Определяем високосность
				days += 29;
			}
			else {
				days += 28;
			}
			break;
		case 4: case 6: case 9: case 11:		//Апрель, Июнь, Сентябрь, Ноябрь
			days += 30;
			break;
		default:
			break;
		}
	}

	days += d;				//Прибавляем дни текущего месяца
	return days;
}