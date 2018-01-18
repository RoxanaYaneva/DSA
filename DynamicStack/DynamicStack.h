#pragma once

#ifndef DYNAMIC_STACK_H
#define DYNAMIC_STACK_H

template <typename T>
class DynamicStack {

public:
	DynamicStack(size_t);
	DynamicStack(const DynamicStack&);
	DynamicStack& operator=(const DynamicStack&);
	~DynamicStack();

public:
	void push(const T&);
	bool pop(T&);
	T top() const;

	size_t getSize() const;
	bool isEmpty() const;

private:
	void copy(const DynamicStack<T>&);
	void expand();
	void clear();

private:
	T* data;
	size_t capacity;
	int tos;
};

#include "DynamicStack.hpp"

#endif // !DYNAMIC_ARRAY_H