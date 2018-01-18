#ifndef LINKED_STACK_HPP
#define LINKED_STACK_HPP

template<typename T>
inline LinkedStack<T>::LinkedStack() : tos(nullptr) {}

template<typename T>
inline LinkedStack<T>::LinkedStack(const LinkedStack& other) {
	copy(other);
}

template<typename T>
inline LinkedStack<T>& LinkedStack<T>::operator=(const LinkedStack& other) {
	if (this != &other) {
		clear();
		copy(other);
	}
}

template<typename T>
inline LinkedStack<T>::~LinkedStack() {
	clear();
}

template<typename T>
inline void LinkedStack<T>::push(const T& element) {
	Node<T>* newNode = new Node<T>;
	newNode->data = element;
	newNode->next = tos;
	tos = newNode;
}

template<typename T>
inline void LinkedStack<T>::pop() {
	if (isEmpty()) {
		printf("Stack is empty.\n");
		return;
	}
	Node<T>* temp = tos;
	tos = tos->next;
	delete temp;
}

template<typename T>
inline T LinkedStack<T>::top() const {
	if (isEmpty()) {
		printf("Stack is empty.\n");
		return T();
	}
	return tos->data;
}

template<typename T>
inline bool LinkedStack<T>::isEmpty() const {
	return tos == nullptr;
}

template<typename T>
inline void LinkedStack<T>::copy(const LinkedStack<T>& other) {
	tos = other.tos;
	Node<T>* temp = tos;
	while (temp) {
		Node<T>* newNode = new Node<T>;
		newNode->data = temp->data;
		newNode->next = temp->next;
		temp = tenp->next;
	}
}

template<typename T>
inline void LinkedStack<T>::clear() {
	while (!isEmpty()) {
		pop();
	}
}

#endif // ! LINKED_STACK_HPP