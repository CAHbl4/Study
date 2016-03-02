#include <conio.h>
#include <iostream>

void main() {
	setlocale(LC_CTYPE, "Rus");

	//Код программы
	int i, i2, i3;
	for (i = 1; i <= 8; i++)
	{
		i2 = i * i;
		i3 = i2 * i;
		printf("%4d %4d %4\n", i, i2, i3);
	}
	_getch();
}