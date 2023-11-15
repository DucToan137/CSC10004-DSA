#include<iostream>
#include"Queue.h"
using namespace std;

Queue::Node* Queue::createNode(int data)
{
	Node* node = new Node;
	if (!node) return nullptr;
	node->key = data;
	node->pNext = nullptr;
	return node;
}

void Queue::init()
{
	pHead = pTail = nullptr;
	size = 0;
}

bool Queue::push(int data)
{
	Node* node = createNode(data);
	if (!pHead)
		pHead = pTail = node;
	else
	{
		pTail->pNext = node;
		pTail = node;
	}
	size++;
	return true;
}

int Queue::front()
{
	if (size <= 0)
		return -1;
	return pHead->key;
}

bool Queue::isEmpty()
{
	if (!pHead)
		return true;
	return false;
}

void Queue::pop()
{
	if (size<=0) return;
	pHead = pHead->pNext;
	size--;
}

void Queue::print()
{
	if (isEmpty())
		cout << "Queue rong " << endl;
	else
	{
		while (!isEmpty())
		{
			cout << pHead->key << " ";
			pop();
		}
	}
}