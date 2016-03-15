#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/*
* Дан массив А[n]. Каждый его элемент, кроме первого, заменить суммой
* всех предыдущих элементов (т.н. нарастающий итог).
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

int*    read_arr	(FILE*, size_t);
void    print_arr	(int *, size_t);
void    cumulate	(int *, size_t);
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

	wprintf(L"Исходный массив:\n");
	print_arr(arr, size);

	cumulate(arr, size);
	wprintf(L"Нарастающий итог:\n");
	print_arr(arr, size);

	fclose(f);
	free(arr);

	return 0;
}

/*
* Function:  cumulate
* --------------------
* Преобразует значение ячеек массива к нарастающему итогу
*
*  arr:        Массив
*  size:       Размер массива
*/
void cumulate(int *arr, size_t size) {
	size_t i;
	int sum = *arr;
	for (i = 1; i < size; ++i) {
		sum += *(arr + i);
		*(arr + i) = sum;
	}
}

/*
* Function:  read_arr
* --------------------
* Создает и заполняет массив значениями из файла
*
*  f:          Файл со значениям
*  size:       Количество элементов
*
*  returns:    Указатель на заполненный массив
*/
int *read_arr(FILE *f, size_t size) {
	size_t i;

	int *arr = (int *)malloc(sizeof(int) * size);

	for (i = 0; i < size; ++i) {
		*(arr + i) = read_int(f);
	}

	return arr;
}

/*
* Function:  print_arr
* --------------------
* Выводит элементы массива в одну строку на экран
*
*  arr:        Массив
*  size:       Размер массива
*/
void print_arr(int *arr, size_t size) {
	size_t i;

	for (i = 0; i < size; ++i) {
		printf("%d ", *(arr + i));
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