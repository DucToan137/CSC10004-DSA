#pragma once
#include<iostream>
using namespace std;

struct NODE {
	int key;
	NODE* p_left;
	NODE* p_right;
};


//1 khởi tạo 1 NODE từ 1 giá trị cho trước
NODE* createNode(int data);
//2 duyệt tiền thứ tự
void NLR(NODE* pRoot);
//3 duyệt trung thứ tự
void LNR(NODE* pRoot);
//5
//4 duyệt hậu thứ tự
void LRN(NODE* pRoot);
//6 tìm và trả về NODE với giá trị cho trước từ cây nhị phân tìm kiếm
NODE* Search(NODE* pRoot, int x);
//7 thêm 1 NODE với giá trị cho trước vào cây nhị phân tìm kiếm
void Insert(NODE*& pRoot, int x);
//8 xóa NODE với giá trị cho trước từ cây nhị phân tìm kiếm
void DiTimNodeTheMang(NODE*& T, NODE*& Y);
void Remove(NODE*& pRoot, int T);
//9 khởi tạo 1 cây nhị phân tìm kiếm từ 1 mảng cho trước
NODE* createTree(int a[], int n);
//10 xóa hoàn toàn cây nhị phân tìm kiếm
void removeTree(NODE*& pRoot);
//11 tính chiều cao cây nhị phân tìm kiếm
int Height(NODE* pRoot);
//12 đếm số NODE trên cây nhị phân
int countNode(NODE* pRoot);
//13 tính tổng giá trị node trong 1 cây nhị phân
int sumNode(NODE* pRoot);
//14 tính chiều cao của 1 NODE với giá trị cho trước (trả về -1 nếu không tồn tại)
int heightNode(NODE* pRoot, int value);
//15
//16 đếm số lá của 1 cây nhị phân
int countLeaf(NODE* pRoot);
//17 đếm số NODE của cây nhị phân tìm kiếm mà giá trị key nhỏ hơn giá trị cho trước
int countLess(NODE* pRoot, int x);
//18 đếm số NODE của cây nhị phân tìm kiếm mà giá trị key lớn hơn giá trị cho trước
int countGreater(NODE* pRoot, int x);
//19
int heightNode(NODE* pRoot, int value);
//20  xác định cây nhị phân có phải là cây nhị phân tìm kiếm đầy đủ hay không
bool isFullBST(NODE* pRoot);

