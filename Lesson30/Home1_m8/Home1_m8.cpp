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
#define HALT			""
#define DEBUG			0
#define SEPARATORS		" "

typedef int (*sort_f)(char*, char*, void*);

void show_menu();
char** read_strings(char**, int*);
char* read_string(FILE*, size_t);
char** words_str(char*, int*, char*);
int check_string(char*);
void sort(char**, int, sort_f, void*);
int char_count(char*, char*);
int word_length(char*, char*);
int char_count_comp_ASC(char*, char*, void*);
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
	}
	while (count < MIN_STRINGS);

	sort_f f = &char_count_comp_ASC;
	printf(Rus("Введите символ: "));
	char* symbol = read_string(stdin, 1);

	int i;
	for (i = 0; i < count; ++i)
	{
		puts(*(str + i));
	}
	puts("\n");

	sort(str, count, f, &symbol);

	for (i = 0; i < count; ++i)
	{
		puts(*(str + i));
	}

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

	while ((s = read_string(stdin, 10)) && strcmp(s, HALT))
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
*
*  returns:	Указатель на массив указателей на начало слов
*/
char** words_str(char* str, int* count, char* sep)
{
	int alloc = *count + 5;
	char** words = (char**)calloc(alloc, sizeof(char*));
	int insep = 1;
	while (*str)
	{
		if (strchr(sep, *str))
		{
			insep = 1;
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
	char** words = words_str(string, &words_count, SEPARATORS);
	if (words_count < MIN_WORDS)
	{
		printf(Rus("Слов должно быть не меньше %d. Вы ввели %d. Строка не сохранена, повторите ввод.\n"), MIN_WORDS, words_count);
		free(words);
		return 0;
	}
	int i;
	for (i = 0; i < words_count; ++i)
	{
		if ((chars_count = word_length(*(words + i), SEPARATORS)) < MIN_CHARS)
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
* Function:  sort
* --------------------
* Функция сортировки строк. Способ сортировки определяется передаваемой функцией
*
*  str:		Массив строк
*  n:		Количество строк
*  f:		Указатель на функцию сравнения двух строк
*/
void sort(char** str, int n, sort_f f, void* param)
{
	if (DEBUG)
	{
		static int iter = 1;
		printf("\nIteration = %d, array:\n", iter++);
		int i;
		for (i = 0; i < n; i++)
		{
			puts(*(str + i));
		}
	}
	int i, j = 0, sorted;
	char* tmp;

	do
	{
		sorted = 1;
		for (i = 0; i < n - j - 1; i++)
		{
			if ((*f)(*(str + i), *(str + i + 1), param) < 0)
			{
				tmp = *(str + i);
				*(str + i) = *(str + i + 1);
				*(str + i + 1) = tmp;
				sorted = 0;
			}
		}
		j++;
	}
	while (!sorted);
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
* Function:  word_length
* --------------------
* Возвращает количество символов в слове до разделителя
*
*  str:		Строка для подсчета
*  sep:		Строка разделителей
*
*  returns:	Количество
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


/*
* Function:  char_count_comp_ASC
* --------------------
* Сравнивает две строки по количеству символов и возвращает результат в виде целого числа.
* Если в первом операнде количество заданных символов меньше результат будет отрицательным
*
*  l:		Первая строка для сравнения
*  l:		Вторая строка для сравнения
*
*  returns:	Разницу в количестве символов
*/
int char_count_comp_ASC(char* l, char* r, void* param)
{
	return char_count(l, (char*)param) - char_count(r, (char*)param);
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