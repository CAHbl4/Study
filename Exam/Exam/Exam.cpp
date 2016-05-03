#include <stdio.h>
#include <windows.h>
#include <conio.h>

/*
*
* amatu, 5/3/2016 9:14:46 AM
*/

#define ARR_FILE_NAME	"arr.dat"
#define STR_FILE_NAME	"strings.txt"
#define HALT			""
#define VOWEL			"aeiouYAEIOUY"

enum state {
	EXIT,
	REDRAW_ALL,
	REDRAW_SELECTED,
	CONTINUE
};

typedef state(*event_cb_t)(void *data, void* params);

struct event_cb {
	event_cb_t	cb;
	void		*data;
	void		*params;
};

enum keys {
	KEY_BACKSPACE = 8,
	KEY_ENTER = 13,
	KEY_ESC = 27,
	KEY_SPACE = 32,
	ARROW_UP = 256 + 72,
	ARROW_DOWN = 256 + 80,
	ARROW_LEFT = 256 + 75,
	ARROW_RIGHT = 256 + 77
};


typedef struct menu_item {
	char				text[80];
	struct event_cb*	action;
	struct menu_item*	next;
} menu_item_t;

typedef struct menu {
	char				name[80];
	struct menu_item*	head;
	struct menu_item*	selected;
	struct menu_item*	prev_selected;
	state				menu_state;
} menu_t;

void	make_borders(char* text);
void	menu_add_item(menu_t* menu, char text[50], event_cb_t action, void* data, void* params);
menu_t* menu_create(char text[50]);
void	menu_show(menu_t* menu);
state	menu_execute(void* menu, void* params);
void	menu_free(menu_t* menu);

int		get_code(void);

state	exit_program(void* data, void* params);
state	exit_sub(void* data, void* params);

char* Rus(const char* text);
char*	RusW(const wchar_t* text);

__int64* read_array(__int64* arr, size_t* count);
__int64* parse_ints(__int64* nums, char* str, size_t* count);
__int64 str_to_int(const char* str);
int is_digit(char);
char* read_string(FILE* fp);
void print_array(__int64* arr, size_t count);
__int64 read_int(FILE* fp);
void flush_stream(FILE* fp);
__int64 pow(__int64 base, __int64 exp);
__int8 str_cmp(const char * str1, const char * str2);
char** read_strings(FILE* fp, char** str, size_t* count);
size_t str_chrs_count(const char* str, const char* find);
int chr_cmp(char ch, const char* str);
int is_vowel(char ch);
int is_letter(char ch);

HANDLE	hConsole;
CONSOLE_SCREEN_BUFFER_INFO csbi;
CONSOLE_CURSOR_INFO cci;

#define HIGHLIGHT_COLOR		BACKGROUND_GREEN	| BACKGROUND_BLUE	| 0
#define DEFAULT_COLOR		BACKGROUND_BLUE | FOREGROUND_BLUE	| FOREGROUND_GREEN	| FOREGROUND_RED	| FOREGROUND_INTENSITY

__int64* arr = NULL;
size_t arr_count = 0;
char** str = NULL;
size_t str_count = 0;

state task1(void* data, void* params);
state task2(void* data, void* params);
state do_task1(void* data, void* params);
state do_task2(void* data, void* params);
state input_arr(void* data, void* params);
state print_arr(void* data, void* params);
state read_arr(void* data, void* params);
state save_arr(void* data, void* params);

state input_str(void* data, void* params);
state print_str(void* data, void* params);
state read_str(void* data, void* params);
state save_str(void* data, void* params);

int exist(const char *fname);

int main() {
	//Сохраняем текущие параметры консоли
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, DEFAULT_COLOR);

	//Создаем меню
	menu_t* main_menu = menu_create("Главное меню");

	//Добавляем пункты в меню
	menu_add_item(main_menu, Rus("Задание 1"), &task1, NULL, NULL);
	menu_add_item(main_menu, Rus("Задание 2"), &task2, NULL, NULL);


	menu_add_item(main_menu, "Exit", &exit_program, NULL, NULL);

	//Выполняем меню
	menu_execute(main_menu, NULL);

	menu_free(main_menu);

	return 0;
}

state task1(void* data, void* params)
{
	system("cls");
	char ch;
	if (exist(ARR_FILE_NAME))
	{
		printf(Rus("Файл существует, прочитать? Y/N: "));
		do {
			ch = fgetc(stdin);
		} while (ch != 'Y' &&
			ch != 'y' &&
			ch != 'N' &&
			ch != 'n');
		switch (ch)
		{
		case 'Y':
		case 'y':
			read_arr(NULL, NULL);
			break;
		default:
			break;
		}
	}

	//Создаем меню
	menu_t* menu = menu_create("Задание 1");

	//Добавляем пункты в меню
	menu_add_item(menu, Rus("Добавить элементы в массив"), &input_arr, NULL, NULL);
	menu_add_item(menu, Rus("Вывести массив на экран"), &print_arr, NULL, NULL);
	menu_add_item(menu, Rus("Сохранить массив в файл"), &save_arr, NULL, NULL);
	menu_add_item(menu, Rus("Прочитать массив из файла"), &read_arr, NULL, NULL);
	menu_add_item(menu, Rus("Выполнить задание варианта 2"), &do_task1, NULL, NULL);

	menu_add_item(menu, Rus("Вернутся в главное меню"), &exit_sub, menu, NULL);

	//Выполняем меню
	menu_execute(menu, NULL);

	menu_free(menu);
	return REDRAW_ALL;
}

state task2(void* data, void* params)
{
	system("cls");
	char ch;
	if (exist(STR_FILE_NAME))
	{
		printf(Rus("Файл существует, прочитать? Y/N: "));
		do {
			ch = fgetc(stdin);
		} while (ch != 'Y' &&
			ch != 'y' &&
			ch != 'N' &&
			ch != 'n');
		switch (ch)
		{
		case 'Y':
		case 'y':
			read_str(NULL, NULL);
			break;
		default:
			break;
		}
	}

	//Создаем меню
	menu_t* menu = menu_create("Задание 2");

	//Добавляем пункты в меню
	menu_add_item(menu, Rus("Добавить строки с клавиатуры"), &input_str, NULL, NULL);
	menu_add_item(menu, Rus("Вывести текст на экран"), &print_str, NULL, NULL);
	menu_add_item(menu, Rus("Сохранить текст в файл"), &save_str, NULL, NULL);
	menu_add_item(menu, Rus("Прочитать текст из файла"), &read_str, NULL, NULL);
	menu_add_item(menu, Rus("Выполнить задание варианта 2"), &do_task2, NULL, NULL);

	menu_add_item(menu, Rus("Вернутся в главное меню"), &exit_sub, menu, NULL);

	//Выполняем меню
	menu_execute(menu, NULL);

	menu_free(menu);
	return REDRAW_ALL;
}

state do_task1(void*, void*)
{
	system("cls");
	size_t i, neg_count = 0, neg_sum = 0;
	if (arr_count)
	{
		for (i = 0; i <arr_count; ++i)
		{
			if (arr[i] < 0)
			{
				++neg_count;
				neg_sum += arr[i];
			}
		}
		printf(Rus("Количество отрицательных элементов: %d\n"), neg_count);
		printf(Rus("Сумма отрицательных элементов: %d\n"), neg_sum);
	} else
	{
		printf(Rus("В массиве отсутствуют элементы\n"));
	}
		system("pause");
	return REDRAW_ALL;
}

state do_task2(void*, void*)
{
	system("cls");
	size_t i, j, vowel_count = 0, consonant_count = 0;
	if (str_count)
	{
		for (i = 0; i <str_count; ++i)
		{
			j = 0;
			while (str[i][j])
			{
				if (is_letter(str[i][j]) && is_vowel(str[i][j]))
				{
					++vowel_count;
				} else
				{
					++consonant_count;
				}
				++j;
			}
		}
		if (vowel_count>consonant_count)
		{
			printf(Rus("В тексте больше гласных\n"));
		} else if (consonant_count<vowel_count)
		{
			printf(Rus("В тексте согласных\n"));
		} else
		{
			printf(Rus("Гласных и согласных поровну\n"));
		}
	}
	else
	{
		printf(Rus("В массиве отсутствуют элементы\n"));
	}
	system("pause");
	return REDRAW_ALL;
}

int is_vowel(char ch)
{
	if (is_letter(ch) && chr_cmp(ch, VOWEL))
		return 1;
	return 0;
}

int chr_cmp(char ch, const char* str)
{
	while(*str)
	{
		if (ch == *str)
			return 1;
		++str;
	}
	return 0;
}

int is_letter(char ch)
{
	return ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'));
}

state print_arr(void* data, void* params)
{
	system("cls");
	size_t i;
	for (i = 0; i < arr_count; ++i)
	{
		printf("%5lld", arr[i]);
		if (!((i + 1) % 5))
			printf("\n");
	}
	printf("\n");
	system("pause");
	return REDRAW_ALL;
}

state read_arr(void*, void*)
{
	system("cls");
	FILE* file;
	size_t i = 0;
	if (file = fopen(ARR_FILE_NAME, "r"))
	{
		arr = (__int64*)realloc(arr, sizeof(__int64) * (arr_count + 1));
		while(fread(arr + arr_count,sizeof(__int64),1,file))
		{
			++arr_count;
			++i;
			arr = (__int64*)realloc(arr, sizeof(__int64) * (arr_count + 1));
		}
		printf(Rus("Считано элементов - %d\n"), i);
		arr = (__int64*)realloc(arr, sizeof(__int64) * (arr_count));
	}
	else
	{
		printf(Rus("Ошибка при открытии файла!\n"));
	}
		system("pause");
	return REDRAW_ALL;
}


state save_arr(void* data, void* params)
{
	cci.dwSize = 5;
	cci.bVisible = TRUE;
	SetConsoleCursorInfo(hConsole, &cci);
	system("cls");
	FILE* file;
	char ch;
	if (arr_count) {
		if (exist(ARR_FILE_NAME))
		{
			printf(Rus("Файл существует, перезаписать? Y/N: "));
			do {
				ch = fgetc(stdin);
			} while (ch != 'Y' &&
				ch != 'y' &&
				ch != 'N' &&
				ch != 'n');
			switch (ch)
			{
			case 'Y':
			case 'y':
				if (file = fopen(ARR_FILE_NAME, "w+b"))
				{
					fwrite(arr, sizeof(__int64), arr_count, file);
					fclose(file);
					printf(Rus("Файл сохранен!\n"));
				} else
				{
					printf(Rus("Ошибка при открытии файла!\n"));
				}
				break;
			case 'N':
			case 'n':
				break;
			}
		}
		else
		{
			if (file = fopen(ARR_FILE_NAME, "w+b"))
			{
				fwrite(arr, sizeof(__int64), arr_count, file);
				fclose(file);
				printf(Rus("Файл сохранен!\n"));
			}
			else
			{
				printf(Rus("Ошибка при открытии файла!\n"));
			}
		}
	} else
	{
		printf(Rus("Нет элементов для записи!\n"));
	}
	system("pause");
	return REDRAW_ALL;
}


state input_arr(void* data, void* params)
{
	cci.dwSize = 5;
	cci.bVisible = TRUE;
	SetConsoleCursorInfo(hConsole, &cci);
	system("cls");
	printf(Rus("Вводите числа и они будут записаны в массив.\n"));
	printf(Rus("Для прекращения ввода-<Enter> в начале строки.\n"));
	arr = read_array(arr, &arr_count);
	return REDRAW_ALL;
}

state print_str(void* data, void* params)
{
	system("cls");
	size_t i;
	for (i = 0; i < str_count; ++i)
	{
		printf("%s\n", str[i]);
	}
	printf("\n");
	system("pause");
	return REDRAW_ALL;
}


state input_str(void* data, void* params)
{
	cci.dwSize = 5;
	cci.bVisible = TRUE;
	SetConsoleCursorInfo(hConsole, &cci);
	system("cls");
	flush_stream(stdin);
	printf(Rus("Вводите строки.\n"));
	printf(Rus("Для прекращения ввода-<Enter> в начале строки.\n"));
	str = read_strings(stdin, str, &str_count);
	return REDRAW_ALL;
}

state read_str(void*, void*)
{
	system("cls");
	FILE* file;
	size_t i = 0;
	if (file = fopen(STR_FILE_NAME, "r"))
	{
		str = read_strings(file, str, &str_count);
	}
	else
	{
		printf(Rus("Ошибка при открытии файла!\n"));
	}
	system("pause");
	return REDRAW_ALL;
}


state save_str(void* data, void* params)
{
	cci.dwSize = 5;
	cci.bVisible = TRUE;
	SetConsoleCursorInfo(hConsole, &cci);
	system("cls");
	FILE* file;
	char ch;
	size_t i;
	if (str_count) {
		if (exist(STR_FILE_NAME))
		{
			printf(Rus("Файл существует, перезаписать? Y/N: "));
			do {
				ch = fgetc(stdin);
			} while (ch != 'Y' &&
				ch != 'y' &&
				ch != 'N' &&
				ch != 'n');
			switch (ch)
			{
			case 'Y':
			case 'y':
				if (file = fopen(STR_FILE_NAME, "w"))
				{
					for(i = 0; i < str_count; ++i)
					{
						fputs(str[i], file);
						fputc('\n', file);
					}
					fclose(file);
				}
				else
				{
					printf(Rus("Ошибка при открытии файла!\n"));
				}
				break;
			case 'N':
			case 'n':
				break;
			}
		}
		else
		{
			if (file = fopen(STR_FILE_NAME, "w"))
			{
				for (i = 0; i < str_count; ++i)
				{
					fputs(str[i], file);
					fputc('\n', file);
				}
				fclose(file);
			}
			else
			{
				printf(Rus("Ошибка при открытии файла!\n"));
			}
		}
	}
	else
	{
		printf(Rus("Нет элементов для записи!\n"));
	}
	system("pause");
	return REDRAW_ALL;
}


int exist(const char *fname)
{
	FILE* file;
	if (file = fopen(fname, "r"))
	{
		fclose(file);
		return 1;
	}
	return 0;
}


size_t str_chrs_count(const char* str, const char* find)
{
	size_t count = 0;
	while (*str)
	{
		if (strchr(find, *str))
			++count;
		++str;
	}
	return count;
}

/*
* Function:  read_array
* --------------------
* Читает целые числа в массив
*
*  arr:		Массив целых чисел
*  count:	Количество элементов в массиве
*
*  returns:	Указатель на массив
*/
__int64* read_array(__int64* arr, size_t* count)
{
	char* s;

	while (1)
	{
		s = read_string(stdin);
		if (!strcmp(s, HALT))
		{
			break;
		}
		arr = parse_ints(arr, s, count);
		free(s);
	}

	return (__int64*)realloc(arr, sizeof(__int64) * *count);
}

/*
* Function:  parse_ints
* --------------------
* Парсит все целые из строки и сохраняет их в массив
*
*  nums:		Массив целых
*  str:			Строка для парсинга
*  count:		Текущее количество элементов в массиве
*
*  returns:		Указатель на новый адрес массива
*/
__int64* parse_ints(__int64* nums, char* str, size_t* count)
{
	int in_num = 0;
	size_t alloc = *count + 5;
	char tmp_c[20];
	int n = 0, i;
	nums = (__int64*)realloc(nums, sizeof(__int64) * alloc);
	for (i = 0; i < (int)strlen(str) + 1; ++i)
	{
		if (!is_digit(*(str + i)))
		{
			if (in_num)
			{
				tmp_c[n] = '\0';
				if (*count == alloc)
					nums = (__int64*)realloc(nums, sizeof(__int64) * (alloc += 5));
				*(nums + *count) = str_to_int(tmp_c);
				++(*count);
				in_num = 0;
			}
			if (*(str + i) == '-' && is_digit(*(str + i + 1)))
			{
				n = 0;
				tmp_c[n++] = *(str + i);
				in_num = 1;
			}
		}
		else
		{
			if (!in_num)
			{
				n = 0;
				tmp_c[n++] = *(str + i);
				in_num = 1;
			}
			else
			{
				tmp_c[n++] = *(str + i);
			}
		}
	}

	return (__int64*)realloc(nums, sizeof(__int64) * *count);
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


/*
* Function:  str_to_int
* --------------------
* Конвертирует строку в целое число
*
*  str:			Строка для конвертации
*
*  returns:		Целое число
*/
__int64 str_to_int(const char* str)
{
	size_t i, j = 0;
	__int64 tmp = 0;
	__int8 sign = 1;

	if (*str == '-')
	{
		sign = -1;
		++str;
	}

	for (i = strlen(str); i--> 0;)
	{
		tmp += (*(str + i) - '0') * (__int64)pow(10, j++);
	}
	return tmp * sign;
}


/*
* Function:  is_digit
* --------------------
* Возвращает единицу если переданный символ является числом
*
*  c:		Символ для проверки
*
*  returns:	Результат проверки
*/
int is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

void print_array(__int64* arr, size_t count)
{
	size_t i;
	for (i = 0; i < count; ++i)
	{
		printf("%lld ", *(arr + i));
	}
	puts("");
}


__int64 read_int(FILE* fp)
{
	__int64 n = 0;
	__int8 result;
	char ch;
	do
	{
		result = fscanf(fp, "%lld", &n);
		if (result == EOF)
		{
			fprintf(stderr, "Unexpected EOF\n");
			exit(74);
		}
		if (result == 0)
		{
			do
			{
				ch = fgetc(fp);
			} while (ch <= '0' && ch >= '9');
			fprintf(stderr, "Incorrect symbol\n");
		}
	} while (!result);

	flush_stream(fp);

	return n;
}

void flush_stream(FILE* fp)
{
	fseek(fp, 0, SEEK_END);
}

__int64 pow(__int64 base, __int64 exp)
{
	if (!exp) {
		return 1;
	}

	__int64 result = 1;
	while (exp)
	{
		if (exp & 1)
			result *= base;
		exp >>= 1;
		base *= base;
	}

	return result;
}

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


char bufRus[256];

char* Rus(const char* text)
{
	CharToOemA(text, bufRus);
	return bufRus;
}

char* RusW(const wchar_t* text) {
	CharToOemW(text, bufRus);
	return bufRus;
}

void make_borders(char* text) {
	size_t i, j, tmp;

	//Получаем ширину консоли
	size_t screen_width, screen_height;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	int ret;
	ret = GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	if (ret)
	{
		screen_width = csbi.srWindow.Right;
		screen_height = csbi.srWindow.Bottom - 2;
	}
	else {
		screen_width = 80;
		screen_height = 25;
	}

	printf(RusW(L"╔"));
	tmp = screen_width / 2 - strlen(text) / 2;
	for (i = 0; i < tmp - 2; ++i) {
		printf(RusW(L"═"));
	}
	printf(Rus(text));
	for (i = tmp + strlen(text); i < screen_width; ++i) {
		printf(RusW(L"═"));
	}
	printf(RusW(L"╗\n"));

	for (i = 0; i < screen_height; ++i) {
		printf(RusW(L"║"));
		for (j = 0; j < screen_width - 2; ++j) {
			printf(" ");
		}
		printf(RusW(L"║\n"));
	}

	printf(RusW(L"╚"));
	for (j = 0; j < screen_width - 2; ++j) {
		printf(RusW(L"═"));
	}
	printf(RusW(L"╝\n"));
}

void menu_add_item(menu_t* menu, char text[50], event_cb_t action, void* data, void* params) {
	menu_item_t* current = menu->head;

	if (current) {
		while (current->next != NULL) {
			current = current->next;
		}

		current->next = (menu_item_t*)malloc(sizeof(menu_item_t));
		strcpy(current->next->text, text);
		current->next->action = (event_cb*)malloc(sizeof(event_cb));
		current->next->action->cb = action;
		current->next->action->data = data;
		current->next->action->params = params;
		current->next->next = NULL;
	}
	else {
		menu->head = (menu_item_t*)malloc(sizeof(menu_item_t));
		strcpy(menu->head->text, text);
		menu->head->action = (event_cb*)malloc(sizeof(event_cb));
		menu->head->action->cb = action;
		menu->head->action->data = data;
		menu->head->action->params = params;
		menu->head->next = NULL;
		menu->selected = menu->head;
	}
}

menu_t* menu_create(char text[50]) {
	menu_t* new_menu = (menu_t*)malloc(sizeof(menu_t));
	if (!new_menu) {
		return NULL;
	}

	strcpy_s(new_menu->name, text);
	new_menu->head = NULL;
	new_menu->selected = NULL;
	new_menu->prev_selected = NULL;
	new_menu->menu_state = REDRAW_ALL;
	return new_menu;
}

void menu_show(menu_t* menu) {
	COORD coord;
	coord.X = 1;
	size_t rows = 1;

	cci.dwSize = 1;
	cci.bVisible = FALSE;
	SetConsoleCursorInfo(hConsole, &cci);


	if (menu->menu_state == REDRAW_ALL) {
		system("cls");
		make_borders(menu->name);
		menu_item_t* current = menu->head;

		while (current != NULL) {
			coord.Y = rows++;
			SetConsoleCursorPosition(hConsole, coord);
			if (current == menu->selected)
				SetConsoleTextAttribute(hConsole, HIGHLIGHT_COLOR);

			printf("%s", current->text);
			if (current == menu->selected)
				SetConsoleTextAttribute(hConsole, DEFAULT_COLOR);
			current = current->next;
		}
		menu->menu_state = CONTINUE;
	}
	else if (menu->menu_state == REDRAW_SELECTED) {
		menu_item_t* current = menu->head;

		while (current != NULL) {
			coord.Y = rows++;
			SetConsoleCursorPosition(hConsole, coord);
			if (current == menu->selected || current == menu->prev_selected) {
				if (current == menu->selected)
					SetConsoleTextAttribute(hConsole, HIGHLIGHT_COLOR);

				printf("%s", current->text);
				if (current == menu->selected)
					SetConsoleTextAttribute(hConsole, DEFAULT_COLOR);
			}

			current = current->next;
		}
		menu->menu_state = CONTINUE;
	}
}

state menu_execute(void* data, void*) {
	menu_t* menu = (menu_t*)data;

	menu_show(menu);

	do {
		switch (get_code()) {
		case KEY_ENTER:
			if (menu->selected->action->cb) {
				menu->menu_state = menu->selected->action->cb(menu->selected->action->data, menu->selected->action->params);
			}
			break;
		case ARROW_UP:
			if (menu->head != menu->selected) {
				menu_item_t* current = menu->head;
				while (current->next != menu->selected) {
					current = current->next;
				}
				menu->prev_selected = menu->selected;
				menu->selected = current;
				menu->menu_state = REDRAW_SELECTED;
			}
			break;
		case ARROW_DOWN:
			if (menu->selected->next) {
				menu->prev_selected = menu->selected;
				menu->selected = menu->selected->next;
				menu->menu_state = REDRAW_SELECTED;
			}
			break;
		}
		menu_show(menu);
	} while (menu->menu_state);
	return REDRAW_ALL;
}

void menu_free(menu_t* menu) {
	if (menu->head) {
		menu_item_t* current = menu->head;
		menu_item_t* tmp;
		do {
			tmp = current;
			current = current->next;
			free(tmp->action);
			free(tmp);
		} while (current);
	}
	free(menu);
}

state exit_program(void* data, void*)
{
	system("cls");
	printf(Rus("Пока\n"));
	system("pause");
	exit(0);
}

state exit_sub(void* data, void*)
{
	return EXIT;
}

static int get_code(void) {
	int ch = _getch();

	if (ch == 0 || ch == 224)
		ch = 256 + _getch();

	return ch;
};