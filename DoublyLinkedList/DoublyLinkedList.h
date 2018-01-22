#pragma once

#ifndef DOUBLE_LINKED_LIST
#define DOUBLE_LINKED_LIST

template<typename T>
struct Node {
	T data;
	Node* prev;
	Node* next;
};

template<typename T>
class DoublyLinkedList {

public:

	DoublyLinkedList();
	DoublyLinkedList(const DoublyLinkedList&);
	DoublyLinkedList& operator=(const DoublyLinkedList&);
	~DoublyLinkedList();

public:

	void iterStart(Node<T>* node = nullptr);
	void iterEnd(Node<T>* node = nullptr);

	Node<T>* iterNext();
	Node<T>* iterPrev();

	void append(const T&);

	void insertAfter(Node<T>*, const T&);
	void insertBefore(Node<T>*, const T&);

	void removeElement(Node<T>*, T&);

	T getFirst() const;
	T getLast() const;

public:

	bool isEmpty() const;
	size_t getSize() const;

	void print() const;
	void print_reverse() const;

private:

	void deleteLinkedList();
	void copyLinkedList(const DoublyLinkedList<T>&);

private:

	Node<T> *start, *end;
	Node<T> *currentS, *currentE;
	size_t size;
};

#include "DoublyLinkedList.hpp"

#endif // !DOUBLE_LINKED_LIST