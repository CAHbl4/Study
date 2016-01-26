#include <iostream>
#include <stdio.h>
#include <conio.h>

void main() {
	setlocale(LC_CTYPE, "Rus");
	const float INCHES = 2.54;
	float a;
	printf("ֲגוהטעו חםאקוםטו ג ה‏ילאץ:");
	scanf_s("%f", &a);
	printf("\n%.2f: ה‏ילמג = %.2f לל", a, a * INCHES);
	_getch();
}