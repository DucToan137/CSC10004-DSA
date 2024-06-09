#pragma once
#include<iostream>

using namespace std;


struct Node {
	char data;
	Node* next;
};

struct Stack {
	Node* top;
	int size;

	void init()
	{
		top = nullptr;
		size = 0;
	}

	bool isEmpty()
	{
		if (top == nullptr)
			return true;
		return false;
	}

	int Top()
	{
		if (size <= 0)
			return '0';
		else
			return top->data;
	}

	bool push(char data)
	{
		if (isEmpty())
		{
			top = new Node{ data, nullptr };
			size++;
		}
		else
		{
			Node* node = new Node{ data, nullptr };
			node->next = top;
			top = node;
		}
		size++;
		return true;
	}

	void pop()
	{
		if (size <= 0)
			return;
		top = top->next;
		size--;
	}

};

int tinh(int a, int b, char c);
int evaluate_postfix(string& postfix);