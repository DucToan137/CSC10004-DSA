#include<iostream>
#include"./Queue.h"

Queue::Node* Queue::createNode(int x)
{
	Node* node = new Node;
	node->data = x;
	node->next = NULL;
	return node;

}

void Queue::init() // hàm khởi tạo queue rỗng
{
	head = tail = nullptr;
	size = 0;
}

bool Queue::isEmpty() // hàm kiểm tra queue rỗng
{
	if (head == nullptr)
		return true;
	return false;
}

int Queue::Top() // hàm trả về giá trị của head trong queue
{
	if (size <= 0)
		return -1;
	return head->data;
}

bool Queue::push(int data) // hàm push dữ liệu vào queue
{
	if (isEmpty())
	{
		Node* node = new Node{ data,nullptr };
		head = node;
		tail = head;
	}
	else
	{
		Node* node = new Node{ data,nullptr };
		tail->next = node;
		tail = node;

	}
	size++;
	return true;
}

void Queue::pop() // hàm pop dữ liệu ra khỏi queue
{
	if (isEmpty())
		return;
	else
	{
		head = head->next;
		size--;
	}
}