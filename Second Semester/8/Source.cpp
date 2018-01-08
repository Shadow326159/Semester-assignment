#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <iostream>
#include<stdlib.h>
#include<math.h>
#include<algorithm>

using namespace std;

double a[10][11];
int p[10];//номера столбцов (для замены)
double x[10];//наши 4 икса(решения)

int main()
{
	FILE* fp = fopen("in.txt", "r"); 
	for (int i = 0; i<10; i++)
		for (int j = 0; j<11; j++)
			fscanf(fp, "%lf", &a[i][j]);
	for (int i = 0; i<10; i++)
		fscanf(fp, "%d", &p);
	fclose(fp);
	FILE* pout = fopen("out.txt", "w");
	int last = 10;//последний ненулевой

	//прямой ход-----------------------------------------------
	for (int i = 0; i<10; i++)
	{
		//вывод матрицы на экран
		for (int i = 0; i<10; i++)
		{
			for (int j = 0; j<11; j++) 
				fprintf(pout, "%8.10lf ", a[i][j]);
			fprintf(pout, "\n"); 
		}
		fprintf(pout, "\n");
		//выбор главного элемента---------------------------------------
		int i_g = i, j_g = i;
		//поиск
		for (int t_i = i; t_i<10; t_i++)
			for (int t_j = i; t_j<10; t_j++)
				if (fabs(a[i_g][j_g])<fabs(a[t_i][t_j])) { i_g = t_i; j_g = t_j; }
		//перестанова строк      
		for (int k = 0; k<11; k++) swap(a[i][k], a[i_g][k]);
		//перестановка столбцов
		for (int k = 0; k<10; k++) swap(a[k][i], a[k][j_g]);
		swap(p[i], p[j_g]);
		//проверка на вырожденные случаи
		if (a[i][i] == 0)
		{
			last = i;
			for (int j = i; j<10; j++)
				if (fabs(a[j][10])>0.00000000001)
				{
					fprintf(pout, "СЛАУ не имеет решения!\n");
					return 0;
				}
			break;
		}

		//------------------------------------------------------------------
		for (int j = i + 1; j<10; j++)
		{
			double  c = a[j][i] / a[i][i];
			for (int k = 0; k<11; k++) a[j][k] -= c*a[i][k];
		}
	}

	//обратный ход------------------------------------------------------
	for (int i = last; i<10; i++) x[p[i]] = 0;
	for (int i = last - 1; i >= 0; i--)
	{
		x[p[i]] = a[i][10];
		for (int j = i + 1; j<10; j++) x[p[i]] -= a[i][j] * x[p[j]];
		x[p[i]] /= a[i][i];
	}
	//вывод на экран-------------------------------------------------
	for (int i = 0; i<10; i++) 
		fprintf(pout, "%lf ", x[i]);
	fprintf(pout, "\n");
	return 0;
	fclose(pout);
}