#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>

int main()
{
	setlocale(LC_ALL, "Russian");
	FILE * pf = fopen("input.txt", "r");
	int k = 0;
	char c;
	bool slovo = false;
	FILE* pout = fopen("out.txt", "w");

	if (pf == NULL) perror("������ �������� �����");
	else
	{
		while ((c = fgetc(pf)) != EOF)
		{
			if ((c == '\n') || (c == ' ') || (c == '\t') || (c == ',') || (c == '.') || (c == ';') || (c == '-') || (c == '_') || (c == ':') || (c == '/') || (c == '!') || (c == '?'))
			{
				slovo = false;
				continue;
			}
			if (((c >= '�') && (c <= '�') && (slovo == false)) || ((c >= '�') && (c <= '�') && (slovo == false)))
			{
				k++;
				slovo = true;
				continue;
			}
			if (((c >= '�') && (c <= '�') && (slovo == true)) || ((c >= '�') && (c <= '�') && (slovo == true)))
				continue;
		}
	}
	fclose(pf);
	//FILE* pout = fopen("out.txt", "w");
	fprintf(pout, "%d", k);
	fclose(pout);
}