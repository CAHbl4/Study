﻿#include <stdio.h>
#include <windows.h>

/*
*
* amatu, 09.03.2016 10:59:32
*/

void main()
{
	long *pl;
	int i;

	//Выделяем память под динамический массив.
	pl = (long*)calloc(10, sizeof(long));
	if (pl)
	{
		// память выделена, можем с ней работать
		for (i = 0; i<10; i++)
			pl[i] = i * 2;
		for (i = 0; i<10; i++)
			printf("pl[%d]=%ld\n", i, *(pl + i));
		// Теперь нам необходимо увеличить размер массива
		pl = (long*) realloc(pl, 20 * sizeof(long));
		if (pl)
		{
			//Работаем с увеличенным массивом. 
			// Старые значения сохранились, дополним их новыми.
			for (i = 10; i<20; i++)
				pl[i] = i * 2 + 1;
			for (i = 0; i<20; i++)
				printf("pl[%d]=%ld\n", i, *(pl + i));
		}
		else
		{
			// В данном случае память не освобождаем, т.к. 
			// она была уже освобождена в функции realloc,
			// после чего realloc вышла с ошибкой, не выделив
			// память заново.
			return;
		}
		// В конце работы освобождаем память, 
		// на которую указывает pl
		free(pl);
	}
	else
	{
		printf("Недостаточно памяти\n");
	}
}
