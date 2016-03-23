#include <stdio.h>
#include <windows.h>

/*
* Домашнее задание №2 к модулю №8 «Строки».
*
* Вариант 6:
* Задан текст, состоящий из строк. Строк не менее 10. В строке не менее 5
* слов. В слове не менее 5 символов. Слова разделены одним пробелом.
* Вывести слова, имеющие в своем составе не менее трех гласных символов.
* Программа должна выполнять ввод текста, вывод его исходного варианта,
* выполнять необходимые действия и выводить требуемый результат.
*
* a.matuzov, 3/23/2016 4:38:52 PM
*/
#define MIN_STRINGS		10
#define MIN_WORDS		5
#define MIN_CHARS		5
#define HALT			""
#define DEBUG			0
#define SEPARATOR		" "
#define VOWEL			"aeiouаеёиоуыэюя"

typedef int(*sort_f)(char*, char*, void*);

char** read_strings(char**, int*);
void print_strings(char**, int);
void free_mem(void**, int);
char* read_string(FILE*, size_t);
int read_int(FILE*);
char** words_str(char*, int*, char*, int);
int check_string(char*);
int char_count(char*, char*);
int word_count(char*, char*);
int word_length(char*, char*);

void do_work(char**, int);

char* Rus(const char*);

void main()
{
	char** str = NULL;
	int count = 0;
	printf(Rus("Вводите строки. Необходимо ввести не меннее %d строк.\n"), MIN_STRINGS);
	printf(Rus("Для прекращения ввода-<Enter> в начале строки.\n"));
	do
	{
		str = read_strings(str, &count);
		if (count < MIN_STRINGS)
			printf(Rus("Строк меньше %d. Вводите дополнительные строки.\n"), MIN_STRINGS);
	} while (count < MIN_STRINGS);


	printf(Rus("Исходный массив:\n"));
	print_strings(str, count);

	do_work(str, count);

	free_mem((void**)str, count);
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
* Function:  print_strings
* --------------------
* Выводит массив строк на экран
*
*  str:		Массив строк
*  count:	Количество строк в массиве
*
*/
void print_strings(char** str, int count)
{
	int i;
	for (i = 0; i < count; ++i)
	{
		puts(*(str + i));
	}
	puts("");
}


/*
* Function:  free_mem
* --------------------
* Освобождает выделенную память для эллементов массива указателей и для самого массива
*
*  ptr:		Массив указателей
*  count:	Количество элементов
*/
void free_mem(void** ptr, int count)
{
	int i;
	for (i = 0; i < count; ++i)
	{
		free(*(ptr + i));
	}
	free(ptr);
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
* Function:  do_work
* --------------------
* Выводит на экран слова, имеющие в своем составе не менее трех гласных символов.
*
*  str:		Массив строк
*  count:	Количество строк
*/
void do_work(char** str, int count)
{
	int i, j, words_count = 0;
	char** words;
	char* symbol = (char*)malloc(sizeof(LPSTR) * strlen(VOWEL));
	CharToOemA(VOWEL, symbol);

	printf(Rus("Cлова, имеющие в своем составе не менее трех гласных символов:\n"));
	for (i = 0; i < count; ++i)
	{
		words = words_str(*(str + i), &words_count, SEPARATOR, 1);
		for (j = 0; j < words_count; ++j)
		{
			if (char_count(*(words + j), symbol) >= 3)
			{
				puts(*(words + j));
			}
		}
		free(words);
		words_count = 0;
	}
	free(symbol);
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

