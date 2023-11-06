#pragma once
#include<iostream>
using namespace std;

struct NODE{
	int key;
	NODE* p_left;
	NODE* p_right;
	int height;
};

NODE* createNode(int data);

int Height(NODE* pRoot);

void rightRotate(NODE*& pRoot);

void leftRotate(NODE*& pRoot);

int getbalace(NODE* pRoot);

void Insert(NODE*& pRoot, int x);

void NLR(NODE* pRoot);

void LNR(NODE* pRoot);

void LRN(NODE* pRoot);