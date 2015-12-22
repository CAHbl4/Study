#include <iostream>

using namespace std;

void main() {
	setlocale(LC_CTYPE, "Rus");

	/*
	8. Написать программу, которая после введенного с клавиатуры числа (в диапазоне от 1 до 999), обозначающего денежную единицу,
	дописывает слово "рубль" в правильной форме. Например, 12 рублей, 21 рубль.

	11. Написать программу, которая после введенного с клавиатуры числа (в диапазоне от 1 до 999), обозначающего денежную единицу,
	дописывает слово "рубль" в правильной форме. Например, 12 рублей, 21 рубль.

	12. Написать программу, которая принимает целое 3-хзначное число с клавиатуры и выводит словесное представление этого числа.
	Например: пользователь ввел 431, программа выводит четыреста тридцать один.
	*/

	//Код программы

	int a;
	cout << "Введите число в диапазоне от 1 до 999: ";
	if (cin >> a && a > 0 && a < 1000) {

		switch (a / 100)
		{
		case 9: cout << "Девятьсот "; break;						//В дальнейшем это все можно переписать в функцию для чисел до триллионов
		case 8: cout << "Восемьсот "; break;
		case 7: cout << "Семьсот "; break;
		case 6: cout << "Шестьсот "; break;
		case 5: cout << "Пятьсот "; break;
		case 4: cout << "Четыреста "; break;
		case 3: cout << "Триста "; break;
		case 2: cout << "Двести "; break;
		case 1: cout << "Сто "; break;
		default:
			break;
		}
		switch (a % 100 / 10) {
		case 9: cout << "Девяносто "; break;
		case 8: cout << "Восемьдесят "; break;
		case 7: cout << "Семьдесят "; break;
		case 6: cout << "Шестьдесят "; break;
		case 5: cout << "Пятьдесят "; break;
		case 4: cout << "Сорок "; break;
		case 3: cout << "Тридцать "; break;
		case 2: cout << "Двадцать "; break;
		}
		if (a > 100 ? a % 100 / 10 == 1 : a / 10 == 1) {
			switch (a % 10) {
			case 9: cout << "Девятнадцать рублей"; break;
			case 8: cout << "Восемнадцать рублей"; break;
			case 7: cout << "Семнадцать рублей"; break;
			case 6: cout << "Шестнадцать рублей"; break;
			case 5: cout << "Пятнадцать рублей"; break;
			case 4: cout << "Четырнадцать рублей"; break;
			case 3: cout << "Тринадцать рублей"; break;
			case 2: cout << "Двенадцать рублей"; break;
			case 1: cout << "Одинадцать рублей"; break;
			case 0: cout << "Десять рублей"; break;
			}
		}
		else {
			switch (a % 10) {
			case 9: cout << "Девять рублей"; break;
			case 8: cout << "Восемь рублей"; break;
			case 7: cout << "Семь рублей"; break;
			case 6: cout << "Шесть рублей"; break;
			case 5: cout << "Пять рублей"; break;
			case 4: cout << "Четыре рубля"; break;
			case 3: cout << "Три рубля"; break;
			case 2: cout << "Два рубля"; break;
			case 1: cout << "Один рубль"; break;
			case 0: cout << "рублей"; break;
			}
		}
	}
	else cout << "Ошибка ввода";

	cout << endl;
	system("pause");
}