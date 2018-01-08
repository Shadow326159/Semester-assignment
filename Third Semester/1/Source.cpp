#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>

using namespace std;

void insertionSort(int *, int);

int main()
{
	const int n = 50000;
	int a[n], b[n];

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

	unsigned int start_time_inserts = clock();
	insertionSort(b, n);
	unsigned int end_time_inserts = clock();
	unsigned int search_time_inserts = end_time_inserts - start_time_inserts;

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

	
	//Сортировка вставками.
	
	//________________________________________________________________________________________________________
	

	fprintf(pout1, "Time Inserts: ");
	fprintf(pout1, "%d\n", search_time_inserts);
	fprintf(pout1, "Time Recording: ");
	fprintf(pout1, "%d \n", search_time_recording);
	fclose(pout1);
	FILE* pout3 = fopen("Output_Value_Inserts.txt", "w");
	for (int i = 0; i < n; i++)
	{
		fprintf(pout3, "%d\n", b[i]);
	}
	fclose(pout3);
}

void insertionSort(int *arrayPtr, int length) // сортировка вставками
{
	int temp, // временная переменная для хранения значения элемента сортируемого массива
		item; // индекс предыдущего элемента
	for (int counter = 1; counter < length; counter++)
	{
		temp = arrayPtr[counter]; // инициализируем временную переменную текущим значением элемента массива
		item = counter - 1; // запоминаем индекс предыдущего элемента массива
		while (item >= 0 && arrayPtr[item] > temp) // пока индекс не равен 0 и предыдущий элемент массива больше текущего
		{
			arrayPtr[item + 1] = arrayPtr[item]; // перестановка элементов массива
			arrayPtr[item] = temp;
			item--;
		}
	}
}