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
/*0 � ������
1 � �����
2 � �������
3 � �������
4 � �������
5 � �������
6 � ������
7 � �����
8 � �����
9 � ����� - �����
A � ������ - �������
B � ������ - �������
� � ������ - �������
E � ������ - ������
F � ���� - �����
system("color F0");*/  // ��������� ������ ���� � ������� ������
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
	int x = 0;//������ ������� �������
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
	x = 0;//������ ������� �������� �������
	while (x < 10)
	{
		int y = 0;//������ ������� ���������������� �������
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