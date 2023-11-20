#include<iostream>
#include"BST.h"
#include"Queue.h"
using namespace std;

int main()
{
	Node* tree = nullptr;
	int a[12] = { 44,88,18,37,13,15,59,108,55,71,23,40 };
	tree=createTree(a, 12);
	cout << "Tien thu tu: ";
	NLR(tree);
	cout << endl << "Trung thu tu: ";
	LNR(tree);
	cout << endl << "Hau thu tu: ";
	LRN(tree);
	cout << endl << "Duyet theo muc: ";
	LevelOder(tree);
	cout << endl << "Chieu cao cay: " << Height(tree);
	cout << endl << "So node: " << countNode(tree);
	cout << endl << "Tong gia tri node: " << sumNode(tree);
	cout << endl << "So la: " << countLeaf(tree);
	cout << endl << "So node nho hon 27: " << countLess(tree, 27);
	cout << endl << "So node lon hon 36: " << countGreater(tree, 36) << endl;
	if (isFullBST(tree) == true)
		cout << "Cay da cho la cay nhi phan tim kiem day du" << endl;
	else
		cout << "Cay da cho khong la cay nhi phan tim kiem day du" << endl;
	if (isBST(tree) == true)
		cout << "Cay da cho la cay nhi phan tim kiem" << endl;
	else
		cout << "Cay da cho khong la cay nhi phan tim kiem" << endl;
	cout << "Chieu cao node: ";
	cout << heightNode(tree, 108) << endl;
	Node* p = Search(tree, 23);
	cout << "Tang node: ";
	cout << Level(tree, p);

	Remove(tree, 44);
	Remove(tree, 13);
	Remove(tree, 23);
	cout << endl << "Trung thu tu: ";
	LNR(tree);
	removeTree(tree);
	cout << "Cay sau khi xoa: ";
	LNR(tree);

	return 0;
}