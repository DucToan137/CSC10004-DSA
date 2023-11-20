#pragma once
#include<iostream>
using namespace std;

struct Node {
	int key;
	Node* pLeft;
	Node* pRight;
};
// tao node
Node* createNode(int data);
// tien thu tu
void NLR(Node* pRoot);
// trung thu tu
void LNR(Node* pRoot);
// hau thu tu
void LRN(Node* pRoot);
// duyet theo muc
void LevelOder(Node* pRoot);
// tim kiem node co gia tri cho truoc
Node* Search(Node*pRoot,int x);
// them node gia tri x vao cay
void Insert(Node* &pRoot, int x);
// khoi tao cay nhi phan tu mang
Node* createTree(int a[], int n);
// tinh chieu cao cua cay
int Height(Node* pRoot);
// dem so luong node cua cay
int  countNode(Node* pRoot);
// tinh tong gia tri cac node
int sumNode(Node* pRoot);
// dem so la cua cay
int countLeaf(Node* pRoot);
// dem so node ma gia tri key nho hon gia tri cho truoc
int countLess(Node* pRoot,int x);
// dem so node ma gia tri key lon hon gia tri cho truoc
int countGreater(Node* pRoot, int x);
// xoa cay nhi phan tim kiem
void removeTree(Node*& pRoot);
// kiem tra cay co phai cay nhi phan tim kiem khong 
bool isBST(Node* pRoot);
// kiem tra cay co phai cay nhi phan tim kiem day du khong
bool isFullBST(Node* pRoot);



// xoa 1 node co gia tri cho truoc
void DiTimNodeTheMang(Node*& T, Node*& Y);
void Remove(Node*& pRoot, int x);
// tinh chieu cao cua 1 node cho truoc

// tinh toan tang cua 1 node cho truoc

int heightNode(Node* pRoot, int x);

int Level(Node* pRoot, Node* p);