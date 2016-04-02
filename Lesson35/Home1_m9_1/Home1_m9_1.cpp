#include <stdio.h>
#include <windows.h>
#include <conio.h>

/*
*
* amatu, 3/31/2016 9:03:43 PM
*/

enum keys{
	KEY_ENTER = 13,
	KEY_ESC = 27,
	ARROW_UP = 256 + 72,
	ARROW_DOWN = 256 + 80,
	ARROW_LEFT = 256 + 75,
	ARROW_RIGHT = 256 + 77
};

typedef int(*event_cb_t)(void *data, void* params);

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
} menu_t;

typedef struct arrayn_m {
	__int64** data;
	size_t n;
	size_t m;
} arrayn_m_t;

int home_1(void* data, void* params);
int home_2(void* data, void* params);
int home_3(void* data, void* params);
int exit_program(void* data, void* params);

void	menu_add_item(menu_t* menu, char text[50], event_cb_t action, void* data, void* params);
menu_t* menu_create(char text[50]);
void	menu_show(menu_t* menu);
int		menu_execute(void* menu, void* params);
void	menu_free(menu_t* menu);

static int get_code(void);
char* Rus(const char* text);

__int64 read_int(FILE* fp);
void flush_stream(FILE* fp);

__int64** allocate_array(size_t n, size_t m);
void print_array(arrayn_m_t* arr);
void free_array(arrayn_m_t* arr);

int fill_rand_wrapper(void* data, void* params);
int fill_keyboard(void* data, void* params);
void fill_rand(__int64 * arr, size_t length, __int64 left, __int64 right);

void add_col(arrayn_m_t* arr, size_t pos);
void del_col(arrayn_m_t* arr, size_t pos);


int shift_selector(void* data, void* params);
int shift_left(void* data, void* params);
int shift_right(void* data, void* params);
int shift_up(void* data, void* params);
int shift_down(void* data, void* params);

void reverse(__int64** arr, size_t size);
void transpose(arrayn_m_t* arr);

int main() {
	menu_t* main_menu =	menu_create(Rus("Главное меню"));

	if (!main_menu) {
		return 1;
	}

	menu_add_item(main_menu, Rus("Задание 1"), &home_1, NULL, NULL);
	menu_add_item(main_menu, Rus("Задание 2"), &home_2, NULL, NULL);
	menu_add_item(main_menu, Rus("Задание 3"), &home_3, NULL, NULL);
	menu_add_item(main_menu, "Exit", &exit_program, NULL, NULL);

	menu_execute(main_menu, NULL);

	menu_free(main_menu);

	return 0;
}


int home_1(void*, void*) {
	system("cls");
	printf(Rus("Написать функцию, добавляющую столбец двухмерному массиву в указанную позицию.\n"));
	arrayn_m_t arr;
	printf(Rus("Введите количество строк: "));
	arr.n = read_int(stdin);
	printf(Rus("Введите количество столбцов: "));
	arr.m = read_int(stdin);

	arr.data = allocate_array(arr.n, arr.m);

	menu_t* sub_menu = menu_create(Rus("Как заполнить массив?"));

	if (!sub_menu) {
		return 1;
	}

	menu_add_item(sub_menu, Rus("С клавиатуры"), &fill_keyboard, &arr, NULL);
	menu_add_item(sub_menu, Rus("Случайными числами"), &fill_rand_wrapper, &arr, NULL);

	menu_execute(sub_menu, NULL);
	menu_free(sub_menu);

	system("cls");
	printf(Rus("Исходный массив:\n"));
	print_array(&arr);

	size_t pos;
	do {
		printf(Rus("\nВведите позицию для добавления столбца: "));
		pos = read_int(stdin);
		if (pos > arr.m) {
			printf(Rus("Позиция должна быть в границах размера массива."));
		}
	} while (pos > arr.m);

	add_col(&arr, pos);

	printf(Rus("\nРезультирующий массив:\n"));
	print_array(&arr);
	system("pause");

	free_array(&arr);
	return 1;
}

int home_2(void*, void*) {
	system("cls");
	printf(Rus("Написать функцию, удаляющую столбец двухмерного массива по указанному номеру.\n"));
	arrayn_m_t arr;
	printf(Rus("Введите количество строк: "));
	arr.n = read_int(stdin);
	printf(Rus("Введите количество столбцов: "));
	arr.m = read_int(stdin);

	arr.data = allocate_array(arr.n, arr.m);

	menu_t* sub_menu = menu_create(Rus("Как заполнить массив?"));

	if (!sub_menu) {
		return 1;
	}

	menu_add_item(sub_menu, Rus("С клавиатуры"), &fill_keyboard, &arr, NULL);
	menu_add_item(sub_menu, Rus("Случайными числами"), &fill_rand_wrapper, &arr, NULL);

	menu_execute(sub_menu, NULL);
	menu_free(sub_menu);

	system("cls");
	printf(Rus("Исходный массив:\n"));
	print_array(&arr);

	size_t pos;
	do {
		printf(Rus("\nВведите позицию для удаления столбца: "));
		pos = read_int(stdin);
		if (pos > arr.m - 1) {
			printf(Rus("Позиция должна быть в границах размера массива."));
		}
	} while (pos > arr.m - 1);

	del_col(&arr, pos);

	printf(Rus("\nРезультирующий массив:\n"));
	print_array(&arr);
	system("pause");

	free_array(&arr);
	return 1;
}

int home_3(void*, void*) {
	system("cls");
	printf(Rus("Дана матрица порядка MxN (M строк, N столбцов). Необходимо заполнить ее значениями "
		"и написать функцию, осуществляющую циклический сдвиг строк и/или столбцов массива указанное "
		"количество раз и в указанную сторону..\n"));
	arrayn_m_t arr;
	printf(Rus("Введите количество строк: "));
	arr.n = read_int(stdin);
	printf(Rus("Введите количество столбцов: "));
	arr.m = read_int(stdin);

	arr.data = allocate_array(arr.n, arr.m);
	menu_t* sub_menu;
	sub_menu = menu_create(Rus("Как заполнить массив?"));

	if (!sub_menu) {
		return 1;
	}

	menu_add_item(sub_menu, Rus("С клавиатуры"), &fill_keyboard, &arr, NULL);
	menu_add_item(sub_menu, Rus("Случайными числами"), &fill_rand_wrapper, &arr, NULL);

	menu_execute(sub_menu, NULL);
	menu_free(sub_menu);

	printf(Rus("На сколько шагов сдвинуть: "));
	size_t steps = read_int(stdin);

	sub_menu = menu_create(Rus("В какую сторону сдвинуть?"));

	if (!sub_menu) {
		return 1;
	}

	menu_add_item(sub_menu, Rus("Влево"), &shift_left, &arr , &steps);
	menu_add_item(sub_menu, Rus("Вправо"), &shift_right, &arr, &steps);
	menu_add_item(sub_menu, Rus("Вверх"), &shift_up, &arr, &steps);
	menu_add_item(sub_menu, Rus("Вниз"), &shift_down, &arr, &steps);

	menu_execute(sub_menu, NULL);
	menu_free(sub_menu);

	free_array(&arr);
	return 1;
}


int exit_program(void*, void*)
{
	system("cls");
	printf(Rus("Пока\n"));
	system("pause");
	exit(0);
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

int menu_execute(void* data, void*) {
	menu_t* menu = (menu_t*)data;
	menu_show(menu);
	int state = 1;

	do {
		switch (get_code()) {
		case KEY_ENTER:
			if (menu->selected->action->cb) {
				state = menu->selected->action->cb(menu->selected->action->data, menu->selected->action->params);
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
	} while (state);
	return 1;
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

void flush_stream(FILE* fp) {
	fseek(fp, 0, SEEK_END);
}

int fill_keyboard(void *data, void*) {
	arrayn_m* arr = (arrayn_m*)data;
	size_t i, j;
	for (i = 0; i < arr->n; ++i) {
		for (j = 0; j < arr->m; ++j) {
			printf("arr[%d][%d] = ", i, j);
			*(*(arr->data + i) + j) = read_int(stdin);
		}
	}
	return 0;
}

int fill_rand_wrapper(void *data, void*) {
	arrayn_m* arr = (arrayn_m*)data;
	int left, right;
	printf(Rus("Введите левую границу: "));
	left = read_int(stdin);
	printf(Rus("Введите правую границу: "));
	right = read_int(stdin);
	size_t i;
	for (i = 0; i < arr->n; ++i) {
		fill_rand(*(arr->data + i), arr->m, left, right);
	}
	return 0;
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

void add_col(arrayn_m_t* arr, size_t pos) {
	size_t i, j;
	++arr->m;
	for (i = 0; i < arr->n; ++i) {
		*(arr->data + i) = (__int64*)realloc(*(arr->data + i), sizeof(__int64) * arr->m);
		for (j = arr->m - 1; j > pos; --j) {
			*(*(arr->data + i) + j) = *(*(arr->data + i) + j - 1);
		}
		printf("arr[%d][%d] = ", i, pos);
		*(*(arr->data + i) + j) = read_int(stdin);
	}
}

void del_col(arrayn_m_t* arr, size_t pos) {
	size_t i, j;
	for (i = 0; i < arr->n; ++i) {

		for (j = pos; j < arr->m - 1; ++j) {
			*(*(arr->data + i) + j) = *(*(arr->data + i) + j + 1);
		}
		*(arr->data + i) = (__int64*)realloc(*(arr->data + i), sizeof(__int64) * arr->m - 1);
	}
	--arr->m;
}


int shift_left(void* data, void* params) {
	arrayn_m_t* arr = (arrayn_m_t*)data;
	size_t steps = *(size_t*)params;

	system("cls");
	printf(Rus("Исходный массив:\n"));
	print_array(arr);

	transpose(arr);

	reverse(arr->data, steps);
	reverse(arr->data + steps, arr->n - steps);
	reverse(arr->data, arr->n);

	transpose(arr);

	printf(Rus("\nРезультат сдвига:\n"));
	print_array(arr);

	
	system("pause");
	return 0;
}

int shift_right(void* data, void* params) {
	arrayn_m_t* arr = (arrayn_m_t*)data;
	size_t steps = *(size_t*)params;

	system("cls");
	printf(Rus("Исходный массив:\n"));
	print_array(arr);

	transpose(arr);

	reverse(arr->data, arr->n - steps);
	reverse(arr->data + arr->n - steps, steps);
	reverse(arr->data, arr->n);

	transpose(arr);

	printf(Rus("\nРезультат сдвига:\n"));
	print_array(arr);


	system("pause");
	return 0;
}

int shift_up(void* data, void* params) {
	arrayn_m_t* arr = (arrayn_m_t*)data;
	size_t steps = *(size_t*)params;

	system("cls");
	printf(Rus("Исходный массив:\n"));
	print_array(arr);

	reverse(arr->data, steps);
	reverse(arr->data + steps, arr->n - steps);
	reverse(arr->data, arr->n);

	printf(Rus("\nРезультат сдвига:\n"));
	print_array(arr);

	system("pause");
	return 0;
}

int shift_down(void* data, void* params) {
	arrayn_m_t* arr = (arrayn_m_t*)data;
	size_t steps = *(size_t*)params;

	system("cls");
	printf(Rus("Исходный массив:\n"));
	print_array(arr);

	reverse(arr->data, arr->n - steps);
	reverse(arr->data + arr->n - steps, steps);
	reverse(arr->data, arr-> n);
	
	printf(Rus("\nРезультат сдвига:\n"));
	print_array(arr);

	system("pause");
	return 0;
}

void reverse(__int64** arr, size_t size)
{
	__int64* tmp;
	size_t i;
	for (i = 0; i < size / 2; i++)
	{
		tmp = *(arr + i);
		*(arr + i) = *(arr + size - 1 - i);
		*(arr + size - 1 - i) = tmp;
	}
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