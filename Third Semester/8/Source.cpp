#include <iostream>
#include <fstream>
using namespace std;

struct Complex
{
	double x, y;
};

const Complex operator+ (const Complex& l, const Complex& r)
{
	Complex res;
	res.x = l.x + r.x;
	res.y = l.y + r.y;
	return res;
}

const Complex operator- (const Complex& l, const Complex& r)
{
	Complex res;
	res.x = l.x - r.x;
	res.y = l.y - r.y;
	return res;
}

const Complex operator* (const Complex& l, const Complex& r)
{
	Complex res;
	res.x = l.x*r.x - l.y*r.y;
	res.y = l.x*r.y + l.y*r.x;
	return res;
}

const Complex operator/ (const Complex& l, const Complex& r)
{
	Complex res;
	double k = r.x * r.x + r.y * r.y;
	res.x = (l.x * r.x + l.y * r.y) / k;
	res.y = (r.x * l.y - l.x * r.y) / k;
	return res;
}

int main()
{
	ifstream fin("input.txt");
	ofstream fout("out.txt");
	Complex C1, C2, C3;
	fin >> C1.x >> C1.y;
	fin >> C2.x >> C2.y;

	C3 = C1 + C2;
	fout << C3.x << +C3.y << "i";
	fout << endl;
	//C3 = C1 - C2;
	C3 = C1*C2;
	//C3 = C1 / C2;

	fout << C3.x << " " <<C3.y << "i";
	fin.close();
	fout.close();
}