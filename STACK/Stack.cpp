#include<iostream>
#include"Stack.h"
using namespace std;

Stack::Node* Stack::createNode(int data)
{
	Node* p = new Node;
	if (!p) return nullptr;
	p->key = data;
	p->pNext = nullptr;
	return p;
}

void Stack::init()
{
	top = nullptr;
	size = 0;
}

bool Stack::push(int data)
{
	Node* node = createNode(data);
	if (top==nullptr)
		top = node;
	else
	{
		node->pNext = top;
		top = node;
	}
	size++;
	return true;
}

int Stack::front()
{
	if (size <= 0)
		return -1;
	return top->key;
}

bool Stack:: isEmpty()
{
	if (top==nullptr) return true;
	return false;
}

void Stack::pop()
{
	if (size <= 0)
		return;
	top = top->pNext;
	size--;
}

void Stack::print()
{
	if (isEmpty())
	{
		cout << "Stack rong" << endl;
		return;
	}
	while (!isEmpty())
	{
		cout << front() << " ";
		pop();
	}
}