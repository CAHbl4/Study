#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <math.h>

/*
*
* amatu, 3/31/2016 9:03:43 PM
*/

#define HALT ""

enum keys {
	KEY_ENTER	= 13,
	KEY_ESC		= 27,
	ARROW_UP	= 256 + 72,
	ARROW_DOWN	= 256 + 80,
	ARROW_LEFT	= 256 + 75,
	ARROW_RIGHT = 256 + 77
};

enum state {
	EXIT,
	REDRAW,
	CONTINUE
};

enum datatypes {
	INTEGER,
	STRING
};

typedef state(*event_cb_t)(void *data, void* params);

struct event_cb {
	event_cb_t	cb;
	void		*data;
	void		*params;
};

typedef struct menu_item {
	char				text[50];
	struct event_cb*	action;
	struct menu_item*	next;
} menu_item_t;

typedef struct menu {
	char				name[50];
	struct menu_item*	head;
	struct menu_item*	selected;
	state				menu_state;
} menu_t;

typedef struct phonebook_item {
	size_t	id;
	char*	first_name;
	char*	last_name;
	char*	patronymic;
	char*	street;
	char*	bld;
	char*	ap;
	char*	phone;
} phonebook_item_t;

typedef struct table_column {
	char		text[50];
	void*		data_source;
	datatypes	data_type;
	size_t		min_width;
	size_t		max_width;
	size_t		print_width;
} table_column_t;

typedef struct table {
	table_column_t* columns;
	size_t			cols;
	size_t			rows;
	size_t			width;
} table_t;


state add_record		(void* data, void* param);
state add_test_records	(void* data, void* param);
state print_records		(void* data, void* param);
state do_work			(void* data, void* param);

char* get_random_first_name();
char* get_random_last_name();
char* get_random_patronymic();
char* get_random_street();

table_t*	table_create		(size_t width, size_t rows);
void		table_add_column	(table_t* table, char text[50], void* data_source, datatypes data_type, size_t min_width, size_t max_width);
void		table_print			(table_t* table, size_t screen_width);
size_t		table_column_width	(table_column_t* col, size_t rows);

state exit_program	(void* data, void* params);
state exit_sub		(void* data, void* params);

void	menu_add_item	(menu_t* menu, char text[50], event_cb_t action, void* data, void* params);
menu_t* menu_create		(char text[50]);
void	menu_show		(menu_t* menu);
state	menu_execute	(void* menu, void* params);
void	menu_free		(menu_t* menu);
int		get_code		(void);

char*	Rus		(const char* text);
char*	RusW	(const wchar_t* text);

__int64 read_int	(FILE* fp);
char*	read_string	(FILE* fp);
void	flush_stream(FILE* fp);

size_t	num_char_count	(__int64 num);
char*	int_to_str		(__int64 num);
int		get_rand		(int left, int right);

int main() {
	phonebook_item_t* phonebook = NULL;
	size_t count = 0;

	//Создаем меню
	menu_t* main_menu = menu_create(Rus("Главное меню"));

	if (!main_menu) {
		return 1;
	}

	//Добавляем пункты в меню
	menu_add_item(main_menu, Rus("Добавить запись"), &add_record, &phonebook, &count);
	menu_add_item(main_menu, Rus("Добавить тестовые записи"), &add_test_records, &phonebook, &count);
	menu_add_item(main_menu, Rus("Вывести записи"), &print_records, &phonebook, &count);
	menu_add_item(main_menu, Rus("Выполнить задание"), &do_work, &phonebook, &count);
	menu_add_item(main_menu, "Exit", &exit_program, NULL, NULL);

	//Выполняем меню
	menu_execute(main_menu, NULL);

	menu_free(main_menu);

	return 0;
}

//Функция формирует данные для таблицы и выводит данные на экран
state print_records(void* data, void* param)
{
	//Данные для вывода
	phonebook_item_t** phonebook = (phonebook_item_t**)data;
	size_t* count = (size_t*)param;

	size_t i;
	table_t* table = table_create(0, *count);

	//Выделяем память под колонки
	size_t* n			= (size_t*)calloc(*count, sizeof(size_t));
	char** last_names	= (char**) calloc(*count, sizeof(char**));
	char** first_names	= (char**) calloc(*count, sizeof(char**));
	char** patronymics	= (char**) calloc(*count, sizeof(char**));
	char** streets		= (char**) calloc(*count, sizeof(char**));
	char** blds			= (char**) calloc(*count, sizeof(char**));
	char** aps			= (char**) calloc(*count, sizeof(char**));
	char** phones		= (char**) calloc(*count, sizeof(char**));

	//Добавляем колонки в таблицу
	table_add_column(table, Rus("№"),		n,			INTEGER,0, 5);
	table_add_column(table, Rus("ФАМИЛИЯ"),	last_names, STRING, 5, 0);
	table_add_column(table, Rus("ИМЯ"),		first_names,STRING, 5, 0);
	table_add_column(table, Rus("ОТЧЕСТВО"),patronymics,STRING, 5, 0);
	table_add_column(table, Rus("УЛИЦА"),	streets,	STRING, 5, 0);
	table_add_column(table, Rus("ДОМ"),		blds,		STRING, 3, 6);
	table_add_column(table, Rus("КВ."),		aps,		STRING, 3, 6);
	table_add_column(table, Rus("ТЕЛЕФОН"), phones,		STRING, 6, 7);

	//Заполняем колонки данными
	for (i = 0; i < *count; ++i)
	{
		*(n + i)			= (*phonebook + i)->id;
		*(last_names + i)	= (*phonebook + i)->last_name;
		*(first_names + i)	= (*phonebook + i)->first_name;
		*(patronymics + i)	= (*phonebook + i)->patronymic;
		*(streets + i)		= (*phonebook + i)->street;
		*(blds + i)			= (*phonebook + i)->bld;
		*(aps + i)			= (*phonebook + i)->ap;
		*(phones + i)		= (*phonebook + i)->phone;
	}

	//Получаем ширину консоли
	size_t sreen_width;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	int ret;
	ret = GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	if (ret)
	{
		sreen_width = csbi.dwSize.X - 4;
	} else {
		sreen_width = 110;
	}

	//Выводим таблицу
	table_print(table, sreen_width);

	//Освобождаем память
	free(n);
	free(last_names);
	free(first_names);
	free(patronymics);
	free(streets);
	free(blds);
	free(aps);
	free(phones);
	free(table);

	system("pause");
	return REDRAW;
}


//Функция выполняет задание варианта 13
state do_work(void* data, void* param) {
	system("cls");
	printf(Rus("Задание варианта 13: Заменить адрес владельца телефона «651480» на адрес: улица «Пирогова», дом «4», квартира «17».\n"));
	phonebook_item_t** phonebook = (phonebook_item_t**)data;
	size_t* count = (size_t*)param;
	size_t i, changed = 0;

	for (i = 0; i < *count; ++i) {
		//Ищем в цикле совпадение по номеру
		if (!strcmp((*phonebook + i)->phone, "651480")) {
			//Выполняем замену
			(*phonebook + i)->street = (char*)realloc((*phonebook + i)->street, sizeof(char) * (strlen("Пирогова") + 1));
			strcpy((*phonebook + i)->street, Rus("Пирогова"));
			(*phonebook + i)->bld = (char*)realloc((*phonebook + i)->bld, sizeof(char) * (strlen("4") + 1));
			strcpy((*phonebook + i)->bld, "4");
			(*phonebook + i)->ap = (char*)realloc((*phonebook + i)->ap, sizeof(char) * (strlen("17") + 1));
			strcpy((*phonebook + i)->ap, "17");
			++changed;
		}
	}
	if (changed) {
		printf(Rus("Произведено замен: %d\n"), changed);
	} else {
		printf(Rus("Совпадений не найдено\n"));
	}
	system("pause");

	return REDRAW;
}


//Функция запрашивает данные с клавиатуры и сохранет их в массив
state add_record(void* data, void* param) {
	system("cls");
	phonebook_item_t** phonebook = (phonebook_item_t**)data;
	size_t* count = (size_t*)param;

	*phonebook = (phonebook_item_t*)realloc(*phonebook, sizeof(phonebook_item_t) * (*count + 1));

	(*phonebook + *count)->id = (*count ? (*phonebook + *count - 1)->id + 1 : 1);

	printf(Rus("Введите фамилию: "));
	(*phonebook + *count)->last_name = read_string(stdin);

	printf(Rus("Введите имя: "));
	(*phonebook + *count)->first_name = read_string(stdin);

	printf(Rus("Введите отчество: "));
	(*phonebook + *count)->patronymic = read_string(stdin);

	printf(Rus("Введите улицу: "));
	(*phonebook + *count)->street= read_string(stdin);

	printf(Rus("Введите номер дома: "));
	(*phonebook + *count)->bld = read_string(stdin);

	printf(Rus("Введите номер квартиры: "));
	(*phonebook + *count)->ap = read_string(stdin);

	printf(Rus("Введите телефон: "));
	(*phonebook + *count)->phone = read_string(stdin);

	++*count;
	return REDRAW;
}

//Функция заполняет массив тестовыми данными
state add_test_records(void* data, void* param) {
	system("cls");
	phonebook_item_t** phonebook = (phonebook_item_t**)data;
	size_t* count = (size_t*)param;
	size_t add_count, i;

	printf(Rus("Сколько записей добавить: "));
	add_count = (size_t)read_int(stdin);

	*phonebook = (phonebook_item_t*)realloc(*phonebook, sizeof(phonebook_item_t) * (*count + add_count));

	for (i = 0; i < add_count; ++i) {			//Заполняем случайными значениями элемент массива
		(*phonebook + *count)->id = (*count ? (*phonebook + *count - 1)->id + 1 : 1);
		(*phonebook + *count)->last_name = get_random_last_name();
		(*phonebook + *count)->first_name = get_random_first_name();
		(*phonebook + *count)->patronymic = get_random_patronymic();
		(*phonebook + *count)->street = get_random_street();
		(*phonebook + *count)->bld = int_to_str(get_rand(0, 300));
		(*phonebook + *count)->ap = int_to_str(get_rand(0, 150));
		(*phonebook + *count)->phone = int_to_str(get_rand(111111, 999999));
		++*count;
	}

	return REDRAW;
}


//Функция возвращает случайное имя из списка
char* get_random_first_name() {
	static const char* names[] = { "Александр", "Алексей", "Виктор", "Михаил", "Иван"};
	size_t count = 5;
	size_t i = rand() % count;
	char* result = (char*)malloc(sizeof(char) * strlen(names[i]));
	strcpy(result, Rus(names[i]));
	return result;
}


//Функция возвращает случайную фамилию из списка
char* get_random_last_name() {
	static const char* names[] = { "Иванов", "Пржевальский", "Пушкин", "Лермонтов", "Сидоров" };
	size_t count = 5;
	size_t i = rand() % count;
	char* result = (char*)malloc(sizeof(char) * strlen(names[i]));
	strcpy(result, Rus(names[i]));
	return result;
}


//Функция возвращает случайное отчество из списка
char* get_random_patronymic() {
	static const char* names[] = { "Петрович", "Александрович", "Ильич", "Иванович", "Николаевич" };
	size_t count = 5;
	size_t i = rand() % count;
	char* result = (char*)malloc(sizeof(char) * strlen(names[i]));
	strcpy(result, Rus(names[i]));
	return result;
}


//Функция возвращает случайную улицу из списка
char* get_random_street() {
	static const char* names[] = { "Советская", "Интернациональная", "Лесная", "Царская", "Рабочая" };
	size_t count = 5;
	size_t i = rand() % count;
	char* result = (char*)malloc(sizeof(char) * strlen(names[i]));
	strcpy(result, Rus(names[i]));
	return result;
}


//Функция создает и инициализирует таблицу и возвращает указатель на нее
table_t* table_create(size_t width, size_t rows) {
	table_t* new_table = (table_t*)malloc(sizeof(table_t));
	if (!new_table) {
		return NULL;
	}

	new_table->columns = NULL;
	new_table->cols = 0;
	new_table->width = width;
	new_table->rows = rows;
	return new_table;
}


//Функция добавляет колонку в таблицу
void table_add_column(table_t* table, char text[50], void* data_source, datatypes data_type, size_t min_width, size_t max_width) {
	table->columns = (table_column_t*)realloc(table->columns, sizeof(table_column_t) * (table->cols + 1));
	strcpy((table->columns + table->cols)->text, text);
	(table->columns + table->cols)->data_source = data_source;
	(table->columns + table->cols)->data_type = data_type;
	(table->columns + table->cols)->min_width = min_width;
	(table->columns + table->cols)->max_width = max_width;
	(table->columns + table->cols)->print_width = min_width;
	++table->cols;
}


//Функция выводит таблицу на экран
void table_print(table_t* table, size_t screen_width) {
	system("cls");
	size_t table_width = 1;
	size_t width, i, j;

	//Высчитываем итоговую ширину таблицы
	for (i = 0; i < table->cols; ++i) {
		width = table_column_width(table->columns + i, table->rows);
		if ((table->columns + i)->max_width && width > (table->columns + i)->max_width) {
			(table->columns + i)->print_width = (table->columns + i)->max_width;
		}
		else if (width > (table->columns + i)->min_width) {
			(table->columns + i)->print_width = width;
		}
		table_width += (table->columns + i)->print_width + 1;
	}

	//Если задана фиксированная ширина таблицы
	if (table->width) {
		//Пока итоговая ширина меньше фиксированной наращиваем размер колонок
		while (table_width < table->width) {
			for (i = 0; i < table->cols; ++i) {
				if ((table->columns + i)->data_type == STRING) {
					if (!(table->columns + i)->max_width ||
						(table->columns + i)->print_width < (table->columns + i)->max_width) {
						++(table->columns + i)->print_width;
						++table_width;
					}
					if (table_width == table->width)
						break;
				}
			}
		}

		size_t resize;
		//Пока итоговая ширина больше фиксированной уменьшаем размер колонок
		while (table_width > table->width) {
			resize = 0;
			for (i = 0; i < table->cols; ++i) {
				if ((table->columns + i)->data_type == STRING) {
					if ((table->columns + i)->print_width >(table->columns + i)->min_width) {
						--(table->columns + i)->print_width;
						--table_width;
					}
					if (table_width == table->width)
						break;
					resize += (table->columns + i)->print_width - (table->columns + i)->min_width;
				}
			}
			//Если доступных колонок для уменьшения нет прерываем цикл
			if (!resize)
				break;
		}
	}

	//Если ширина таблицы не задана
	if(!table->width) {
		while(table_width < screen_width) { //Наращиваем ширину колонок пока итоговая ширина не достигнет ширины экрана
			for (i = 0; i < table->cols; ++i) {
				if(!(table->columns + i)->max_width ||
					(table->columns + i)->print_width < (table->columns + i)->max_width) {
					++(table->columns + i)->print_width;
					++table_width;
				}
			}
		}
	}

	printf(RusW(L"╔"));
	for (i = 0; i < table->cols; ++i) {
		for (j = 0; j < (table->columns + i)->print_width; ++j) {
			printf(RusW(L"═"));
		}
		if (i + 1 == table->cols) {
			printf(RusW(L"╗\n"));
		}
		else {
			printf(RusW(L"╤"));
		}
	}

	printf(RusW(L"║"));
	for (i = 0; i < table->cols; ++i) {
		printf("%-*.*s", (table->columns + i)->print_width, (table->columns + i)->print_width, (table->columns + i)->text);

		if (i + 1 == table->cols) {
			printf(RusW(L"║\n"));
		}
		else {
			printf(RusW(L"│"));
		}
	}

	printf(RusW(L"╠"));
	for (i = 0; i < table->cols; ++i) {
		for (j = 0; j < (table->columns + i)->print_width; ++j) {
			printf(RusW(L"═"));
		}
		if (i + 1 == table->cols) {
			printf(RusW(L"╣\n"));
		}
		else {
			printf(RusW(L"╪"));
		}
	}

	for (j = 0; j < table->rows; ++j) {
		printf(RusW(L"║"));
		for (i = 0; i < table->cols; ++i) {
			if ((table->columns + i)->data_type == INTEGER) {
				printf("%*d",
					(table->columns + i)->print_width,
					*((int*)(table->columns + i)->data_source + j)
					);
			}

			if ((table->columns + i)->data_type == STRING) {
				printf("%-*.*s",
					(table->columns + i)->print_width,
					(table->columns + i)->print_width,
					*((char**)(table->columns + i)->data_source + j)
					);
			}

			if (i + 1 == table->cols) {
				printf(RusW(L"║\n"));
			}
			else {
				printf(RusW(L"│"));
			}
		}
	}

	printf(RusW(L"╚"));
	for (i = 0; i < table->cols; ++i) {
		for (j = 0; j < (table->columns + i)->print_width; ++j) {
			printf(RusW(L"═"));
		}
		if (i + 1 == table->cols) {
			printf(RusW(L"╝\n"));
		}
		else {
			printf(RusW(L"╧"));
		}
	}
}

size_t table_column_width(table_column_t* col, size_t rows) {
	size_t i, max_width = 0, width;
	switch (col->data_type)
	{
	case INTEGER:
		for (i = 0; i < rows; ++i) {
			width = num_char_count(*((int*)col->data_source + i));
			if (width > max_width) {
				max_width = width;
			}
		}
		break;
	case STRING:
		for (i = 0; i < rows; ++i) {
			width = strlen(*((char**)col->data_source + i));
			if (width > max_width) {
				max_width = width;
			}
		}
		break;
	default:
		break;
	}
	return max_width;
}

state exit_program(void*, void*)
{
	system("cls");
	printf(Rus("Пока\n"));
	system("pause");
	exit(0);
}

state exit_sub(void*, void*)
{
	return EXIT;
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
	new_menu->menu_state = REDRAW;
	return new_menu;
}

void menu_show(menu_t* menu) {
	if (menu->menu_state == REDRAW) {
		system("cls");
		printf("===%s===\n", menu->name);
		menu_item_t* current = menu->head;

		while (current != NULL) {
			if (current == menu->selected)
				printf("[");
			else
				printf(" ");
			printf("%s", current->text);
			if (current == menu->selected)
				printf("]\n");
			else
				printf("\n");
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
				menu->selected = current;
				menu->menu_state = REDRAW;
			}
			break;
		case ARROW_DOWN:
			if (menu->selected->next) {
				menu->selected = menu->selected->next;
				menu->menu_state = REDRAW;
			}
			break;
		}
		menu_show(menu);
	} while (menu->menu_state);
	return REDRAW;
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

static int get_code(void) {
	int ch = _getch();

	if (ch == 0 || ch == 224)
		ch = 256 + _getch();

	return ch;
}

char bufRus[256];

char* Rus(const char* text) {
	CharToOemA(text, bufRus);
	return bufRus;
}

char* RusW(const wchar_t* text) {
	CharToOemW(text, bufRus);
	return bufRus;
}

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


__int64 read_int(FILE* fp) {
	__int64 n = 0;
	__int8 result;
	char ch;
	do {
		result = fscanf(fp, "%lld", &n);
		if (result == EOF) {
			fprintf(stderr, "Unexpected EOF\n");
			exit(74);
		}
		if (result == 0) {
			do {
				ch = fgetc(fp);
			} while (ch <= '0' && ch >= '9');
			fprintf(stderr, "Incorrect symbol\n");
		}
	} while (!result);

	flush_stream(fp);

	return n;
}

void flush_stream(FILE* fp) {
	fseek(fp, 0, SEEK_END);
}

size_t num_char_count(__int64 num)
{
	size_t count = 1;
	if (num)
	{
		count = (size_t)(floorl(log10((double)llabs(num))) + 1);
		if (num < 0)
			++count;
	}
	return count;
}

char* int_to_str(__int64 num)
{
	size_t length = num_char_count(num) - 1;
	char* str = (char*)calloc(length + 2, sizeof(char));
	if (num < 0)
		*str = '-';
	if (!num)
		*str = '0';

	num = llabs(num);
	while (num)
	{
		*(str + length--) = '0' + num % 10;
		num /= 10;
	}
	return str;
}

int get_rand(int left, int right) {
	return rand() * rand() % (right - left + 1) + left;
}