#include <stdio.h>
#include <windows.h>
#include <conio.h>

/*
*
* amatu, 3/31/2016 9:03:43 PM
*/

enum {
	KEY_ENTER = 13,
	KEY_ESC = 27,
	ARROW_UP = 256 + 72,
	ARROW_DOWN = 256 + 80,
	ARROW_LEFT = 256 + 75,
	ARROW_RIGHT = 256 + 77
};

typedef void(*event_cb_t)(void *userdata);

struct event_cb {
	event_cb_t cb;
	void *data;
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
} menu_t;

typedef struct arrayn_m {
	__int64** data;
	size_t n;
	size_t m;
} arrayn_m_t;

void menu_add_item(menu_t* menu, char text[50], event_cb_t action, void* data);
menu_t* menu_create(char text[50]);
void menu_show(menu_t* menu);
void menu_execute(void* menu);
void menu_free(menu_t* menu);
static int get_code(void);

char* Rus(const char* text);
__int64 read_int(FILE* fp);
void flush_stream(FILE* fp);
void fill_rand(void* );
void print_array(arrayn_m_t* arr);


void home_1(void* data) {
	system("cls");
	printf(Rus("Написать функцию, добавляющую столбец двухмерному массиву в указанную позицию.\n"));
	arrayn_m_t arr;
	printf(Rus("Введите количество строк: "));
	arr.n = read_int(stdin);
	printf(Rus("Введите количество столбцов: "));
	arr.m = read_int(stdin);

	arr.data = (__int64**)malloc(sizeof(int*) * arr.n);
	size_t i;
	for (i = 0; i < arr.m; ++i)
	{
		*(arr.data + i) = (__int64*)malloc(sizeof(int) * arr.m);
	}

	menu_t* sub_menu = menu_create(Rus("Как заполнить массив?"));

	if (!sub_menu) {
		return;
	}

	menu_add_item(sub_menu, Rus("С клавиатуры"), NULL, NULL);
	menu_add_item(sub_menu, Rus("Случайными числами"), &fill_rand, &arr);

	menu_execute(sub_menu);

	menu_free(sub_menu);
}

static void exit_program(void *data)
{
	system("cls");
	printf(Rus("Пока\n"));
	system("pause");
	exit(0);
}

int main() {
	menu_t* main_menu =	menu_create(Rus("Главное меню"));

	if (!main_menu) {
		return 1;
	}

	menu_add_item(main_menu, Rus("Задание 1"), &home_1, NULL);
	menu_add_item(main_menu, Rus("Задание 2"), NULL, NULL);
	menu_add_item(main_menu, Rus("Задание 3"), NULL, NULL);
	menu_add_item(main_menu, "Exit", &exit_program, NULL);

	menu_execute(main_menu);

	menu_free(main_menu);

	return 0;
}


void menu_add_item(menu_t* menu, char text[50], event_cb_t action_cb, void* action_data) {
	menu_item_t* current = menu->head;

	if (current) {
		while (current->next != NULL) {
			current = current->next;
		}

		current->next = (menu_item_t*)malloc(sizeof(menu_item_t));
		strcpy(current->next->text, text);
		current->next->action = (event_cb*)malloc(sizeof(event_cb));
		current->next->action->cb = action_cb;
		current->next->action->data = action_data;
		current->next->next = NULL;
	}
	else {
		menu->head = (menu_item_t*)malloc(sizeof(menu_item_t));
		strcpy(menu->head->text, text);
		menu->head->action = (event_cb*)malloc(sizeof(event_cb));
		menu->head->action->cb = action_cb;
		menu->head->action->data = action_data;
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
	return new_menu;
}

void menu_show(menu_t* menu) {
	static menu_item_t* last_selected = NULL;

	if (last_selected != menu->selected) {
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
		last_selected = menu->selected;
	}
}

void menu_execute(void* data) {
	menu_t* menu = (menu_t*)data;
	menu_show(menu);
	int ch;

	while ((ch = get_code()) != KEY_ESC) {
		switch (ch) {
		case KEY_ENTER:
			if (menu->selected->action->cb) {
				menu->selected->action->cb(menu->selected->action->data);
			}
			break;
		case ARROW_UP:
			if (menu->head != menu->selected) {
				menu_item_t* current = menu->head;
				while (current->next != menu->selected) {
					current = current->next;
				}
				menu->selected = current;
			}
			break;
		case ARROW_DOWN:
			if (menu->selected->next)
				menu->selected = menu->selected->next;
			break;
		}
		menu_show(menu);
	}
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

void fill_rand(void *data) {
	arrayn_m* arr = (arrayn_m*)data;
	int left, right;
	printf(Rus("Введите левую границу: "));
	left = read_int(stdin);
	printf(Rus("Введите правую границу: "));
	right = read_int(stdin);
	size_t i, j;
	for (i = 0; i < arr->n; ++i) {
		for (j = 0; j < arr->m; ++j) {
			*(*(arr->data + i) + j) = rand() % (right - left + 1) + left;
		}
	}
	print_array(arr);
}

void print_array(arrayn_m_t* arr)
{
	size_t i, j;
	for (i = 0; i < arr->n; ++i)
	{
		for (j = 0; j < arr->m; ++j)
		{
			printf("%lld ", *(*(arr->data + i) + j));
		}
		printf("\n");
	}
}

void flush_stream(FILE* fp) {
	fseek(fp, 0, SEEK_END);
}