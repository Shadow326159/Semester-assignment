#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

template <typename T> T Summa(T *a, int n)
{
	T sum = 0;
	for (int i = 0; i < n; i++)
		sum += a[i];
	return sum;
}

template <typename T> T Summa(T *a, float n)
{
	T sum = 0;
	for (int i = 0; i < n; i++)
		sum += a[i];
	return sum;
}

template <typename T> T Summa(T *a, double n)
{
	T sum = 0;
	for (int i = 0; i < n; i++)
		sum += a[i];
	return sum;
}

const int n = 15;
int in[n], sum_in;
float f[n], sum_f;
double d[n], sum_d;

int main()
{
	FILE* pf1 = fopen("input_int.txt", "r");
	for (int i = 0; i < n; i++)
		fscanf(pf1, "%d", &in[i]);
	fclose(pf1);

	FILE* pf2 = fopen("input_float.txt", "r");
	for (int i = 0; i < n; i++)
		fscanf(pf2, "%f", &f[i]);
	fclose(pf2);

	FILE* pf3 = fopen("input_double.txt", "r");
	for (int i = 0; i < n; i++)
		fscanf(pf3, "%lf", &d[i]);
	fclose(pf3);

	FILE* pout1 = fopen("output_int.txt", "w");
	fprintf(pout1, "%d", Summa(in, n));
	fclose(pout1);

	FILE* pout2 = fopen("output_float.txt", "w");
	fprintf(pout2, "%f", Summa(f, n));
	fclose(pout2);

	FILE* pout3 = fopen("output_double.txt", "w");
	fprintf(pout3, "%lf", Summa(d, n));
	fclose(pout3);
}