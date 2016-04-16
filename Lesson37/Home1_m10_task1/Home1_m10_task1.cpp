#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h>
#include <conio.h>

/*
*
* amatu, 4/16/2016 1:28:56 PM
*/


#define HALT ""

enum keys {
	KEY_ENTER = 13,
	KEY_ESC = 27,
	ARROW_UP = 256 + 72,
	ARROW_DOWN = 256 + 80,
	ARROW_LEFT = 256 + 75,
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

typedef struct student {
	size_t	id;
	char*	last_name;
	char*	group;
	int		marks[5];
} student_t;

typedef struct journal {
	student_t**	records;
	size_t count;
} journal_t;

typedef struct table_column {
	char		text[50];
	void*		data_source;
	datatypes	data_type;
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


state add_record(void* data, void* param);
state add_test_records(void* data, void* param);
state print_records(void* data, void* param);
state print_bests(void* data, void* param);
state print_bads(void* data, void* param);


char* marks_to_str(int marks[5]);

char* get_random_last_name();
char* get_random_group();

table_t*	table_create(size_t width, size_t rows, char name[50]);
void		table_add_column(table_t* table, char text[50], void* data_source, datatypes data_type, size_t min_width, size_t max_width);
void		table_print(table_t* table, size_t screen_width);
size_t		table_column_width(table_column_t* col, size_t rows);

state exit_program(void* data, void* params);
state exit_sub(void* data, void* params);

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
__int8 is_digit(char ch);
__int64 pow(__int64 base, __int64 exp);
int* parse_ints(int* nums, char* str, int* count);

int main() {
	journal_t journal;
	journal.records = NULL;
	journal.count = 0;

	//Создаем меню
	menu_t* main_menu = menu_create(Rus("Главное меню"));

	if (!main_menu) {
		return 1;
	}

	//Добавляем пункты в меню
	menu_add_item(main_menu, Rus("Добавить запись"), &add_record, &journal, NULL);
	menu_add_item(main_menu, Rus("Добавить тестовые записи"), &add_test_records, &journal, NULL);
	menu_add_item(main_menu, Rus("Вывести все записи"), &print_records, &journal, "Список студентов");
	menu_add_item(main_menu, Rus("Вывести список отличников"), &print_bests, &journal, "Список отличников");
	menu_add_item(main_menu, Rus("Вывести список двоечников"), &print_bads, &journal, "Список двоечников");

	menu_add_item(main_menu, "Exit", &exit_program, NULL, NULL);

	//Выполняем меню
	menu_execute(main_menu, NULL);

	menu_free(main_menu);

	return 0;
}

state print_bests(void* data, void* param) {
	journal_t* journal = (journal_t*)data;
	char* name = (char*)param;
	journal_t bests;
	bests.records = NULL;
	bests.count = NULL;

	size_t i, j, fives_count;
	for(i = 0; i < journal->count; ++i){
		fives_count = 0;
		for(j = 0; j < 5; ++j) {
			if (journal->records[i]->marks[j] < 4) {
				break;
			}
			if (journal->records[i]->marks[j] == 5) {
				++fives_count;
			}
		}
		if (j == 5) {
			if (100/5 * fives_count > 75) {
				bests.records = (student_t**)realloc(bests.records, sizeof(student_t*) * (bests.count + 1));
				bests.records[bests.count] = journal->records[i];
				++bests.count;
			}
		}
	}
	print_records(&bests, &name);
	free(bests.records);
	return REDRAW;
}

state print_bads(void* data, void* param) {
	journal_t* journal = (journal_t*)data;
	char* name = (char*)param;
	journal_t bads;
	bads.records = NULL;
	bads.count = NULL;

	size_t i, j, bads_count;
	for (i = 0; i < journal->count; ++i) {
		bads_count = 0;
		for (j = 0; j < 5; ++j) {
			if (journal->records[i]->marks[j] < 4) {
				++bads_count;
			}
		}
		if (100 / 5 * bads_count > 50) {
			bads.records = (student_t**)realloc(bads.records, sizeof(student_t*) * (bads.count + 1));
			bads.records[bads.count] = journal->records[i];
			++bads.count;
		}
	}
	print_records(&bads, &name);
	free(bads.records);
	return REDRAW;
}

//Функция формирует данные для таблицы и выводит данные на экран
state print_records(void* data, void* param)
{
	//Данные для вывода
	journal_t* journal = (journal_t*)data;
	char* name = (char*)param;

	size_t i;
	table_t* table = table_create(0, journal->count, name);

	//Выделяем память под колонки
	size_t* n = (size_t*)calloc(journal->count, sizeof(size_t));
	char** last_names = (char**)calloc(journal->count, sizeof(char**));
	char** groups = (char**)calloc(journal->count, sizeof(char**));
	char** marks = (char**)calloc(journal->count, sizeof(char**));
	

	//Добавляем колонки в таблицу
	table_add_column(table, Rus("№"), n, INTEGER, 0, 5);
	table_add_column(table, Rus("ФАМИЛИЯ"), last_names, STRING, 5, 0);
	table_add_column(table, Rus("ГРУППА"), groups, STRING, 5, 0);
	table_add_column(table, Rus("ОЦЕНКИ"), marks, STRING, 5, 0);

	//Заполняем колонки данными
	for (i = 0; i < journal->count; ++i)
	{
		*(n + i) = journal->records[i]->id;
		*(last_names + i) = journal->records[i]->last_name;
		*(groups + i) = journal->records[i]->group;
		*(marks + i) = marks_to_str(journal->records[i]->marks);
	}

	//Получаем ширину консоли
	size_t sreen_width;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	int ret;
	ret = GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	if (ret)
	{
		sreen_width = csbi.dwSize.X - 4;
	}
	else {
		sreen_width = 110;
	}

	//Выводим таблицу
	table_print(table, sreen_width);

	//Освобождаем память
	free(n);
	free(last_names);
	free(groups);
	free(marks);
	free(table);

	system("pause");
	return REDRAW;
}

char* marks_to_str(int marks[5]) {
	char* tmp;
	size_t i, length = 1;;
	char* str = (char*)calloc(length, sizeof(char));

	for (i = 0; i < 5; ++i) {
		tmp = int_to_str(marks[i]);
		length += strlen(tmp);
		str = (char*)realloc(str, sizeof(char) * length);
		strcat(str, tmp);
		if (i != 4) {
			++length;
			str = (char*)realloc(str, sizeof(char) * length);
			strcat(str, " ");
		}
		free(tmp);
	}
	return str;
}

//Функция запрашивает данные с клавиатуры и сохранет их в массив
state add_record(void* data, void* param) {
	system("cls");
	journal_t* journal = (journal_t*)data;

	journal->records = (student_t**)realloc(journal->records, sizeof(student_t*) * (journal->count + 1));
	journal->records[journal->count] = (student_t*)calloc(1, sizeof(student_t));
	
	journal->records[journal->count]->id = journal->count ? journal->records[journal->count - 1]->id + 1 : 1;

	printf(Rus("Введите фамилию: "));
	journal->records[journal->count]->last_name = read_string(stdin);

	printf(Rus("Введите группу: "));
	journal->records[journal->count]->group = read_string(stdin);

	printf(Rus("Введите 5 оценок от 1 до 5, сохранены будут только 5 оценок: "));
	size_t i, j = 0;
	int* tmp_int = NULL, count = 0;
	char* tmp_str;
	do {
		tmp_str = read_string(stdin);
		tmp_int = parse_ints(tmp_int, tmp_str, &count);
		for (i = 0; i < count; ++i) {
			if (tmp_int[i] >= 1 && tmp_int[i] <= 5) {
				journal->records[journal->count]->marks[j++] = tmp_int[i];
			}
			if (j == 5) {
				break;
			}
		}
		free(tmp_str);
		free(tmp_int);
		tmp_int = NULL;
		count = 0;

	} while (j < 5);

	++journal->count;
	return REDRAW;
}

//Функция заполняет массив тестовыми данными
state add_test_records(void* data, void* param) {
	system("cls");
	journal_t* journal = (journal_t*)data;
	size_t add_count, i, j;

	printf(Rus("Сколько записей добавить: "));
	add_count = (size_t)read_int(stdin);

	journal->records = (student_t**)realloc(journal->records, sizeof(student_t*) * (journal->count + add_count));

	for (i = 0; i < add_count; ++i) {			//Заполняем случайными значениями элемент массива
		journal->records[journal->count] = (student_t*)calloc(1, sizeof(student_t));
		journal->records[journal->count]->id = journal->count ? journal->records[journal->count - 1]->id + 1 : 1;
		journal->records[journal->count]->last_name = get_random_last_name();
		journal->records[journal->count]->group = get_random_group();
		for (j = 0; j < 5; ++j) {
			journal->records[journal->count]->marks[j] = get_rand(2, 5);
		}
		++journal->count;
	}

	return REDRAW;
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

char* get_random_group() {
	static const char* names[] = { "П11015", "П21014", "Д23011", "В31011", "С32016" };
	size_t count = 5;
	size_t i = rand() % count;
	char* result = (char*)malloc(sizeof(char) * strlen(names[i]));
	strcpy(result, Rus(names[i]));
	return result;
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
	for(i = 0; i < (table_width - 2) / 2 - strlen(table->name)/2;++i) {
		printf(" ");
	}
	printf(Rus(table->name));
	for(i = 0; i < (table_width - 2) / 2 - strlen(table->name) / 2; ++i) {
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