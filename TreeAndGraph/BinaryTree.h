#pragma once

#ifndef BINARY_TREE_H
#define BINARY_TREE_H

template<typename T>
struct Node_t {
	T data;
	Node_t<T>* left;
	Node_t<T>* right;
};

template<typename T>
class BinaryTree {
public:
	BinaryTree();
	BinaryTree(const BinaryTree<T>&);
	BinaryTree<T>& operator=(const BinaryTree<T>&);
	~BinaryTree();

public:
	void create();
	void createTree(T, BinaryTree<T>&, BinaryTree<T>&);

	Node_t<T>* getRoot() const;
	T getRootData() const;

	BinaryTree<T> getLeftTree() const;
	BinaryTree<T> getRightTree() const;

	void inorder(const Node_t<T>*) const;
	void preorder(const Node_t<T>*) const;
	void postorder(const Node_t<T>*) const;

	bool isLeaf(Node_t<T>*) const;
	void print() const;
	bool isEmpty() const;

private:
	void createBinaryTree(Node_t<T>*&);
	void printRec(Node_t<T>*, int) const;
	void copy(Node_t<T>* &, Node_t<T>* const &) const;
	void deleteTree(Node_t<T>*&) const;

private:
	Node_t<T>* root;
};

#include "BinaryTree.hpp"

#endif // !BINARY_TREE_H