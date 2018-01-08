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

	if (pf == NULL) perror("Ошибка открытия файла");
	else
	{
		while ((c = fgetc(pf)) != EOF)
		{
			if ((c == '\n') || (c == ' ') || (c == '\t') || (c == ',') || (c == '.') || (c == ';') || (c == '-') || (c == '_') || (c == ':') || (c == '/') || (c == '!') || (c == '?'))
			{
				slovo = false;
				continue;
			}
			if (((c >= 'а') && (c <= 'я') && (slovo == false)) || ((c >= 'А') && (c <= 'Я') && (slovo == false)))
			{
				k++;
				slovo = true;
				continue;
			}
			if (((c >= 'а') && (c <= 'я') && (slovo == true)) || ((c >= 'А') && (c <= 'Я') && (slovo == true)))
				continue;
		}
	}
	fclose(pf);
	//FILE* pout = fopen("out.txt", "w");
	fprintf(pout, "%d", k);
	fclose(pout);
}