#pragma once
#include<iostream>
using namespace std;

struct Queue {
	struct Node {
		int data;
		Node* next;
	};
	int size;
	Node* head;
	Node* tail;
	Node* createNode(int x);
	void init();
	bool isEmpty();
	int Top();
	bool push(int data);
	void pop();
};
