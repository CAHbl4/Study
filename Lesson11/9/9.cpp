#include <iostream>


using namespace std;

FILE *stream;

void main() {
	setlocale(LC_CTYPE, "Rus");

	/*
	Возьмем любое натуральное число. Если оно четное - разделим его пополам, если нечетное - умножим на 3, прибавим 1 и разделим пополам.
	Повторим эти действия с вновь полученным числом. Гипотеза гласит, что независимо от выбора первого числа рано или поздно мы получим 1.
	Проверить гипотезу для всех чисел от 20 до 30. Вывести числа, для которых гипотеза верна.

	*/

	//Код программы
	errno_t err;
	int n = 0, m = 100;

	err = fopen_s(&stream, "out.csv", "w+");
	if (err)
	{
		cout << "Ошибка при открытии файла." << endl;
		system("pause");
		return;
	}


	for (; n <= m; n++) {
		int k = n;
		int count = 0;
		do {
			if (k % 2) k = (k * 3 + 1) / 2;
			else k /= 2;
			count++;
		} while (k > 1);
		if (k == 1) {
			cout << n << ": " << count << endl;
			fprintf_s(stream, "%d,%d\n", n, count);
		}
	}

	fclose(stream);
	system("pause");
}