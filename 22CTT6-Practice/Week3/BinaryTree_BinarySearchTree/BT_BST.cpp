#include"BT_BST.h"


//1 khởi tạo 1 NODE từ 1 giá trị cho trước
NODE* createNode(int data)
{
	NODE* Node = new NODE;
	Node->key = data;
	Node->p_left = nullptr;
	Node->p_right = nullptr;
	return Node;
}

//2 duyệt tiền thứ tự
void NLR(NODE* pRoot)
{
	if (!pRoot) return;
	cout << pRoot->key << " ";
	NLR(pRoot->p_left);
	NLR(pRoot->p_right);
}

//3 duyệt trung thứ tự
void LNR(NODE* pRoot)
{
	if (!pRoot) return;
	LNR(pRoot->p_left);
	cout << pRoot->key << " ";
	LNR(pRoot->p_right);
}

//4 duyệt hậu thứ tự
void LRN(NODE* pRoot)
{
	if (!pRoot) return;
	LRN(pRoot->p_left);
	LRN(pRoot->p_right);
	cout << pRoot->key << " ";
}

//5 duyệt theo mức
void LevelOrder(NODE* pRoot)
{

}

//6 tìm và trả về NODE với giá trị cho trước từ cây nhị phân tìm kiếm
NODE* Search(NODE* pRoot, int x)
{
	if (!pRoot) return nullptr;
	else
	{
		if (pRoot->key == x)
			return pRoot;
		if (x < pRoot->key)
			Search(pRoot->p_left, x);
		else
			Search(pRoot->p_right, x);
	}
}

//7 thêm 1 NODE với giá trị cho trước vào cây nhị phân tìm kiếm
void Insert(NODE*& pRoot, int x)
{
	if (!pRoot)
	{
		NODE* p = new NODE;
		p->key = x;
		p->p_left = NULL;
		p->p_right = NULL;
		pRoot = p;
	}
	else
	{
		if (pRoot->key > x)
		{
			Insert(pRoot->p_left, x);
		}
		else if (pRoot->key < x)
		{
			Insert(pRoot->p_right, x);
		}
	}
}

//8 xóa NODE với giá trị cho trước từ cây nhị phân tìm kiếm
void DiTimNodeTheMang(NODE*& T, NODE*& Y)
{
	if (Y->p_left != NULL)
	{
		DiTimNodeTheMang(T, Y->p_left);
	}
	else
	{
		T->key = Y->key;
		T = Y;
		Y = Y->p_right;
	}
}
void Remove(NODE*& pRoot, int x)
{
	if (!pRoot) return;
	else
	{
		if (x < pRoot->key)
		{
			Remove(pRoot->p_left, x);
		}
		else if (x > pRoot->key)
		{
			Remove(pRoot->p_right, x);
		}
		else
		{
			NODE* T = pRoot;
			if (pRoot->p_left == NULL)
				pRoot = pRoot->p_right;
			else if (pRoot->p_right == NULL)
				pRoot = pRoot->p_left;
			else
			{
				DiTimNodeTheMang(T, pRoot->p_right);
			}
			delete T;
		}
	}
}

//9 khởi tạo 1 cây nhị phân tìm kiếm từ 1 mảng cho trước
NODE* createTree(int a[], int n)
{
	NODE* p = nullptr;
	if (n == 0)
		return nullptr;
	else
	{
		for (int i = 0; i < n; i++)
		{

			Insert(p, a[i]);
		}
	}
	return p;
}

//10 xóa hoàn toàn cây nhị phân tìm kiếm
void removeTree(NODE*& pRoot)
{
	if (!pRoot) return;
	if (pRoot->p_left)
	{
		removeTree(pRoot->p_left);
	}
	if (pRoot->p_right)
	{
		removeTree(pRoot->p_right);
	}
	delete pRoot;
	pRoot = NULL;
}

//11 tính chiều cao cây nhị phân tìm kiếm
int Height(NODE* pRoot)
{
	if (!pRoot)	return 0;
	int t = Height(pRoot->p_left);
	int p = Height(pRoot->p_right);
	if (t > p)
	{
		return t + 1;
	}
	return p + 1;
}

//12 đếm số NODE trên cây nhị phân
int countNode(NODE* pRoot) // đếm số node trong cây
{
	if (!pRoot) return 0;
	return 1 + countNode(pRoot->p_left) + countNode(pRoot->p_right);
}

//13 tính tổng giá trị node trong 1 cây nhị phân
int sumNode(NODE* pRoot)
{
	if (!pRoot) return 0;
	return pRoot->key + sumNode(pRoot->p_left) + sumNode(pRoot->p_right);
}

//14 tính chiều cao của 1 NODE với giá trị cho trước (trả về -1 nếu không tồn tại)
int heightNode(NODE* pRoot, int value)
{
	if (!pRoot) return -1;
	if (pRoot->key == value)
		return 0;
	int t = heightNode(pRoot->p_left, value);
	int p = heightNode(pRoot->p_right, value);

	if (t != -1)
		return 1 + t;
	else if (p != -1)
		return 1 + p;
	else
		return -1;
}

//16 đếm số lá của 1 cây nhị phân
int countLeaf(NODE* pRoot)
{
	if (!pRoot) return 0;
	if (!pRoot->p_left && !pRoot->p_right)
		return 1;
	return countLeaf(pRoot->p_right) + countLeaf(pRoot->p_right);
}

//17 đếm số NODE của cây nhị phân tìm kiếm mà giá trị key nhỏ hơn giá trị cho trước
int countLess(NODE* pRoot, int x)
{
	if (!pRoot) return 0;
	int dem = 0;
	if (pRoot->key < x)
		dem = 1;
	dem = dem + countLess(pRoot->p_left, x);
	dem = dem + countLess(pRoot->p_right, x);
	return dem;
}

//18 đếm số NODE của cây nhị phân tìm kiếm mà giá trị key lớn hơn giá trị cho trước
int countGreater(NODE* pRoot, int x)
{
	if (!pRoot) return 0;
	int dem = 0;
	if (pRoot->key > x)
		dem = 1;
	dem = dem + countGreater(pRoot->p_left, x);
	dem = dem + countGreater(pRoot->p_right, x);
	return dem;
}

//20  xác định cây nhị phân có phải là cây nhị phân tìm kiếm đầy đủ hay không
bool isFullBST(NODE* pRoot)
{
	if (!pRoot) return false;
	if (pRoot->p_left == NULL && pRoot->p_right == NULL)
		return true;
	return isFullBST(pRoot->p_left) && isFullBST(pRoot->p_right);
}


