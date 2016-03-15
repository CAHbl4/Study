#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdint.h>

/*
* Составить программу, определяющую, из каких цифр состоит заданное натуральное
* число и печатающую эти цифры в возрастающем порядке.
*
* a.matuzov, 13-03-2016
*/

int     read_int	(FILE*);
void    print_nums	(int);

int main(void) {
	setlocale(LC_ALL, "Rus");

	int n;

	wprintf(L"Введите натуральное число (Максимальный размер %d): ", INT32_MAX);
	n = read_int(stdin);
	wprintf(L"Число состоит из следующиц цифр: ");
	print_nums(n);

	return 0;
}

/*
* Function:  print_nums
* --------------------
* Выводит на экран цифры из которых состоит число
*
*  n:      число
*/
void print_nums(int n) {
	int num[10] = { 0 };
	size_t i;

	while (n) {
		num[n % 10]++;
		n /= 10;
	}

	for (i = 0; i < 10; ++i) {
		if (num[i] > 0)
			printf("%d ", i);
	}

	printf("\n");
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