#pragma once
#include<iostream>
using namespace std;

struct BST {
	struct BSTNode {
		int key;
		BSTNode* pLeft;
		BSTNode* pRight;
	};
	BSTNode* pRoot;
	BSTNode* creatNode(int data);

	void NLR(BSTNode* pRoot);

	void NLR();

	void LNR(BSTNode* pRoot);

	void LNR();

	void LRN(BSTNode* pRoot);

	void LRN();

	void LevelOrder();

	BSTNode* Search(int x);
	
		
	
	void Insert(int x);
	void createTree(int a[], int n);

	void removeTree();


	int countNode();

	int sumNode();

	int countLeaf();

	int countLess(int x);

	int countGreater(int x);

	bool isBST();

	bool isFullBST();
};