#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>

using namespace std;

const int n = 50000;
int a[n], b[n];

template<class T>
void quickSort(T* a, long N)
{
	long i = 0, j = N - 1;
	T temp, pivot;
	pivot = a[(rand() % N)];
	do
	{
		while (a[i] < pivot) i++;
		while (a[j] > pivot) j--;
		if (i <= j)
		{
			temp = a[i];
			a[i] = a[j];
			a[j] = temp;
			i++;
			j--;
		}
	} while (i <= j);

	// рекурсивные вызовы, если есть, что сортировать 
	if (j > 0) quickSort(a, j);
	if (N > i) quickSort(a + i, N - i);
}

int main()
{
	unsigned int start_time_reading = clock();
	FILE* pf = fopen("input.txt", "r");
	for (int i = 0; i < n; i++)
		fscanf(pf, "%d", &a[i]);
	fclose(pf);
	unsigned int end_time_reading = clock();
	unsigned int search_time_reading = end_time_reading - start_time_reading;

	for (int i = 0; i < n; i++)
		b[i] = a[i];

	FILE* mass_1 = fopen("mas1.txt", "w");
	for (int i = 0; i < n; i++)
		fprintf(mass_1, "%d\n", a[i]);
	fclose(mass_1);
	FILE* mass_2 = fopen("mas2.txt", "w");
	for (int i = 0; i < n; i++)
		fprintf(mass_2, "%d\n", b[i]);
	fclose(mass_2);

	unsigned int start_time_bubble = clock();
	//Пузырьковая сортировка.
	for (int i = 0; i< n - 1; i++)
		for (int j = 0; j < n - 1 - i; j++)
			if (a[j] > a[j + 1])
				swap(a[j], a[j + 1]);
	//________________________________________________________________________________________________________
	unsigned int end_time_bubble = clock();
	unsigned int search_time_bubble = end_time_bubble - start_time_bubble;

	FILE* pout1 = fopen("Output_Time.txt", "w");
	fprintf(pout1, "Time Reading: ");
	fprintf(pout1, "%d \n", search_time_reading);
	fprintf(pout1, "Time Bubble: ");
	fprintf(pout1, "%d \n", search_time_bubble);
	FILE* pout2 = fopen("Output_Value_Bubble.txt", "w");
	unsigned int start_time_recording = clock();
	for (int i = 0; i < n; i++)
		fprintf(pout2, "%d\n", a[i]);
	unsigned int end_time_recording = clock();
	unsigned int search_time_recording = end_time_recording - start_time_recording;
	fclose(pout2);

	unsigned int start_time_inserts = clock();
	//Быстрая сортировка .
	quickSort(b, n);
	//________________________________________________________________________________________________________
	unsigned int end_time_inserts = clock();
	unsigned int search_time_inserts = end_time_inserts - start_time_inserts;

	fprintf(pout1, "Time qsort: ");
	fprintf(pout1, "%d\n", search_time_inserts);
	fprintf(pout1, "Time Recording: ");
	fprintf(pout1, "%d \n", search_time_recording);
	fclose(pout1);
	FILE* pout3 = fopen("Output_Value_qsort.txt", "w");
	for (int i = 0; i < n; i++)
	{
		fprintf(pout3, "%d\n", b[i]);
	}
	fclose(pout3);
}