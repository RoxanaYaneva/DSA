#pragma once

#ifndef GRAPH_H
#define GRAPH_H

#include "C:\Users\roxy1\source\repos\LinkedList\LinkedList\LinkedList.h"

template<typename T>
class Graph {
public:
	Graph();

public:
	void create();

	void addVertex(const T&);
	void deleteVertex(const T&);
	bool hasVertex(const T&);

	void addEdge(const T&, const T&);
	void deleteEdge(const T&, const T&);
	bool hasEdge(const T&, const T&);

	void print();
	bool isEmpty() const;

	Node<T>* point(const T&);
	LinkedList<T> getVertices();

private:
	LinkedList<LinkedList<T>> lists;
};

#endif // !GRAPH_H

template<typename T>
inline Graph<T>::Graph() {}

template<typename T>
inline void Graph<T>::create() {
	T element, element2;
	char answer;
	std::cout << "Do you want to add a vetex? y/n: ";
	std::cin >> answer;
	while (answer == 'y') {
		std::cout << "Enter vertex: ";
		std::cin >> element;
		addVertex(element);
		std::cout << "Do you want to add another vetex? y/n: ";
		std::cin >> answer;
	}
	std::cout << "Do you want to add an egde? y/n: ";
	std::cin >> answer;
	while (answer == 'y') {
		std::cout << "Enter 2 vertices: ";
		std::cin >> element >> element2;
		addEdge(element, element2);
		std::cout << "Do you want to add another egde? y/n: ";
		std::cin >> answer;
	}
}

template<typename T>
inline void Graph<T>::addVertex(const T& vertex) {
	LinkedList<T> newList;
	newList.append(vertex);
	lists.append(newList);
}

template<typename T>
inline void Graph<T>::deleteVertex(const T& vertex) {
	LinkedList<T> list;
	T el;
	lists.iterStart();
	Node<LinkedList<T>>* currList = lists.iter(), *temp = nullptr;
	while (currList) {
		currList->data.iterStart();
		Node<T>* p = currList->data.iter();
		if (p->data == vertex) {
			temp = currList;
		}
		while (p && p->data != vertex) {
			p = currList->data.iter();
		}
		if (p) {
			currList->data.removeElement(p, el);
		}
		currList = lists.iter();

		if (temp != nullptr) {
			lists.removeElement(temp, list);
		}
	}
}

template<typename T>
inline void Graph<T>::addEdge(const T& v1, const T& v2) {
	Node<T>* p = point(v1);
	while (p->next) {
		p = p->next;
	}
	Node<T>* newNode = new Node<T>;
	newNode->data = v2;
	newNode->next = nullptr;
	p->next = newNode;
}

template<typename T>
inline void Graph<T>::deleteEdge(const T&  v1, const T& v2) {
	lists.iterStart();
	T el;
	Node<LinkedList<T>>* currList;
	Node<T>* temp;
	do {
		currList = lists.iter();
		currList->data.iterStart();
		temp = currList->data.iter();

	} while (v1 != temp->data);

	while (temp && temp->data != v2) {
		temp = temp->next;
	}
	currList->data.removeElement(temp, el);
}

template<typename T>
inline bool Graph<T>::hasEdge(const T& v1, const T& v2) {
	if (isEmpty()) {
		return false;
	}
	Node<T>* p = point(v1);
	p = p->next;
	while (p && p->data != v2) {
		p = p->next;
	}
	return (p != nullptr);
}

template<typename T>
inline void Graph<T>::print() {
	lists.iterStart();
	Node<LinkedList<T>>* currList = lists.iter();
	while (currList) {
		currList->data.print();
		currList = lists.iter();
	}
	std::cout << std::endl;
}

template<typename T>
inline bool Graph<T>::isEmpty() const {
	return lists.isEmpty();
}

template<typename T>
inline bool Graph<T>::hasVertex(const T& vertex) {
	if (isEmpty()) {
		return false;
	}
	lists.iterStart();
	Node<LinkedList<T>>* currList = lists.iter();
	Node<T>* temp;
	while (currList) {
		currList->data.iterStart();
		temp = currList->data.iter();
		if (temp->data == vertex) {
			return true;
		}
		currList = lists.iter();
	}
	return false;
}

template<typename T>
inline Node<T>* Graph<T>::point(const T& vertex) {
	lists.iterStart();
	Node<LinkedList<T>>* currList;
	Node<T>* temp;
	do {
		currList = lists.iter();
		currList->data.iterStart();
		temp = currList->data.iter();

	} while (vertex != temp->data);
	return temp;
}

template<typename T>
inline LinkedList<T> Graph<T>::getVertices() {
	LinkedList<T> vertices;
	lists.iterStart();
	Node<LinkedList<T>>* currList = lists.iter();
	Node<T>* temp;
	while (currList) {
		currList->data.iterStart();
		temp = currList->data.iter();
		vertices.append(temp->data);
		currList = lists.iter();
	}
	return vertices;
}
