#include <stdio.h>
#include <windows.h>
#include <conio.h>

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

enum search_area {
	NAME,
	PHONE
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

typedef struct arrayn_m {
	__int64** data;
	size_t n;
	size_t m;
} arrayn_m_t;

state home_1(void* data, void* params);
void transpose(arrayn_m_t* arr);

state home_2(void* data, void* params);
state add_record(void* data, void* params);
state edit_select(void* data, void* params);
state edit_record(void* data, void* params);
state print_str(void* data, void* params);
state find_by_name(void* data, void* params);
state find_by_phone(void* data, void* params);
size_t* find_str(char** str, size_t count, search_area area, const char* search, size_t* matches);

state exit_program(void* data, void* params);
state exit_sub(void* data, void* params);

void	menu_add_item(menu_t* menu, char text[50], event_cb_t action, void* data, void* params);
menu_t* menu_create(char text[50]);
void	menu_show(menu_t* menu);
state	menu_execute(void* menu, void* params);
void	menu_free(menu_t* menu);

static int get_code(void);
char* Rus(const char* text);

__int64 read_int(FILE* fp);
char* read_string(FILE* fp);
void flush_stream(FILE* fp);

__int64** allocate_array(size_t n, size_t m);
void print_array(arrayn_m_t* arr);
void free_array(arrayn_m_t* arr);
void* free_ptr_ptr(void **ptr, size_t count);

state fill_rand_wrapper(void* data, void* params);
state fill_keyboard(void* data, void* params);
void fill_rand(__int64 * arr, size_t length, __int64 left, __int64 right);

int main() {
	menu_t* main_menu = menu_create(Rus("Главное меню"));

	if (!main_menu) {
		return 1;
	}

	menu_add_item(main_menu, Rus("Задание 1"), &home_1, NULL, NULL);
	menu_add_item(main_menu, Rus("Задание 2"), &home_2, NULL, NULL);
	menu_add_item(main_menu, "Exit", &exit_program, NULL, NULL);

	menu_execute(main_menu, NULL);

	menu_free(main_menu);

	return 0;
}


state home_1(void*, void*) {
	system("cls");
	printf(Rus("Задание1: Напиcать функцию транспонирования матрицы.\n"));
	arrayn_m_t arr;
	printf(Rus("Введите количество строк: "));
	arr.n = read_int(stdin);
	printf(Rus("Введите количество столбцов: "));
	arr.m = read_int(stdin);

	arr.data = allocate_array(arr.n, arr.m);

	menu_t* sub_menu = menu_create(Rus("Как заполнить массив?"));

	if (!sub_menu) {
		return EXIT;
	}

	menu_add_item(sub_menu, Rus("С клавиатуры"), &fill_keyboard, &arr, NULL);
	menu_add_item(sub_menu, Rus("Случайными числами"), &fill_rand_wrapper, &arr, NULL);

	menu_execute(sub_menu, NULL);
	menu_free(sub_menu);

	system("cls");
	printf(Rus("Исходный массив:\n"));
	print_array(&arr);

	transpose(&arr);

	printf(Rus("\nРезультирующий массив:\n"));
	print_array(&arr);
	system("pause");

	free_array(&arr);
	return REDRAW;
}

void transpose(arrayn_m_t* arr)
{
	__int64** data_new = allocate_array(arr->m, arr->n);

	size_t i, j;
	for (i = 0; i < arr->m; ++i) {
		for (j = 0; j < arr->n; ++j) {
			*(*(data_new + i) + j) = *(*(arr->data + j) + i);
		}
	}
	free_array(arr);
	arr->data = data_new;
	size_t tmp = arr->n;
	arr->n = arr->m;
	arr->m = tmp;
}

state home_2(void*, void*) {
	system("cls");

	printf(Rus("Задание 2: Создайте динамический массив, хранящий в первой строке имя, а во второй - телефон. "
		"Организуйте поиск по имени и по номеру телефона и возможность ввода и изменения данных.\n"));
	system("Pause");

	char** str = NULL;
	size_t count = 0;

	menu_t* sub_menu = menu_create(Rus("Выберите операцию:"));

	if (!sub_menu) {
		return EXIT;
	}

	menu_add_item(sub_menu, Rus("Добавить запись"), &add_record, &str, &count);
	menu_add_item(sub_menu, Rus("Изменить запись"), &edit_select, &str, &count);
	menu_add_item(sub_menu, Rus("Вывести список на экран"), &print_str, &str, &count);
	menu_add_item(sub_menu, Rus("Поиск по имени"), &find_by_name, &str, &count);
	menu_add_item(sub_menu, Rus("Поиск по телефону"), &find_by_phone, &str, &count);
	menu_add_item(sub_menu, Rus("Вернуться"), &exit_sub, NULL, NULL);

	menu_execute(sub_menu, NULL);
	menu_free(sub_menu);

	free_ptr_ptr((void**)str, count);
	return REDRAW;
}

state add_record(void* data, void* param) {
	system("cls");
	char*** str = (char***)data;
	size_t* count = (size_t*)param;

	*count += 2;
	
	*str = (char**)realloc(*str, sizeof(char*) * *count);
	char* s;

	printf(Rus("Введите имя: "));
	do {
		s = read_string(stdin);
		if (!strcmp(s, HALT)) {
			printf(Rus("Введите не пустую строку: "));
		}
	} while (!strcmp(s, HALT));

	*(*str + *count - 2) = s;

	printf(Rus("Введите телефон: "));
	do {
		s = read_string(stdin);
		if (!strcmp(s, HALT)) {
			printf(Rus("Введите не пустую строку: "));
		}
	} while (!strcmp(s, HALT));

	*(*str + *count - 1) = s;
	return REDRAW;
}

state edit_select(void* data, void* param) {
	system("cls");

	char** str = *(char***)data;
	size_t count = *(size_t*)param;

	if (count) {
		menu_t* sub_menu = menu_create(Rus("Выберите запись:"));

		if (!sub_menu) {
			return REDRAW;
		}

		size_t i;
		for (i = 0; i < count / 2; ++i) {
			menu_add_item(sub_menu, *(str + i * 2), &edit_record, (str + (i * 2)), NULL);
		}

		menu_execute(sub_menu, NULL);
		menu_free(sub_menu);
	}
	else {
		printf(Rus("Нет записей.\n"));
	}
	return REDRAW;
}

state edit_record(void* data, void* ) {
	system("cls");
	char** str = (char**)data;
	char* s;

	printf(Rus("Введите имя: "));
	do {
		s = read_string(stdin);
		if (!strcmp(s, HALT)) {
			printf(Rus("Введите не пустую строку: "));
		}
	} while (!strcmp(s, HALT));
	free(*str);
	*str = s;

	printf(Rus("Введите телефон: "));
	do {
		s = read_string(stdin);
		if (!strcmp(s, HALT)) {
			printf(Rus("Введите не пустую строку: "));
		}
	} while (!strcmp(s, HALT));

	free(*(str + 1));
	*(str + 1) = s;
	return EXIT;
}

state find_by_name(void* data, void* param) {
	system("cls");

	char** str = *(char***)data;
	size_t count = *(size_t*)param;
	char* search;
	size_t matches;
	size_t* search_result;
	size_t i;

	if (count) {
		printf(Rus("Введите строку поиска: "));
		search = read_string(stdin);
		matches = 0;
		search_result = find_str(str, count, NAME, search, &matches);
		if (matches) {
			printf(Rus("Результаты поиска:\n"));
			for (i = 0; i < matches; ++i) {
				printf(Rus("Запись %d:\n"), *(search_result + i));
				printf(Rus("Имя:\t\t %s\n"), *(str + *(search_result + i) * 2));
				printf(Rus("Телефон:\t %s\n"), *(str + *(search_result + i) * 2 + 1));
				printf("\n");
			}
		}
		free(search);
		free(search_result);
	}
	else {
		printf(Rus("Нет записей.\n"));
	}

	system("pause");
	return REDRAW;
}

state find_by_phone(void* data, void* param) {
	system("cls");

	char** str = *(char***)data;
	size_t count = *(size_t*)param;
	char* search;
	size_t matches;
	size_t* search_result;
	size_t i;

	if (count) {
		printf(Rus("Введите строку поиска: "));
		search = read_string(stdin);
		matches = 0;
		search_result = find_str(str, count, PHONE, search, &matches);
		if (matches) {
			printf(Rus("Результаты поиска:\n"));
			for (i = 0; i < matches; ++i) {
				printf(Rus("Запись %d:\n"), *(search_result + i));
				printf(Rus("Имя:\t\t %s\n"), *(str + *(search_result + i) * 2));
				printf(Rus("Телефон:\t %s\n"), *(str + *(search_result + i) * 2 + 1));
				printf("\n");
			}
		}
		free(search);
		free(search_result);
	}
	else {
		printf(Rus("Нет записей.\n"));
	}

	system("pause");
	return REDRAW;
}

size_t* find_str(char** str, size_t count, search_area area, const char* search, size_t* matches) {
	size_t alloc = 5;
	size_t* result = (size_t*)realloc(NULL, sizeof(size_t) * alloc);

	size_t i;
	for (i = 0; i < count / 2; ++i) {
		if(strstr(*(str + i * 2 + area), search)) {
			if (*matches == alloc)
				result = (size_t*)realloc(result, sizeof(size_t) * (alloc += 5));
			*(result + (*matches)++) = i;
		}
	}
	return (size_t*)realloc(result, sizeof(size_t) * *matches);
}

state print_str(void* data, void* param) {
	system("cls");
	char** str = *(char***)data;
	size_t count = *(size_t*)param;

	size_t i;

	if (count) {

		for (i = 0; i < count / 2; ++i) {
			printf(Rus("Запись %d:\n"), i);
			printf(Rus("Имя:\t\t %s\n"), *(str + i * 2));
			printf(Rus("Телефон:\t %s\n"), *(str + i * 2 + 1));
			printf("\n");
		}
	} else {
		printf(Rus("Нет записей.\n"));
	}

	system("pause");
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

state fill_keyboard(void *data, void*) {
	arrayn_m* arr = (arrayn_m*)data;
	size_t i, j;
	for (i = 0; i < arr->n; ++i) {
		for (j = 0; j < arr->m; ++j) {
			printf("arr[%d][%d] = ", i, j);
			*(*(arr->data + i) + j) = read_int(stdin);
		}
	}
	return EXIT;
}

state fill_rand_wrapper(void *data, void*) {
	arrayn_m* arr = (arrayn_m*)data;
	int left, right;
	printf(Rus("Введите левую границу: "));
	left = read_int(stdin);
	printf(Rus("Введите правую границу: "));
	do {
		right = read_int(stdin);
		if (right < left) {
			printf(Rus("Правая граница должна быть не менее левой. Повторите ввод: "));
		}
	} while (right < left);
	
	size_t i;
	for (i = 0; i < arr->n; ++i) {
		fill_rand(*(arr->data + i), arr->m, left, right);
	}
	return EXIT;
}

void fill_rand(__int64 * arr, size_t length, __int64 left, __int64 right)
{
	for (int i = 0; i < length; i++)
	{
		*(arr + i) = rand() % (right - left + 1) + left;
	}
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

__int64** allocate_array(size_t n, size_t m) {
	__int64** arr = (__int64**)malloc(sizeof(__int64*) * n);
	size_t i;
	for (i = 0; i < n; ++i)
	{
		*(arr + i) = (__int64*)malloc(sizeof(__int64) * m);
	}
	return arr;
}

void free_array(arrayn_m_t* arr) {
	size_t i;
	for (i = 0; i < arr->n; ++i)
	{
		free(*(arr->data + i));
	}
	free(arr->data);
}

void* free_ptr_ptr(void **ptr, size_t count)
{
	size_t i;
	for (i = 0; i < count; ++i)
	{
		free(*(ptr + i));
	}
	free(ptr);
	return NULL;
}