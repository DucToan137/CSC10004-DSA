#include<iostream>
#include"./Data.h"
using namespace std;


const int D = 1000000;
const int E = 1000000000;


void NgauNhien(const string& file_name)
{
	ofstream outFile(file_name);

	if (!outFile.is_open()) {
		cout << "Khong the mo file";
		return;
	}

	srand((unsigned int)time(NULL));
	for (int i = 0; i < D; i++)
	{
		outFile << rand() % E;

		if (i < D - 1)
			outFile << " ";
	}
	outFile.close();
}

void TangDan(const string& file_name)
{
	ofstream outFile(file_name);

	if (!outFile.is_open()) {
		cout << "Khong the mo file";
		return;
	}
	for (int i = 0; i < D; i++)
	{
		outFile << i;

		if (i < D - 1)
			outFile << " ";
	}
	outFile.close();

}

void GiamDan(const string& file_name)
{
	ofstream outFile(file_name);

	if (!outFile.is_open()) {
		cout << "Khong the mo file";
		return;
	}
	for (int i = 0; i < D; i++)
	{
		outFile << D - 1 - i;
		if (i < D - 1)
			outFile << " ";
	}
	outFile.close();
}

void DulieuCoThuTu(const string& file_name)
{
	ofstream outFile(file_name);

	if (!outFile.is_open()) {
		cout << "Khong the mo file";
		return;
	}
	int* d = new int[D];
	for (int i = 0; i < D; i++)
	{
		d[i] = i;
	}
	srand((unsigned int)time(NULL));
	for (int i = 0; i < 10; i++)
	{
		int r1 = rand() % D;
		int r2 = rand() % D;
		swap(d[r1], d[r2]);
	}
	for (int i = 0; i < D; i++)
	{
		outFile << d[i];
		if (i < D - 1)
			outFile << " ";
	}
	outFile.close();
}