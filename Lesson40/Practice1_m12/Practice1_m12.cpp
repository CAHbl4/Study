#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h>
#include <conio.h>

/*
*
* amatu, 4/16/2016 1:28:56 PM
*/

#define CONSOLE_WIDTH	120
#define CONSOLE_HEIGTH	25

#define ITEMS_DB_F		"items.db"
#define	LIST_F			"list"

#define HALT ""

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

enum state {
	EXIT,
	REDRAW_ALL,
	REDRAW_SELECTED,
	CONTINUE
};

enum data_types {
	_INTEGER,
	_FLOAT,
	_STRING
};

enum field_types {
	INPUTFIELD,
	CHECKBOX,
	RADIO,
	SEPARATOR
};

typedef state(*event_cb_t)(void *data, void* params);

struct event_cb {
	event_cb_t	cb;
	void		*data;
	void		*params;
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

typedef struct table_column {
	char		text[80];
	void*		data_source;
	data_types	data_type;
	size_t		min_width;
	size_t		max_width;
	size_t		print_width;
} table_column_t;

typedef struct table {
	char			name[50];
	table_column_t* columns;
	size_t			cols;
	size_t			rows;
	size_t			width;
} table_t;

table_t*table_create(size_t width, size_t rows, char name[50]);
void	table_add_column(table_t* table, char text[50], void* data_source, data_types data_type, size_t min_width, size_t max_width);
void	table_print(table_t* table, size_t screen_width);
size_t	table_column_width(table_column_t* col, size_t rows);

state	exit_program(void* data, void* params);
state	exit_sub(void* data, void* params);

void	menu_add_item(menu_t* menu, char text[50], event_cb_t action, void* data, void* params);
menu_t* menu_create(char text[50]);
void	menu_show(menu_t* menu);
state	menu_execute(void* menu, void* params);
void	menu_free(menu_t* menu);

int		get_code(void);

char*	Rus(const char* text);
char*	RusW(const wchar_t* text);

__int64 read_int(FILE* fp);
char*	read_string(FILE* fp);
void	flush_stream(FILE* fp);

size_t	num_char_count(__int64 num);
char*	int_to_str(__int64 num);
int		get_rand(int left, int right);
__int64 _llabs(__int64 x);
__int64 str_to_int(const char* str);
__int8	is_digit(char ch);
__int64 pow(__int64 base, __int64 exp);
int*	parse_ints(int* nums, char* str, int* count);
__int8	is_valid_char(int ch);

void	set_console_size(size_t x, size_t y);
void	make_borders(char* text);

//Переменные для настройки консоли
HANDLE	hConsole;
CONSOLE_SCREEN_BUFFER_INFO csbi;
CONSOLE_CURSOR_INFO cci;

#define HIGHLIGHT_COLOR		BACKGROUND_GREEN	| BACKGROUND_BLUE	| 0
#define DEFAULT_COLOR		BACKGROUND_BLUE | FOREGROUND_BLUE	| FOREGROUND_GREEN	| FOREGROUND_RED	| FOREGROUND_INTENSITY


typedef struct item {
	size_t id;
	char name[30];
	char model[10];
	float price;
} item_t;

typedef struct record {
	size_t id;
	char department[20];
	size_t item_id;
	int count;
	char mark_del;
} record_t;

typedef struct items_db {
	item_t* items;
	size_t count;
} items_db_t;

typedef struct list {
	record_t* records;
	size_t count;
} list_t;

state add_record(void* data, void* params);
state add_test_records(void* data, void* params);
state add_test_items(void* data, void* params);

size_t get_random_item(items_db_t* items_db);

state print_records(void* data, void* params);
state read_files(void* data, void* params);
state save_files(void* data, void* params);

item_t* get_item_by_id(size_t id, items_db_t* items_db);

list_t list = { NULL, 0 };
items_db_t items_db = { NULL, 0 };

int main() {
	//Сохраняем текущие параметры консоли
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, DEFAULT_COLOR);

	//Создаем меню
	menu_t* main_menu = menu_create("Главное меню");

	//Добавляем пункты в меню
	menu_add_item(main_menu, Rus("Добавить запись"), &add_record, &list, NULL);
	menu_add_item(main_menu, Rus("Добавить тестовые записи в базу оборудования"), &add_test_items, &items_db, NULL);
	menu_add_item(main_menu, Rus("Добавить тестовые записи в список оборудования в цехах"), &add_test_records, &list, &items_db);
	menu_add_item(main_menu, Rus("Вывести список оборудования"), &print_records, &list, "Cписок оборудования");
	menu_add_item(main_menu, Rus("Сохранить БД"), &save_files, NULL, NULL);
	menu_add_item(main_menu, Rus("Прочитать БД"), &read_files, NULL, NULL);


	menu_add_item(main_menu, "Exit", &exit_program, NULL, NULL);

	//Выполняем меню
	menu_execute(main_menu, NULL);


	menu_free(main_menu);

	return 0;
}

item_t* get_item_by_id(size_t id, items_db_t* items_db)
{
	size_t i;
	for(i = 0; i < items_db->count; ++i)
	{
		if (items_db->items[i].id == id)
		{
			return &items_db->items[i];
		}
	}
	return NULL;
}

state read_files(void*, void*)
{
	list.count = 0;
	items_db.count = 0;

	FILE * list_f = fopen(LIST_F, "r");
	FILE * items_db_f = fopen(ITEMS_DB_F, "r");


	items_db.items = (item_t*)realloc(items_db.items, sizeof(item_t) * (items_db.count + 1));
	list.records = (record_t*)realloc(list.records, sizeof(record_t) * (list.count + 1));

	while (fread(&items_db.items[items_db.count], sizeof(item_t), 1, items_db_f))
	{
		++items_db.count;
		items_db.items = (item_t*)realloc(items_db.items, sizeof(item_t) * (items_db.count + 1));
	}

	while (fread(&list.records[list.count], sizeof(record_t), 1, list_f))
	{
		++list.count;
		list.records = (record_t*)realloc(list.records, sizeof(record_t) * (list.count + 1));
	}

	list.records = (record_t*)realloc(list.records, sizeof(record_t) * list.count);
	items_db.items = (item_t*)realloc(items_db.items, sizeof(item_t) * items_db.count);

	fclose(list_f);
	fclose(items_db_f);
	return CONTINUE;
}

state save_files(void*, void*)
{

	FILE * list_f = fopen(LIST_F, "w");
	FILE * items_db_f = fopen(ITEMS_DB_F, "w");

	fwrite(list.records, sizeof(record_t), list.count, list_f);
	fwrite(items_db.items, sizeof(item_t), items_db.count, items_db_f);
	
	fclose(list_f);
	fclose(items_db_f);

	return CONTINUE;
}

//Функция формирует данные для таблицы и выводит данные на экран
state print_records(void* data, void* params)
{
	//Данные для вывода
	list_t* list = (list_t*)data;
	char* name = (char*)params;

	size_t i;
	table_t* table = table_create(0, list->count, name);

	//Выделяем память под колонки
	size_t* n = (size_t*)calloc(list->count, sizeof(size_t));
	char** department = (char**)calloc(list->count, sizeof(char**));
	char** item_name = (char**)calloc(list->count, sizeof(char**));
	char** item_model = (char**)calloc(list->count, sizeof(char**));
	float*	item_price = (float*)calloc(list->count, sizeof(float));
	int*	count = (int*)calloc(list->count, sizeof(int));


	//Добавляем колонки в таблицу
	table_add_column(table, Rus("№"), n, _INTEGER, 0, 5);
	table_add_column(table, Rus("ЦЕХ"), department, _STRING, 5, 0);
	table_add_column(table, Rus("НАИМЕНОВАНИЕ"), item_name, _STRING, 5, 0);
	table_add_column(table, Rus("МОДЕЛЬ"), item_model, _STRING, 5, 0);
	table_add_column(table, Rus("ЦЕНА"), item_price, _FLOAT, 5, 0);
	table_add_column(table, Rus("КОЛИЧЕСТВО"), count, _INTEGER, 5, 0);

	//Заполняем колонки данными
	for (i = 0; i < list->count; ++i)
	{
		*(n + i) = list->records[i].id;
		*(department + i) = list->records[i].department;
		*(item_name + i) = get_item_by_id(list->records[i].item_id, &items_db)->name;
		*(item_model + i) = get_item_by_id(list->records[i].item_id, &items_db)->model;
		*(item_price + i) = get_item_by_id(list->records[i].item_id, &items_db)->price;
		*(count + i) = list->records[i].count;
		
	}

	//Выводим таблицу
	table_print(table, CONSOLE_WIDTH - 5);

	//Освобождаем память
	free(n);
	free(department);
	free(item_name);
	free(item_model);
	free(item_price);
	free(table);

	system("pause");
	return REDRAW_ALL;
}

state add_test_items(void*, void*)
{
	system("cls");
	size_t add_count, i, j;

	static const char* names[] = { "Перфоратор", "Дрель", "Лобзик", "Шуроповерт", "Циркулярная пила" };
	static const char* model[] = { "ПФ-", "ДР-", "ЛБ-", "ШВ-", "ЦП-" };
	size_t count = 5;

	printf(Rus("Сколько записей добавить: "));
	add_count = read_int(stdin);

	items_db.items = (item_t*)realloc(items_db.items, sizeof(item_t) * (items_db.count + add_count));

	for (i = 0; i < add_count; ++i) {			//Заполняем случайными значениями элемент массива
		j = rand() % count;
		items_db.items[items_db.count].id = items_db.count ? items_db.items[items_db.count - 1].id + 1 : 1;
		strcpy(items_db.items[items_db.count].name, Rus(names[j]));
		strcpy(items_db.items[items_db.count].model, Rus(model[j]));
		strcat(items_db.items[items_db.count].model, int_to_str(get_rand(1, 900)));
		items_db.items[items_db.count].price = (float)get_rand(0, 100) + (float)get_rand(0, 99) / 100;
		++items_db.count;
	}

	return REDRAW_ALL;
}

state add_test_records(void*, void*) {
	system("cls");
	size_t add_count, i, j;
	static const char* names[] = { "Слесарный", "Инструментальный", "Первый", "Второй", "Третий" };
	size_t count = 5;

	printf(Rus("Сколько записей добавить: "));
	add_count = read_int(stdin);

	list.records = (record_t*)realloc(list.records, sizeof(record_t) * (list.count + add_count));

	for (i = 0; i < add_count; ++i) {			//Заполняем случайными значениями элемент массива
		j = rand() % count;
		list.records[list.count].id = list.count ? list.records[list.count - 1].id + 1 : 1;
		strcpy(list.records[list.count].department, Rus(names[j]));
		list.records[list.count].item_id = get_random_item(&items_db);
		list.records[list.count].count = get_rand(0, 10);
		++list.count;
	}

	return REDRAW_ALL;
}


size_t get_random_item(items_db_t* items_db)
{
	return items_db->items[rand() % items_db->count].id;
}

state add_record(void* data, void* params)
{
	return CONTINUE;
}

void set_console_size(size_t x, size_t y) {
	char command[20] = { 0 };
	strcat(command, "mode ");
	strcat(command, int_to_str(x));
	strcat(command, ", ");
	strcat(command, int_to_str(y));
	system(command);
}

//Функция создает и инициализирует таблицу и возвращает указатель на нее
table_t* table_create(size_t width, size_t rows, char name[50]) {
	table_t* new_table = (table_t*)malloc(sizeof(table_t));
	if (!new_table) {
		return NULL;
	}

	strcpy(new_table->name, name);
	new_table->columns = NULL;
	new_table->cols = 0;
	new_table->width = width;
	new_table->rows = rows;
	return new_table;
}


//Функция добавляет колонку в таблицу
void table_add_column(table_t* table, char text[50], void* data_source, data_types data_type, size_t min_width, size_t max_width) {
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
	size_t width, i, j, tmp;

	//Высчитываем итоговую ширину таблицы
	for (i = 0; i < table->cols; ++i) {
		width = table_column_width(table->columns + i, table->rows);
		if ((table->columns + i)->max_width && width >(table->columns + i)->max_width) {
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
				if ((table->columns + i)->data_type == _STRING) {
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
				if ((table->columns + i)->data_type == _STRING) {
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
	if (!table->width) {
		while (table_width < screen_width) { //Наращиваем ширину колонок пока итоговая ширина не достигнет ширины экрана
			for (i = 0; i < table->cols; ++i) {
				if (!(table->columns + i)->max_width ||
					(table->columns + i)->print_width < (table->columns + i)->max_width) {
					++(table->columns + i)->print_width;
					++table_width;
				}
			}
		}
	}

	//Верхняя граница "╔════════════════════╗"
	printf(RusW(L"╔"));
	for (i = 0; i < table_width - 2; ++i) {
		printf(RusW(L"═"));
	}
	printf(RusW(L"╗\n"));

	//Заголовок таблицы "║     Заголовок      ║"
	printf(RusW(L"║"));
	tmp = (table_width - 2) / 2 - strlen(table->name) / 2;
	for (i = 0; i < tmp - 2; ++i) {
		printf(" ");
	}
	printf(Rus(table->name));
	for (i = tmp + strlen(table->name); i < table_width; ++i) {
		printf(" ");
	}
	printf(RusW(L"║\n"));

	//Граница между заголовком таблицы и именами колонок "╠═══╤══════╤═════════╣"
	printf(RusW(L"╠"));
	for (i = 0; i < table->cols; ++i) {
		for (j = 0; j < (table->columns + i)->print_width; ++j) {
			printf(RusW(L"═"));
		}
		if (i + 1 == table->cols) {
			printf(RusW(L"╣\n"));
		}
		else {
			printf(RusW(L"╤"));
		}
	}

	//Имена колонок "║ № │ Имя │ Фамилия ║"
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

	//Граница между именами колонок и содержимым "╠═══╪══════╪═════════╣"
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

	//Содержимое колонок "║ 1 │Иван  │Иванов   ║"
	for (j = 0; j < table->rows; ++j) {
		printf(RusW(L"║"));
		for (i = 0; i < table->cols; ++i) {
			if ((table->columns + i)->data_type == _INTEGER) {
				printf("%*d",
					(table->columns + i)->print_width,
					*((int*)(table->columns + i)->data_source + j)
					);
			}

			if ((table->columns + i)->data_type == _FLOAT) {
				printf("%*.2f",
					(table->columns + i)->print_width,
					*((float*)(table->columns + i)->data_source + j)
					);
			}


			if ((table->columns + i)->data_type == _STRING) {
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

	//Нижняя граница "╚═══╧══════╧═════════╝"
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
	case _INTEGER:
		for (i = 0; i < rows; ++i) {
			width = num_char_count(*((int*)col->data_source + i));
			if (width > max_width) {
				max_width = width;
			}
		}
		break;
	case _STRING:
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

void make_borders(char* text) {
	size_t i, j, tmp;

	printf(RusW(L"╔"));
	tmp = CONSOLE_WIDTH / 2 - strlen(text) / 2;
	for (i = 0; i < tmp - 3; ++i) {
		printf(RusW(L"═"));
	}
	printf(Rus(text));
	for (i = tmp + strlen(text); i < CONSOLE_WIDTH; ++i) {
		printf(RusW(L"═"));
	}
	printf(RusW(L"╗\n"));

	for (i = 0; i < CONSOLE_HEIGTH - 3; ++i) {
		printf(RusW(L"║"));
		for (j = 0; j < CONSOLE_WIDTH - 3; ++j) {
			printf(" ");
		}
		printf(RusW(L"║\n"));
	}

	printf(RusW(L"╚"));
	for (j = 0; j < CONSOLE_WIDTH - 3; ++j) {
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

	cci.dwSize = 1;
	cci.bVisible = FALSE;
	SetConsoleCursorInfo(hConsole, &cci);

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
	size_t count = 0;
	if (num < 0)
		++count;
	do {
		++count;
		num /= 10;
	} while (num);
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

__int64 _llabs(__int64 x) {
	return x < 0 ? x * -1 : x;
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
int* parse_ints(int* nums, char* str, int* count)
{
	int in_num = 0;
	int alloc = *count + 5;
	char tmp_c[20];
	int n = 0, i;
	nums = (int*)realloc(nums, sizeof(int) * alloc);
	for (i = 0; i < (int)strlen(str) + 1; ++i)
	{
		if (!is_digit(*(str + i)))
		{
			if (in_num)
			{
				tmp_c[n] = '\0';
				if (*count == alloc)
					nums = (int*)realloc(nums, sizeof(int) * (alloc += 5));
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

	return (int*)realloc(nums, sizeof(int) * *count);
}

__int8 is_digit(char ch)
{
	return (ch >= '0' && ch <= '9');
}

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

__int8 is_valid_char(int ch)
{
	return ch >= 32 && ch <= 126 || ch >= 128 && ch <= 254;
}