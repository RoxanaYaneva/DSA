#include "stdafx.h"
#include "BinaryTree.h"
#include "Graph.h"

#include<iostream>

template<typename T>
bool isLeaf(Node_t<T>*);

template<typename T>
void deleteLast(LinkedList<T>&);

template<typename T>
void printPath(LinkedList<T>&);

template<typename T>
void checkForPath(Graph<T>&, BinaryTree<T>&);

template<typename T>
bool matchWay(Node_t<T>*, Graph<T>&, LinkedList<T>&);

int main() {

	Graph<char> graph;
	graph.addVertex('a'); graph.addVertex('d');
	graph.addVertex('e'); graph.addVertex('g');
	graph.addVertex('f'); graph.addVertex('c');
	graph.addVertex('b'); graph.addVertex('h');

	graph.addEdge('a', 'd'); graph.addEdge('e', 'h');
	graph.addEdge('a', 'f'); graph.addEdge('d','e');
	graph.addEdge('g', 'e'); graph.addEdge('f', 'c');
	graph.addEdge('g', 'b'); graph.addEdge('f', 'h');
	graph.addEdge('c', 'h');
	
	BinaryTree<char> tree;
	tree.create();

	checkForPath(graph, tree);

	system("pause");
    return 0;
}

template<typename T>
bool isLeaf(Node_t<T>* root) {
	return (!root->left && !root->right);
}

template<typename T>
void deleteLast(LinkedList<T>& list) {
	T x;
	list.iterStart();
	Node<T>* temp = list.iter();
	while (temp->next) {
		temp = temp->next;
	}
	list.removeElement(temp, x);
}

template<typename T>
void printPath(LinkedList<T>& list) {
	list.iterStart();
	Node<T>* temp = list.iter();
	while (temp->next) {
		std::cout << temp->data << " - ";
		temp = temp->next;
	}
	std::cout << temp->data << std::endl;
}

template<typename T>
void checkForPath(Graph<T>& graph, BinaryTree<T>& tree) {
	Node_t<T>* root = tree.getRoot();
	LinkedList<T> path;
	if (root) {
		path.append(root->data);
		if (matchWay(root, graph, path)) {
			printPath(path);
		}
		else {
			std::cout << "No matched path!\n";
		}
	}
}

template<typename T>
bool matchWay(Node_t<T>* root, Graph<T>& graph, LinkedList<T>& path) {
	if (isLeaf(root)) {
		return true;
	}
	if (root->left && graph.hasEdge(root->data, root->left->data)) {
		path.append(root->left->data);
		if (matchWay(root->left, graph, path)) {
			return true;
		}
	}
	if (root->right && graph.hasEdge(root->data, root->right->data)) {
		path.append(root->right->data);
		if (matchWay(root->right, graph, path)) {
			return true;
		}
	}
	deleteLast(path);
	return false;
}