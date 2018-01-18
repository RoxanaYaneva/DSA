#pragma once

#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

template <typename T>
class DynamicArray {

public:
	DynamicArray();
	DynamicArray(size_t);
	DynamicArray(const DynamicArray&);
	DynamicArray& operator=(const DynamicArray&);
	~DynamicArray();

public:
	void insertAt(size_t, const T&);
	void append(const T&);

	void removeAt(size_t);

	T getElementAt(size_t) const;
	T& operator[](size_t) const;

	size_t getSize() const;
	bool isEmpty() const;

	void swap(size_t, size_t);
	void print() const;

private:
	void expand();
	bool isIndexValid(size_t) const;
	void copy(const DynamicArray&);
	void clear();

private:
	T* data;
	size_t size;
	size_t capacity;
};

#include "DynamicArray.hpp"

#endif // !DYNAMIC_ARRAY_H

