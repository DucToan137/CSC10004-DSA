#include<iostream>
#include"BST.h"
using namespace std;

int main() {
	BST tree;
	tree.pRoot = nullptr;
	
	int a[5] = { 3,2,4,1,5 };
	BST tmp;
	tmp.pRoot = nullptr;
	tmp.createTree(a, 5);
	tmp.NLR();
	cout << endl;
	
	cout << tmp.Search(4)->key << endl;

	tree.Insert(5);
	tree.Insert(1);
	tree.Insert(7);
	tree.Insert(6);
	tree.Insert(9);
	
	cout << endl;
	tree.LNR();

	cout << endl << "So node: " << tree.countNode();
	cout << endl << "Tong cac node: " << tree.sumNode();
	cout << endl << "So la: " << tree.countLeaf();
	cout << endl << "So gia tri nho hon x: " << tree.countLess(5);
	cout << endl << "So gia tri lon hon x: " << tree.countGreater(5);
	cout << endl << "Duyet theo muc: ";
	tree.LevelOrder();
	cout << endl;
	if (tree.isBST() == true)
		cout << "Cay da cho la cay nhi phan tim kiem" << endl;
	else
		cout << "Cay da cho khong la cay nhi phan tim kiem" << endl;
	if (tree.isFullBST() == true)
		cout << "Cay da cho la cay nhi phan tim kiem day du" << endl;
	else
		cout << "Cay da cho khong la cay nhi phan tim kiem day du" << endl;

	tree.removeTree();
	cout << "cay sau khi xoa: ";

	tree.LNR();
	return 0;
}