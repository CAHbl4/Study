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

typedef void(*menu_action_t)(void);

typedef struct menu_item {
	char text[20];
	menu_action_t action;
	struct menu_item* next;
} menu_item_t;

typedef struct menu {
	char name[20];
	struct menu_item* head;
	struct menu_item* selected;
} menu_t;

void menu_add_item(menu_t* menu, char text[20], menu_action_t action);
menu_t* menu_create(char text[20]);
void menu_show(menu_t* menu);
void menu_execute(menu_t* menu);
void menu_free(menu_t* menu);
static int get_code(void);

char* Rus(const char* text);
__int64 read_int(FILE* fp);
void flush_stream(FILE* fp);
void fill_rand(int** arr, size_t n, size_t m, int left, int right);

int main() {
	menu_t* main_menu =	menu_create(Rus("Главное меню"));

	if (!main_menu) {
		return 1;
	}

	menu_add_item(main_menu, Rus("Первый пункт"), NULL);
	menu_add_item(main_menu, Rus("Второй пункт"), NULL);

	menu_execute(main_menu);
	menu_free(main_menu);

	system("pause");
	return 0;
}

void home_1(void) {
	
}


void menu_add_item(menu_t* menu, char text[20], menu_action_t action) {
	menu_item_t* current = menu->head;

	if (current) {
		while (current->next != NULL) {
			current = current->next;
		}

		current->next = (menu_item_t*)malloc(sizeof(menu_item_t));
		strcpy(current->next->text, text);
		current->next->action = action;
		current->next->next = NULL;
	}
	else {
		menu->head = (menu_item_t*)malloc(sizeof(menu_item_t));
		strcpy(menu->head->text, text);
		menu->head->action = action;
		menu->head->next = NULL;
		menu->selected = menu->head;
	}
}

menu_t* menu_create(char text[20]) {
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

void menu_execute(menu_t* menu) {
	menu_show(menu);
	int ch;

	while ((ch = get_code()) != KEY_ESC) {
		switch (ch) {
		case KEY_ENTER:
			if (menu->selected->action) {
				menu->selected->action();
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

void fill_rand(int** arr, size_t n, size_t m, int left, int right) {
	size_t i, j;
	for (i = 0; i < n; ++i) {
		for (j = 0; j < m; ++j) {
			*(*(arr + i) + j) = rand() % (right - left + 1) + left;
		}
	}
}

void flush_stream(FILE* fp) {
	fseek(fp, 0, SEEK_END);
}