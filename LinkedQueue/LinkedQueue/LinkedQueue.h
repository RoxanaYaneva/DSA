#pragma once

#ifndef LINKED_QUEUE_H
#define LINKED_QUEUE_H

template<typename T>
struct Node {
	T data;
	Node<T>* next;
};

template<typename T>
class LinkedQueue {

public:
	LinkedQueue();
	LinkedQueue(const LinkedQueue&);
	LinkedQueue& operator=(const LinkedQueue&);
	~LinkedQueue();

public:
	void enqueue(const T&);
	bool dequeue(T&);
	T front() const;

	bool isEmpty() const;
	void print() const;

private:
	void copy(const LinkedQueue&);
	void clear();

private:
	Node<T> *head, *tail;
};

#include "LinkedQueue.hpp"

#endif // !LINKED_QUEUE_H

