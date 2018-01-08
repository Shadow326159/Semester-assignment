#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Math.h>
#include <cmath>
#include <Windows.h>
#include <algorithm>
#include "ReadImage.h"

using namespace std;

char *B, *G, *R;
int h, w, n;
double mas_x[20];//Для наглядности изменить на 4
const double minf = -1.3, maxf = 1.5;

double fun(double x)
{
	return (cos(x) - pow(x, 6) - 0.5);
}
double Ln(double X)
{
	double res = 0;
	for (int i = 0; i <= n; i++)
	{
		double slag = fun(mas_x[i]);
		for (int j = 0; j <= n; j++)
			if (i != j) slag *= (X - mas_x[j]) / (mas_x[i] - mas_x[j]);
		res += slag;
	}
	return res;
}

int main()
{
	double a, b;
	FILE* fp = fopen("in.txt", "r");
	fscanf(fp, "%d", &n);
	fscanf(fp, "%lf", &a);
	fscanf(fp, "%lf", &b);
	fclose(fp);
	for (int i = 0; i <= n; i++)
		mas_x[i] = a+i*(b - a) / n;
	GetSize("input.bmp", &h, &w);
	B = new char[h*w];
	G = new char[h*w];
	R = new char[h*w];
	ReadImageFromFile("input.bmp", B, G, R);

	//Рисуем ось x
	for (int j = 0; j<w; j++)
	{
		int i = (int)(h*(0. - minf) / (maxf - minf));
		if (i<h && i >= 0) B[i*w + j] = G[i*w + j] = R[i*w + j] = 0;
	}
	//Рисуем график функции-----------------------------------------------
	for (int j = 0; j<w; j++)
	{
		double x = a + (b - a)*j / w;
		double y = fun(x);
		int i = (int)(h*(y - minf) / (maxf - minf));
		if (i<h && i >= 0) B[i*w + j] = G[i*w + j] = 0;
		//Для непрерывности----------------------------------------------
		double x_next = a + (b - a)*(j + 1) / w;
		double y_next = fun(x_next);
		int i_next = (int)(h*(y_next - minf) / (maxf - minf));
		if (i>i_next)
			for (int k = i - 1; k>i_next; k--)
				if (k<h && k >= 0) B[k*w + j] = G[k*w + j] = 0;
		if (i<i_next)
			for (int k = i + 1; k<i_next; k++)
				if (k<h && k >= 0) B[k*w + j] = G[k*w + j] = 0;
	}
	//Рисуем график полинома-----------------------------------------------
	for (int j = 0; j<w; j++)
	{
		double x = a + (b - a)*j / w;
		double y = Ln(x);
		int i = (int)(h*(y - minf) / (maxf - minf));
		if (i<h && i >= 0) R[i*w + j] =  G[i*w + j] = 0;
		//Для непрерывности----------------------------------------------
		double x_next = a + (b - a)*(j + 1) / w;
		double y_next = Ln(x_next);
		int i_next = (int)(h*(y_next - minf) / (maxf - minf));
		if (i>i_next)
			for (int k = i - 1; k>i_next; k--)
				if (k<h && k >= 0) R[k*w + j] = G[k*w + j] = 0;
		if (i<i_next)
			for (int k = i + 1; k<i_next; k++)
				if (k<h && k >= 0) R[k*w + j] = G[k*w + j] = 0;
	}
	//Вывод--------------------------------------------------------------
	WriteImage("out.bmp", B, G, R);
	FILE* pout = fopen("out.txt", "w");
	for (int i = 0; i <= n; i++)
		fprintf(pout, "%lf\n", Ln(mas_x[i]));
	fclose(pout);
}