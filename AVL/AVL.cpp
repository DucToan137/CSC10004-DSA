#include<iostream>
#include"AVL.h"
#include"Queue.h"
#include<math.h>
using namespace std;

Node* createNode(int data)
{
	Node* node = new Node;
	if (!node) return nullptr;
	node->key = data;
	node->pLeft = nullptr;
	node->pRight = nullptr;
	node->height = 1;
	return node;
}

void DiTimNodeTheMang(Node*& pRoot, Node*& tmp)
{
	if (pRoot->pRight)
		DiTimNodeTheMang(pRoot->pRight, tmp);
	else
	{
		tmp->key = pRoot->key;
		tmp = pRoot;
		pRoot = pRoot->pLeft;
		delete tmp;
		tmp = nullptr;
	}
}

void Remove(Node*& pRoot, int key) {
	if (!pRoot)
		return;
	if (key > pRoot->key)
		Remove(pRoot->pRight, key);
	else if (key < pRoot->key)
		Remove(pRoot->pLeft, key);
	else {
		// found key
		Node* tmp = pRoot;
		if (!pRoot->pLeft)
		{
			pRoot = pRoot->pRight;
			delete tmp;
			tmp = nullptr;
		}
		else if (!pRoot->pRight)
		{
			pRoot = pRoot->pLeft;
			delete tmp;
			tmp = nullptr;
		}
		else
			DiTimNodeTheMang(pRoot->pLeft, tmp);
	}
	Balance(pRoot);
}


Node* Search(Node* pRoot, int x)
{
	if (!pRoot) return nullptr;
	if (pRoot->key == x)
		return pRoot;
	else if (x < pRoot->key)
		Search(pRoot->pLeft, x);
	else if (x > pRoot->key)
		Search(pRoot->pRight, x);
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


int Height(Node* pRoot)
{
	if (!pRoot) return 0;
	return 1 + max(Height(pRoot->pLeft), Height(pRoot->pRight));
}

// xoay phải
Node* rightRotate(Node*& pRoot)
{
	Node* p = pRoot->pLeft;
	// xoay phải
	pRoot->pLeft = p->pRight;
	p->pRight = pRoot;
	// cập nhật chiều cao
	pRoot->height = 1 + max(Height(pRoot->pLeft), Height(pRoot->pRight));
	p->height = 1 + max(Height(p->pLeft), Height(p->pRight));
	//pRoot = p;
	return p;
}

// xoay trái
Node* leftRotate(Node*& pRoot)
{
	Node* p = pRoot->pRight;
	// xoay trái
	pRoot->pRight = p->pLeft;
	p->pLeft = pRoot;
	// cập nhật chiều cao
	pRoot->height = 1 + max(Height(pRoot->pLeft), Height(pRoot->pRight));
	p->height = 1 + max(Height(p->pLeft), Height(p->pRight));
	//pRoot= p;
	return p;
}

void Balance(Node* &pRoot)
{
	if (!pRoot) return;

	int bal = getbalance(pRoot);
	pRoot->height = 1 + max(Height(pRoot->pLeft), Height(pRoot->pRight));

	if (abs(bal) <= 1)
		return;
	//L-L
	 if (bal > 1 && getbalance(pRoot->pLeft) >= 0)
		pRoot = rightRotate(pRoot);
	//R-R
	 if (bal < -1 && getbalance(pRoot->pRight) < 0)
		pRoot = leftRotate(pRoot);
	//L-R
	 if (bal > 1 && getbalance(pRoot->pLeft) < 0)
	{
		pRoot->pLeft = leftRotate(pRoot->pLeft);
		pRoot = rightRotate(pRoot);
	}
	//R-L
	 if (bal <-1 && getbalance(pRoot->pRight)>=0)
	{
		pRoot->pRight=rightRotate(pRoot->pRight);
		pRoot = leftRotate(pRoot);
	}
}

// tìm chỉ số cân bằng của Node
int getbalance(Node* pRoot)
{
	if (!pRoot) return 0;
	return Height(pRoot->pLeft) - Height(pRoot->pRight);
}

//2 thêm 1 Node có giá trị cho trước vào cây AVL
void Insert(Node*& pRoot, int x)
{
	int bal;
	if (!pRoot)
		pRoot = createNode(x);
	else
	{
		// x nằm bên trái
		if (x < pRoot->key)
			Insert(pRoot->pLeft, x);
		else
			// x nằm bên phải
			Insert(pRoot->pRight, x);
		// tính chiều cao của pRoot
		/*pRoot->height = 1 + max(Height(pRoot->pLeft), Height(pRoot->pRight));
		// kiểm tra cân bằng của pRoot
		bal = getbalance(pRoot);

		// lệch trái trái
		if (bal > 1 && x < pRoot->pLeft->key)
			pRoot=rightRotate(pRoot);
		// lệch phải phải
		else if (bal < -1 && x > pRoot->pRight->key)
			pRoot =leftRotate(pRoot);
		// lệch trái phải
		else if (bal > 1 && x > pRoot->pLeft->key)
		{
			pRoot->pLeft=leftRotate(pRoot->pLeft);
			pRoot=rightRotate(pRoot);
		}
		// lệch phải trái
		else if (bal < -1 && x < pRoot->pRight->key)
		{
			pRoot->pRight =rightRotate(pRoot->pRight);
			pRoot=leftRotate(pRoot);
		}*/
		Balance(pRoot);
	}
}

//4 duyệt tiền thứ tự
void NLR(Node* pRoot)
{
	if (!pRoot) return;
	cout << pRoot->key << "(" << Height(pRoot) << ")" << " ";
	NLR(pRoot->pLeft);
	NLR(pRoot->pRight);
}

//5 duyệt trung thứ tự
void LNR(Node* pRoot)
{
	if (!pRoot) return;
	LNR(pRoot->pLeft);
	cout << pRoot->key << "(" << Height(pRoot) << ")" << " ";
	LNR(pRoot->pRight);
}

//6 duyệt hậu thứ tự
void LRN(Node* pRoot)
{
	if (!pRoot) return;
	LRN(pRoot->pLeft);
	LRN(pRoot->pRight);
	cout << pRoot->key << "(" << Height(pRoot) << ")" << " ";
}

//8 kiểm tra cây có phải cây AVL không
bool isAVL(Node* pRoot)
{
	if (!pRoot) return true;
	if (abs(Height(pRoot->pLeft) - Height(pRoot->pRight)) > 1) return false;
	return isAVL(pRoot->pLeft) && isAVL(pRoot->pRight);
}