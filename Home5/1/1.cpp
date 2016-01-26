#include <iostream>
#include <iomanip>

using namespace std;

const int HOUR_S = 3600;			//Секунд в часе
const int MIN_S = 60;				//Секунд в минуте
const int DAY_S = 86400;			//24 часа
const int ALARM_S = 25200;			//7 утра
const int REST_S = 72000;			//8 вечера
const int TIME_TO_REST_S = 2700;	//Время пути до ресторана 45 мин

int HOUR(int s);
int MIN(int s);
int SEC(int s);

void main() {
	setlocale(LC_CTYPE, "Rus");

	/*
	Пользователь вводит с клавиатуры время в секундах, прошедшее с начала дня.
	Вывести на экран текущее время в часах, минутах и секундах. Посчитать, сколько часов, минут и секунд осталось до полуночи.
	*/

	//Код программы

	int s;
	int cur_h, cur_m, cur_s;
	int tmp_h, tmp_m;
	int remain_h, remain_m, remain_s;

	cout << "Введите время в секундах с начала дня: ";
	cin >> s;

	if (s > DAY_S) cout << "Похоже вы не выспались, прошло уже более суток";
	else if (s < 1) cout << "Похоже день еще не начался";
	else {
		cur_h = HOUR(s);
		cur_m = MIN(s);
		cur_s = SEC(s);

		remain_h = HOUR(DAY_S - s);
		remain_m = MIN(DAY_S - s);
		remain_s = SEC(DAY_S - s);

		cout << setw(2) << setfill('0');
		if (cur_h < 7) {
			cout << "Доброй ночи, время на часах " << cur_h << ":" << setw(2) << setfill('0') << cur_m << ":" << setw(2) << setfill('0') << cur_s << "." << endl;
			cout << "Будильник прозвенит через ";

			tmp_h = HOUR(ALARM_S - s);
			tmp_m = MIN(ALARM_S - s);

			if (tmp_h) cout << tmp_h << " ч. ";
			if (tmp_m) cout << tmp_m << " м. ";

			cout << endl;
			cout << "До конца дня осталось " << remain_h << " ч., " << remain_m << " м., " << remain_s << " с.";
		}

		else if (cur_h < 12) {
			cout << "Доброе утро, время на часах " << cur_h << ":" << setw(2) << setfill('0') << cur_m << ":" << setw(2) << setfill('0') << cur_s << "." << endl;
			cout << "В Малибу 22 градуса, легкая облачность. Высота волны от пояса до плеча, условия для серфинга сносные." << endl;
			cout << "До конца дня осталось " << remain_h << " ч., " << remain_m << " м., " << remain_s << " с.";
		}

		else if (cur_h < 17) {
			cout << "Добрый день, время на часах " << cur_h << ":" << setw(2) << setfill('0') << cur_m << ":" << setw(2) << setfill('0') << cur_s << "." << endl;

			tmp_h = HOUR(REST_S);
			tmp_m = MIN(REST_S);

			cout << "После обеда возможен небольшой дождь. На ";
		
			cout << tmp_h << " ч. ";
			if (tmp_m) cout << tmp_m << " м. ";

			cout << "вечерa у вас заказан столик в ресторане, такси прибудет в ";

			tmp_h = HOUR(REST_S - TIME_TO_REST_S);
			tmp_m = MIN(REST_S - TIME_TO_REST_S);

			cout << tmp_h << " ч. ";
			if (tmp_m) cout << tmp_m << " м. ";

			cout << endl;
			cout << "До конца дня осталось " << remain_h << " ч., " << remain_m << " м., " << remain_s << " с.";
		}

		else {
			cout << "Добрый вечер, время на часах " << cur_h << ":" << setw(2) << setfill('0') << cur_m << ":" << setw(2) << setfill('0') << cur_s << "." << endl;
			if (s < REST_S) {

				cout << "У вас заказан столик в ресторане \"Maude\" на 8 часов. ";

				if (s < REST_S - TIME_TO_REST_S) {

					tmp_h = HOUR(REST_S - TIME_TO_REST_S - s);
					tmp_m = MIN(REST_S - TIME_TO_REST_S - s);

					cout << "Такси подъедет через ";

					if (tmp_h) cout << tmp_h << " ч. ";
					if (tmp_m) cout << tmp_m << " м. ";

					cout << endl;
				}
				else cout << "Но боюсь вы не успеете доехать" << endl;
			}
			else {
				cout << "Сегодня неплохая погода для прогулки по набережной. Приятного отдыха." << endl;
			}
			cout << "До конца дня осталось " << remain_h << " ч., " << remain_m << " м., " << remain_s << " с.";
		}
	}

	cout << endl;
	system("pause");
}

int HOUR(int s) {
	return s / HOUR_S;
}

int MIN(int s) {
	return s / MIN_S - HOUR(s) * MIN_S;
}

int SEC(int s) {
	return s % MIN_S;
}
