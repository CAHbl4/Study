#include <stdio.h>
#include <windows.h>
#include "strings.h"
#include "io.h"
#include "utils.h"

#define SENTENCE_SEPARATORS		".!?"

char* Rus(const char* text);
size_t count_nums(char* str);
size_t count_letters(char* str);
void sentence_start_up(char* str, const char* separators);
void func_311();
void func_312();
void func_313();
void func_314();
void func_315();
void func_316();
void func_321();
void func_322();
void func_323();
void func_324();
void func_325();
void func_326();
void func_331();


void main() {
	
	printf(Rus("Все функции написаны и протестированы только для латинских символов\n"));
	func_311();
	puts("");
	func_312();
	puts("");
	func_313();
	puts("");
	func_314();
	puts("");
	func_315();
	puts("");
	func_316();
	printf(Rus("Задание 3.2.1:\nДополните свою библиотеку функций реализациями нижеследующих функций:\n"));
	func_321();
	puts("");
	func_322();
	puts("");
	func_323();
	puts("");
	func_324();
	puts("");
	func_325();
	puts("");
	func_326();
	puts("");
	func_331();
	system("pause");
}


void func_311()
{
	printf(Rus("Задание 3.1.1:\nНаписать функцию, которая удаляет из строки символ с заданным номером.\n"));
	printf(Rus("Введите строку:\n"));
	char* str = read_string(stdin);
	printf(Rus("Введите позицию символа (счет с 0): "));
	int pos = read_int(stdin);
	printf(Rus("Исходная строка:\n"));
	puts(str);
	printf(Rus("Результат работы функции str_pos_del():\n"));
	puts(str_pos_del(str, pos));
	free(str);
}

void func_312()
{
	printf(Rus("Задание 3.1.2:\nНаписать функцию, которая удаляет из строки все вхождения в нее заданного символа.\n"));
	printf(Rus("Введите строку:\n"));
	char* str = read_string(stdin);
	printf(Rus("Введите символ: "));
	char ch = read_char(stdin);
	printf(Rus("Исходная строка:\n"));
	puts(str);
	printf(Rus("Результат работы функции str_chr_del():\n"));
	puts(str_chr_del(str, ch));
	free(str);
}

void func_313()
{
	printf(Rus("Задание 3.1.3:\nНаписать функцию, которая вставляет в строку в указанную позицию заданный символ.\n"));
	printf(Rus("Введите строку:\n"));
	char* str = read_string(stdin);
	printf(Rus("Введите позицию символа (счет с 0): "));
	int pos = read_int(stdin);
	printf(Rus("Введите символ: "));
	char ch = read_char(stdin);
	printf(Rus("Исходная строка:\n"));
	puts(str);
	printf(Rus("Результат работы функции str_pos_add():\n"));
	str = (char*)realloc(str, sizeof(char) * (strlen(str) + 2));
	puts(str_pos_add(str, pos, ch));
	free(str);
}

void func_314()
{
	printf(Rus("Задание 3.1.4:\nНаписать программу, которая заменяет все символы точки \".\" "
		"в строке, введенной пользователем, на символы восклицательного знака \"!\".\n"));
	printf(Rus("Введите строку:\n"));
	char* str = read_string(stdin);
	printf(Rus("Исходная строка:\n"));
	puts(str);
	printf(Rus("Результат работы функции str_chr_replace():\n"));
	puts(str_chr_replace(str, '.' ,'!'));
	free(str);
}

void func_315()
{
	printf(Rus("Задание 3.1.5:\nПользователь вводит строку символов и искомый символ, "
		"посчитать сколько раз он встречается в строке.\n"));
	printf(Rus("Введите строку:\n"));
	char* str = read_string(stdin);
	printf(Rus("Введите символ: "));
	char ch = read_char(stdin);
	printf(Rus("Исходная строка:\n"));
	puts(str);
	printf(Rus("Результат работы функции str_chr_count(): "));
	printf("%u\n", str_chr_count(str, ch));
	free(str);
}

void func_316()
{
	printf(Rus("Задание 3.1.6:\nПользователь вводит строку. Определить количество букв, "
		"количество цифр и количество остальных символов, присутствующих в строке.\n"));
	printf(Rus("Введите строку:\n"));
	char* str = read_string(stdin);
	printf(Rus("Исходная строка:\n"));
	puts(str);
	size_t letters = count_letters(str);
	size_t nums = count_nums(str);
	printf(Rus("Количество букв: %d\n"), letters);
	printf(Rus("Количество цифр: %d\n"), nums);
	printf(Rus("Количество остальных символов: %d\n"), strlen(str) - letters - nums);
	free(str);
}

void func_321()
{
	printf(Rus("Функция сравнивает две строки, и, если строки равны возвращает 0, если первая строка"
		"больше второй, то возвращает 1, иначе - 1.\n"));
	printf(Rus("Введите строку 1:\n"));
	char* str1 = read_string(stdin);
	printf(Rus("Введите строку 2:\n"));
	char* str2 = read_string(stdin);
	printf(Rus("Исходная строка 1:\n"));
	puts(str1);
	printf(Rus("Исходная строка 2:\n"));
	puts(str2);
	printf(Rus("Результат работы функции str_cmp(): "));
	printf("%d\n", str_cmp(str1, str2));
	free(str1);
	free(str2);
}

void func_322()
{
	printf(Rus("Функция конвертирует строку в число и возвращает это число.\n"));
	printf(Rus("Введите корректную строку:\n"));
	char* str = read_string(stdin);
	printf(Rus("Исходная строка:\n"));
	puts(str);
	printf(Rus("Результат работы функции str_to_int(): "));
	printf("%lld\n", str_to_int(str));
	free(str);
}

void func_323()
{
	printf(Rus("Функция конвертирует число в строку и возвращает указатель на эту строку.\n"));
	printf(Rus("Введите число: "));
	__int64 num = read_int(stdin);
	printf(Rus("Исходное число: "));
	printf("%lld\n", num);
	printf(Rus("Результат работы функции int_to_str(): "));
	char* str = int_to_str(num);
	printf("%s\n", str);
	free(str);
}

void func_324()
{
	printf(Rus("Функция преобразует строку в верхний регистр.\n"));
	printf(Rus("Введите строку:\n"));
	char* str = read_string(stdin);
	printf(Rus("Исходная строка:\n"));
	puts(str);
	printf(Rus("Результат работы функции str_to_upper():\n"));
	puts(str_to_upper(str));
	free(str);
}

void func_325()
{
	printf(Rus("Функция преобразует строку в нижний регистр.\n"));
	printf(Rus("Введите строку:\n"));
	char* str = read_string(stdin);
	printf(Rus("Исходная строка:\n"));
	puts(str);
	printf(Rus("Результат работы функции str_to_lower():\n"));
	puts(str_to_lower(str));
	free(str);
}

void func_326()
{
	printf(Rus("Функция реверсирует строку и возвращает указатель на новую строку.\n"));
	printf(Rus("Введите строку:\n"));
	char* str = read_string(stdin);
	printf(Rus("Исходная строка:\n"));
	puts(str);
	printf(Rus("Результат работы функции str_rev():\n"));
	char* rev_str = str_rev(str);
	puts(str_to_lower(rev_str));
	free(str);
	free(rev_str);
}

void func_331()
{
	printf(Rus("Задание 3.3.1:\n"));
	printf(Rus("Есть некоторый текст.\n"));
	printf(Rus("Вводите текст.\n"));
	printf(Rus("Для прекращения ввода-<Enter> в начале строки.\n"));
	size_t count = 0;
	char** str = read_strings(stdin, NULL, &count);

	printf(Rus("Исходный текст:\n"));
	print_strings(str, count);

	printf(Rus("Задание 1: Найдите и замените вхождение некоторого слова на заданное пользователем слово.\n"));
	printf(Rus("Введите строку поиска: "));
	char* find = read_string(stdin);
	printf(Rus("Введите строку замены: "));
	char* replace = read_string(stdin);

	size_t i;
	char* tmp;
	for (i = 0; i < count; ++i)
	{
		tmp = str_str_replace(*(str + i), find, replace);
		free(*(str + i));
		*(str + i) = tmp;
	}

	printf(Rus("Результат замены:\n"));
	print_strings(str, count);

	printf(Rus("Задание 2: Изменить текст таким образом, чтобы каждое предложение начиналось с большой буквы\n"));

	for (i = 0; i < count; ++i)
	{
		sentence_start_up(*(str + i), SENTENCE_SEPARATORS);
	}

	printf(Rus("Результат замены:\n"));
	print_strings(str, count);

	free_ptr_ptr((void**)str, count);
	free(find);
	free(replace);
}

char bufRus[256];
char* Rus(const char* text)
{
	CharToOemA(text, bufRus);
	return bufRus;
}


/*
* Function:  count_nums
* --------------------
* Возвращает количество цифр в строке
*
*  str:		Строка для подсчета
*
*  returns:	Количество цифр
*/
size_t count_nums(char* str)
{
	size_t count = 0;
	while(*str)
	{
		if (is_digit(*str))
			++count;
	}
	return count;
}


/*
* Function:  count_letters
* --------------------
* Возвращает количество букв в строке
*
*  str:		Строка для подсчета
*
*  returns:	Количество букв
*/
size_t count_letters(char* str)
{
	size_t count = 0;
	while (*str)
	{
		if (is_letter(*str))
			++count;
	}
	return count;
}


void sentence_start_up(char* str, const char* separators)
{
	__int8 insep = 1;
	while (*str)
	{
		if (strchr(separators, *str))
		{
			insep = 1;
		}
		else if (insep && is_letter(*str))
		{
			chr_to_upper(str);
			insep = 0;
		}
		++str;
	}
}