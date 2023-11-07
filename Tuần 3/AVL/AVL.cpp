#pragma once
#include<iostream>
#include<math.h>
#include"./AVL.h"
using namespace std;

//1 tạo NODE
NODE* createNode(int data)
{
	NODE* node = new NODE;
	if (node != NULL)
	{
		node->key = data;
		node->p_left = NULL;
		node->p_right = NULL;
		node->height = 1;
		return node;
	}
	return NULL;
}

// độ cao 
int Height(NODE* pRoot)
{
	if (!pRoot) return 0;
	return 1 + max(Height(pRoot->p_left), Height(pRoot->p_right));
}

// xoay phải
void rightRotate(NODE* &pRoot) 
{
	NODE* p = pRoot->p_left;
	// xoay phải
	pRoot->p_left = p->p_right;
	p->p_right = pRoot;
	// cập nhật chiều cao
	pRoot->height = 1 + max(Height(pRoot->p_left), Height(pRoot->p_right));
	p->height = 1 + max(Height(p->p_left), Height(p->p_right));
	pRoot = p;
}

// xoay trái
void leftRotate(NODE* &pRoot) 
{
	NODE* p = pRoot->p_right;
	// xoay trái
	pRoot->p_right = p->p_left;
	p->p_left = pRoot;
	// cập nhật chiều cao
	pRoot->height = 1 + max(Height(pRoot->p_left), Height(pRoot->p_right));
	p->height = 1 + max(Height(p->p_left), Height(p->p_right));
	pRoot = p;
}

// tìm chỉ số cân bằng của node
int getbalace(NODE* pRoot)
{
	if (!pRoot) return 0;
	return Height(pRoot->p_left) - Height(pRoot->p_right);
}

//2 thêm 1 NODE có giá trị cho trước vào cây AVL
void Insert(NODE* &pRoot, int x)
{
	int bal;
	if (!pRoot)
	{
		NODE *p = createNode(x);
		pRoot = p;
	}
	else
	{
		// x nằm bên trái
		if (x < pRoot->key)
			Insert(pRoot->p_left, x);
		else
		// x nằm bên phải
			Insert(pRoot->p_right, x);
		// tính chiều cao của pRoot
		pRoot->height = max(Height(pRoot->p_left), Height(pRoot->p_right));
		// kiểm tra cân bằng của pRoot
		bal = getbalace(pRoot);

		// lệch trái trái
		if (bal > 1 && x < pRoot->p_left->key)
			rightRotate(pRoot);
		// lệch phải phải
		else if (bal < -1 && x > pRoot->p_right->key)
			leftRotate(pRoot);
		// lệch trái phải
		else if (bal > 1 && x > pRoot->p_left->key)
		{
			leftRotate(pRoot->p_left);
			rightRotate(pRoot);
		}
		// lệch phải trái
		else if (bal < -1 && x < pRoot->p_right->key)
		{
			rightRotate(pRoot->p_right);
			leftRotate(pRoot);
		}
	}
}

//4 duyệt tiền thứ tự
void NLR(NODE* pRoot)
{
	if (!pRoot) return;
	cout << pRoot->key << "(" << Height(pRoot) << ")" << " ";
	NLR(pRoot->p_left);
	NLR(pRoot->p_right);
}

//5 duyệt trung thứ tự
void LNR(NODE* pRoot)
{
	if (!pRoot) return;
	LNR(pRoot->p_left);
	cout << pRoot->key << "(" << Height(pRoot) << ")" << " ";
	LNR(pRoot->p_right);
}

//6 duyệt hậu thứ tự
void LRN(NODE* pRoot)
{
	if (!pRoot) return;
	LRN(pRoot->p_left);
	LRN(pRoot->p_right);
	cout << pRoot->key << "(" << Height(pRoot) << ")" << " ";
}

//8 kiểm tra cây có phải cây AVL không
bool isAVL(NODE* pRoot)
{
	if (!pRoot) return true;
	if (abs(Height(pRoot->p_left) - Height(pRoot->p_right)) > 1) return false;
	return isAVL(pRoot->p_left) && isAVL(pRoot->p_right);
}
