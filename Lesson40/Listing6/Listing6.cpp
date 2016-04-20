#include <stdio.h>      // �������� ������� �����-������
#include <stdlib.h>     // �������� ������� exit()
#include <windows.h>    // �������� ������� CharToOem()
char* Rus(const char* text);

int main(void)
{
	char fileName[256];    // ���� � �����
	FILE *in;              // ���������, ����������� ����
	char buff[512];        // ������ ��� ����� ��������
	unsigned int num;      // ����� ����������� ��������
	int numChars = 0;        // ��������� ����� �������� := 0
	int numLines = 0;        // ��������� ����� ����� := 0
	unsigned int i;        // ���������� �����

	printf(Rus("������� ��� �����: "));
	scanf("%s", fileName);

	if ((in = fopen(fileName, "rb")) != NULL)   // ��������� ���� �� ������ � �������� ������
		while ((num = fread(buff, 1, 512, in))>0)
		{
			// ������
			// ���� �� 512 ��������. num -- ����� �������
			// ����������� ��������. ���� ������������, ����
			// num > 0
			numChars += num;                     // ����������� ����� ��������

												 // ������������ ����� �������� �������� ������
			for (i = 0; i<num; i++)
				if (buff[i] == '\n')
					++numLines;                  // ����������� ����� �����
		}
	else
	{
		// ��� ������ �������� �����
		// ������� ��������� �� ������
		printf(Rus("�� ���� ������� ���� ��� ������\n"));
		exit(1);  // ��������� ������ ��������� � ����� 1
				  // ���������� ����������
	}
	fclose(in);

	// ������� ���������
	printf(Rus("����� �������� � ����� = %d\n"), numChars);
	printf(Rus("����� ����� � ����� = %d\n"), numLines);
	return 0; // ���������� ��� ��������� ����������
}

char bufRus[256];
char* Rus(const char* text)
{
	CharToOemA(text, bufRus);
	return bufRus;
}