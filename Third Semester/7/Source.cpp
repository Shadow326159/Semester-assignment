#include <fstream>
#include <ctime>
using namespace std;

int main()
{
	long double summ[32];
	unsigned int times[32];
	long long n, i;
	ifstream fin("input.txt");
	fin >> n;
	fin.close();
	for (i = 0; i < 32; i++) // Обнуляем массив
		summ[i] = 0;

	unsigned int start_time_1 = clock();//без разворота
	for (i = 1; i <= n; i++)
		summ[1] += i;
	unsigned int end_time_1 = clock();
	unsigned int search_time_1 = end_time_1 - start_time_1;
	times[1] = search_time_1;

	unsigned int start_time_2 = clock();
	for (i = 1; i < n; i += 2)
		summ[2] += 2 * i + 1;
	for (; i <= n; i++)
		summ[2] += i;
	unsigned int end_time_2 = clock();
	unsigned int search_time_2 = end_time_2 - start_time_2;
	times[2] = search_time_2;

	unsigned int start_time_3 = clock();
	for (i = 1; i <= n - 2; i += 3)
		summ[3] += 3 * i + 1 + 2;
	for (; i <= n; i++)
		summ[3] += i;
	unsigned int end_time_3 = clock();
	unsigned int search_time_3 = end_time_3 - start_time_3;
	times[3] = search_time_3;

	unsigned int start_time_4 = clock();
	for (i = 1; i <= n - 3; i += 4)
		summ[4] += 4 * i + 1 + 2 + 3;
	for (; i <= n; i++)
		summ[4] += i;
	unsigned int end_time_4 = clock();
	unsigned int search_time_4 = end_time_4 - start_time_4;
	times[4] = search_time_4;

	unsigned int start_time_5 = clock();
	for (i = 1; i <= n - 5; i += 6)
		summ[5] += i + (i + 1) + (i + 2) + (i + 3) + (i + 4) + (i + 5);
	for (; i <= n; i++)
		summ[5] += i;
	unsigned int end_time_5 = clock();
	unsigned int search_time_5 = end_time_5 - start_time_5;
	times[5] = search_time_5;

	unsigned int start_time_6 = clock();
	for (i = 1; i <= n - 6; i += 7)
		summ[6] += i + (i + 1) + (i + 2) + (i + 3) + (i + 4) + (i + 5) + (i + 6);
	for (; i <= n; i++)
		summ[6] += i;
	unsigned int end_time_6 = clock();
	unsigned int search_time_6 = end_time_6 - start_time_6;
	times[6] = search_time_6;

	unsigned int start_time_7 = clock();
	for (i = 1; i <= n - 7; i += 8)
		summ[7] += i + (i + 1) + (i + 2) + (i + 3) + (i + 4) + (i + 5) + (i + 6) + (i + 7);
	for (; i <= n; i++)
		summ[7] += i;
	unsigned int end_time_7 = clock();
	unsigned int search_time_7 = end_time_7 - start_time_7;
	times[7] = search_time_7;

	unsigned int start_time_8 = clock();
	for (i = 1; i <= n - 8; i += 9)
		summ[8] += i + (i + 1) + (i + 2) + (i + 3) + (i + 4) + (i + 5) + (i + 6) + (i + 7) + (i + 8);
	for (; i <= n; i++)
		summ[8] += i;
	unsigned int end_time_8 = clock();
	unsigned int search_time_8 = end_time_8 - start_time_8;
	times[8] = search_time_8;

	unsigned int start_time_9 = clock();
	for (i = 1; i <= n - 9; i += 10)
		summ[9] += i + (i + 1) + (i + 2) + (i + 3) + (i + 4) + (i + 5) + (i + 6) + (i + 7) + (i + 8) + (i + 9);
	for (; i <= n; i++)
		summ[9] += i;
	unsigned int end_time_9 = clock();
	unsigned int search_time_9 = end_time_9 - start_time_9;
	times[9] = search_time_9;

	unsigned int start_time_10 = clock();
	for (i = 1; i <= n - 10; i += 11)
		summ[10] += i + (i + 1) + (i + 2) + (i + 3) + (i + 4) + (i + 5) + (i + 6) + (i + 7) + (i + 8) + (i + 9) + (i + 10);
	for (; i <= n; i++)
		summ[10] += i;
	unsigned int end_time_10 = clock();
	unsigned int search_time_10 = end_time_10 - start_time_10;
	times[10] = search_time_10;

	unsigned int start_time_11 = clock();
	for (i = 1; i <= n - 11; i += 12)
		summ[11] += i + (i + 1) + (i + 2) + (i + 3) + (i + 4) + (i + 5) + (i + 6) + (i + 7) + (i + 8) + (i + 9) + (i + 10) + (i + 11);
	for (; i <= n; i++)
		summ[11] += i;
	unsigned int end_time_11 = clock();
	unsigned int search_time_11 = end_time_11 - start_time_11;
	times[11] = search_time_11;

	unsigned int start_time_12 = clock();
	for (i = 1; i <= n - 12; i += 13)
		summ[12] += i + (i + 1) + (i + 2) + (i + 3) + (i + 4) + (i + 5) + (i + 6) + (i + 7) + (i + 8) + (i + 9) + (i + 10) + (i + 11) + (i + 12);
	for (; i <= n; i++)
		summ[12] += i;
	unsigned int end_time_12 = clock();
	unsigned int search_time_12 = end_time_12 - start_time_12;
	times[12] = search_time_12;

	unsigned int start_time_13 = clock();
	for (i = 1; i <= n - 13; i += 14)
		summ[13] += i + (i + 1) + (i + 2) + (i + 3) + (i + 4) + (i + 5) + (i + 6) + (i + 7) + (i + 8) + (i + 9) + (i + 10) + (i + 11) + (i + 12) + (i + 13);
	for (; i <= n; i++)
		summ[13] += i;
	unsigned int end_time_13 = clock();
	unsigned int search_time_13 = end_time_13 - start_time_13;
	times[13] = search_time_13;

	unsigned int start_time_14 = clock();
	for (i = 1; i <= n - 14; i += 15)
		summ[14] += i + (i + 1) + (i + 2) + (i + 3) + (i + 4) + (i + 5) + (i + 6) + (i + 7) + (i + 8) + (i + 9) + (i + 10) + (i + 11) + (i + 12) + (i + 13) + (i + 14);
	for (; i <= n; i++)
		summ[14] += i;
	unsigned int end_time_14 = clock();
	unsigned int search_time_14 = end_time_14 - start_time_14;
	times[14] = search_time_14;

	unsigned int start_time_15 = clock();
	for (i = 1; i <= n - 15; i += 16)
		summ[15] += i + (i + 1) + (i + 2) + (i + 3) + (i + 4) + (i + 5) + (i + 6) + (i + 7) + (i + 8) + (i + 9) + (i + 10) + (i + 11) + (i + 12) + (i + 13) + (i + 14) + (i + 15);
	for (; i <= n; i++)
		summ[15] += i;
	unsigned int end_time_15 = clock();
	unsigned int search_time_15 = end_time_15 - start_time_15;
	times[15] = search_time_15;

	unsigned int start_time_16 = clock();
	for (i = 1; i <= n - 16; i += 17)
		summ[16] += i + (i + 1) + (i + 2) + (i + 3) + (i + 4) + (i + 5) + (i + 6) + (i + 7) + (i + 8) + (i + 9) + (i + 10) + (i + 11) + (i + 12) + (i + 13) + (i + 14) + (i + 15) + (i + 16);
	for (; i <= n; i++)
		summ[16] += i;
	unsigned int end_time_16 = clock();
	unsigned int search_time_16 = end_time_16 - start_time_16;
	times[16] = search_time_16;

	unsigned int start_time_17 = clock();
	for (i = 1; i <= n - 17; i += 18)
		summ[17] += i + (i + 1) + (i + 2) + (i + 3) + (i + 4) + (i + 5) + (i + 6) + (i + 7) + (i + 8) + (i + 9) + (i + 10) + (i + 11) + (i + 12) + (i + 13) + (i + 14) + (i + 15) + (i + 16) + (i + 17);
	for (; i <= n; i++)
		summ[17] += i;
	unsigned int end_time_17 = clock();
	unsigned int search_time_17 = end_time_17 - start_time_17;
	times[17] = search_time_17;

	unsigned int start_time_18 = clock();
	for (i = 1; i <= n - 18; i += 19)
		summ[18] += i + (i + 1) + (i + 2) + (i + 3) + (i + 4) + (i + 5) + (i + 6) + (i + 7) + (i + 8) + (i + 9) + (i + 10) + (i + 11) + (i + 12) + (i + 13) + (i + 14) + (i + 15) + (i + 16) + (i + 17) + (i + 18);
	for (; i <= n; i++)
		summ[18] += i;
	unsigned int end_time_18 = clock();
	unsigned int search_time_18 = end_time_18 - start_time_18;
	times[18] = search_time_18;

	unsigned int start_time_19 = clock();
	for (i = 1; i <= n - 19; i += 20)
		summ[19] += i + (i + 1) + (i + 2) + (i + 3) + (i + 4) + (i + 5) + (i + 6) + (i + 7) + (i + 8) + (i + 9) + (i + 10) + (i + 11) + (i + 12) + (i + 13) + (i + 14) + (i + 15) + (i + 16) + (i + 17) + (i + 18) + (i + 19);
	for (; i <= n; i++)
		summ[19] += i;
	unsigned int end_time_19 = clock();
	unsigned int search_time_19 = end_time_19 - start_time_19;
	times[19] = search_time_19;

	unsigned int start_time_20 = clock();
	for (i = 1; i <= n - 20; i += 21)
		summ[20] += 21 * i + 1 + 2 + 3 + 4 + 5 + 6 + 7 + 8 + 9 + 10 + 11 + 12 + 13 + 14 + 15 + 16 + 17 + 18 + 19 + 20;
	for (; i <= n; i++)
		summ[20] += i;
	unsigned int end_time_20 = clock();
	unsigned int search_time_20 = end_time_20 - start_time_20;
	times[20] = search_time_20;

	unsigned int start_time_21 = clock();
	for (i = 1; i <= n - 21; i += 22)
		summ[21] += 22 * i + 1 + 2 + 3 + 4 + 5 + 6 + 7 + 8 + 9 + 10 + 11 + 12 + 13 + 14 + 15 + 16 + 17 + 18 + 19 + 20 + 21;
	for (; i <= n; i++)
		summ[21] += i;
	unsigned int end_time_21 = clock();
	unsigned int search_time_21 = end_time_21 - start_time_21;
	times[21] = search_time_21;

	unsigned int start_time_22 = clock();
	for (i = 1; i <= n - 22; i += 23)
		summ[22] += 23 * i + 1 + 2 + 3 + 4 + 5 + 6 + 7 + 8 + 9 + 10 + 11 + 12 + 13 + 14 + 15 + 16 + 17 + 18 + 19 + 20 + 21 + 22;
	for (; i <= n; i++)
		summ[22] += i;
	unsigned int end_time_22 = clock();
	unsigned int search_time_22 = end_time_22 - start_time_22;
	times[22] = search_time_22;

	unsigned int start_time_23 = clock();
	for (i = 1; i <= n - 23; i += 24)
		summ[23] += 24 * i + 1 + 2 + 3 + 4 + 5 + 6 + 7 + 8 + 9 + 10 + 11 + 12 + 13 + 14 + 15 + 16 + 17 + 18 + 19 + 20 + 21 + 22 + 23;
	for (; i <= n; i++)
		summ[23] += i;
	unsigned int end_time_23 = clock();
	unsigned int search_time_23 = end_time_23 - start_time_23;
	times[23] = search_time_23;

	unsigned int start_time_24 = clock();
	for (i = 1; i <= n - 24; i += 25)
		summ[24] += 25 * i + 1 + 2 + 3 + 4 + 5 + 6 + 7 + 8 + 9 + 10 + 11 + 12 + 13 + 14 + 15 + 16 + 17 + 18 + 19 + 20 + 21 + 22 + 23 + 24;
	for (; i <= n; i++)
		summ[24] += i;
	unsigned int end_time_24 = clock();
	unsigned int search_time_24 = end_time_24 - start_time_24;
	times[24] = search_time_24;

	unsigned int start_time_25 = clock();
	for (i = 1; i <= n - 25; i += 26)
		summ[25] += 26 * i + 1 + 2 + 3 + 4 + 5 + 6 + 7 + 8 + 9 + 10 + 11 + 12 + 13 + 14 + 15 + 16 + 17 + 18 + 19 + 20 + 21 + 22 + 23 + 24 + 25;
	for (; i <= n; i++)
		summ[25] += i;
	unsigned int end_time_25 = clock();
	unsigned int search_time_25 = end_time_25 - start_time_25;
	times[25] = search_time_25;

	unsigned int start_time_26 = clock();
	for (i = 1; i <= n - 26; i += 27)
		summ[26] += 27 * i + 1 + 2 + 3 + 4 + 5 + 6 + 7 + 8 + 9 + 10 + 11 + 12 + 13 + 14 + 15 + 16 + 17 + 18 + 19 + 20 + 21 + 22 + 23 + 24 + 25 + 26;
	for (; i <= n; i++)
		summ[26] += i;
	unsigned int end_time_26 = clock();
	unsigned int search_time_26 = end_time_26 - start_time_26;
	times[26] = search_time_26;

	unsigned int start_time_27 = clock();
	for (i = 1; i <= n - 27; i += 28)
		summ[27] += 28 * i + 1 + 2 + 3 + 4 + 5 + 6 + 7 + 8 + 9 + 10 + 11 + 12 + 13 + 14 + 15 + 16 + 17 + 18 + 19 + 20 + 21 + 22 + 23 + 24 + 25 + 26 + 27;
	for (; i <= n; i++)
		summ[27] += i;
	unsigned int end_time_27 = clock();
	unsigned int search_time_27 = end_time_27 - start_time_27;
	times[27] = search_time_27;

	unsigned int start_time_28 = clock();
	for (i = 1; i <= n - 28; i += 29)
		summ[28] += 29 * i + 1 + 2 + 3 + 4 + 5 + 6 + 7 + 8 + 9 + 10 + 11 + 12 + 13 + 14 + 15 + 16 + 17 + 18 + 19 + 20 + 21 + 22 + 23 + 24 + 25 + 26 + 27 + 28;
	for (; i <= n; i++)
		summ[28] += i;
	unsigned int end_time_28 = clock();
	unsigned int search_time_28 = end_time_28 - start_time_28;
	times[28] = search_time_28;

	unsigned int start_time_29 = clock();
	for (i = 1; i <= n - 29; i += 30)
		summ[29] += 30 * i + 1 + 2 + 3 + 4 + 5 + 6 + 7 + 8 + 9 + 10 + 11 + 12 + 13 + 14 + 15 + 16 + 17 + 18 + 19 + 20 + 21 + 22 + 23 + 24 + 25 + 26 + 27 + 28 + 29;
	for (; i <= n; i++)
		summ[29] += i;
	unsigned int end_time_29 = clock();
	unsigned int search_time_29 = end_time_29 - start_time_29;
	times[29] = search_time_29;

	unsigned int start_time_30 = clock();
	for (i = 1; i <= n - 30; i += 31)
		summ[30] += 31 * i + 1 + 2 + 3 + 4 + 5 + 6 + 7 + 8 + 9 + 10 + 11 + 12 + 13 + 14 + 15 + 16 + 17 + 18 + 19 + 20 + 21 + 22 + 23 + 24 + 25 + 26 + 27 + 28 + 29 + 30;
	for (; i <= n; i++)
		summ[30] += i;
	unsigned int end_time_30 = clock();
	unsigned int search_time_30 = end_time_30 - start_time_30;
	times[30] = search_time_30;

	unsigned int start_time_31 = clock();
	for (i = 1; i <= n - 31; i += 32)
		summ[31] += 32 * i + 1 + 2 + 3 + 4 + 5 + 6 + 7 + 8 + 9 + 10 + 11 + 12 + 13 + 14 + 15 + 16 + 17 + 18 + 19 + 20 + 21 + 22 + 23 + 24 + 25 + 26 + 27 + 28 + 29 + 30 + 31;
	for (; i <= n; i++)
		summ[31] += i;
	unsigned int end_time_31 = clock();
	unsigned int search_time_31 = end_time_31 - start_time_31;
	times[31] = search_time_31;
	
	ofstream fout1("out.txt");
	ofstream fout2("time.txt");
	for (int i = 1; i < 32; i++)
		fout1 << summ[i] << endl;
	for (int i = 1; i < 32; i++)
		fout2 << times[i] << endl;
	fout1.close();
	fout2.close();
}