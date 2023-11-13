#include<iostream>
#include<math.h>
#include"AVL.h"
using namespace std;

AVL::AVLNode* AVL::createNode(int data)
{
	AVLNode* node = new AVLNode;
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


int AVL :: Height(AVLNode* pRoot)
{
	if (!pRoot) return 0;
	return 1 + max(Height(pRoot->p_left), Height(pRoot->p_right));
}

// xoay phải
void AVL :: rightRotate(AVLNode*& pRoot)
{
	AVLNode* p = pRoot->p_left;
	// xoay phải
	pRoot->p_left = p->p_right;
	p->p_right = pRoot;
	// cập nhật chiều cao
	pRoot->height = 1 + max(Height(pRoot->p_left), Height(pRoot->p_right));
	p->height = 1 + max(Height(p->p_left), Height(p->p_right));
	pRoot = p;
}

// xoay trái
void AVL :: leftRotate(AVLNode*& pRoot)
{
	AVLNode* p = pRoot->p_right;
	// xoay trái
	pRoot->p_right = p->p_left;
	p->p_left = pRoot;
	// cập nhật chiều cao
	pRoot->height = 1 + max(Height(pRoot->p_left), Height(pRoot->p_right));
	p->height = 1 + max(Height(p->p_left), Height(p->p_right));
	pRoot = p;
}

// tìm chỉ số cân bằng của node
int AVL :: getbalace(AVLNode* pRoot)
{
	if (!pRoot) return 0;
	return Height(pRoot->p_left) - Height(pRoot->p_right);
}