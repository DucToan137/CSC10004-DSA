#pragma once
#include<iostream>
using namespace std;

struct Node {
	int key;
	Node* pLeft;
	Node* pRight;
	int height;
};

Node* createNode(int data);
int Height(Node* pRoot);
int getbalance(Node* pRoot);
Node* rightRotate(Node* &pRoot);
Node* leftRotate(Node* &pRoot);
void Balance(Node* &pRoot);
void Insert(Node* &pRoot, int x);
void Remove(Node*& pRoot, int x);
bool isAVL(Node* pRoot);
void NLR(Node* pRoot);
void LNR(Node* pRoot);
void LRN(Node* pRoot);
void LevelOder(Node* pRoot);
Node* Search(Node* pRoot, int x);
