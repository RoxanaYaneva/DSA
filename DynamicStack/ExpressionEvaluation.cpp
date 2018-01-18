#include "stdafx.h"
#include "DynamicStack.h"
#include "Utils.hpp"

#include<iostream>

template<typename T, typename U>
void fillStacks(const char*, DynamicStack<T>&, DynamicStack<U>&);

int evaluateExpression(const char*);

int main() {

	char* expression = "f(m(6, l(4)))";
	int value = evaluateExpression(expression);
	printf("%s = %d\n", expression, value); // 6

	char* expression2 = "m(f(l(4)), 4)";
	int value2 = evaluateExpression(expression2);
	printf("%s = %d\n", expression2, value2); // 5

	system("pause");
	return 0;
}

/*
* Here we evaluate the expression. We suppose that every expression we process is valid.
* We have two stacks - one with operations and one with digits.
* First we pop an operation from the stack of operations (f, l or m) and depending what that operation is,
* we pop one or two operands from the stack of digits. Then we calculate the expression (e.g f(4) = 6)
* by the given formula and assign it to the variable result. Then we push the result back into the stack of digits.
* The last digit which is in the stack of digits is the final result from calculating the expression.
* Functions f, l, and m are defined in "Utils.cpp".
*/
int evaluateExpression(const char* expression) {
	DynamicStack<char> operations(16);
	DynamicStack<int> digits(16);
	fillStacks<int, char>(expression, digits, operations);

	int result = 0, operand1, operand2;
	char operation;

	while (!operations.isEmpty()) {
		operations.pop(operation);
		switch (operation) {
		case 'f':
			if (digits.pop(operand1)) {
				result = utils::f(operand1);
				digits.push(result);
			}
			break;
		case 'l':
			if (digits.pop(operand1)) {
				result = utils::l(operand1);
				digits.push(result);
			}
			break;
		case 'm':
			if (digits.pop(operand1) && digits.pop(operand2)) {
				result = utils::m(operand1, operand2);
				digits.push(result);
			}
			break;
		default:
			break;
		}
	}
	digits.pop(result);
	return result;
}

/*
* We have two seperate stacks for the digits and operations (f, l or m) 
* and we fill them with the content of the expression. 
* Functions isDigit and isOperation are defined in "Utils.cpp".
*/
template<typename T, typename U>
void fillStacks(const char* expression, DynamicStack<T>& digits, DynamicStack<U>& operations) {
	int digit;
	for (size_t i = 0; expression[i] != '\0'; ++i) {
		if (utils::isDigit(expression[i])) {
			digit = expression[i] - '0';
			digits.push(digit);
		} else if (utils::isOperation(expression[i])) {
			operations.push(expression[i]);
		}
	}
}
