#define _CRT_SECURE_NO_WARNINGS
#include <windows.h>
#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>
using namespace std;
enum ConsoleColor {
	Black, Blue, Green, Cyan, Red, Magenta, Brown, LightGray, DarkGray,
	LightBlue, LightGreen, LightCyan, LightRed, LightMagenta, Yellow, White
};
void SetColor(int text, int background)
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}
void GotoXY(int X, int Y)
{
	HANDLE hConsole;
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coord = { X, Y };
	SetConsoleCursorPosition(hStdOut, coord);
}
#include <stdio.h>
/*0 Ч черный
1 Ч синий
2 Ч зеленый
3 Ч голубой
4 Ч красный
5 Ч лиловый
6 Ч желтый
7 Ч белый
8 Ч серый
9 Ч свело - синий
A Ч светло - зеленый
B Ч светло - голубой
— Ч светло - красный
E Ч светло - желтый
F Ч €рко - белый
system("color F0");*/  // ”становка белого фона и черного текста
void main()
{
	ofstream ofile("stl.txt", ios::out);
	ifstream ifile("stl.txt", ios::in);
	if (ifile.is_open())
	{
		string line;
		while (ifile >> line)
		{
			SetColor(1, 0);
			cout << line << ' ';
		}
	}
	vector <int> direction = { 1 * 1, 2 * 2, 3 * 3, 4 * 4, 5 * 5, 6 * 6, 7 * 7, 8 * 8, 9 * 9, 10 * 10 };
	int x = 0;//первый элемент вектора
	while (x < 10)
	{
		SetColor(2, 0);
		cout << direction.at(x) << setw(3);
		ofile << direction.at(x) << setw(3);
		x++;
	}
	cout << endl;
	ofile << endl;
	vector <int> orientation = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	vector <int> trend = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	x = 0;//первый элемент главного вектора
	while (x < 10)
	{
		int y = 0;//первый элемент вспомогательного вектора
		while (y < 10)
		{
			SetColor(3, 0);
			cout << orientation.at(x) * trend.at(y) << setw(3);
			ofile << orientation.at(x) * trend.at(y) << setw(3);
			y++;
		}
		cout << endl;
		ofile << endl;
		x++;
	}
}