#pragma once

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

template<typename T>
struct Node {
	T data;
	Node* next;
};

template<typename T>
class LinkedList {
public:
	LinkedList();
	LinkedList(const LinkedList&);
	LinkedList& operator=(const LinkedList&);
	~LinkedList();

public:
	void iterStart(Node<T>* node = nullptr);
	Node<T>* iter();

	void append(const T&);
	void insertBefore(Node<T>*, const T&);
	void insertAfter(Node<T>*, const T&);

	void removeBefore(Node<T>*, T&);
	void removeAfter(Node<T>*, T&);
	void removeElement(Node<T>*, T&);

	bool hasElement(const T&, Node<T>*) const;
	bool hasElement(const T&) const;
	bool hasDuplicates() const;

	T getElement(Node<T>*) const;

	void print() const;
	void reverse();
	void concatenate(const LinkedList<T>&);

	size_t getSize() const;
	bool isEmpty() const;

private:
	void copy(const LinkedList&);
	void clear();

private:
	Node<T> *first, *last, *current;
	size_t size;
};

#include "LinkedList.hpp"

#endif // LINKED_LIST_H
