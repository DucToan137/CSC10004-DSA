#include<math.h>
#include"AVL.h"
#include"Queue.h"

using namespace std;

// tạo node
AVL::AVLNode* AVL::createNode(int data)
{
	AVLNode* node = new AVLNode;
	if (node != NULL)
	{
		node->key = data;
		node->p_left = NULL;
		node->p_right = NULL;
		node->height = 1;
		return node;
	}
	return NULL;
}

// tính độ cao
int AVL::Height(AVLNode* pRoot)
{
	if (!pRoot) return 0;
	return 1 + max(Height(pRoot->p_left), Height(pRoot->p_right));
}

// xoay phải
void AVL::rightRotate(AVLNode*& pRoot)
{
	AVLNode* p = pRoot->p_left;
	// xoay phải
	pRoot->p_left = p->p_right;
	p->p_right = pRoot;
	// cập nhật chiều cao
	pRoot->height = 1 + max(Height(pRoot->p_left), Height(pRoot->p_right));
	p->height = 1 + max(Height(p->p_left), Height(p->p_right));
	pRoot = p;
}

// xoay trái
void AVL::leftRotate(AVLNode*& pRoot)
{
	AVLNode* p = pRoot->p_right;
	// xoay trái
	pRoot->p_right = p->p_left;
	p->p_left = pRoot;
	// cập nhật chiều cao
	pRoot->height = 1 + max(Height(pRoot->p_left), Height(pRoot->p_right));
	p->height = 1 + max(Height(p->p_left), Height(p->p_right));
	pRoot = p;
}

// tìm chỉ số cân bằng của node
int AVL::getbalance(AVLNode* pRoot)
{
	if (!pRoot) return 0;
	return Height(pRoot->p_left) - Height(pRoot->p_right);
}

// tìm node có giá trị cho trước
AVL::AVLNode* AVL::Search(int x)
{
	AVLNode* tmp = pRoot;
	while (tmp)
	{
		if (x == tmp->key)
			return tmp;
		else if (x < tmp->key)
			tmp = tmp->p_left;
		else
			tmp = tmp->p_right;
	}
	return nullptr;
}

//thêm node vào cây
void AVL::Insert(AVLNode*& pRoot, int x)
{
	int bal;
	if (!pRoot)
	{
		AVLNode* p = createNode(x);
		pRoot = p;
	}
	else
	{
		// x nằm bên trái
		if (x < pRoot->key)
			Insert(pRoot->p_left, x);
		else
			// x nằm bên phải
			Insert(pRoot->p_right, x);
		// tính chiều cao của pRoot
		pRoot->height = max(Height(pRoot->p_left), Height(pRoot->p_right));
		// kiểm tra cân bằng của pRoot
		bal = getbalance(pRoot);

		// lệch trái trái
		if (bal > 1 && x < pRoot->p_left->key)
			rightRotate(pRoot);
		// lệch phải phải
		else if (bal < -1 && x > pRoot->p_right->key)
			leftRotate(pRoot);
		// lệch trái phải
		else if (bal > 1 && x > pRoot->p_left->key)
		{
			leftRotate(pRoot->p_left);
			rightRotate(pRoot);
		}
		// lệch phải trái
		else if (bal < -1 && x < pRoot->p_right->key)
		{
			rightRotate(pRoot->p_right);
			leftRotate(pRoot);
		}
	}
}

void AVL::Insert(int x)
{
	Insert(pRoot, x);
}

//void AVL::Insert(int x)
//{
//    AVLNode* node = createNode(x);
//    if (!pRoot)
//    {
//        pRoot = node;
//        return;
//    }
//
//    Queue q;
//    q.init();
//    q.push(pRoot->key);
//
//    while (!q.isEmpty())
//    {
//        AVLNode* tmp = Search(q.Top());
//        q.pop();
//
//        if (x < tmp->key)
//        {
//            if (!tmp->p_left)
//            {
//                tmp->p_left = node;
//                break;
//            }
//            else
//            {
//                q.push(tmp->p_left->key);
//            }
//        }
//        else
//        {
//            if (!tmp->p_right)
//            {
//                tmp->p_right = node;
//                break;
//            }
//            else
//            {
//                q.push(tmp->p_right->key);
//            }
//        }
//
//        q.push(tmp->key);
//        while (!q.isEmpty())
//        {
//            AVLNode* tmp1 = Search(q.Top());
//            q.pop();
//
//            int bal = getbalance(tmp1);
//
//            if (bal > 1 && x < tmp1->p_left->key)
//                rightRotate(tmp1);
//            else if (bal < -1 && x > tmp1->p_right->key)
//                leftRotate(tmp1);
//            else if (bal > 1 && x > tmp1->p_left->key)
//            {
//                leftRotate(tmp1->p_left);
//                rightRotate(tmp1);
//            }
//            else if (bal < -1 && x < tmp1->p_right->key)
//            {
//                rightRotate(tmp1->p_right);
//                leftRotate(tmp1);
//            }
//        }
//    }
//}

// duyệt tiền thứ tự
void AVL::NLR(AVLNode* pRoot)
{
	if (!pRoot) return;
	cout << pRoot->key << "(" << Height(pRoot) << ")" << " ";
	NLR(pRoot->p_left);
	NLR(pRoot->p_right);
}

void AVL::NLR()
{
	NLR(pRoot);
}

// duyệt trung thứ tự
void AVL::LNR(AVLNode* pRoot)
{
	if (!pRoot) return;
	LNR(pRoot->p_left);
	cout << pRoot->key << "(" << Height(pRoot) << ")" << " ";
	LNR(pRoot->p_right);
}

void AVL::LNR()
{
	LNR(pRoot);
}

// duyệt hậu thứ tự
void AVL::LRN(AVLNode* pRoot)
{
	if (!pRoot) return;
	LRN(pRoot->p_left);
	LRN(pRoot->p_right);
	cout << pRoot->key << "(" << Height(pRoot) << ")" << " ";
}

void AVL::LRN()
{
	LRN(pRoot);
}

// duyệt theo mức
void AVL::LevelOrder()
{
	if (!pRoot) return;
	Queue q;
	q.init();
	q.push(pRoot->key);

	while (!q.isEmpty())
	{
		AVLNode* tmp = Search(q.Top());
		cout << tmp->key << "(" << Height(tmp) << ")" << " ";

		if (tmp->p_left)
			q.push(tmp->p_left->key);

		if (tmp->p_right)
			q.push(tmp->p_right->key);

		q.pop();
	}
}

// kiểm tra cây có phải cây AVL không
bool AVL::isAVL()
{
	if (!pRoot) return true;
	Queue q;
	q.init();
	q.push(pRoot->key);

	while (!q.isEmpty())
	{
		AVLNode* tmp = Search(q.Top());
		q.pop();

		if (tmp->p_left)
			q.push(tmp->p_left->key);

		if (tmp->p_right)
			q.push(tmp->p_right->key);

		int bal = getbalance(tmp);

		if (abs(bal) > 1)
			return false;
	}
	return true;
}