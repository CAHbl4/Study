#include <stdio.h>
#include <windows.h>

/*
* Задан текст, состоящий из строк. Строк не менее 10. В строке не менее 5
* слов. В слове не менее 5 символов. Слова разделены 1 пробелом.
* Осуществить сортировку строк по количеству в них заданного символа в
* неубывающем порядке.
* Программа должна выполнять ввод текста, вывод его исходного варианта,
* выполнять необходимые действия и выводить полученный текст.
*
* a.matuzov, 3/15/2016 7:02:43 PM
*/
#define MIN_STRINGS		10
#define MAX_STRINGS		100
#define MIN_WORDS		5
#define MIN_CHARS		5

char* Rus(const char* text);

void main() {

	//Code goes here


}

char bufRus[256];

char* Rus(const char* text)
{
	CharToOemA(text, bufRus);
	return bufRus;
}