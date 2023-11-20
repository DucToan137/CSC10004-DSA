#include<iostream>
#include"Queue.h"

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
	Node* p = createNode(data);
	if (size <= 0)
		pHead = pTail = p;
	else
	{
		pTail->pNext = p;
		pTail = p;
	}
	size++;
	return true;
}

int Queue::front()
{
	if (size <= 0) return -1;
	return pHead->key;
}

void Queue::pop()
{
	if (size <= 0) return;
	pHead = pHead->pNext;
	size--;
}

bool Queue::isEmpty()
{
	if (size <= 0) return true;
	return false;
}
