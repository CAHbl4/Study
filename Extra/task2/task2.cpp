#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

/*
* Задача: Для заданного 0<=n<=200 , рассматриваемого как возраст человека, вывести
* фразу вида «Мне 21 год», «Мне 32 года», «Мне 12 лет».
*
* a.matuzov, 13-03-2016
*/

#define MIN_AGE     0
#define MAX_AGE     200

const wchar_t *	num_to_str	(int, const wchar_t **);
int				read_int	(FILE *);

int main(void) {
	setlocale(LC_CTYPE, "Rus");

	//Массив с формами слова
	const wchar_t *str[3];
	str[0] = L"лет";
	str[1] = L"год";
	str[2] = L"года";

	int age;
	wprintf(L"Введите возраст (от %d до %d): ", MIN_AGE, MAX_AGE);
	do {
		age = read_int(stdin);
		if (age < MIN_AGE || age > MAX_AGE)
			wprintf(L"Неверный возраст. Возраст должен быть в диапазоне "
				"от %d до %d. Повторите ввод: \n", MIN_AGE, MAX_AGE);
	} while (age < MIN_AGE || age > MAX_AGE);

	wprintf(L"Мне %d %ls\n", age, num_to_str(age, str));
	return 0;
}

/*
* Function:  convert_age
* --------------------
* Возвращает правильное склонение переданного слова в зависимости от числа
*
*  age:        число
*  str:        массив строк для подстановки
*
*  returns:    указатель на нужный элемент массива строк
*/
const wchar_t *num_to_str(int n, const wchar_t **str) {

	if (n == 0) return *str;
	n = abs(n) % 100;
	if (n > 10 && n < 20) return *str;
	n %= 10;

	if (n > 1 && n < 5) return *(str + 2);
	if (n == 1) return *(str + 1);
	return *str;

}

/*
* Function:  read_int
* --------------------
* Читает целое число с заданного потока
*
*  stream:     поток ввода
*
*  returns:    целое число
*/
int read_int(FILE *stream) {
	int n, result, ch;
	do {
		result = fscanf(stream, "%d", &n);
		if (result == EOF) {
			fwprintf(stderr, L"Неожиданный конец файла\n");
			exit(74);
		}
		if (result == 0) {
			do {
				ch = fgetc(stream);
			} while (ch <= '0' && ch >= '9');
			fwprintf(stderr, L"Ожидалось целое\n");
		}
	} while (!result);

	return n;
}