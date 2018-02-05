#ifndef BST_HPP
#define BST_HPP

#include<iomanip>

template<typename T>
inline BST<T>::BST() : root(nullptr) {}

template<typename T>
inline BST<T>::BST(const BST<T>& other) {
	copy(root, other.root);
}

template<typename T>
inline BST<T>& BST<T>::operator=(const BST<T>& other) {
	if (this != &other) {
		deleteTree(root);
		copy(root, other.root);
	}
	return *this;
}

template<typename T>
inline BST<T>::~BST() {
	deleteTree(root);
}

template<typename T>
inline void BST<T>::create() {
	T element;
	char answer;
	std::cout << "Do you want to enter an element? y/n: ";
	std::cin >> answer;
	while (answer == 'y') {
		std::cout << "Enter the element: ";
		std::cin >> element;
		addElement(element);
		std::cout << "Do you want to enter another element? y/n: ";
		std::cin >> answer;
	}
}

template<typename T>
inline void BST<T>::createTree(const T& element, BST<T>& left, BST<T>& right) {
	root = new Node<T>();
	root->data = element;
	copy(root->left, left.root);
	copy(root->right, right.root);
}

template<typename T>
inline void BST<T>::addElement(const T& element) {
	add(root, element);
}

template<typename T>
inline Node<T>* BST<T>::deleteElement(Node<T>* node, const T& element) {
	if (node == nullptr)
		return node;
	else if (element < node->data) {
		node->left = deleteElement(node->left, element);
	} else if (element > node->data) {
		node->right = deleteElement(node->right, element);
	} else {
		if (node->left == nullptr && node->right == nullptr) {
			delete node;
			node = nullptr;
		} else if (node->left == nullptr) {
			Node<T>* temp = node;
			node = node->right;
			delete temp;
		} else if (node->right == nullptr) {
			Node<T>* temp = node;
			node = node->left;
			delete temp;
		} else {
			Node<T> *temp = findMin(node->right);
			node->data = temp->data;
			node->right = deleteElement(node->right, temp->data);
		}
	}
	return node;
}

template<typename T>
inline void BST<T>::deleteElement(const T& element) {
	deleteElement(root, element);
}

template<typename T>
inline Node<T>* BST<T>::getRoot() const {
	return root;
}

template<typename T>
inline T BST<T>::getRootData() const {
	if (root) {
		return root->data;
	}
	return T();
}

template<typename T>
inline BST<T> BST<T>::getLeftTree() const {
	BST<T> leftTree;
	copy(leftTree.root, root->left);
	return leftTree;
}

template<typename T>
inline BST<T> BST<T>::getRightTree() const {
	BST<T> rightTree;
	copy(rightTree.root, root->right);
	return rightTree;
}

template<typename T>
inline void BST<T>::inorder(const Node<T>* root) const {
	if (root) {
		inorder(root->left);
		std::cout << root->data << " ";
		inorder(root->right);
	}
}

template<typename T>
inline void BST<T>::preorder(const Node<T>* root) const {
	if (root) {
		std::cout << root->data << " ";
		preorder(root->left);
		preorder(root->right);
	}
}

template<typename T>
inline void BST<T>::postorder(const Node<T>* root) const {
	if (root) {
		postorder(root->left);
		postorder(root->right);
		std::cout << root->data << " ";
	}
}

template<typename T>
inline void BST<T>::print() const {
	printRec(root, 0);
}

template<typename T>
inline bool BST<T>::isEmpty() const {
	return (root == nullptr);
}

template<typename T>
inline bool BST<T>::hasElement(Node<T>* node, const T& element) const {
	if (node == nullptr) {
		return false;
	} else if (node->data == element) {
		return true;
	} else if (element < node->data) {
		hasElement(node->left, element);
	} else {
		hasElement(node->right, element);
	}
}

template<typename T>
inline T BST<T>::findMin() const {
	Node<T>* min = findMin(root);
	return min->data;
}

template<typename T>
inline Node<T>* BST<T>::findMinNode(Node<T>* node) const {
	Node<T>* temp = node;
	while (temp) {
		if (temp->left == nullptr) {
			return temp;
		} else {
			temp = temp->left;
		}
	}
	return temp;
}

template<typename T>
inline T BST<T>::findMax() const {
	Node<T>* max = findMax(root);
	return max->data;
}

template<typename T>
inline Node<T>* BST<T>::findMaxNode(Node<T>* node) const {
	Node<T>* temp = node;
	while (temp) {
		if (temp->right == nullptr) {
			return temp;
		} else {
			temp = temp->right;
		}
	}
	return temp;
}

template<typename T>
inline void BST<T>::add(Node<T>*& node, const T& element) const {
	if (node == nullptr) {
		node = new Node<T>;
		node->data = element;
		node->left = node->right = nullptr;
	} else if (element < node->data) {
		add(node->left, element);
	} else {
		add(node->right, element);
	}
}

template<typename T>
inline void BST<T>::printRec(Node<T>* node, int level) const {
	if (node) {
		int identation = 2;
		std::cout << std::setw(level + identation) << "--" << node->data << std::endl;
		printRec(node->left, level + identation);
		printRec(node->right, level + identation);
	}
}

template<typename T>
inline void BST<T>::copy(Node<T>* & dest, Node<T>* const & src) const {
	dest = nullptr;
	if (src) {
		dest = new Node<T>;
		dest->data = src->data;
		copy(dest->left, src->left);
		copy(dest->right, src->right);
	}
}

template<typename T>
inline void BST<T>::deleteTree(Node<T>* &root) const {
	if (root) {
		deleteTree(root->left);
		deleteTree(root->right);
		delete root;
		root = nullptr;
	}
}

#endif // ! BST_HPP
