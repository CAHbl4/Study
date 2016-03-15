#include <stdio.h>
#include <string.h>
#include <windows.h>

#define SIZE 81  /* предельная длина строки, включая \0*/
#define LIM 20   /* максимальное количество считанных строк */
#define HALT ""  /* нулевая строка для прекращения ввода */
void main(void);
void str_sort(char *[], int);
char* Rus(const char* text);

void main(void)
{
	static char input[LIM][SIZE]; /* массив для запоминания ввод. строк */
	char *ptstr[LIM];             /* массив указателей */
	int ct = 0;                     /* счетчик вводимых строк */
	int k;                        /* счетчик выводимых строк*/

	printf(Rus("Введите до %d  строк и они будут отсортированы.\n"), LIM);
	printf(Rus("Для прекращения ввода-<Enter> в начале строки.\n"));
	while (gets_s(input[ct]) != NULL && strcmp(input[ct], HALT) != 0 && ct++<LIM)
		ptstr[ct - 1] = input[ct - 1]; /* указывает на начало строк в памяти */
	str_sort(ptstr, ct);             /* вызов функции сортировки строк */
	puts(Rus("\nОтсортированный список строк:\n"));
	for (k = 0; k<ct; k++)
		puts(ptstr[k]);           /* в качестве аргумента в функцию puts() передаются */
								  /*   указатели на отсортированные строки */
}
void str_sort(char *string[], int num)
{
	char *temp;
	int top, seek;

	for (top = 0; top<num - 1; top++)
		for (seek = top + 1; seek<num; seek++)
			if (strcmp(string[top], string[seek])>0)
			{
				temp = string[top];
				string[top] = string[seek];
				string[seek] = temp;
			}
}

char bufRus[256];
char* Rus(const char* text)
{
	CharToOemA(text, bufRus);
	return bufRus;
}
