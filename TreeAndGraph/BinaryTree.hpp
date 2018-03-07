#include "BinaryTree.h"
#ifndef BINARY_TREE_HPP
#define BINARY_TREE_HPP

#include<iomanip>

template<typename T>
inline BinaryTree<T>::BinaryTree() : root(nullptr) {}

template<typename T>
inline BinaryTree<T>::BinaryTree(const BinaryTree<T>& other) {
	copy(root, other.root);
}

template<typename T>
inline BinaryTree<T>& BinaryTree<T>::operator=(const BinaryTree<T>& other) {
	if (this != &other) {
		deleteTree(root);
		copy(root, other.root);
	}
	return *this;
}

template<typename T>
inline BinaryTree<T>::~BinaryTree() {
	deleteTree(root);
}

template<typename T>
inline void BinaryTree<T>::create() {
	createBinaryTree(root);
}

template<typename T>
inline void BinaryTree<T>::createTree(T element, BinaryTree<T>& left, BinaryTree<T>& right) {
	root = new Node_t<T>();
	root->data = element;
	copy(root->left, left.root);
	copy(root->right, right.root);
}

template<typename T>
inline void BinaryTree<T>::createBinaryTree(Node_t<T>* &root) {
	T element;
	std::cout << "Enter element: ";
	std::cin >> element;
	root = new Node_t<T>;
	root->data = element;
	root->left = root->right = nullptr;
	char answer;
	std::cout << "Has "<< root->data <<" have left subtree? y/n: ";
	std::cin >> answer;
	if (answer == 'y') {
		createBinaryTree(root->left);
	}
	std::cout << "Has " << root->data << " have right subtree? y/n: ";
	std::cin >> answer;
	if (answer == 'y') {
		createBinaryTree(root->right);
	}	
}

template<typename T>
inline Node_t<T>* BinaryTree<T>::getRoot() const {
	return root;
}

template<typename T>
inline T BinaryTree<T>::getRootData() const {
	if (root) {
		return root->data;
	}
	return T();
}

template<typename T>
inline BinaryTree<T> BinaryTree<T>::getLeftTree() const {
	BinaryTree<T> leftTree;
	copy(leftTree.root, root->left);
	return leftTree;
}

template<typename T>
inline BinaryTree<T> BinaryTree<T>::getRightTree() const {
	BinaryTree<T> rightTree;
	copy(rightTree.root, root->right);
	return rightTree;
}

template<typename T>
inline void BinaryTree<T>::inorder(const Node_t<T>* root) const {
	if (root) {
		inorder(root->left);
		std::cout << root->data << " ";
		inorder(root->right);
	}
}

template<typename T>
inline void BinaryTree<T>::preorder(const Node_t<T>* root) const {
	if (root) {
		std::cout << root->data << " ";
		preorder(root->left);
		preorder(root->right);
	}
}

template<typename T>
inline void BinaryTree<T>::postorder(const Node_t<T>* root) const {
	if (root) {
		postorder(root->left);
		postorder(root->right);
		std::cout << root->data << " ";
	}
}

template<typename T>
inline bool BinaryTree<T>::isLeaf(Node_t<T>* root) const
{
	return (!root->left && !root->right);
}

template<typename T>
inline void BinaryTree<T>::print() const {
	printRec(root, 0);
}

template<typename T>
inline bool BinaryTree<T>::isEmpty() const {
	return (root == nullptr);
}

template<typename T>
inline void BinaryTree<T>::printRec(Node_t<T>* Node_t, int level) const {
	if (Node_t) {
		int identation = 2;
		std::cout << std::setw(level + identation)  << "--" << Node_t->data << std::endl;
		printRec(Node_t->left, level + identation);
		printRec(Node_t->right, level + identation);
	}
}

template<typename T>
inline void BinaryTree<T>::copy(Node_t<T>* & p, Node_t<T>* const & q) const {
	p = nullptr;
	if (q) {
		p = new Node_t<T>;
		p->data = q->data;
		copy(p->left, q->left);
		copy(p->right, q->right);
	}
}

template<typename T>
inline void BinaryTree<T>::deleteTree(Node_t<T>* &root) const {
	if (root) {
		deleteTree(root->left);
		deleteTree(root->right);
		delete root;
		root = nullptr;
	}
}

#endif // !BINARY_TREE_HPP