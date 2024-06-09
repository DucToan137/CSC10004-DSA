#include<iostream>
#include<string>
#include"Stack.h"

using namespace std;

int main() {

	Stack st;
	string s;
	getline(cin, s);

	st.init();
	cout << evaluate_postfix(s);

	return 0;
}