#include <iostream>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <fstream>
using namespace std;


struct Student
{
	int number;
	char name[26];
	char date[9];
	bool tasks[9];
};

int main()
{	
	setlocale(LC_ALL, "Russian");
	int i, j, m, count;
	int cout[12] = { 0 };
	char s_buf[100];
	char task_temp[4];// номер, фио, даты, задания
	char ch_temp;
	fstream f_buf;
	Student list[12];
	Student st_temp;
	Student buffer[12];
	
	f_buf.open("journal.txt", ios::in);
	f_buf.getline(s_buf, 100); //Пропускаем первую строку
	for (int i = 0; i < 12; i++)
	{
		f_buf >> st_temp.number;
		f_buf.get(ch_temp); //Пропускаем символ табуляции
		f_buf.getline(st_temp.name, 26, '	');
		f_buf.get(ch_temp); //Пропускаем символы пока не встретим что то кроме пробела (после некоторых ФИО 1, 2 или 3 символа табуляции)
		while (ch_temp == '	')
			f_buf.get(ch_temp);
		f_buf.unget(); //Возвращаемся назад на символ
		for (j = 0; j < 9; j++)
			f_buf >> st_temp.date[j];
		f_buf.get(ch_temp);
		for (j = 0; j < 9; j++)
		{
			if (j<8)
				f_buf.getline(task_temp, 4, '	'); //считываем строку заканчивающуюся на '	' во временную переменную
			else
				f_buf.getline(task_temp, 4); //последний столебец оканчивается на '\n'
			if (strchr(task_temp, '+') != NULL)
				st_temp.tasks[j] = true;//Если в столбце есть "+"
			else
				st_temp.tasks[j] = false;//Иначе "-"
		}
		list[i] = st_temp;
	}
	f_buf.close();

	for (i = 0; i< 12; i++)
	{
		std::cout << list[i].number << ' ' << list[i].name << ' ';
		for (j = 0; j < 9; j++)
		{
			std::cout << list[i].tasks[j] << ' ';
			if (list[i].date[j] == '+') //Если "+", то сданных семестровых +1
				cout[i]++;
		}
		for (j = 0; j < 9; j++)
			std::cout << list[i].tasks[j] << ' ';
		std::cout << '\n';
	}

	//Сортировка выбором -------------------------------
	for (i = 0; i < 12; i++)
	{
		for (j = i, m = i; j < 12; j++)
		{
			if (cout[j]>cout[m])
				m = j;
		}
		std::swap(cout[i], cout[m]); //Меняем местами студентов в списке и их семестровые в массиве сданных семестровых
		std::swap(list[i], list[m]);
	}

	f_buf.open("out.txt", ios::out);
	f_buf << "№" << "\t" << "ФИО" << "\t" << "\t" << "\t" << "\t" << "14.окт" << "\t" << "21.окт" << "\t" << "28.окт" << "\t" << "11.ноя" << "\t" << "18.ноя" << "\t" << "25.ноя" << "\t" << "02.дек" << "\t" << "09.дек" << "\t" << "16.дек" << "\t" << "1" << "\t" << "2" << "\t" << "3" << "\t" << "4" << "\t" << "5" << "\t" << "6" << "\t" << "7" << "\t" << "8" << "\t" << "9" << endl;
	for (i = 0; i < 12; i++)
	{
		f_buf << list[i].number << '\t' << list[i].name << "\t" << "\t" << "\t";
		for (j = 0; j < 9; j++)
			f_buf << st_temp.date[j] << "\t";
		for (j = 0; j<9; j++)
			f_buf << st_temp.tasks[j] << '\t';
		f_buf << '\n';
	}
	f_buf.close();
}