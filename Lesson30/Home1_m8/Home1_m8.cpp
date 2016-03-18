#include <stdio.h>
#include <windows.h>

/*
* Задан текст, состоящий из строк. Строк не менее 10. В строке не менее 5
* слов. В слове не менее 5 символов. Слова разделены 1 пробелом.
* Осуществить сортировку строк по количеству в них заданного символа в
* неубывающем порядке.
* Программа должна выполнять ввод текста, вывод его исходного варианта,
* выполнять необходимые действия и выводить полученный текст.
*
* a.matuzov, 3/15/2016 7:02:43 PM
*/
#define MIN_STRINGS		10
#define MAX_STRINGS		100
#define MIN_WORDS		5
#define MIN_CHARS		5
#define MAX_LENGTH		100
#define HALT			""

typedef int(*sort_f)(char*, char*);

char* Rus(const char* text);
char** read_str(char **, int* ct);
void sort(char ** str, int n, sort_f f);

int char_count(char* str);
int char_count_comp_ASC(char* l, char* r);

char sort_symbol = 'a';

void main() {

	//Code goes here
	char ** str = (char**)malloc(sizeof(char*));
	int count = 0;
	str = read_str(str, &count);

	sort_f f = &char_count_comp_ASC;

	int i;
	for (i = 0; i < count; i++)
	{
		puts(*(str + i));
	}
	puts("\n");
	sort(str, count, f);
	for (i = 0; i < count; i++)
	{
		puts(*(str + i));
	}

}

char** read_str(char **str, int* ct)
{

	printf(Rus("Введите до %d строк.\n"), MAX_STRINGS);
	printf(Rus("Для прекращения ввода-<Enter> в начале строки.\n"));
	*str = (char*)calloc(MAX_LENGTH, sizeof(char));
	while (gets_s(*(str + *ct), MAX_LENGTH) != NULL && strcmp(*(str + *ct), HALT) != 0 && (*ct)++ < MAX_STRINGS){
		str = (char**)realloc(str, sizeof(char*)* (*ct + 1));
		*(str + *ct) = (char*)calloc(MAX_LENGTH, sizeof(char));
	}
	return str;
}

char bufRus[256];
char* Rus(const char* text)
{
	CharToOemA(text, bufRus);
	return bufRus;
}

void sort(char ** str, int n, sort_f f)
{
	int l = 0, r = n - 1;
	char* m = *(str + n / 2);
	char* tmp;

	do
	{
		while ((*f)(*(str + l), m) < 0) l++;
		while ((*f)(m, *(str + r)) < 0) r--;

		if ((*f)(*(str + l), *(str + r)) < 0)
		{
			tmp = *(str + l);
			*(str + l) = *(str + r);
			*(str + r) = tmp;
			l++;
			r--;
		}
	} while (l <= r);


	if (r > 0) sort(str, r + 1, f);
	if (n > l) sort(str + l, n - l, f);
}

int char_count(char * str)
{
	int count = 0;
	while (*str++){
		if (*str == sort_symbol)
		++count;
	}
	return count;
}

int char_count_comp_ASC(char * l, char * r)
{
	return char_count(l) - char_count(r);
}
