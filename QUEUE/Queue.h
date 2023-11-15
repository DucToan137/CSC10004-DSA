#pragma once
#include<iostream>
using namespace std;

struct Queue {
	struct Node {
		int key;
		Node* pNext;
	};
	int size;
	Node* pHead;
	Node* pTail;

	Node* createNode(int data);
	void init();
	bool push(int data);
	int front();
	bool isEmpty();
	void pop();

	void print();
};
