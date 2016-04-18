#include <windows.h>
#include <stdio.h>
#include <conio.h>

int main(void)
{
	int ch, ch2;
	while (1) {
		ch = _getch();
		if (ch == 224) {
			if (ch2 = _getch()) {
				ch = 256 + ch2;
			}
		}
		printf("ch = %d \n", ch);
	}



	return 0;
}