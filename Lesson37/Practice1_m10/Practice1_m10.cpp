#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <locale.h>
#include <iostream>

/*
*
* amatu, 3/31/2016 9:03:43 PM
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

typedef state(*event_cb_t)(void *data, void* params);

struct event_cb {
	event_cb_t cb;
	void *data;
	void *params;
};

typedef struct menu_item {
	char text[50];
	struct event_cb* action;
	struct menu_item* next;
} menu_item_t;

typedef struct menu {
	char name[50];
	struct menu_item* head;
	struct menu_item* selected;
	state menu_state;
} menu_t;

typedef struct phonebook_item {
	char* first_name;
	char* last_name;
	char* surname;
	char* street;
	size_t bld;
	size_t ap;
	char* phone;
} phonebook_item_t;


state add_record(void* data, void* param);
state print_records(void* data, void* param);

state exit_program(void* data, void* params);
state exit_sub(void* data, void* params);

void	menu_add_item(menu_t* menu, char text[50], event_cb_t action, void* data, void* params);
menu_t* menu_create(char text[50]);
void	menu_show(menu_t* menu);
state	menu_execute(void* menu, void* params);
void	menu_free(menu_t* menu);

static int get_code(void);
char* Rus(const char* text);
char* RusW(const wchar_t* text);

__int64 read_int(FILE* fp);
char* read_string(FILE* fp);
void flush_stream(FILE* fp);

int main() {
	phonebook_item_t* phonebook = NULL;
	size_t count = 0;

	menu_t* main_menu = menu_create(Rus("Главное меню"));

	if (!main_menu) {
		return 1;
	}

	menu_add_item(main_menu, Rus("Добавить запись"), &add_record, &phonebook, &count);
	menu_add_item(main_menu, Rus("Вывести записи"), &print_records, &phonebook, &count);
	menu_add_item(main_menu, "Exit", &exit_program, NULL, NULL);

	menu_execute(main_menu, NULL);

	menu_free(main_menu);

	return 0;
}

state print_records(void* data, void* param)
{
	phonebook_item_t** phonebook = (phonebook_item_t**)data;
	size_t* count = (size_t*)param;

	size_t i;
	printf(RusW(L"╔═══╤══════════════╤══════════════╤══════════════╤══════════════╤═══╤═══╤══════╗\n"));
	printf(RusW(L"║ № │   ФАМИЛИЯ    │     ИМЯ      │   ОТЧЕСТВО   │    УЛИЦА     │ДОМ│КВ.│ТЕЛЕФО║\n"));
	printf(RusW(L"╠═══╪══════════════╪══════════════╪══════════════╪══════════════╪═══╪═══╪══════╣\n"));

	for (i = 0; i < *count; ++i)
	{
		printf(RusW(L"║%3d│%-14s│%-14s│%-14s│%-14s│%3d│%3d│%6s║\n"),
			i + 1,
			(*phonebook + i)->last_name,
			(*phonebook + i)->first_name,
			(*phonebook + i)->surname,
			(*phonebook + i)->street,
			(*phonebook + i)->bld,
			(*phonebook + i)->ap,
			(*phonebook + i)->phone);
	}
	printf(RusW(L"╚═══╧══════════════╧══════════════╧══════════════╧══════════════╧═══╧═══╧══════╝\n"));
	system("pause");
	return REDRAW;
}

state add_record(void* data, void* param) {
	system("cls");
	phonebook_item_t** phonebook = (phonebook_item_t**)data;
	size_t* count = (size_t*)param;

	*phonebook = (phonebook_item_t*)realloc(*phonebook, sizeof(phonebook_item_t) * (*count + 1));

	printf(Rus("Введите фамилию: "));
	(*phonebook + *count)->last_name = read_string(stdin);

	printf(Rus("Введите имя: "));
	(*phonebook + *count)->first_name = read_string(stdin);

	printf(Rus("Введите отчество: "));
	(*phonebook + *count)->surname = read_string(stdin);

	printf(Rus("Введите улицу: "));
	(*phonebook + *count)->street= read_string(stdin);

	printf(Rus("Введите номер дома: "));
	(*phonebook + *count)->bld = read_int(stdin);

	printf(Rus("Введите номер квартиры: "));
	(*phonebook + *count)->ap = read_int(stdin);

	printf(Rus("Введите телефон: "));
	(*phonebook + *count)->phone = read_string(stdin);

	++*count;
	return REDRAW;
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
	int ch = getch();

	if (ch == 0 || ch == 224)
		ch = 256 + getch();

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