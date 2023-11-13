#pragma once
#include<iostream>

struct AVL {
	struct AVLNode {
		int key;
		AVLNode* p_left;
		AVLNode* p_right;
		int height;
	};
	AVLNode* pRoot;
	AVLNode* createNode(int data);
	void Insert(int x);
	void Remove(int x);
	void NLR();
	void LNR();
	void LRN();
	void LevelOrder();
	bool isAVL();
	void copy(const AVL& tree);

	int Height(AVLNode* pRoot);
	void rightRotate(AVLNode*& pRoot);
	void leftRotate(AVLNode*& pRoot);
	int getbalace(AVLNode* pRoot);
};