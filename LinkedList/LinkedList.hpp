#include "LinkedList.h"
#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

template<typename T>
inline LinkedList<T>::LinkedList() : first(nullptr), last(nullptr), size(0) {}

template<typename T>
inline LinkedList<T>::LinkedList(const LinkedList& other) {
	copy(other);
}

template<typename T>
inline LinkedList<T>& LinkedList<T>::operator=(const LinkedList& other) {
	if (this != &other) {
		clear();
		copy(other);
	}
	return *this;
}

template<typename T>
inline LinkedList<T>::~LinkedList() {
	clear();
}

template<typename T>
inline void LinkedList<T>::iterStart(Node<T>* node) {
	if (node) {
		current = node;
	} 
	current = first;
}

template<typename T>
inline Node<T>* LinkedList<T>::iter() {
	Node<T>* temp = current;
	if (current) {
		current = current->next;
	}
	return temp;
}


template<typename T>
inline void LinkedList<T>::append(const T& element) {
	current = last;
	last = new Node<T>;
	last->data = element;
	last->next = nullptr;
	if (current) {
		current->next = last;
	} else {
		first = last;
	}
	++size;
}

template<typename T>
inline void LinkedList<T>::insertBefore(Node<T>* node, const T& element) {
	Node<T>* newNode = new Node<T>;
	*newNode = *node;
	if (node == last) {
		last = newNode;
	}
	node->data = element;
	node->next = newNode;
	++size;
                                                            }

template<typename T>
inline void LinkedList<T>::insertAfter(Node<T>* node, const T& element) {
	Node<T>* newNode = new Node<T>;
	newNode->data = element;
	newNode->next = node->next;
	if (node == last) {
		last = newNode;
	}
	node->next = newNode;
	++size;
}

template<typename T>
inline void LinkedList<T>::removeBefore(Node<T>* node, T& element) {
	if (node != start) {
		Node<T>* temp = start;
		while (temp) {
			temp = temp->next;
		}
		removeElement(temp, element);
	}
}

template<typename T>
inline void LinkedList<T>::removeAfter(Node<T>* node, T& element) {
	if (node->next) {
		Node<T>* nextNode = node->next;
		element = nextNode->data;
		node->next = nextNode->next;
		if (nextNode == last) {
			last = node;
		}
		delete nextNode;
		--size;
	}
}

template<typename T>
inline void LinkedList<T>::removeElement(Node<T>* node, T& element) {
	if (node == first) {
		element = node->data;
		if (first == last) {
			first = last = nullptr;
		} else {
			first = first->next;
		}
		delete node;
		--size;
	} else {
		Node<T>* temp = first;
		while (temp->next != node) {
			temp = temp->next;
		}
		removeAfter(temp, element);
	}
}

template<typename T>
inline bool LinkedList<T>::hasElement(const T& element, Node<T>* node) const {
	Node<T>* temp = node;
	while (temp) {
		if (temp->data == element) {
			return true;
		} else {
			temp = temp->next;
		}
	}
	return false;
}

template<typename T>
inline bool LinkedList<T>::hasElement(const T& element) const {
	return hasElement(element, first);
}

template<typename T>
inline bool LinkedList<T>::hasDuplicates() const {
	Node<T>* temp = first;
	while (temp) {
		if (hasElement(temp->data, temp->next)) {
			return true;
		}
		temp = temp->next;
	}
	return false;
}

template<typename T>
inline T LinkedList<T>::getElement(Node<T>* node) const {
	if (node) {
		return node->data;
	}
	return T();
}

template<typename T>
inline size_t LinkedList<T>::getSize() const {
	return size;
}

template<typename T>
inline bool LinkedList<T>::isEmpty() const {
	return size == 0;
}

template<typename T>
inline void LinkedList<T>::reverse() {
	Node<T> *current, *prev, *next;
	current = first;
	last = first;
	prev = nullptr;
	while (current) {
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	first = prev;
}

template<typename T>
inline void LinkedList<T>::concatenate(const LinkedList<T>& list) {
	Node<T>* temp = list.first;
	while (temp) {
		append(temp->data);
		temp = temp->next;
	}
}

template<typename T>
inline void LinkedList<T>::print() const {
	Node<T>* temp = first;
	while (temp) {
		std::cout << temp->data << " ";
		temp = temp->next;
	}
	std::cout << std::endl;
}

template<typename T>
inline void LinkedList<T>::copy(const LinkedList<T>& other) {
	first = last = nullptr;
	size = other.size;

	if (other.first) {
		Node<T>* temp  = other.first;
		while (temp) {
			append(temp->data);
			temp = temp->next;
		}
	}
}

template<typename T>
inline void LinkedList<T>::clear() {
	Node<T>* temp;
	while (first) {
		temp = first;
		first = first->next;
		delete temp;
	}
	last = nullptr;
}

#endif // ! LINKED_LIST_HPP
