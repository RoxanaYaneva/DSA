#pragma once

#ifndef LINKED_STACK_H
#define LINKED_STACK_H

template<typename T>
struct Node
{
	T data;
	Node* next;
};

template<typename T>
class LinkedStack
{
public:
	LinkedStack();
	LinkedStack(const LinkedStack&);
	LinkedStack& operator=(const LinkedStack&);
	~LinkedStack();

public:
	void push(const T&);
	void pop();
	T top() const;

	bool isEmpty() const;

private:
	void copy(const LinkedStack&);
	void clear();

private:
	Node<T>* tos;
};

#include "LinkedStack.hpp"

#endif // ! LINKED_STACK_H
