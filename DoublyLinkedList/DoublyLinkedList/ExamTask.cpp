#include "stdafx.h"

#include "..\StaticStack.h"
#include "..\DoublyLinkedList.h"
#include "..\LinkedQueue.h"

#include<iostream>

bool isDigit(char);
bool isOperator(char);
int charToInt(char);
int makeOperation(char, int, int);
int evaluateExpression(CircularQueue<char>);
bool checkForEquality(DoublyLinkedList<CircularQueue<char>>);

int main() {
	
	LinkedQueue<char> q1, q2, q3;
	DoublyLinkedList<CircularQueue<char>> dll;

	q1.enqueue('1'); q1.enqueue('2'); q1.enqueue('+');
	q2.enqueue('3');
	q3.enqueue('7'); q3.enqueue('1'); q3.enqueue('/');

	dll.append(q1); dll.append(q2); dll.append(q3);
	
	std::cout << checkForEquality(dll);

	system("pause");
	return 0;
}

bool isDigit(char c) {
	return (c >= '0' && c <= '9');
}

bool isOperator(char c) {
	return (c == '+' || c == '-' || c == '*' || c == '/');
}

int charToInt(char c) {
	return (c - '0');
}

int makeOperation(char c, int op1, int op2) {
	int result;
	switch (c) {
	case '+': 
		result = op1 + op2;  break;
	case '-':
		result = op1 - op2;  break;
	case '*': 
		result = op1 * op2; break;
	case '/':
		result = op1 / op2; break;
	default:
		break;
	}
	return result;
}

int evaluateExpression(CircularQueue<char> queue) {
	StaticStack<int> resultStack;
	char element;
	int operand1, operand2, result;
	while (!queue.isEmpty()) {
		queue.dequeue(element);
		if (isDigit(element)) {
			resultStack.push(charToInt(element));
		} 
		else if (isOperator(element)) {
			resultStack.pop(operand2);
			resultStack.pop(operand1);
			resultStack.push(makeOperation(element, operand1, operand2));
		}
	}
	resultStack.pop(result);
	return result;
}

bool checkForEquality(DoublyLinkedList<CircularQueue<char>> list) {
	list.iterStart();
	Node<CircularQueue<char>>* start = list.iterNext();
	list.iterEnd();
	Node<CircularQueue<char>>* end = list.iterPrev();
	int sum1 = 0, sum2 = 0, size = list.getSize();
	CircularQueue<char> queue;
	for (size_t i = 0; i < size / 2; ++i) {
		list.removeElement(start, queue);
		sum1 += evaluateExpression(queue);
		list.removeElement(end, queue);
		sum2 += evaluateExpression(queue);
		start = list.iterNext();
		end = list.iterPrev();
	}
	if (!list.isEmpty()) {
		list.removeElement(start, queue);
		sum1 += evaluateExpression(queue);
		sum2 += evaluateExpression(queue);
	}
	return (sum1 == sum2);
}