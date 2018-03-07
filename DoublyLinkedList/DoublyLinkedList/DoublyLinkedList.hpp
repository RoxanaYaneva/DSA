#include "DoublyLinkedList.h"
#ifndef DOUBLY_LINKED_LIST_HPP
#define  DOUBLY_LINKED_LIST_HPP

template<typename T>
inline DoublyLinkedList<T>::DoublyLinkedList() : start(nullptr), end(nullptr), size(0) {}

template<typename T>
inline DoublyLinkedList<T>::DoublyLinkedList(const DoublyLinkedList& other) {
	copyLinkedList(other);
}

template<typename T>
inline DoublyLinkedList<T>& DoublyLinkedList<T>::operator=(const DoublyLinkedList<T>& other) {
	if (this != &other) {
		deleteLinkedList();
		copyLinkedList(other);
	}
	return *this;
}

template<typename T>
inline DoublyLinkedList<T>::~DoublyLinkedList() {
	deleteLinkedList();
}

template<typename T>
inline void DoublyLinkedList<T>::iterStart(Node<T>* node) {
	if (node) {
		currentS = node;
	}
	currentS = start;
}

template<typename T>
inline void DoublyLinkedList<T>::iterEnd(Node<T>* node) {
	if (node) {
		currentE = node;
	}
	currentE = end;
}

template<typename T>
inline Node<T>* DoublyLinkedList<T>::iterNext() {
	Node<T>* temp = currentS;
	if (currentS) {
		currentS = currentS->next;
	}
	return temp;
}

template<typename T>
inline Node<T>* DoublyLinkedList<T>::iterPrev() {
	Node<T>* temp = currentE;
	if (currentE) {
		currentE = currentE->prev;
	}
	return temp;
}

template<typename T>
inline void DoublyLinkedList<T>::append(const T& element) {
	Node<T>* temp = end;
	end = new Node<T>;
	end->data = element;
	end->next = nullptr;
	end->prev = temp;
	if (temp) {
		temp->next = end;
	} else {
		start = end;
	}
	++size;
}

template<typename T>
inline void DoublyLinkedList<T>::insertAfter(Node<T>* node, const T& element) {
	Node<T>* newNode = new Node<T>;
	newNode->data = element;
	newNode->prev = node;
	newNode->next = nullptr;
	if (node) {
		if (node->next) {
			node->next->prev = newNode;
		}
		newNode->next = node->next;
		node->next = newNode;

		if (node == end) {
			end = newNode;
		}
	}
	++size;
}

template<typename T>
inline void DoublyLinkedList<T>::insertBefore(Node<T>* node, const T& element) {
	Node<T>* newNode = new Node<T>;
	newNode->data = element;
	newNode->prev = nullptr;
	newNode->next = node;
	if (node) {
		if (node->prev) {
			node->prev->next = newNode;
		}
		node->prev = newNode;
		newNode->prev = node->prev;

		if (node == start) {
			start = newNode;
		}
	}
	++size;
}

template<typename T>
inline void DoublyLinkedList<T>::removeElement(Node<T>* node, T& element) {
	if (node) {
		element = node->data;
		if (start == end) {
			start = end = nullptr;
		} else if (node == start) {
			start = start->next;
			start->prev = nullptr;
		} else if (node == end) {
			end = end->prev;
			end->next = nullptr;
		} else {
			node->prev->next = node->next;
			node->next->prev = node->prev;
		}
		delete node;
		--size;
	}
}

template<typename T>
inline T DoublyLinkedList<T>::getFirst() const {
	if (isEmpty()) {
		std::cout << "List is empty.\n";
		return T();
	}
	return start->data;
}

template<typename T>
inline T DoublyLinkedList<T>::getLast() const {
	if (isEmpty()) {
		std::cout << "List is empty.\n";
		return T();
	}
	return end->data;
}

template<typename T>
inline void DoublyLinkedList<T>::deleteLinkedList() {
	size = 0;
	Node<T>* temp;
	while (start) {
		temp = start;
		start = start->next;
		delete temp;
	}
	start = end = nullptr;
}

template<typename T>
inline void DoublyLinkedList<T>::copyLinkedList(const DoublyLinkedList<T>& other) {
	start = end = nullptr;
	size = 0;
	Node<T>* temp = other.start;
	while (temp) {
		append(temp->data);
		temp = temp->next;
	}
}

template<typename T>
inline bool DoublyLinkedList<T>::isEmpty() const {
	return size == 0;
}

template<typename T>
inline size_t DoublyLinkedList<T>::getSize() const {
	return size;
}

template<typename T>
inline void DoublyLinkedList<T>::print() const {
	Node<T>* temp = start;
	while (temp) {
		std::cout << temp->data << " ";
		temp = temp->next;
	}
	std::cout << std::endl;
}

template<typename T>
inline void DoublyLinkedList<T>::print_reverse() const {
	Node<T>* temp = end;
	while (temp) {
		std::cout << temp->data << " ";
		temp = temp->prev;
	}
	std::cout << std::endl;
}

#endif // ! DOUBLY_LINKED_LIST_HPP