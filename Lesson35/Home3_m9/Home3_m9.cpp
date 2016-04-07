#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <math.h>

/*
*
* amatu, 3/31/2016 9:03:43 PM
*/

#define HALT			""
#define TASK1_LIMIT		5

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

typedef unsigned char boolean;

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

typedef struct arrayn_m {
	__int64** data;
	size_t n;
	size_t m;
} arrayn_m_t;

state task1(void* data, void* params);
state task2(void* data, void* params);

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
char**	read_strings(FILE* fp, char** str, size_t* count);
void	print_strings(char** str, size_t count);
void	sort(char** str, size_t count);
void	flush_stream(FILE* fp);
void*	free_ptr_ptr(void **ptr, size_t count);

__int64**	allocate_array(size_t n, size_t m);
void		print_array(arrayn_m_t* arr);
void		free_array(arrayn_m_t* arr);
void print_arr(__int64* arr, size_t size);

state	fill_rand_wrapper(void* data, void* params);
state	fill_keyboard(void* data, void* params);
void	fill_rand(__int64 * arr, size_t length, __int64 left, __int64 right);

__int64* create_set(arrayn_m_t* arr, size_t* set_size);
boolean contain(__int64* set, size_t size, __int64 find);

int main() {
	//Создаем меню
	menu_t* main_menu = menu_create(Rus("Главное меню"));

	if (!main_menu) {
		return 1;
	}

	//Добавляем пункты в меню
	menu_add_item(main_menu, Rus("Задание 1"), &task1, NULL, NULL);
	menu_add_item(main_menu, Rus("Задание 2"), &task2, NULL, NULL);
	menu_add_item(main_menu, "Exit", &exit_program, NULL, NULL);

	//Выполняем меню
	menu_execute(main_menu, NULL);

	menu_free(main_menu);

	return 0;
}

state task1(void*, void*) {
	system("cls");
	printf(Rus("Задание 1. Написать программу, которая дает пользователю ввести 5 фамилий студентов,"
		" а затем сортирует их по возрастанию.\n\n"));

	char** str = (char**)malloc(sizeof(char*) * TASK1_LIMIT);
	size_t count = 0;
	printf(Rus("Введите %d фамилий студентов:\n"), TASK1_LIMIT);
	do {
		str[count++] = read_string(stdin);
	} while (count < TASK1_LIMIT);

	system("cls");
	printf(Rus("\nИсходный массив:\n"));
	print_strings(str, count);
	sort(str, count);
	printf(Rus("\nОтсортированный массив:\n"));
	print_strings(str, count);

	free_ptr_ptr((void**)str, count);
	system("pause");
	return REDRAW;
}


state task2(void*, void*) {
	menu_t* fill_menu = menu_create(Rus("Как заполнить массив?"));
	arrayn_m_t* current;

	if (!fill_menu) {
		return REDRAW;
	}

	menu_add_item(fill_menu, Rus("С клавиатуры"), &fill_keyboard, &current, NULL);
	menu_add_item(fill_menu, Rus("Случайными числами"), &fill_rand_wrapper, &current, NULL);

	arrayn_m_t arr_A, arr_B, arr_C;

	system("cls");
	printf(Rus("Введите количество строк массива A: "));
	arr_A.n = read_int(stdin);
	printf(Rus("Введите количество столбцов массива A: "));
	arr_A.m = read_int(stdin);

	arr_A.data = allocate_array(arr_A.n, arr_A.m);

	current = &arr_A;
	menu_execute(fill_menu, NULL);

	system("cls");
	printf(Rus("Введите количество строк массива B: "));
	arr_B.n = read_int(stdin);
	printf(Rus("Введите количество столбцов массива B: "));
	arr_B.m = read_int(stdin);

	arr_B.data = allocate_array(arr_B.n, arr_B.m);

	current = &arr_B;
	menu_execute(fill_menu, NULL);

	
	system("cls");
	printf(Rus("Введите количество строк массива C: "));
	arr_C.n = read_int(stdin);
	printf(Rus("Введите количество столбцов массива C: "));
	arr_C.m = read_int(stdin);

	arr_C.data = allocate_array(arr_C.n, arr_C.m);

	current = &arr_C;
	menu_execute(fill_menu, NULL);

	system("cls");

	printf(Rus("\nМассив A:\n"));
	print_array(&arr_A);
	printf(Rus("\nМассив B:\n"));
	print_array(&arr_B);
	printf(Rus("\nМассив C:\n"));
	print_array(&arr_C);

	__int64 *set_A, *set_B, *set_C;
	size_t set_A_size = 0, set_B_size = 0, set_C_size = 0;
	set_A = create_set(&arr_A, &set_A_size);
	set_B = create_set(&arr_B, &set_B_size);
	set_C = create_set(&arr_C, &set_C_size);

	size_t i, j, k;

	__int64* s_ABC = NULL;
	size_t s_ABC_size = 0;

	for (i = 0; i < set_A_size; ++i) {
		if (contain(set_B, set_B_size, set_A[i]) && contain(set_C, set_C_size, set_A[i])) {
			s_ABC = (__int64*)realloc(s_ABC, sizeof(__int64) * (s_ABC_size + 1));
			s_ABC[s_ABC_size] = set_A[i];
			++s_ABC_size;
		}
	}

	for (i = 0; i < set_B_size; ++i) {
		if (!contain(s_ABC, s_ABC_size, set_B[i])) {
			if (contain(set_A, set_A_size, set_B[i]) && contain(set_C, set_C_size, set_B[i])) {
				s_ABC = (__int64*)realloc(s_ABC, sizeof(__int64) * (s_ABC_size + 1));
				s_ABC[s_ABC_size] = set_B[i];
				++s_ABC_size;
			}
		}
	}

	for (i = 0; i < set_C_size; ++i) {
		if (!contain(s_ABC, s_ABC_size, set_C[i])) {
			if (contain(set_A, set_A_size, set_C[i]) && contain(set_B, set_B_size, set_C[i])) {
				s_ABC = (__int64*)realloc(s_ABC, sizeof(__int64) * (s_ABC_size + 1));
				s_ABC[s_ABC_size] = set_C[i];
				++s_ABC_size;
			}
		}
	}

	__int64* u_ABC = NULL;
	size_t u_ABC_size = 0;

	for (i = 0; i < set_A_size; ++i) {
		if (!contain(set_B, set_B_size, set_A[i]) && !contain(set_C, set_C_size, set_A[i])) {
			u_ABC = (__int64*)realloc(u_ABC, sizeof(__int64) * (u_ABC_size + 1));
			u_ABC[u_ABC_size] = set_A[i];
			++u_ABC_size;
		}
	}

	for (i = 0; i < set_B_size; ++i) {
		if (!contain(u_ABC, u_ABC_size, set_B[i])) {
			if (!contain(set_A, set_A_size, set_B[i]) && !contain(set_C, set_C_size, set_B[i])) {
				u_ABC = (__int64*)realloc(u_ABC, sizeof(__int64) * (u_ABC_size + 1));
				u_ABC[u_ABC_size] = set_B[i];
				++u_ABC_size;
			}
		}
	}

	for (i = 0; i < set_C_size; ++i) {
		if (!contain(u_ABC, u_ABC_size, set_C[i])) {
			if (!contain(set_A, set_A_size, set_C[i]) && !contain(set_B, set_B_size, set_C[i])) {
				u_ABC = (__int64*)realloc(u_ABC, sizeof(__int64) * (u_ABC_size + 1));
				u_ABC[u_ABC_size] = set_C[i];
				++u_ABC_size;
			}
		}
	}

	__int64* s_AC = NULL;
	size_t s_AC_size = 0;

	for (i = 0; i < set_A_size; ++i) {
		if (contain(set_C, set_C_size, set_A[i])) {
			s_AC = (__int64*)realloc(s_AC, sizeof(__int64) * (s_AC_size + 1));
			s_AC[s_AC_size] = set_A[i];
			++s_AC_size;
		}
	}

	__int64* n_ABC = NULL;
	size_t n_ABC_size = 0;

	for (i = 0; i < set_A_size; ++i) {
		if (set_A[i] < 0) {
			n_ABC = (__int64*)realloc(n_ABC, sizeof(__int64) * (n_ABC_size + 1));
			n_ABC[n_ABC_size] = set_A[i];
			++n_ABC_size;
		}
	}

	for (i = 0; i < set_B_size; ++i) {
		if (!contain(n_ABC, n_ABC_size, set_B[i])) {
			if (set_B[i] < 0) {
				n_ABC = (__int64*)realloc(n_ABC, sizeof(__int64) * (n_ABC_size + 1));
				n_ABC[n_ABC_size] = set_B[i];
				++n_ABC_size;
			}
		}
	}

	for (i = 0; i < set_C_size; ++i) {
		if (!contain(n_ABC, n_ABC_size, set_C[i])) {
			if (set_C[i] < 0) {
				n_ABC = (__int64*)realloc(n_ABC, sizeof(__int64) * (n_ABC_size + 1));
				n_ABC[n_ABC_size] = set_C[i];
				++n_ABC_size;
			}
		}
	}

	printf(Rus("Одномерный массив, который содержит общие значения для A, B, C:\n"));
	print_arr(s_ABC, s_ABC_size);
	printf(Rus("Одномерный массив, который содержит уникальные значения для A, B, C:\n"));
	print_arr(u_ABC, u_ABC_size);
	printf(Rus("Одномерный массив, который содержит общие значения для A и C:\n"));
	print_arr(s_AC, s_AC_size);
	printf(Rus("одномерный массив, который содержит отрицательные значения для A, B, C без повторений:\n"));
	print_arr(n_ABC, n_ABC_size);

	free_array(&arr_A);
	free_array(&arr_B);
	free_array(&arr_C);
	free(set_A);
	free(set_B);
	free(set_C);
	free(s_ABC);
	free(u_ABC);
	free(s_AC);
	free(n_ABC);

	menu_free(fill_menu);
	system("pause");
	return REDRAW;
}

boolean contain(__int64* set, size_t size, __int64 find) {
	size_t i;
	for (i = 0; i < size; ++i) {
		if (set[i] == find) {
			return TRUE;
		}
	}
	return FALSE;
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
	menu->menu_state = REDRAW;
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


char** read_strings(FILE* fp, char** str, size_t* count)
{
	char* s;
	int alloc = *count + 10;
	str = (char**)realloc(str, sizeof(char*) * alloc);

	while (((s = read_string(fp))) && strcmp(s, HALT))
	{
		if (*count == alloc)
			str = (char**)realloc(str, sizeof(char*) * (alloc += 10));
		*(str + *count) = s;
		++(*count);
	}
	return (char**)realloc(str, sizeof(char*) * *count);
}


void print_strings(char** str, size_t count)
{
	size_t i;
	for (i = 0; i < count; ++i)
	{
		puts(*(str + i));
	}
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

void sort(char** str, size_t count)
{
	int i, j = 0, sorted;
	char* tmp;

	do
	{
		sorted = 1;
		for (i = 0; i < count - j - 1; i++)
		{
			if (strcmp(*(str + i), *(str + i + 1)) > 0)
			{
				tmp = *(str + i);
				*(str + i) = *(str + i + 1);
				*(str + i + 1) = tmp;
				sorted = 0;
			}
		}
		j++;
	} while (!sorted);
}

void flush_stream(FILE* fp) {
	fseek(fp, 0, SEEK_END);
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

state fill_keyboard(void *data, void*) {
	arrayn_m* arr = *(arrayn_m**)data;
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
	arrayn_m* arr = *(arrayn_m**)data;
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

void print_arr(__int64* arr, size_t size) {
	size_t i;
	for (i = 0; i < size; ++i)
	{
		printf("%lld ", arr[i]);
	}
	printf("\n");
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

__int64* create_set(arrayn_m_t* arr, size_t* set_size)
{
	size_t i, j, k;
	__int64* set = (__int64*)malloc(sizeof(__int64) * arr->n * arr->m);
	boolean unique;

	for (i = 0; i < arr->n; ++i)
	{
		for (j = 0; j < arr->m; ++j)
		{
			unique = TRUE;
			for (k = 0; k < *set_size; ++k) {
				if(arr->data[i][j] == set[k]) {
					unique = FALSE;
					break;
				}
			}
			if(unique) {
				set[*set_size] = arr->data[i][j];
				++*set_size;
			}
		}
	}
	return (__int64*)realloc(set, sizeof(__int64) * *set_size);
}