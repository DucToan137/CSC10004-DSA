#include<iostream>
#include"AVL.h"
#include"Queue.h"
using namespace std;

int main()
{
	Node* tree = nullptr;
	Insert(tree, 33);
	Insert(tree, 14);
	Insert(tree, 15);
	Insert(tree, 92);
	Insert(tree, 64);
	Insert(tree, 35);
	Insert(tree, 79);
	Insert(tree, 27);
	Insert(tree, 38);
	Insert(tree, 105);
	Insert(tree, 99);
	cout << "Tien thu tu: ";
	NLR(tree);
	cout << endl << "Trung thu tu: ";
	LNR(tree);
	cout << endl << "Hau thu tu: ";
	LRN(tree);
	cout << endl << "Duyet theo muc: ";
	LevelOder(tree);

	Remove(tree, 33);
	cout << endl << "Xoa node: ";
	LevelOder(tree);

	if (isAVL(tree) == true)
		cout << endl << "Cay da cho la cay AVL" << endl;
	else
		cout << endl << "Cay da cho khong la cay AVL";

	return 0;
}