#include<iostream>
#include"BST.h"
#include"Queue.h"
using namespace std;

BST::BSTNode* BST::creatNode(int data)
{

	BSTNode* node = new BSTNode;
	if (node != NULL)
	{
		node->key = data;
		node->pLeft = NULL;
		node->pRight = NULL;
		return node;
	}
	return NULL;
}

void BST::NLR(BSTNode*pRoot)
{
	if (!pRoot) return;
	cout << pRoot->key << " ";
	NLR(pRoot->pLeft);
	NLR(pRoot->pRight);
}

void BST::NLR()
{
	NLR(pRoot);
}

void BST:: LNR(BSTNode* pRoot)
{
	if (!pRoot) return;
	LNR(pRoot->pLeft);
	cout << pRoot->key << " ";
	LNR(pRoot->pRight);
}

void BST:: LNR()
{
	LNR(pRoot);
}

void BST::LRN(BSTNode* pRoot)
{
	if (!pRoot) return;
	LRN(pRoot->pLeft);
	LRN(pRoot->pRight);
	cout << pRoot->key << " ";
}

void BST::LRN()
{
	LRN(pRoot);
}

void BST :: LevelOrder()
{
	if (!pRoot) return;
	Queue q;
	q.init();
	q.push(pRoot->key);
	while (!q.isEmpty())
	{
		BSTNode* tmp = Search(q.Top());
		cout << tmp->key << " ";

		if (tmp->pLeft)
			q.push(tmp->pLeft->key);
		if (tmp->pRight)
			q.push(tmp->pRight->key);
		q.pop();
	}
}

BST::BSTNode* BST::Search(int x)
{
	BSTNode* tmp = pRoot;
	while (tmp)
	{
		if (x == tmp->key)
			return tmp;
		else if (x < tmp->key)
			tmp = tmp->pLeft;
		else
			tmp = tmp->pRight;
	}
	return nullptr;
}

void BST::Insert(int x)
{
	BSTNode* p = creatNode(x);
	if (pRoot==nullptr)
	{
		pRoot = p;
		return;
	}

	BSTNode* tmp = pRoot;
	BSTNode* tmp1 = NULL;
	while (tmp!=NULL)
	{
		
		tmp1 = tmp;
		if (x < tmp->key)
			tmp = tmp->pLeft;
		else
			tmp = tmp->pRight;
	}

	if (x < tmp1->key)
		tmp1->pLeft = p;
	else
		tmp1->pRight = p;
	

}

void BST:: createTree(int a[], int n)
{
	if (n == 0)	return;
	for (int i = 0; i < n; i++)
	{
		Insert(a[i]);
	}
}

void BST :: removeTree() // 
{
	if (!pRoot) return;
	Queue q;
	q.init();
	q.push(pRoot->key);

	while (!q.isEmpty())
	{
		BSTNode* tmp = Search(q.Top());

		if (tmp->pLeft)
			q.push(tmp->pLeft->key);
		if (tmp->pRight)
			q.push(tmp->pRight->key);

		delete tmp;
		q.pop();
	}
}



int BST::countNode()
{
	if (!pRoot) return 0;
	int dem = 0;
	Queue q;
	q.init();

	q.push(pRoot->key);
	while (!q.isEmpty())
	{
		BSTNode* tmp = Search(q.Top());
		dem++;
		q.pop();

		if (tmp->pLeft)
			q.push(tmp->pLeft->key);
		if (tmp->pRight)
			q.push(tmp->pRight->key);
	}
	return dem;
}

int BST ::countLeaf()
{
	if (!pRoot) return 0;
	int dem = 0;
	Queue q;
	q.init();

	q.push(pRoot->key);
	while (!q.isEmpty())
	{
		BSTNode* tmp = Search(q.Top());
		if (!tmp->pLeft && !tmp->pRight)
			dem++;
		if (tmp->pLeft)
			q.push(tmp->pLeft->key);
		if (tmp->pRight)
			q.push(tmp->pRight->key);
		q.pop();
	}
	return dem;
}

int BST::sumNode()
{
	if (!pRoot) return 0;
	int sum = 0;
	Queue q;
	q.init();

	q.push(pRoot->key);
	while (!q.isEmpty())
	{
		BSTNode* tmp = Search(q.Top());
		sum = sum + q.Top();
		q.pop();

		if (tmp->pLeft)
			q.push(tmp->pLeft->key);
		if (tmp->pRight)
			q.push(tmp->pRight->key);

	}
	return sum;
}

int BST::countLess(int x)
{
	int dem = 0;
	Queue q;
	q.init();

	q.push(pRoot->key);
	while (!q.isEmpty())
	{
		BSTNode* tmp = Search(q.Top());
		q.pop();

		if (tmp)
		{
			if (tmp->key < x)
			{
				dem++;
			}
			if (tmp->pLeft)
				q.push(tmp->pLeft->key);
			if (tmp->pRight)
				q.push(tmp->pRight->key);
		}
	}
	return dem;
}

int BST::countGreater(int x)
{
	int dem = 0;
	Queue q;
	q.init();

	q.push(pRoot->key);
	while (!q.isEmpty())
	{
		BSTNode* tmp = Search(q.Top());
		q.pop();

		if (tmp)
		{
			if (tmp->key > x)
			{
				dem++;
			}
			if (tmp->pLeft)
				q.push(tmp->pLeft->key);
			if (tmp->pRight)
				q.push(tmp->pRight->key);
		}
	}
	return dem;
}

bool BST:: isBST()
{
	if (!pRoot) return true;
	Queue q;
	q.init();
	q.push(pRoot->key);

	while (!q.isEmpty())
	{
		BSTNode* tmp = Search(q.Top());
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

bool BST :: isFullBST()
{
	if (!pRoot) return true;
	Queue q;
	q.init();
	q.push(pRoot->key);

	while (!q.isEmpty())
	{
		BSTNode* tmp = Search(q.Top());
		q.pop();

		if ((!tmp->pLeft && tmp->pRight) || (tmp->pLeft && !tmp->pRight))
			return false;

		if (tmp->pLeft)
			q.push(tmp->pLeft->key);

		if (tmp->pRight)
			q.push(tmp->pRight->key);
	}
	return true;
}

