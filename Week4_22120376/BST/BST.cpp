#include<iostream>
#include"./BST.h"
#include"./Queue.h"
using namespace std;

// tạo node
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

// duyệt tiền thứ tự
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

// duyệt trung thứ tự
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

// duyệt hậu thứ tự
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

//duyệt theo mức
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

// tìm kiếm node có giá trị cho trước trong cây
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

// thêm node vào cây
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

// tạo cây từ mảng
void BST:: createTree(int a[], int n)
{
	if (n == 0)	return;
	for (int i = 0; i < n; i++)
	{
		Insert(a[i]);
	}
}

//xóa cây
void BST :: removeTree() // 
{
	/*if (!pRoot) return;
	Queue q;
	q.init();
	q.push(pRoot->key);

	while (!q.isEmpty())
	{
		BSTNode* tmp = Search(q.Top());
		q.pop();
		
		if (tmp->pLeft)
			q.push(tmp->pLeft->key);

		if (tmp->pRight)
			q.push(tmp->pRight->key);

		delete tmp;
	}
	pRoot = NULL;*/

	removeTree(pRoot);
}

void BST:: removeTree(BSTNode*& pRoot) {
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


//xóa node có giá trị x trong cây
void BST :: remove(int x)
{
	if (!pRoot) return;
	Queue q;
	q.init();
	q.push(pRoot->key);

	BSTNode* xoa = NULL;
	BSTNode* tmp = NULL;

	while (!q.isEmpty())
	{
		BSTNode* tmp1 = Search(q.Top());
		q.pop();

		if (tmp1->key == x)
			xoa = tmp1;

		tmp = tmp1;

		if (tmp1->pLeft)
			q.push(tmp1->pLeft->key);

		if (tmp1->pRight)
			q.push(tmp1->pRight->key);
	}
	if (xoa)
	{
		xoa->key = tmp->key;
		delete tmp;
	}
}

//đếm số node trong cây
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

// đếm số node là trong cây
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
		q.pop();

		if (!tmp->pLeft && !tmp->pRight)
			dem++;

		if (tmp->pLeft)
			q.push(tmp->pLeft->key);

		if (tmp->pRight)
			q.push(tmp->pRight->key);
	}
	return dem;
}

// tính tổng các node trong cây 
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

//đếm số node của cây BST mà giá trị key lớn hơn giá trị cho trước
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
				dem++;

			if (tmp->pLeft)
				q.push(tmp->pLeft->key);

			if (tmp->pRight)
				q.push(tmp->pRight->key);
		}
	}
	return dem;
}

//đếm số node của cây BST mà giá trị key lớn hơn giá trị cho trước
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
				dem++;

			if (tmp->pLeft)
				q.push(tmp->pLeft->key);

			if (tmp->pRight)
				q.push(tmp->pRight->key);
		}
	}
	return dem;
}

// kiểm tra cây có phải là cây nhị phân hay không
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

// kiểm tra cây có phải là cây nhị phân tìm kiếm đầy đủ hay không
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

