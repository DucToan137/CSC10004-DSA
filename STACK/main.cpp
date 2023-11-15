#include<iostream>
#include"Stack.h"
using namespace std;

int main()
{
	Stack s;
	s.init();

	if (s.isEmpty())
		cout << "Stack rong" << endl;
	s.push(3);
	s.push(2);
	s.push(5);
	s.push(9);
	s.push(15);

	cout <<"Size: " << s.size << endl;
	cout << "Top: " << s.front() << endl;
	if (s.isEmpty())
		cout << "Stack rong" << endl;
	else
	{
		cout << "Cac phan tu: " << endl;
		while (!s.isEmpty())
		{
			s.print();
		}
	}
	cout << endl;
	cout << "Cac phan tu cua stack: " << endl;
	s.print();
}