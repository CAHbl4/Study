#include <stdio.h>
#include <windows.h>

/*
 * Задана строка. В строке не менее 5слов. В слове не менее 3 символов.
 * Слова разделены 1 пробелом. Напишите функцию, которая проверяет, есть ли в
 * полученной ею в качестве параметра строке точка и пробел перед каждой
 * заглавной буквой, кроме первой (алфавит латинский). Если нет, то функция
 * вставляет их.
 * amatu, 3/16/2016 9:11:36 AM
*/
#define MAX_LENGTH	100
#define MAX_STRINGS 20
#define HALT ""

char*	Rus			(const char* text);
int		read_str	(char str[MAX_STRINGS][MAX_LENGTH]);
void	points		(char* str);

void main() {

	//Code goes here

	static char str[MAX_STRINGS][MAX_LENGTH];
	int count = read_str(str);
	int i;
	for (i = 0; i < count; i++)
	{
		puts(Rus("Оригинальная строка:"));
		puts(str[i]);

		points(str[i]);

		puts(Rus("Отформатировання строка:"));
		puts(str[i]);
	}
	
	
}


char bufRus[256];

char* Rus(const char* text)
{
	CharToOemA(text, bufRus);
	return bufRus;
}

int read_str(char str[MAX_STRINGS][MAX_LENGTH])
{

	int ct = 0;
	printf(Rus("Введите до %d строк.\n"), MAX_STRINGS);
	printf(Rus("Для прекращения ввода-<Enter> в начале строки.\n"));
	while (gets_s(str[ct]) != NULL && strcmp(str[ct], HALT) != 0 && ct++ < MAX_STRINGS)
		;
	return ct;
}

void points(char * str)
{
	int i = 1, j = 1;
	char result[MAX_LENGTH];
	*result = *str;
	while (*(str + i) != '\0')
	{
		if (*(str + i) >= 'A' && *(str + i) <= 'Z') {
			if (*(str + i - 1) == '.')
			{
				*(result + j++) = ' ';
			}
			else if (*(str + i -1) != ' ')
			{
				if (*(str + i -2) != '.')
				{
					*(result + j++) = '.';
				}
				*(result + j++) = ' ';
			}
			else if (*(str + i - 1) == ' ')
			{
				if (*(str + i - 2) != '.')
				{
					*(result + j - 1) = '.';
					*(result + j++) = ' ';
				}
			}
		}
		*(result + j++) = *(str + i);
		i++;
	}
	*(result + j++) = '\0';
	strcpy(str, result);
}
