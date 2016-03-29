#include <stdio.h>
#include <windows.h>

/*
 * Вариант 9:
 * Написать программу, которая дает пользователю ввести 5 фамилий студентов, а затем находит среди них самую длинную фамилию.
 *
 * amatu, 3/29/2016 7:16:43 PM
 */
#define MIN_STRINGS		5
#define HALT			""

char* Rus(const char* text);
char* read_string(FILE* fp);
char** read_strings(FILE*fp, char** str, size_t* count);
__int8 str_cmp(const char* str1, const char* str2);
char* str_find_max(char** str, size_t count);

void main() {
	char** str = NULL;
	size_t count = 0;
	printf(Rus("Введите не меннее %d фамилий.\n"), MIN_STRINGS);
	printf(Rus("Для прекращения ввода-<Enter> в начале строки.\n"));
	do
	{
		str = read_strings(stdin, str, &count);
		if (count < MIN_STRINGS)
			printf(Rus("Строк меньше %d. Вводите дополнительные строки.\n"), MIN_STRINGS);
	} while (count < MIN_STRINGS);

	printf(Rus("Самая длинная фамилия: %s"), str_find_max(str, count));
	system("pause");
}


/**
 * Returns pointer to longest string
 */
char* str_find_max(char** str, size_t count)
{
	char* max = *str;
	size_t i;
	for (i = 1; i < count; ++i)
	{
		if (strlen(max) < strlen(*(str + i )))
		{
			max = (char*)*(str + i);
		}
	}
	return max;
}


char bufRus[256];
char* Rus(const char* text)
{
	CharToOemA(text, bufRus);
	return bufRus;
}


/**
 * Returns the pointer to string readed from given stream
 */
char* read_string(FILE* fp)
{
	char* str, ch;
	size_t len = 0, alloc = 16;

	str = (char*)calloc(alloc, sizeof(char));

	while (EOF != (ch = fgetc(fp)) && ch != '\n')
	{
		str[len++] = ch;
		if (len == alloc)
		{
			str = (char*)realloc(str, sizeof(char) * (alloc += 16));
			if (!str)return str;
		}
	}
	str[len++] = '\0';

	return (char*)realloc(str, sizeof(char) * len);
}


/**
 * Returns the pointer to array of pointer to strings readed from given stream
 */
char** read_strings(FILE* fp, char** str, size_t* count)
{
	char* s;
	int alloc = *count + 10;
	str = (char**)realloc(str, sizeof(char*) * alloc);

	while (((s = read_string(fp))) && str_cmp(s, HALT))
	{
		if (*count == alloc)
			str = (char**)realloc(str, sizeof(char*) * (alloc += 10));
		*(str + *count) = s;
		++(*count);
	}
	return (char**)realloc(str, sizeof(char*) * *count);
}


/**
 * Compares the two strings and returns 0 if they are equal,
 * 1 if the first string bigger than the second and -1 otherwise
 */
__int8 str_cmp(const char * str1, const char * str2)
{
	while (*str1 && *str2)
	{
		if (*str1 > *str2)
			return 1;
		if (*str1 < *str2)
			return -1;
		++str1;
		++str2;
	}
	if (*str1) return 1;
	if (*str2) return -1;
	return 0;
}