#include<iostream>
#include"Queue.h"
using namespace std;

int main()
{
	Queue q;
	q.init();

	if (q.isEmpty())
		cout << "Queue rong" << endl;

	q.push(7);
	q.push(5);
	q.push(3);
	q.push(8);
	q.push(9);

	cout << q.size << endl;
	if (q.isEmpty())
		cout << "Queue rong" << endl;
	else
	{
		cout << "Danh sach queue: " << endl;
		q.print();
	}
	return 0;
}