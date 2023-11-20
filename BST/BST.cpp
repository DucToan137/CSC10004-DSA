#include<iostream>
#include"BST.h"
#include"Queue.h"

Node* createNode(int data)
{
	Node* node = new Node;
	if (!node) return nullptr;
	node->key = data;
	node->pLeft = nullptr;
	node->pRight = nullptr;
	return node;
}

void NLR(Node* pRoot)
{
	if (!pRoot) return;
	cout << pRoot->key << " ";
	NLR(pRoot->pLeft);
	NLR(pRoot->pRight);
}

void LNR(Node* pRoot)
{
	if (!pRoot) return;
	LNR(pRoot->pLeft);
	cout << pRoot->key << " ";
	LNR(pRoot->pRight);
}

void LRN(Node* pRoot)
{
	if (!pRoot) return;
	LRN(pRoot->pLeft);
	LRN(pRoot->pRight);
	cout << pRoot->key << " ";
}

void LevelOder(Node* pRoot)
{
	if (!pRoot) return;
	Queue q;
	q.init();
	q.push(pRoot->key);

	while (q.isEmpty() == false)
	{
		Node* tmp = Search(pRoot, q.front());
		cout << tmp->key << " ";

		if (tmp->pLeft)
			q.push(tmp->pLeft->key);
		if (tmp->pRight)
			q.push(tmp->pRight->key);
		q.pop();
	}
}

Node* Search(Node*pRoot,int x)
{
	if (!pRoot) return nullptr;
	if (pRoot->key == x)
		return pRoot;
	else if (x < pRoot->key)
		Search(pRoot->pLeft, x);
	else if (x > pRoot->key)
		Search(pRoot->pRight, x);
}

void Insert(Node* &pRoot, int x)
{
	if (!pRoot)
		pRoot = createNode(x);
	if (x < pRoot->key)
		Insert(pRoot->pLeft, x);
	else if (x > pRoot->key)
		Insert(pRoot->pRight, x);
}

Node* createTree(int a[], int n)
{
	Node* p = nullptr;
	for (int i = 0; i < n; i++)
	{
		Insert(p, a[i]);
	}
	return p;
}

int Height(Node* pRoot)
{
	if (!pRoot)return 0;
	//int left = Height(pRoot->pLeft);
	//int right = Height(pRoot->pRight);
	//return max(left, right) + 1;
	return 1 + max(Height(pRoot->pLeft), Height(pRoot->pRight));
}

int  countNode(Node* pRoot)
{	
	if(!pRoot) return 0;
	return 1 + countNode(pRoot->pLeft) + countNode(pRoot->pRight);
}

int sumNode(Node* pRoot)
{
	if (!pRoot) return 0;
	return pRoot->key + sumNode(pRoot->pLeft) + sumNode(pRoot->pRight);
}
/*
int countLeaf(Node* pRoot)
{
	if (!pRoot) return 0;
	if (!pRoot->pLeft && !pRoot->pRight)
		return 1;
	return countLeaf(pRoot->pLeft) + countLeaf(pRoot->pRight);
}*/

int sola = 0;
int countLeaf(Node* pRoot)
{
	if (!pRoot) return 0;
	if (!pRoot->pLeft && !pRoot->pRight)
		sola++;
	countLeaf(pRoot->pLeft);
	countLeaf(pRoot->pRight);
	return sola;
}

/*

int demLess = 0;
int countLess(Node* pRoot,int x)
{
	if (!pRoot) return 0;
	if (pRoot->key < x)
		demLess++;
	countLess(pRoot->pLeft, x);
	countLess(pRoot->pRight, x);
	return demLess;
}

int demGreater = 0;
int countGreater(Node* pRoot, int x)
{
	if (!pRoot) return 0;
	if (pRoot->key > x)
		demGreater++;
	countGreater(pRoot->pLeft,x);
	countGreater(pRoot->pRight,x);
	return demGreater;
}*/

int countLess(Node* pRoot, int x)
{
	if (!pRoot) return 0;
	int dem = 0;
	if (pRoot->key < x)
		dem = 1;
	dem = dem + countLess(pRoot->pLeft, x);
	dem = dem + countLess(pRoot->pRight, x);
	return dem;
}


int countGreater(Node* pRoot, int x)
{
	if (!pRoot) return 0;
	int dem = 0;
	if (pRoot->key > x)
		dem = 1;
	dem = dem + countGreater(pRoot->pLeft, x);
	dem = dem + countGreater(pRoot->pRight, x);
	return dem;
}

void removeTree(Node*& pRoot)
{
	if (!pRoot) return;
	if (pRoot->pLeft)
	{
		removeTree(pRoot->pLeft);
	}
	if (pRoot->pRight)
	{
		removeTree(pRoot->pRight);
	}
	delete pRoot;
	pRoot = NULL;
}

bool isBST(Node*pRoot)
{
	if (!pRoot) return false;
	Queue q;
	q.init();
	q.push(pRoot->key);

	while (!q.isEmpty())
	{
		Node* tmp = Search(pRoot,q.front());
		q.pop();

		if (tmp->pLeft)
		{
			if (tmp->pLeft->key > tmp->key)
				return false;
			q.push(tmp->pLeft->key);
		}

		if (tmp->pRight)
		{
			if (tmp->pRight->key < tmp->key)
				return false;
			q.push(tmp->pRight->key);
		}
	}
	return true;
}

bool isFullBST(Node* pRoot)
{
	if (!pRoot) return false;
	if (pRoot->pLeft == NULL && pRoot->pRight == NULL)
		return true;
	return isFullBST(pRoot->pLeft) && isFullBST(pRoot->pRight);
}

void DiTimNodeTheMang(Node*& T, Node*& Y)
{
	if (Y->pLeft != NULL)
	{
		DiTimNodeTheMang(T, Y->pRight);
	}
	else
	{
		T->key = Y->key;
		T = Y;
		Y = Y->pLeft;
	}
}
void Remove(Node*& pRoot, int x)
{
	if (!pRoot) return;
	else
	{
		if (x < pRoot->key)
		{
			Remove(pRoot->pLeft, x);
		}
		else if (x > pRoot->key)
		{
			Remove(pRoot->pRight, x);
		}
		else
		{
			Node* T = pRoot;
			if (pRoot->pLeft == NULL)
				pRoot = pRoot->pRight;
			else if (pRoot->pRight == NULL)
				pRoot = pRoot->pLeft;
			else
			{
				DiTimNodeTheMang(T, pRoot->pRight);
			}
			delete T;
		}
	}
}

int heightNode(Node* pRoot, int x)
{
	if (!pRoot) return -1;
	if (pRoot->key > x)
		return heightNode(pRoot->pLeft, x);
	if (pRoot->key < x)
		return heightNode(pRoot->pRight, x);
	return Height(pRoot);
}

int Level(Node* pRoot, Node* p)
{
	if (!pRoot) 
		return -1;
	if (pRoot->key == p->key)
		return 1;

	int res;
	if (p->key < pRoot->key)
		res = Level(pRoot->pLeft, p);
	else if (p->key > pRoot->key)
		res = Level(pRoot->pRight, p);

	if (res == -1)
		return res;
	else
		return res + 1;
}