#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Math.h>
#include <cmath>
#include <Windows.h>
#include <algorithm>
#include "ReadImage.h"

using namespace std;

int h, w;
char *B, *G, *R;
const double a = 0.7, b = 1.0, minf = -1.3, maxf = 1.5;

double fun(double x)//cos(x)-x^6-0.5
{
	return (cos(x) - pow(x, 6) - 0.5);
}

double pro(double x)//-sin(x)-6*x^5
{
	return (-sin(x) - 6 * pow(x, 5));
}

void DrawSegment(double x1, double y1, double x2, double y2)
{
	if (x1>x2) 
	{ 
		swap(x1, x2);
		swap(y1, y2); 
	}
	int j1 = (int)((x1 - a) / (b - a)*w);
	int j2 = (int)((x2 - a) / (b - a)*w);
	for (int j = j1; j <= j2; j++)
	{
		double x = a + (b - a)*j / w;
		double y = y1 + (x - x1) / (x2 - x1)*(y2 - y1);
		int i = (int)(h*(y - minf) / (maxf - minf));
		if (i<h && i >= 0 && j >= 0 && j<w) R[i*w + j] = G[i*w + j] = 0;

		//for continuety--------------------------------------------------------
		double x_next = a + (b - a)*(j + 1) / w;
		double y_next = y1 + (x_next - x1) / (x2 - x1)*(y2 - y1);
		int i_next = (int)(h*(y_next - minf) / (maxf - minf));
		if (i>i_next)
			for (int k = i - 1; k>i_next; k--)
				if (k<h && k >= 0 && j >= 0 && j<w) R[k*w + j] = G[k*w + j] = 0;
		if (i<i_next)
			for (int k = i + 1; k<i_next; k++)
				if (k<h && k >= 0 && j >= 0 && j<w) R[k*w + j] = G[k*w + j] = 0;
	}
}

int main()
{
	GetSize("input.bmp", &h, &w);
	B = new char[h*w];
	G = new char[h*w];
	R = new char[h*w];
	ReadImageFromFile("input.bmp", B, G, R);

	//draw axes x
	for (int j = 0; j<w; j++)
	{
		int i = (int)(h*(0. - minf) / (maxf - minf));
		if (i<h && i >= 0) B[i*w + j] = G[i*w + j] = R[i*w + j] = 0;
	}
	//draw graphic of f-----------------------------------------------
	for (int j = 0; j<w; j++)
	{
		double x = a + (b - a)*j / w;
		double y = fun(x);
		int i = (int)(h*(y - minf) / (maxf - minf));
		if (i<h && i >= 0) B[i*w + j] = G[i*w + j] = 0;

		//for continuety----------------------------------------------
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

	//Newton algo----------------------------------------------
	double x_n, x_o = b;
	const double eps = 0.0001;
	while (fabs(fun(x_o)) >= eps)
	{
		x_n = x_o - fun(x_o) / pro(x_o);
		DrawSegment(x_o, fun(x_o), x_n, 0.);
		int j = (int)((x_n - a) / (b - a)*w);
		if (j >= 0 && j<w)
		{
			int i_0 = (int)(h*(0. - minf) / (maxf - minf));
			int i = (int)(h*(fun(x_n) - minf) / (maxf - minf));

			if (i<i_0) swap(i, i_0);
			for (int k = i_0; k <= i; k++)
				if (k<h && k >= 0) R[k*w + j] = G[k*w + j] = 0;
		}

		x_o = x_n;
	}
	//Decision----------------------------------------------------------
	int k1 = 0, k2 = 0;
	double x, xo, xn, a, b, epse;
	FILE* fp = fopen("in.txt", "r");
	fscanf(fp, "%lf", &epse);
	fscanf(fp, "%lf", &a);//[-1;-0.7]
	fscanf(fp, "%lf", &b);
	fscanf(fp, "%lf", &xo);
	fclose(fp);
	while (fabs(a - b)>epse)
	{
		x = (a + b) / 2;
		if (fun(a)*fun(x)<0)
			b = x;
		else
			a = x;
		k1 = k1 + 1;
	}
	while (fabs(fun(xo))>epse)
	{
		xn = xo - fun(xo) / pro(xo);
		xo = xn;
		k2 = k2 + 1;
	}
	FILE* pout = fopen("out.txt", "w");
	fprintf(pout, "Метод дихотомии: %lf\n", fabs(x));
	fprintf(pout, "Количество итераций: %d\n", k1);
	fprintf(pout, "Метод Ньютона: %lf\n", xo);
	fprintf(pout, "Количество итераций: %d\n", k2);
	fclose(pout);
	//----------------------------------------------------------

	WriteImage("out.bmp", B, G, R);
}