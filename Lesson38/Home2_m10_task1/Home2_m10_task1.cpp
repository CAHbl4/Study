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
	REDRAW,
	CONTINUE
};

enum data_types {
	INTEGER,
	STRING
};

enum field_types {
	INPUTFIELD,
	CHECKBOX,
	RADIO
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

typedef struct field_input {
	char input_buffer[80];
} field_input_t;

typedef struct field_checkbox {
	__int8 checked;
	void* data_ptr;
} field_checkbox_t;

typedef struct field_radio {
	size_t radio_id;
	__int8 checked;
	void* data_ptr;
} field_radio_t;

typedef struct field_item {
	char				text[50];
	field_types type;
	union data{
		field_input_t		*input;
		field_checkbox_t	*checkbox;
		field_radio_t		*radio;
	} data;
	struct field_item*	next;
} field_item_t;

typedef struct form {
	char				name[50];
	struct field_item*	head;
	struct field_item*	selected;
	state				form_state;
} form_t;

typedef struct table_column {
	char		text[50];
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



table_t*	table_create(size_t width, size_t rows, char name[50]);
void		table_add_column(table_t* table, char text[50], void* data_source, data_types data_type, size_t min_width, size_t max_width);
void		table_print(table_t* table, size_t screen_width);
size_t		table_column_width(table_column_t* col, size_t rows);

state exit_program(void* data, void* params);
state exit_sub(void* data, void* params);

void	menu_add_item(menu_t* menu, char text[50], event_cb_t action, void* data, void* params);
menu_t* menu_create(char text[50]);
void	menu_show(menu_t* menu);
state	menu_execute(void* menu, void* params);
void	menu_free(menu_t* menu);

void	form_add_item(form_t* form, char text[50], field_types type, void* data);
form_t* form_create(char text[50]);
void form_show(form_t* form, int key_code);
state	form_execute(void* form, void* params);
void	form_free(form_t* form);
size_t	field_get_id(form_t* form, field_item_t* field);

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
__int8 is_valid_char(int ch);

//Переменные для настройки консоли
HANDLE	hConsole;
WORD	currentConsoleAttr = 0;
#define HIGHLIGHT_COLOR		FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY

int main() {
	//Сохраняем текущие параметры консоли
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (GetConsoleScreenBufferInfo(hConsole, &csbi))
		currentConsoleAttr = csbi.wAttributes;


	form_t* form = form_create("Test form");

	field_input_t* input1 = (field_input_t*)calloc(1, sizeof(field_input_t));
	form_add_item(form, "Input 1", INPUTFIELD, input1);

	field_checkbox_t* checkbox1 = (field_checkbox_t*)calloc(1, sizeof(field_checkbox_t));
	form_add_item(form, "Checkbox 1", CHECKBOX, checkbox1);

	field_checkbox_t* checkbox2 = (field_checkbox_t*)calloc(1, sizeof(field_checkbox_t));
	form_add_item(form, "Checkbox 2", CHECKBOX, checkbox2);

	field_radio_t* radio1 = (field_radio_t*)calloc(1, sizeof(field_radio_t));
	radio1->radio_id = 1;
	form_add_item(form, "Radio 1", RADIO, radio1);

	field_radio_t* radio2 = (field_radio_t*)calloc(1, sizeof(field_radio_t));
	radio2->radio_id = 1;
	form_add_item(form, "Radio 2", RADIO, radio2);

	field_radio_t* radio3 = (field_radio_t*)calloc(1, sizeof(field_radio_t));
	radio3->radio_id = 1;
	form_add_item(form, "Radio 3", RADIO, radio3);

	field_radio_t* aradio1 = (field_radio_t*)calloc(1, sizeof(field_radio_t));
	aradio1->radio_id = 2;
	form_add_item(form, "Another Radio 1", RADIO, aradio1);

	field_radio_t* aradio2 = (field_radio_t*)calloc(1, sizeof(field_radio_t));
	aradio2->radio_id = 2;
	form_add_item(form, "Another Radio 2", RADIO, aradio2);

	field_radio_t* aradio3 = (field_radio_t*)calloc(1, sizeof(field_radio_t));
	aradio3->radio_id = 2;
	form_add_item(form, "Another Radio 3", RADIO, aradio3);

	//Создаем меню
	menu_t* main_menu = menu_create(Rus("Главное меню"));

	//Добавляем пункты в меню
	menu_add_item(main_menu, Rus("Показать форму"), &form_execute, form, NULL);

	menu_add_item(main_menu, "Exit", &exit_program, NULL, NULL);

	//Выполняем меню
	menu_execute(main_menu, NULL);

	form_free(form);
	menu_free(main_menu);

	return 0;
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
	for (i = 0; i < (table_width - 2) / 2 - strlen(table->name) / 2; ++i) {
		printf(" ");
	}
	printf(Rus(table->name));
	for (i = 0; i < (table_width - 2) / 2 - strlen(table->name) / 2; ++i) {
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

void form_add_item(form_t* form, char text[50], field_types type, void* data) {
	field_item_t* current = form->head;

	if (current) {
		while (current->next != NULL) {
			current = current->next;
		}

		current->next = (field_item_t*)calloc(1, sizeof(field_item_t));
		strcpy(current->next->text, text);
		current->next->type = type;
		switch (type)
		{
		case INPUTFIELD:
			current->next->data.input = (field_input_t*)data;
			break;
		case CHECKBOX:
			current->next->data.checkbox = (field_checkbox_t*)data;
			break;
		case RADIO:
			current->next->data.radio = (field_radio_t*)data;
			break;
		default:
			break;
		}
		current->next->next = NULL;
	}
	else {
		form->head = (field_item_t*)calloc(1, sizeof(field_item_t));
		strcpy(form->head->text, text);
		form->head->type = type;
		switch (type)
		{
		case INPUTFIELD:
			form->head->data.input = (field_input_t*)data;
			break;
		case CHECKBOX:
			form->head->data.checkbox = (field_checkbox_t*)data;
			break;
		case RADIO:
			form->head->data.radio = (field_radio_t*)data;
			break;
		default:
			break;
		}
		form->head->next = NULL;
		form->selected = form->head;
	}
}

form_t* form_create(char text[50]) {
	form_t* new_form = (form_t*)calloc(1, sizeof(form_t));
	if (!new_form) {
		return NULL;
	}

	strcpy_s(new_form->name, text);
	new_form->head = NULL;
	new_form->selected = NULL;
	new_form->form_state = REDRAW;
	return new_form;
}

void form_show(form_t* form, int key_code) {
	if (form->form_state == REDRAW) {
		system("cls");
		printf("===%s=== code[%d]\n", form->name, key_code);
		field_item_t* current = form->head;

		while (current != NULL) {
			if (current == form->selected)
				SetConsoleTextAttribute(hConsole, HIGHLIGHT_COLOR);

			switch (current->type)
			{
			case INPUTFIELD:
				printf("%s : %s", current->text, current->data.input->input_buffer);
				break;
			case CHECKBOX:
				printf("%s [%c]", current->text, current->data.checkbox->checked?'*':' ');
				break;
			case RADIO:
				printf("%s (%c)", current->text, current->data.radio->checked ? '*' : ' ');
				break;
			default:
				break;
			}

			if (current == form->selected) 
				SetConsoleTextAttribute(hConsole, currentConsoleAttr);
			printf("\n");
			current = current->next;
		}
		form->form_state = CONTINUE;
	}

	COORD coord;
	coord.X = 1;
	coord.Y = field_get_id(form, form->selected);;

	switch (form->selected->type){
	case INPUTFIELD:
		coord.X = strlen(form->selected->text) + 3 + strlen(form->selected->data.input->input_buffer);
		break;
	case CHECKBOX:
		coord.X = strlen(form->selected->text) + 2;
		break;
	case RADIO:
		coord.X = strlen(form->selected->text) + 2;
		break;
	default:
		break;
	}
	SetConsoleCursorPosition(hConsole, coord);
}

size_t field_get_id(form_t* form, field_item_t* field) {
	size_t id = 1;
	field_item_t* current = form->head;
	while (current != field) {
		++id;
		current = current->next;
	}
	return id;
}

state form_execute(void* data, void*) {
	form_t* form = (form_t*)data;
	int ch = 0;
	form_show(form, ch);

	do {
		ch = _getch();

		if (ch == 0 || ch == 224)
			ch = 256 + _getch();

		switch (ch) {
		case KEY_BACKSPACE:
			if (form->selected->type == INPUTFIELD) {
				form->selected->data.input->input_buffer[strlen(form->selected->data.input->input_buffer) - 1] = '\0';
				form->form_state = REDRAW;
			}
			break;
		case KEY_SPACE:
			if (form->selected->type == INPUTFIELD) {
				if (strlen(form->selected->data.input->input_buffer) < sizeof(form->selected->data.input->input_buffer) - 1)
					form->selected->data.input->input_buffer[strlen(form->selected->data.input->input_buffer)] = ch;
				form->form_state = REDRAW;
			}
			if (form->selected->type == CHECKBOX) {
				if (form->selected->data.checkbox->checked)
					form->selected->data.checkbox->checked = 0;
				else
					form->selected->data.checkbox->checked = 1;
				form->form_state = REDRAW;
			}
			if (form->selected->type == RADIO) {
				field_item_t* current = form->head;
				while (current) {
					if (current->type == RADIO &&
						current->data.radio->radio_id == form->selected->data.radio->radio_id &&
						current != form->selected)
						current->data.radio->checked = 0;

					current = current->next;
				}
				form->selected->data.radio->checked = 1;
				form->form_state = REDRAW;
			}
			break;
		case ARROW_UP:
			if (form->head != form->selected) {
				field_item_t* current = form->head;
				while (current->next != form->selected) {
					current = current->next;
				}
				form->selected = current;
				form->form_state = REDRAW;
			}
			break;
		case ARROW_DOWN:
			if (form->selected->next) {
				form->selected = form->selected->next;
				form->form_state = REDRAW;
			}
			break;
		default:
			if (is_valid_char(ch)) {
				if (form->selected->type == INPUTFIELD) {
					if (strlen(form->selected->data.input->input_buffer) < sizeof(form->selected->data.input->input_buffer) - 1)
						form->selected->data.input->input_buffer[strlen(form->selected->data.input->input_buffer)] = ch;
					form->form_state = REDRAW;
				}
			}
			break;
		}
		form_show(form, ch);
	} while (form->form_state);
	return REDRAW;
}

void form_free(form_t* form) {
	if (form->head) {
		field_item_t* current = form->head;
		field_item_t* tmp;
		do {
			tmp = current;
			current = current->next;
			free(tmp);
		} while (current);
	}
	free(form);
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

__int8 is_valid_char(int ch)
{
	return ((ch >= 32 && ch <= 126) ||
			(ch >= 128 && ch <= 254));
}
