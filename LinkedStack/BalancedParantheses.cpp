#include "stdafx.h"
#include "LinkedStack.h"

#include<iostream>

bool checkBalancedParantheses(const char* expr) {
	LinkedStack<char> stack;
	bool result = true;
	int i = 0;
	while(expr[i] && result) {
		char c = expr[i];
		switch (c) {
		case '(':
		case '{':
		case '[':
			stack.push(c);
			break;
		case ')':
			!stack.isEmpty() && stack.top() == '(' ? stack.pop() : result = false;
			break;
		case ']':
			!stack.isEmpty() && stack.top() == '[' ? stack.pop() : result = false;
			break;
		case '}':
			!stack.isEmpty() && stack.top() == '{' ? stack.pop() : result = false;
			break;
		default:
			break;
		}
		++i;
	}
	if (result && stack.isEmpty()) return true;
}

int main() {
	char* c = "{3*[a+b(c*d+s)+3*(23*f+5)]}";
	std::cout << checkBalancedParantheses(c) << std::endl; // true

	char* c1 = ")4*(4*t)+[{5*u}](";
	std::cout << checkBalancedParantheses(c1) << std::endl; // false;

	system("pause");
	return 0;
}

