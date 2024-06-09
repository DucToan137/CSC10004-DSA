#include<iostream>
#include"AVL.h"

using namespace std;

int main() {

	NODE* p = NULL;
	int x;
	int n;
	cout << "Nhap so phan tu: ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		Insert(p, x);
	}

	cout << "Duyet NLR: ";
	NLR(p);
	cout << endl << "Duyet LNR: ";
	LNR(p);
	cout << endl << "Duyet LRN: ";
	LRN(p);

	cout << endl;
	if (isAVL(p) == true)
		cout << "Cay da cho la cay nhi phan tim kiem can bang" << endl;
	else
		cout << "Cay da cho khong la cay nhi phan tim kiem can bang" << endl;
	return 0;
}