#include "LinkedQueue.h"
#ifndef LINKED_QUEUE_HPP
#define LINKED_QUEUE_HPP

template<typename T>
inline LinkedQueue<T>::LinkedQueue() : head(nullptr), tail(nullptr) {}

template<typename T>
inline LinkedQueue<T>::LinkedQueue(const LinkedQueue& other) : head(nullptr), tail(nullptr) {
	copy(other);
}

template<typename T>
inline LinkedQueue<T>& LinkedQueue<T>::operator=(const LinkedQueue<T>& other) {
	if (this != &other) {
		clear();
		copy(other);
	}
	return *this;
}

template<typename T>
inline LinkedQueue<T>::~LinkedQueue() {
	clear();
}

template<typename T>
inline void LinkedQueue<T>::enqueue(const T& element) {
	Node<T>* newNode = new Node<T>;
	newNode->data = element;
	newNode->next = nullptr;
	if (isEmpty()) {
		head = newNode;
	}
	else {
		tail->next = newNode;
	}
	tail = newNode;
}

template<typename T>
inline bool LinkedQueue<T>::dequeue(T& element) {
	if (isEmpty()) {
		std::cout << "Empty queue.\n";
		return false;
	}
	Node<T>* temp = head;
	if (head == tail) {
		head = tail = nullptr;
	} else {
		head = head->next;
	}
	element = temp->data;
	delete temp;
	return true;
}

template<typename T>
inline T LinkedQueue<T>::front() const {
	if (isEmpty()) {
		return T();
	}
	return head->data;
}

template<typename T>
inline bool LinkedQueue<T>::isEmpty() const {
	return tail == nullptr;
}

template<typename T>
inline void LinkedQueue<T>::print() const {
	if (isEmpty()) {
		std::cout << "Queue is empty.\n";
	} else {
		Node<T>* temp = head;
		while (temp) {
			std::cout << temp->data << " ";
			temp = temp->next;
		}
		std::cout << std::endl;
	}
}

template<typename T>
inline void LinkedQueue<T>::copy(const LinkedQueue<T>& other) {
	head = tail = nullptr;
	if (!other.isEmpty()) {
		Node<T>* temp = other.head;
		while (temp) {
			enqueue(temp->data);
			temp = temp->next;
		}
	}
}

template<typename T>
inline void LinkedQueue<T>::clear() {
	while (!isEmpty()) {
		Node<T>* temp = head;
		if (head == tail) {
			head = tail = nullptr;
		} else {
			head = head->next;
		}
		delete temp;
	}
}

#endif // !LINKED_QUEUE_HPP
