#include<iostream>
#include"./BST.h"
#include"./Queue.h"
using namespace std;

int main() {
	BST tree;
	tree.pRoot = nullptr;
	
	int a[5] = { 3,2,4,9,5 };
	BST tmp;
	tmp.pRoot = nullptr;
	tmp.createTree(a, 5);
	cout << "Cay A duoc tao tu mang" << endl;
	cout << "Duyet NLR cay A: ";
	tmp.NLR();
	cout << endl << "Duyet LNR cay A: ";
	tmp.LNR();
	cout << endl << "Duyet LRN cay A: ";
	tmp.LRN();
	
	cout << endl << "Tim phan tu co gia tri 4 trong cay A(neu co xuat phan tu ra man hinh, nguoc lai xuat 0): ";
	if (tmp.Search(4))
		cout << tmp.Search(4)->key << endl;
	else
		cout << "0" << endl;

	tree.Insert(5);
	tree.Insert(1);
	tree.Insert(7);
	tree.Insert(6);
	tree.Insert(9);
	cout << "Duyet cay B sau khi them cac phan tu: " << endl;
	cout << "Duyet NLR cay B: ";
	tree.NLR();
	cout << endl << "Duyet LNR cay B: ";
	tree.LNR();
	cout << endl << "Duyet LRN cay B: ";
	tree.LRN();
	

	cout << endl << "So node cay B: " << tree.countNode();
	cout << endl << "Tong cac node cay B: " << tree.sumNode();
	cout << endl << "So la cay B: " << tree.countLeaf();
	cout << endl << "Nhap x: ";
	int x;
	cin >> x;
	cout << "So gia tri nho hon x trong cay B: " << tree.countLess(x);
	cout << endl << "So gia tri lon hon x: " << tree.countGreater(x);
	cout << endl << "Duyet cay B theo muc: ";
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
	cout << "Cay sau khi xoa: ";
	tree.LRN();
	tmp.remove(3);
	cout << endl << "Cay duoc tao tu mang sau khi xoa node 3 theo thu tu LNR: ";
	tmp.LNR();
	
	return 0;
}