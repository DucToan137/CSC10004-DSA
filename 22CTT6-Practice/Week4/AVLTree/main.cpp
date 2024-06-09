#include<iostream>
#include"AVL.h"
#include"Queue.h"
using namespace std;


int main()
{
	AVL tree;
	tree.pRoot = NULL;

	tree.Insert(70);
	tree.Insert(50);
	tree.Insert(80);
	tree.Insert(79);
	tree.Insert(72);
	tree.Insert(90);
	tree.Insert(10);
	tree.Insert(5);
	tree.Insert(25);
	tree.Insert(60);
	cout << "Duyet LNR cay AVL sau khi them cac phan tu: " << endl;
	tree.LNR();
	cout << endl << "Duyet cay theo muc :" << endl;
	tree.LevelOrder();
	if (tree.isAVL())
		cout << endl << "Cay da cho la cay AVL" << endl;
	else
		cout << endl << "Cay da cho khong la cay AVL" << endl;
	return 0;
}