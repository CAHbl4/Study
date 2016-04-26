#include<stdio.h>
#define MAXLINE 80
void main(void)
{
	FILE *fi;
	char string[MAXLINE];
	fi = fopen("story.txt", "r");
	while (fgets(string, MAXLINE, fi) != NULL)
		puts(string);
	fclose(fi);
}