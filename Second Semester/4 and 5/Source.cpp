//#define _CRT_SECURE_NO_WARNINGS
#include <cstdlib>
#include <iostream>
#include "ReadImage.h"

double f(double x, double y)//���� �������
{ 
	return 7*(x*x + y*y);
}

int n, h, w;
double a[14];//��������� ������ ��� n ����� a
unsigned char col[255];//��������� ������ ��� n+1 �����
unsigned char *B, *G, *R;//�������� �������� � ���������� ReadImage.h ��� ����������, � char �� unsigned char

int main()
{
	FILE* pf = fopen("input.txt", "r");
	fscanf(pf, "%d", &n);//��������� n
	for (int i = 0; i < n; i++)
		fscanf(pf, "%lf", &a[i]);//��������� n ����� a
	for (int i = 0; i < n+1; i++)
		fscanf(pf, "%hhd", &col[i]);//��������� n+1 ������
	fclose(pf);

	GetSize("in.bmp", &h, &w);//�������� ������ �����
	//������ �� b g r ������� ������� �����������
	B = new unsigned char[h*w];
	G = new unsigned char[h*w];
	R = new unsigned char[h*w];

	ReadImageFromFile("in.bmp", B, G, R);//��������� �����������
	for (int i = 0; i<h; i++)
		for (int j = 0; j<w; j++)
		{
			double val = f((double)j / (w - 1), (double)i / (h - 1));//��������� ����������� ����� ���������� � ������������	(x = j/w-1; y = i/h-1)
			int k = 0;
			while (k<11 && val>a[k])
				k++;	
			B[i*w + j] = col[k];
			G[i*w + j] = col[k];
			R[i*w + j] = col[k];
		}
	//����������� 2.5
	unsigned char *b, *g, *r;
	b = new unsigned char[h*w];
	g = new unsigned char[h*w];
	r = new unsigned char[h*w];
	for (int i = 0; i<h; i++)
		for (int j = 0; j<w; j++)
			r[i*w + j] = g[i*w + j] = b[i*w + j] = 255;//����������� ��� ����� � �����
	for (int i = 0; i<h - 1; i++)
		for (int j = 0; j<w - 1; j++)
			if (R[(i + 1)*w + j] != R[i*w + j] || R[i*w + j] != R[i*w + j + 1]) //���� �� ����� x-1 ��� �� ����� y+1, ��:
				r[i*w + j] = g[i*w + j] = b[i*w + j] = 0;//������� ����� ������
	WriteImage("out2_4.bmp", B, G, R);
	WriteImage("out2_5.bmp", b, g, r);
}