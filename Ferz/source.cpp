#include <stdio.h>
#include <conio.h>
#include <iostream>

void disp_field(int s, char **f);
void init_field(int s, char **f);
void place(int x, int y, int s, char **f);
int check(int i, int j, int s, char **f);

void main() {
	setlocale(LC_CTYPE, "Rus");

	//Код программы

	int s;
	scanf_s("%d", &s);

	char **f = (char**)malloc(s *sizeof(char*));
	for (int i = 0; i < s; i++)
		f[i] = (char*)malloc(s *sizeof(char));
	init_field(s, f);
	place(0, 0, s, f);
	free(f);
	_getch();
}

void place(int x, int y, int s, char **f) {
	int i, j;
	if (x == 0) {
		j = y;
	}
	else j = 0;
	for (i = x; i < s; i++) {
		for (j; j < s; j++) {
			if (check(i, j, s, f) == 0) {
				f[i][j] = 'x';
				if (x == s - 1) {
					disp_field(s, f);
					init_field(s, f);
					place(0, y + 1, s, f);
				}
				else place(x + 1, y, s, f);
			}
		}
	}
}

int check(int x, int y, int s, char **f) {

	int i, j;

	for (i = 0; i < s; i++) {
		if (f[i][y] == 'x')
			return 1;
		if (f[x][i] == 'x')
			return 1;
	}

	i = x; j = y;

	while (i >= 0 && j >= 0) {
		if (f[i][j] == 'x') return 1;
		i--; j--;
	}

	i = x; j = y;
	while (i >= 0 && j <= s) {
		if (f[i][j] == 'x') return 1;
		i--; j++;
	}
	return 0;
}

void init_field(int s, char **f) {
	int i, j;
	for (i = 0; i < s; i++) {
		for (j = 0; j < s; j++) {
			f[i][j] = '.';
		}
	}
}

void disp_field(int s, char **f) {
	int i, j;

	for (i = 0; i < s; i++) {
		for (j = 0; j < s; j++) {
			printf("%c", f[i][j]);
		}
		if (i != s - 1) 
			printf("\n");
	}
	printf("\n\n");
}