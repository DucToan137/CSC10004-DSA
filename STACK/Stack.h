#pragma once
#include<iostream>
using namespace std;

struct Stack {
	struct Node {
		int key;
		Node* pNext;
	};
	int size;
	Node* top;

	Node* createNode(int data);
	void init();
	int front();
	bool push(int data);
	bool isEmpty();
	void pop();
	void print();
};