#include<iostream>
#include<string>
#include<sstream>
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

	char Top()
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

	void print()
	{
		while (!isEmpty())
		{
			cout << Top() << " ";
			pop();
		}
	}
};

struct Queue {
	Node* head;
	Node* tail;
	int size;

	void init()
	{
		head = tail = nullptr;
		size = 0;
	}

	bool isEmpty()
	{
		if (head == nullptr)
			return true;
		return false;
	}

	char Top()
	{
		if (size <= 0)
			return -1;
		return head->data;
	}

	bool push(char data)
	{
		if (isEmpty())
		{
			head = new Node{ data,nullptr };
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

	void pop() {
		if (isEmpty())
			return;
		else
		{
			head = head->next;
			size--;
		}
	}

	void print()
	{
		while (!isEmpty())
		{
			cout << Top() << " ";
			pop();
		}
	}

};



int UuTien(char op)
{
	if (op == '+' || op == '-')
		return 1;
	if (op == '*' || op == '/')
		return 2;
	return -1;
}


//a
void inStack(string a) {
	Stack s;
	s.init();
	for (int i = 0; i < a.size(); i++) {
		if (a[i] >= '0' && a[i] <= '9') {
			cout << a[i] << " ";
		}
		else
			if (a[i] == '+' || a[i] == '-' || a[i] == '*' || a[i] == '/') {
				//top-pop
				if (!s.isEmpty()) {
					if (UuTien(s.Top()) >= UuTien(a[i])) {
						cout << s.Top() << " ";
						s.pop();
					}
				}
				if (s.isEmpty() || s.Top() == '(' ||
					UuTien(s.Top()) < UuTien(a[i])) {
					s.push(a[i]);
				}
			}
			else
				if (a[i] == '(') {
					s.push(a[i]);
				}
				else {
					//dau )
					while (s.Top() != '(') {
						cout << s.Top() << " ";
						s.pop();
					}
					s.pop(); //bo dau ( hien co trong stack
				}
	}
	//xuat het Stack con lai
	while (!s.isEmpty()) {
		cout << s.Top() << " ";
		s.pop();
	}
}



//c

int Uutien2(char op) {
	if (op == 'and' || op == 'not') return 1;
	if (op == 'not') return 2;
	return 0;
}




int main() {
	string s;
	getline(cin, s);


	inStack(s);


	return 0;
}