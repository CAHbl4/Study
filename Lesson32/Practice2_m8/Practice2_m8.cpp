﻿#include <stdio.h>
#include <windows.h>

/*
* Задан текст, состоящий из строк. Строк не менее 10. В строке не менее 5
* слов. В слове не менее 5 символов. Слова разделены одним пробелом.
* Осуществить «переворачивание» в строке всех слов (например: «Жили были
* дед и баба» - «илиЖ илыб дед и абаб»).
* Программа должна выполнять ввод текста, вывод его исходного варианта,
* выполнять необходимые действия и выводить требуемый результат.
*
* a.matuzov, 22/08/2016
*/
#define MIN_STRINGS		10
#define MIN_WORDS		5
#define MIN_CHARS		5
#define HALT			""
#define DEBUG			0
#define SEPARATOR		" "

char** read_strings(char**, int*);
char* read_string(FILE*, size_t);
char** words_str(char*, int*, char*, int);
int check_string(char*);
void do_work(char**, int);
void reverse_word(char*);
int char_count(char*, char*);
int word_count(char*, char*);
int word_length(char*, char*);

char* Rus(const char*);

void main()
{
	char** str = NULL;
	int count = 0;
	printf(Rus("Вводите строки и они будут отсортированы. Необходимо ввести не меннее %d строк.\n"), MIN_STRINGS);
	printf(Rus("Для прекращения ввода-<Enter> в начале строки.\n"));
	do
	{
		str = read_strings(str, &count);
		if (count < MIN_STRINGS)
			printf(Rus("Строк меньше %d. Вводите дополнительные строки.\n"), MIN_STRINGS);
	} while (count < MIN_STRINGS);

	int i;

	printf(Rus("Исходный массив:\n"));
	for (i = 0; i < count; ++i)
	{
		puts(*(str + i));
	}
	puts("");

	do_work(str, count);

	printf(Rus("Отсортированный массив:\n"));
	for (i = 0; i < count; ++i)
	{
		puts(*(str + i));
	}
	puts("");

	for (i = 0; i < count; ++i)
	{
		free(*(str + i));
	}
	free(str);
}



/*
* Function:  read_strings
* --------------------
* Читает строки в массив пока не получит пустую строку
*
*  str:		Массив строк
*  count:	Количество строк в массиве
*
*  returns:	Указатель на массив строк
*/
char** read_strings(char** str, int* count)
{
	char* s;
	int alloc = *count + 10;
	str = (char**)realloc(str, sizeof(char*) * alloc);

	while (((s = read_string(stdin, 10))) && strcmp(s, HALT))
	{
		if (check_string(s))
		{
			if (*count == alloc)
				str = (char**)realloc(str, sizeof(char*) * (alloc += 10));
			*(str + *count) = s;
			++(*count);
		}
	}
	return (char**)realloc(str, sizeof(char*) * *count);
}


/*
* Function:  read_string
* --------------------
* Читает строку с указанного потока
*
*  fp:		Поток ввода
*  count:	Начальный размер строки
*
*  returns:	Указатель на прочитанную строку
*/
char* read_string(FILE* fp, size_t size)
{
	char* str;
	char ch;
	size_t len = 0;
	str = (char*)calloc(size + 1, sizeof(char));
	while (EOF != (ch = fgetc(fp)) && ch != '\n')
	{
		str[len++] = ch;
		if (len == size)
		{
			str = (char*)realloc(str, sizeof(char) * (size += 16));
			if (!str)return str;
		}
	}
	str[len++] = '\0';

	return (char*)realloc(str, sizeof(char) * len);
}


/*
* Function:  words_str
* --------------------
* Возвращает массив указателей на начало слов в строке
*
*  str:		Строка
*  count:	Количество слов
*  sep:		Строка с разделителями слов
*  replace:	Флаг указывающий нужно ли заменять разделители на символ конца строки
*
*  returns:	Указатель на массив указателей на начало слов
*/
char** words_str(char* str, int* count, char* sep, int replace)
{
	int alloc = *count + 5;
	char** words = (char**)calloc(alloc, sizeof(char*));
	int insep = 1;
	while (*str)
	{
		if (strchr(sep, *str))
		{
			insep = 1;
			if (replace)
				*str = '\0';
		}
		else if (insep)
		{
			if (*count == alloc)
				words = (char**)realloc(words, sizeof(char*) * (alloc += 5));
			*(words + (*count)++) = str;
			insep = 0;
		}
		++str;
	}
	return (char**)realloc(words, sizeof(char*) * *count);
}


/*
* Function:  check_string
* --------------------
* Проверяет строку на соответствие условиям
*
*  string:	Строка
*
*  returns:	1 если строка соответствует всем условиям иначе 0
*/
int check_string(char* string)
{
	int words_count = 0, chars_count = 0;
	char** words = words_str(string, &words_count, SEPARATOR, 0);
	if (words_count < MIN_WORDS)
	{
		printf(Rus("Слов должно быть не меньше %d. Вы ввели %d. Строка не сохранена, повторите ввод.\n"), MIN_WORDS, words_count);
		free(words);
		return 0;
	}
	int i;
	for (i = 0; i < words_count; ++i)
	{
		if ((chars_count = word_length(*(words + i), SEPARATOR)) < MIN_CHARS)
		{
			printf(Rus("В слове должно быть не менее %d символов. В %d слове вы ввели %d символов. Строка не сохранена, повторите ввод.\n"), MIN_CHARS, i + 1, chars_count);
			free(words);
			return 0;
		}
	}
	free(words);
	return 1;
}


void do_work(char **str, int count)
{
	int i, j;
	int words_count = 0;
	char** words;

	for (i = 0; i < count; ++i)
	{
		words = words_str(*(str + i), &words_count, SEPARATOR, 0);

		for (j = 0; j < words_count; ++j)
		{
			reverse_word(*(words + j));

		}
		free(words);
		words_count = 0;
	}
}


void reverse_word(char* word)
{
	char* tmp = (char*)calloc(strlen(word), sizeof(char));
	int i, j = 0;
	int length = word_length(word, SEPARATOR);
	for (i = length - 1; i >= 0; --i)
	{
		*(tmp + j++) = *(word + i);
	}
	for (i = 0; i < length; ++i)
	{
		*(word + i) = *(tmp + i);
	}
	free(tmp);
}


/*
* Function:  char_count
* --------------------
* Возвращает количество заданных символов в строке
*
*  str:		Строка для подсчета
*  symbol:	Строка символов для подсчета
*
*  returns:	Количество
*/
int char_count(char* str, char* symbol)
{
	int count = 0;
	while (*str)
	{
		if (strchr(symbol, *str))
			++count;
		++str;
	}
	return count;
}


/*
* Function:  word_count
* --------------------
* Возвращает количество заданных слов в строке
*
*  str:		Строка для подсчета
*  word:	Слово для подсчета
*
*  returns:	Количество
*/
int word_count(char* str, char* word)
{
	int count = 0;
	while (*str)
	{
		if (strstr(str, word))
			++count;
		++str;
	}
	return count;
}


/*
* Function:  word_length
* --------------------
* Возвращает количество символов в слове до разделителя
*
*  str:		Строка для подсчета
*  sep:		Строка разделителей
*
*  returns:	Количество символов
*/
int word_length(char* str, char* sep)
{
	int count = 0;
	while (!strchr(sep, *str) && *str != '\0')
	{
		++count;
		++str;
	}
	return count;
}

char bufRus[256];

/*
* Function:  Rus
* --------------------
* Переводит строку в кодировку консоли
*
*  text:	исходная строка
*
*  returns: Строка в кодировке консоли
*/
char* Rus(const char* text)
{
	CharToOemA(text, bufRus);
	return bufRus;
}