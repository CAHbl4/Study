#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h>

char* Rus(const char* text);

int main(void)
{
	int age;
	float assets;
	char pet[30];
	printf(Rus("Укажите возраст, состояние и любимое животное :\n"));
	scanf("%d  %f", &age, &assets);
	scanf("%s", pet); /* & отсутствует при указании массива символов */
	printf("%d\n%f\n%s\n", age, assets, pet);
	system("pause");
}

char bufRus[256];

char* Rus(const char* text)
{
	CharToOemA(text, bufRus);
	return bufRus;
}
