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
#define MIN_WORDS		5
#define MIN_CHARS		5
#define MAX_LENGTH		100
#define HALT			""

typedef int(*sort_f)(char*, char*);

char* Rus(const char* text);
char** read_strings(char **, int* ct);
char *read_string(FILE* fp, size_t size);
void sort(char ** str, int n, sort_f f);

int char_count(char* str);
int char_count_comp_ASC(char* l, char* r);

char sort_symbol = 'a';

void main() {

	//Code goes here
	char ** str = NULL;
	int count = 0;

	printf(Rus("Вводите строки и они будут отсортированы. Необходимо ввести не меннее %d строк.\n"), MIN_STRINGS);
	printf(Rus("Для прекращения ввода-<Enter> в начале строки.\n"));
	str = read_strings(str, &count);

	sort_f f = &char_count_comp_ASC;

	int i;
	//for (i = 0; i < count; i++)
	//{
	//	printf("%s - %d\n", *(str + i), char_count_comp_ASC(*str, *(str+i)));
	//}
	//puts("\n");

	sort(str, count, f);
	for (i = 0; i < count; i++)
	{
		puts(*(str + i));
	}

}

char** read_strings(char **str, int* count)
{
	char* s;
	int alloc = *count + 10;
	str = (char**)realloc(str, sizeof(char*) * alloc);

	while ((s = read_string(stdin, 10)) && strcmp(s, HALT)){
		if (*count == alloc)
			str = (char**)realloc(str, sizeof(char*)*(alloc+=10));
		*(str + *count) = s;
		++(*count);
	}
	return (char**)realloc(str,sizeof(char*) * *count);
}

char* read_string(FILE* fp, size_t size) {
	char *str;
	int ch;
	size_t len = 0;
	str = (char*)calloc(size, sizeof(char));
	while (EOF != (ch = fgetc(fp)) && ch != '\n') {
		str[len++] = ch;
		if (len == size) {
			str = (char*)realloc(str, sizeof(char)*(size += 16));
			if (!str)return str;
		}
	}
	str[len++] = '\0';

	return (char*)realloc(str, sizeof(char)*len);
}

char bufRus[256];
char* Rus(const char* text)
{
	CharToOemA(text, bufRus);
	return bufRus;
}

void sort(char ** str, int n, sort_f f)
{
	static int iter = 1;
	printf("\nIteration = %d, array:\n", iter++);
	int i;
	for (i = 0; i < n; i++)
	{
		puts(*(str + i));
	}


	int l = 0, r = n - 1;
	char* m = *(str + n / 2);
	char* tmp;

	do
	{
		while ((*f)(*(str + l), m) < 0) l++;
		while ((*f)(*(str + r), m) > 0) r--;

		if (l <= r)
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
	while (*str){
		if (*str == sort_symbol)
		++count;
		++str;
	}
	return count;
}

int char_count_comp_ASC(char * l, char * r)
{
	return char_count(l) - char_count(r);
}