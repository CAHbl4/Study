#include <stdio.h>
#include <windows.h>

/*
* Программа выполняет все варианты из домашнего задания 1 к модулю 8
*
* a.matuzov, 3/15/2016 7:02:43 PM
*/
#define MIN_STRINGS		10
#define MIN_WORDS		5
#define MIN_CHARS		5
#define HALT			""
#define DEBUG			0
#define SEPARATOR		" "

typedef int (*sort_f)(char*, char*, void*);

char** read_strings(char**, int*);
char* read_string(FILE*, size_t);
void do_work(int, char**, int);
int read_int(FILE* stream);
char** words_str(char*, int*, char*, int);
int check_string(char*);
void sort_words(char**, int, sort_f, void*);
void sort(char**, int, sort_f, void*);
int char_count(char*, char*);
int word_count(char*, char*);
int word_length(char*, char*);
int longest_word_length(char*);
int shortest_word_length(char*);
int sort_f1(char*, char*, void*);
int sort_f2(char*, char*, void*);
int sort_f3(char*, char*, void*);
int sort_f4(char*, char*, void*);
int sort_f5(char*, char*, void*);
int sort_f6(char*, char*, void*);
int sort_f7(char*, char*, void*);
int sort_f12(char*, char*, void*);
int sort_f13(char*, char*, void*);
int sort_f14(char*, char*, void*);
int sort_f15(char*, char*, void*);
int sort_f16(char*, char*, void*);
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

	int v;
	printf(Rus("Выберите вариант задания(1-16): "));
	do
	{
		v = read_int(stdin);
		if (v < 0 || v > 16)
			printf(Rus("Неверный вариант. Повторите."));
	}
	while (v < 0 || v > 16);
	scanf("%*c");

	int i;

	printf(Rus("Исходный массив:\n"));
	for (i = 0; i < count; ++i)
	{
		puts(*(str + i));
	}
	puts("");

	do_work(v, str, count);

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

void do_work(int v, char** str, int count)
{
	sort_f f;
	char* symbol;
	switch (v)
	{
	case 1:
		f = &sort_f1;
		sort(str, count, f, NULL);
		break;
	case 2:
		f = &sort_f2;
		sort(str, count, f, NULL);
		break;
	case 3:
		f = &sort_f3;
		sort(str, count, f, NULL);
		break;
	case 4:
		f = &sort_f4;
		printf(Rus("Введите символ: "));
		symbol = read_string(stdin, 1);
		sort(str, count, f, symbol);
		free(symbol);
		break;
	case 5:
		f = &sort_f5;
		printf(Rus("Введите символ: "));
		symbol = read_string(stdin, 1);
		sort(str, count, f, symbol);
		free(symbol);
		break;
	case 6:
		f = &sort_f6;
		printf(Rus("Введите слово: "));
		symbol = read_string(stdin, 1);
		sort(str, count, f, symbol);
		free(symbol);
		break;
	case 7:
		f = &sort_f6;
		printf(Rus("Введите слово: "));
		symbol = read_string(stdin, 1);
		sort(str, count, f, symbol);
		free(symbol);
		break;
	case 8:
		f = &sort_f1;
		sort_words(str, count, f, NULL);
		break;
	case 9:
		f = &sort_f3;
		sort_words(str, count, f, NULL);
		break;
	case 10:
		f = &sort_f5;
		symbol = Rus("aeiouаеёиоуыэюя");
		sort_words(str, count, f, symbol);
		break;
	case 11:
		f = &sort_f4;
		symbol = Rus("bcdfghjklmnpqrstvwxyzбвгджзйклмнпрстфхцчшщъь");
		sort_words(str, count, f, symbol);
		break;
	case 12:
		f = &sort_f12;
		sort_words(str, count, f, NULL);
		break;
	case 13:
		f = &sort_f13;
		sort_words(str, count, f, NULL);
		break;
	case 14:
		f = &sort_f14;
		sort(str, count, f, NULL);
		break;
	case 15:
		f = &sort_f15;
		sort(str, count, f, NULL);
		break;
	case 16:
		f = &sort_f16;
		sort(str, count, f, NULL);
		break;
	default:
		fprintf(stderr, Rus("Неверный вариант"));
		exit(1);
	}
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
* Function:  read_int
* --------------------
* Читает целое число с заданного потока
*
*  stream:     поток ввода
*
*  returns:    целое число
*/
int read_int(FILE* stream)
{
	int n, result, ch;
	do
	{
		result = fscanf(stream, "%d", &n);
		if (result == EOF)
		{
			fwprintf(stderr, L"Неожиданный конец файла\n");
			exit(74);
		}
		if (result == 0)
		{
			do
			{
				ch = fgetc(stream);
			}
			while (ch <= '0' && ch >= '9');
			fwprintf(stderr, L"Ожидалось целое\n");
		}
	}
	while (!result);

	return n;
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
* Function:  sort_words
* --------------------
* Функция слов в строках. Способ сортировки определяется передаваемой функцией
*
*  str:		Массив строк
*  n:		Количество строк
*  f:		Указатель на функцию сравнения двух строк
*  param:	Параметры для функции сравнения
*/
void sort_words(char** str, int n, sort_f f, void* param)
{
	int i, j;
	int words_count = 0;
	char** words;
	char* s;
	for (i = 0; i < n; ++i)
	{
		words = words_str(*(str + i), &words_count, SEPARATOR, 1);
		s = (char*)calloc(1, sizeof(char));
		sort(words, words_count, f, param);
		for (j = 0; j < words_count; ++j)
		{
			s = (char*)realloc(s, sizeof(char) * (strlen(s) + strlen(*(words + j)) + 2));
			strcat(s, *(words + j));
			strcat(s, SEPARATOR);
		}
		*(s + (strlen(s) - 1)) = '\0';
		s = (char*)realloc(s, sizeof(char) * (strlen(s) + 1));
		free(*(str + i));
		*(str + i) = s;
		free(words);
		words_count = 0;
	}
}

/*
* Function:  sort
* --------------------
* Функция сортировки строк. Способ сортировки определяется передаваемой функцией
*
*  str:		Массив строк
*  n:		Количество строк
*  f:		Указатель на функцию сравнения двух строк
*  param:	Параметры для функции сравнения
*/
void sort(char** str, int n, sort_f f, void* param)
{
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

/*
* Function:  longest_word_length
* --------------------
* Возвращает количество символов в самом длинном слове в строке
*
*  str:		Строка для подсчета
*  sep:		Строка разделителей
*
*  returns:	Количество символов
*/
int longest_word_length(char* str)
{
	int count = 0;
	int length = 0, i, tmp;
	char** words;
	words = words_str(str, &count, SEPARATOR, 0);
	for (i = 0; i < count; ++i)
	{
		if ((tmp = word_length(*(words + i), SEPARATOR)) > length)
			length = tmp;
	}
	free(words);
	return length;
}

/*
* Function:  shortest_word_length
* --------------------
* Возвращает количество символов в самом коротком слове в строке
*
*  str:		Строка для подсчета
*  sep:		Строка разделителей
*
*  returns:	Количество символов
*/
int shortest_word_length(char* str)
{
	int count = 0;
	int length, i, tmp;
	char** words;
	words = words_str(str, &count, SEPARATOR, 0);
	length = word_length(*words, SEPARATOR);
	for (i = 1; i < count; ++i)
	{
		if ((tmp = word_length(*(words + i), SEPARATOR)) < length)
			length = tmp;
	}
	free(words);
	return length;
}


int sort_f1(char* l, char* r, void*)
{
	return strlen(l) - strlen(r);
}


int sort_f2(char* l, char* r, void*)
{
	int length_l = strlen(l) - 1;
	int length_r = strlen(r) - 1;
	while (*(l + length_l) == *(r - length_r) && length_l && length_r)
	{
		length_l--;
		length_r--;
	}
	return *(r + length_r) - *(l + length_l);
}


int sort_f3(char* l, char* r, void*)
{
	return strlen(r) - strlen(l);
}


int sort_f4(char* l, char* r, void* param)
{
	return char_count(r, (char*)param) - char_count(l, (char*)param);
}


int sort_f5(char* l, char* r, void* param)
{
	return char_count(l, (char*)param) - char_count(r, (char*)param);
}


int sort_f6(char* l, char* r, void* param)
{
	return word_count(r, (char*)param) - char_count(l, (char*)param);
}


int sort_f7(char* l, char* r, void* param)
{
	return word_count(l, (char*)param) - char_count(r, (char*)param);
}


int sort_f12(char* l, char* r, void*)
{
	return *r - *l;
}


int sort_f13(char* l, char* r, void*)
{
	return *(l + strlen(l) - 1) - *(r + strlen(r) - 1);
}


int sort_f14(char* l, char* r, void*)
{
	return longest_word_length(r) - longest_word_length(l);
}


int sort_f15(char* l, char* r, void*)
{
	return longest_word_length(l) - longest_word_length(r);
}


int sort_f16(char* l, char* r, void*)
{
	return shortest_word_length(r) - shortest_word_length(l);
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

