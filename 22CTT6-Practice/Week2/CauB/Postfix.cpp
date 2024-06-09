#include"Stack.h"

int tinh(int a, int b, char c) {
	if (c == '+') return a + b;
	if (c == '-') return a - b;
	if (c == '*') return a * b;
	if (a == '/') return a / b;
}

int evaluate_postfix(string& postfix) {
	Stack s;
	s.init();

	for (int i = 0; i < postfix.length(); i++) {
		if (postfix[i] == ' ') {
			continue;
		}
		if (isdigit(postfix[i])) {
			int num = 0;
			while (isdigit(postfix[i])) {
				num = num * 10 + (postfix[i] - '0');
				i++;
			}
			i--;
			s.push(num);
		}
		else {
			int a = s.Top();
			s.pop();
			int b = s.Top();
			s.pop();
			switch (postfix[i]) {
			case '+':
				s.push(b + a);
				break;
			case '-':
				s.push(b - a);
				break;
			case '*':
				s.push(b * a);
				break;
			default:
				break;
			}
		}
	}
	return s.Top();
}