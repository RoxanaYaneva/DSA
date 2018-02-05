#pragma once

#ifndef BST_H
#define BST_H

template<typename T>
struct Node {
	T data;
	Node<T>* left;
	Node<T>* right;
};

template<typename T>
class BST {
public:
	BST();
	BST(const BST<T>&);
	BST<T>& operator=(const BST<T>&);
	~BST();

public:
	void create();
	void createTree(const T&, BST<T>&, BST<T>&);

	void addElement(const T&);
	void deleteElement(const T&);

	Node<T>* getRoot() const;
	T getRootData() const;

	BST<T> getLeftTree() const;
	BST<T> getRightTree() const;
 
	void inorder(const Node<T>*) const;
	void preorder(const Node<T>*) const;
	void postorder(const Node<T>*) const;

	void print() const;
	bool isEmpty() const;
	bool hasElement(Node<T>*, const T&) const;

	T findMin() const;
	Node<T>* findMinNode(Node<T>*) const;

	T findMax() const;
	Node<T>* findMaxNode(Node<T>*) const;

private:
	void add(Node<T>* &, const T&) const;
	void printRec(Node<T>*, int) const;
	void copy(Node<T>* &, Node<T>* const &) const;
	void deleteTree(Node<T>*&) const;
	Node<T>* deleteElement(Node<T>*, const T&);

private:
	Node<T>* root;
};

#include "BST.hpp"

#endif // !BST_H