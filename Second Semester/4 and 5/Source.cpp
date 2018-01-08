//#define _CRT_SECURE_NO_WARNINGS
#include <cstdlib>
#include <iostream>
#include "ReadImage.h"

double f(double x, double y)//Наша функция
{ 
	return 7*(x*x + y*y);
}

int n, h, w;
double a[14];//Объявляем массив для n точек a
unsigned char col[255];//Объявляем массив для n+1 цвета
unsigned char *B, *G, *R;//Пришлось заменить в библиотеке ReadImage.h тип переменных, с char на unsigned char

int main()
{
	FILE* pf = fopen("input.txt", "r");
	fscanf(pf, "%d", &n);//Считываем n
	for (int i = 0; i < n; i++)
		fscanf(pf, "%lf", &a[i]);//Считываем n точек a
	for (int i = 0; i < n+1; i++)
		fscanf(pf, "%hhd", &col[i]);//Считываем n+1 цветов
	fclose(pf);

	GetSize("in.bmp", &h, &w);//Получаем размер файла
	//Делаем из b g r массивы размера изображения
	B = new unsigned char[h*w];
	G = new unsigned char[h*w];
	R = new unsigned char[h*w];

	ReadImageFromFile("in.bmp", B, G, R);//Считываем изображение
	for (int i = 0; i<h; i++)
		for (int j = 0; j<w; j++)
		{
			double val = f((double)j / (w - 1), (double)i / (h - 1));//Установка соотношения между квардратом и изображением	(x = j/w-1; y = i/h-1)
			int k = 0;
			while (k<11 && val>a[k])
				k++;	
			B[i*w + j] = col[k];
			G[i*w + j] = col[k];
			R[i*w + j] = col[k];
		}
	//Семестровое 2.5
	unsigned char *b, *g, *r;
	b = new unsigned char[h*w];
	g = new unsigned char[h*w];
	r = new unsigned char[h*w];
	for (int i = 0; i<h; i++)
		for (int j = 0; j<w; j++)
			r[i*w + j] = g[i*w + j] = b[i*w + j] = 255;//Закрашиваем все точки в белое
	for (int i = 0; i<h - 1; i++)
		for (int j = 0; j<w - 1; j++)
			if (R[(i + 1)*w + j] != R[i*w + j] || R[i*w + j] != R[i*w + j + 1]) //Если не равно x-1 или не равно y+1, то:
				r[i*w + j] = g[i*w + j] = b[i*w + j] = 0;//сделать точку чёрной
	WriteImage("out2_4.bmp", B, G, R);
	WriteImage("out2_5.bmp", b, g, r);
}