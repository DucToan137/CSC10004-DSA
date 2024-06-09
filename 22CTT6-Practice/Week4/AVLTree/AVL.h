#pragma once
#include<iostream>
#include"Queue.h"

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
	//void Remove(int x);
	void NLR();
	void LNR(AVLNode* pRoot);
	void LNR();
	void NLR(AVLNode* pRoot);
	void LRN();
	void LRN(AVLNode* pRoot);
	void LevelOrder();
	bool isAVL();
	//void copy(const AVL& tree);
	AVLNode* Search(int x);
	int Height(AVLNode* pRoot);
	void rightRotate(AVLNode*& pRoot);
	void leftRotate(AVLNode*& pRoot);
	int getbalance(AVLNode* pRoot);
	void Insert(AVLNode*& pRoot, int x);
};