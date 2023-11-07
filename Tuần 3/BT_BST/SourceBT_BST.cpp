#include<iostream>
#include"./BT_BST.h"
#include<math.h>

using namespace std;

int main()
{
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

	cout << "Chieu cao cua cay: " << Height(p) << endl;
	cout << "So luong node cua cay: " << countNode(p) << endl;
	cout << "Tong gia tri toan bo node cua cay: " << sumNode(p) << endl;
	cout << "Chieu cao cua node: ";
	int m;
	cin >> m;
	cout << "Chieu cao node co gia tri " << m << ": " << heightNode(p, m) << endl;
	cout << "So la cua cay: " << countLeaf(p) << endl;
	cout << "Nhap c" << endl;
	int c;
	cin >> c;
	cout << "So node cua cay nhi phan tim kiem ma gia tri key nho hon gia tri cho truoc c: " << countLess(p, c) << endl;
	cout << "So node cua cay nhi phan tim kiem ma gia tri lon hon gia tri cho truoc c: " << countGreater(p, c) << endl;
	if (isFullBST(p) == true)
	{
		cout << "Cay nhi phan nay la cay nhi phan tim kiem day du" << endl;
	}
	else
	{
		cout << "Cay nhi phan nay khong la cay nhi phan tim kiem day du" << endl;
	}
	
	int k;
	cout << "Nhap gia tri can them vao cay nhi phan: ";
	cin >> k;
	Insert(p, k);
	cout << "Duyet LNR sau khi them: ";
	LNR(p);
	
	int h;
	cout << endl << "Nhap gia tri can xoa: ";
	cin >> h;
	Remove(p, h);
	cout << "Duyet LNR sau khi xoa: ";
	LNR(p);

	NODE* t = NULL;
	int a[5] = { 3,2,6,7,8 };
	t = createTree(a, 5);
	cout << endl << "Cay sau khi tao tu mang gom 5 phan tu {3,2,6,7,8}: ";
	LNR(t);

	removeTree(t);
	cout << endl << "Duyet LNR sau khi xoa: ";
	LNR(t);

	return 0;
}