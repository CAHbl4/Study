#include <stdio.h>
// ReSharper disable CppPrintfBadFormat

void main(void)
{
	static int mas[] = { 100,200,300 };
	int *ptr1, *ptr2;
	ptr1 = mas;    /*присваивает адрес первого элемента массива указателю */
	ptr2 = &mas[2];/*присваивает адрес третьего элемента массива указателю */
	printf("ptr1=%u,  *ptr1=%d,  &ptr1=%u \n", ptr1, *ptr1, &ptr1);
	ptr1++;      /* увеличение указателя-переход на второй элемент массива*/
	printf("ptr1=%u,  *ptr1=%d,  &ptr1=%u \n", ptr1, *ptr1, &ptr1);
	printf("ptr2=%u,  *ptr2=%d,  &ptr2=%u \n", ptr2, *ptr2, &ptr2);
	++ptr2;      /* выход за конец массива */
	printf("ptr2=%u,  *ptr2=%d,  &ptr2=%u \n", ptr2, *ptr2, &ptr2);
	printf("ptr2-ptr1=%u\n", ptr2 - ptr1);
}