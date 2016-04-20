#include <stdio.h>      // Описания функций ввода-вывода
#include <stdlib.h>     // Описание функции exit()
#include <windows.h>    // Описание функции CharToOem()
char* Rus(const char* text);

int main(void)
{
	char fileName[256];    // Путь к файлу
	FILE *in;              // Структура, описывающая файл
	char buff[512];        // Массив для ввода символов
	unsigned int num;      // Число прочитанных символов
	int numChars = 0;        // Суммарное число символов := 0
	int numLines = 0;        // Суммарное число строк := 0
	unsigned int i;        // Переменная цикла

	printf(Rus("Введите имя файла: "));
	scanf("%s", fileName);

	if ((in = fopen(fileName, "rb")) != NULL)   // Открываем файл на чтение в двоичном режиме
		while ((num = fread(buff, 1, 512, in))>0)
		{
			// Читаем
			// блок из 512 символов. num -- число реально
			// прочитанных символов. Цикл продолжается, пока
			// num > 0
			numChars += num;                     // Увеличиваем число символов

												 // Подсчитываем число символов перевода строки
			for (i = 0; i<num; i++)
				if (buff[i] == '\n')
					++numLines;                  // Увеличиваем число строк
		}
	else
	{
		// При ошибке открытия файла
		// Выдаётся сообщение об ошибке
		printf(Rus("Не могу открыть файл для чтения\n"));
		exit(1);  // закончить работу программы с кодом 1
				  // ошибочного завершения
	}
	fclose(in);

	// Выводим результат
	printf(Rus("Число символов в файле = %d\n"), numChars);
	printf(Rus("Число строк в файле = %d\n"), numLines);
	return 0; // Возвращаем код успешного завершения
}

char bufRus[256];
char* Rus(const char* text)
{
	CharToOemA(text, bufRus);
	return bufRus;
}