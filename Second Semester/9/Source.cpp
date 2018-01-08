#define _CRT_SECURE_NO_WARNINGS
#include <cstdlib>
#include <iostream>
#include <math.h>
#include <algorithm>
#include "ReadImage.h"

using namespace std;

unsigned char *B, *G, *R;//массивы под цвета
int w, h;//ширина и высота
const double a = 0, b = 20.0, min_f = -1., max_f = 10.;

//преобразование координат-----------------------------------------------------------------
double j_to_x(int j)
{
	return a + (b - a)*j / w;
}
double i_to_y(int i)
{
	return min_f + (max_f - min_f)*i / h;
}
int x_to_j(double x)
{
	return w*(x - a) / (b - a);
}
int y_to_i(double y)
{
	return h*(y - min_f) / (max_f - min_f);
}
//---------------------------------------------------------------------------------------------------
void DrawSegment(double x1, double y1, double x2, double y2, unsigned char b, unsigned char g, unsigned char r);//рисовалка графика
const int n = 10;//размер матрицы
double  eps;//точность
double A[n][n];//сама матрица
double f[n];//вектор-столбец правых частей
double r[n], y_old[n], y_new[n];

double scal_mul(double* l, double* r)//скалярное произведение
{
	double res = 0;
	for (int i = 0; i<n; i++)
		res += l[i] * r[i];
	return res;
}
void matrixAmul(double* res, double* arg)//произведение матрицы на вектор?
{
	for (int i = 0; i<n; i++)
	{
		res[i] = 0;
		for (int j = 0; j<n; j++)
			res[i] += A[i][j] * arg[j];
	}
}

int main()
{
	FILE* fp = fopen("input.txt", "r");
	fscanf(fp, "%lf", &eps);
	for (int i = 0; i<10; i++)
		for (int j = 0; j<10; j++)
			fscanf(fp, "%lf", &A[i][j]);
	for (int i = 0; i<10; i++)
		fscanf(fp, "%lf", &f[i]);
	fclose(fp);
	GetSize("in.bmp", &h, &w);//считывание размера файла
	B = new unsigned char[h*w];
	G = new unsigned char[h*w];
	R = new unsigned char[h*w];
	ReadImageFromFile("in.bmp", B, G, R);//считывание его содержимого
	FILE* pout = fopen("output.txt", "w");
	//рисуем оси---------------------------------------------------------
	for (int j = 0; j<w; j++)
	{
		int i = y_to_i(0.);
		B[i*w + j] = G[i*w + j] = R[i*w + j] = 0;
	}
	//находим r^0
	matrixAmul(r, y_old);
	for (int i = 0; i<n; i++) 
		r[i] = -f[i];
	int step_counter = 0;
	double old_r = sqrt(scal_mul(r, r));
	while (scal_mul(r, r) >= eps*eps)
	{
		//находим tau_k
		double Ar[n];
		matrixAmul(Ar, r);
		double tau = scal_mul(r, r) / scal_mul(r, Ar);
		//находим y^(k+1)
		for (int i = 0; i<n; i++)
			y_new[i] = y_old[i] - tau*r[i];
		//находим r^(k+1)
		matrixAmul(r, y_new);
		for (int i = 0; i<n; i++)
			r[i] -= f[i];
		//y_old = y_new
		for (int i = 0; i<n; i++)
			y_old[i] = y_new[i];
		//рисование
		step_counter++;
		DrawSegment(step_counter - 1, old_r, step_counter, sqrt(scal_mul(r, r)), 0, 0, 255);
		old_r = sqrt(scal_mul(r, r));
	}
	fprintf(pout, "%d\n", step_counter);
	for (int i = 0; i<n; i++)
		fprintf(pout, "%lf ", y_old[i]);
	fclose(pout);
	fclose(pout);
	WriteImage("out.bmp", B, G, R);
}

void DrawSegment(double x1, double y1, double x2, double y2, unsigned char b, unsigned char g, unsigned char r)
{
	if (x1 != x2)
	{
		if (x1>x2)
		{
			swap(x1, x2);
			swap(y1, y2);
		}
		int j1 = max(x_to_j(x1), 0);
		int j2 = min(x_to_j(x2), w - 1);
		for (int j = j1; j <= j2; j++)
		{
			double x = j_to_x(j);
			double y = y1 + (y2 - y1) / (x2 - x1)*(x - x1);
			int i = y_to_i(y);
			double x_next = j_to_x(j + 1);
			double y_next = y1 + (y2 - y1) / (x2 - x1)*(x_next - x1);
			int i_next = y_to_i(y_next);
			if (i >= 0 && i<h)
			{
				B[i*w + j] = b; G[i*w + j] = g; R[i*w + j] = r;
			}
			if (i_next>i)
				for (int k = i + 1; k<i_next; k++)
					if (k >= 0 && k<h)
					{
						B[k*w + j] = b; G[k*w + j] = g; R[k*w + j] = r;
					}
			if (i_next<i)
				for (int k = i - 1; k>i_next; k--)
					if (k >= 0 && k<h)
					{
						B[k*w + j] = b; G[k*w + j] = g; R[k*w + j] = r;
					}
		}
	}
}