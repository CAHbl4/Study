#include <stdio.h>
#include <windows.h>

/*
*
* amatu, 09.03.2016 10:52:56
*/

void main()
{
	long *pl;
	short *ps;
	int i;

	//Выделяем память под динамические массивы.
	//В calloc передаём количество элементов и размер элемента.
	//В malloc передаём полный размер выделяемого блока в
	//байтах.

	pl = (long*)calloc(10, sizeof(long));
	ps = (short*)malloc(10 * sizeof(short));

	if (pl && ps) // если оба указателя не равны NULL (0)
	{
		// память выделена, можем с ней работать
		for (i = 0; i<10; i++)
		{
			pl[i] = i * 2;
			ps[i] = i * 2 + 1;
		}
		for (i = 0; i<10; i++)
			printf("pl[%d]=%d,ps[%d]=%d\n", i, *(pl + i), i, *(ps + i));
		// В конце работы освобождаем память, 
		// на которую указывают pl и ps.
		free(pl);
		free(ps);
	}
	else
	{
		printf("Недостаточно памяти\n");
	}
}
