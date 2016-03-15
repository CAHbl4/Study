#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/*
* Задача: Разработать функцию поиска самой длинной цепочки из подряд идущих
* одинаковых элементов в массиве.
*
* Решение: Программа читает все необходимые параметры из файла переданного через командную строку
* или из файла указанного в DEFAULT_FILE.
*
* Формат входного файла:
* Первое целое - количество элементов, остальные целые - эллементы массива.
*
* a.matuzov, 13-03-2016
*/
#define DEFAULT_FILE    "test.txt"

int*    find_longest(int *, size_t);
int*    read_arr	(FILE*, size_t);
void    print_arr	(int *, size_t);
int     read_int	(FILE*);

int main(int argc, char *argv[]) {
	setlocale(LC_ALL, "Rus");
	FILE *f;
	char *file_name;
	if (argc > 1) {
		file_name = argv[1];
	}
	else {
		file_name = DEFAULT_FILE;
	}

	f = fopen(file_name, "r");
	if (!f) {
		fprintf(stderr, "\"%s\" ", file_name);
		fwprintf(stderr, L"Файл не найден");
		return 1;
	}

	size_t size;

	//Читаем первое целое из файла которое будет размером массива
	size = (size_t)read_int(f);

	int *arr = read_arr(f, size);

	print_arr(arr, size);

	int *longest = find_longest(arr, size);

	wprintf(L"Самая длинная цепочка начинается на arr[%d] = %d\n", (int)(longest - arr), *longest);

	fclose(f);
	free(arr);

	return 0;
}

/*
* Function:  read_arr
* --------------------
* Создает и заполняет массив значениями из файла
*
*  f:       Файл со значениям
*  size:	Количество элементов
*
*  returns: Указатель на заполненный массив
*/
int *read_arr(FILE *f, size_t size) {
	size_t i;

	int *arr = (int *)malloc(sizeof(int) * size);

	for (i = 0; i < size; ++i) {
		*(arr+i) = read_int(f);
	}

	return arr;
}

/*
* Function:  print_arr
* --------------------
* Выводит элементы массива в одну строку на экран
*
*  arr:		Массив
*  size:	Размер массива
*/
void print_arr(int *arr, size_t size) {
	size_t i;

	for (i = 0; i < size; ++i) {
		printf("%d ", *(arr + i));
	}
	printf("\n");
}

/*
* Function:  find_longest
* --------------------
* Ищет левую самую длинную цепочку из одинаковых элементов в массиве и возвращает указатель на нее
*
*  arr:		Массив
*  size:	Размер массива
*
*  returns: Указатель на начало цепочки
*/
int *find_longest(int *arr, size_t size) {
	int *cur = arr, *longest = arr;
	size_t i, count_cur = 0, count_longest = 0;

	for (i = 0; i < size; ++i) {
		if (*cur == *(arr + i)) {
			++count_cur;
		}
		else {
			count_cur = 1;
			cur = arr + i;
		}

		if (count_cur > count_longest) {
			if (longest != cur)
				longest = cur;
			count_longest = count_cur;
		}
	}

	return longest;
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