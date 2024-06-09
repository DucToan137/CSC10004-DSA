#pragma once
#include<iostream>
using namespace std;

struct NODE {
	int key;
	NODE* p_left;
	NODE* p_right;
	int height;
};
//1 Tạo NODE
NODE* createNode(int data);

// độ cao
int Height(NODE* pRoot);

// xoay phải
void rightRotate(NODE*& pRoot);

// xoay trái
void leftRotate(NODE*& pRoot);

// tìm chỉ số cân bằng của node
int getbalace(NODE* pRoot);

//2 thêm 1 node có giá trị cho trước
void Insert(NODE*& pRoot, int x);

//3

//4 duyệt tiền thứ tự
void NLR(NODE* pRoot);

//5 duyệt trung thứ tự
void LNR(NODE* pRoot);

//6 duyệt hậu thứ tự
void LRN(NODE* pRoot);

//7

//8 kiểm tra cây có phải cây AVL không
bool isAVL(NODE* pRoot);







