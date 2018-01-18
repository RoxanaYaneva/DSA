#ifndef DYNAMIC_STACK_HPP
#define DYNAMIC_STACK_HPP

template <typename T>
inline DynamicStack<T>::DynamicStack(size_t initialCapacity) : capacity(initialCapacity), tos(-1) {
	data = new T[capacity];
}

template<typename T>
inline DynamicStack<T>::DynamicStack(const DynamicStack& other) {
	copy(other);
}

template<typename T>
inline DynamicStack<T>& DynamicStack<T>::operator=(const DynamicStack<T> & other) {
	if (this != &other) {
		clear();
		copy(other);
	}
	return *this;
}

template<typename T>
inline DynamicStack<T>::~DynamicStack() {
	clear();
}

template<typename T>
inline void DynamicStack<T>::push(const T& element) {
	if (getSize() == capacity) {
		expand();
	}
	data[++tos] = element;
}

template<typename T>
inline bool DynamicStack<T>::pop(T& element) {
	if (isEmpty()) {
		printf("%s\n", "Stack is empty.");
		return false;
	}
	element = data[tos--];
	return true;
}

template<typename T>
inline T DynamicStack<T>::top() const {
	if (isEmpty()) {
		printf("%s\n", "Stack is empty.");
		return T();
	}
	return data[tos];
}

template<typename T>
inline size_t DynamicStack<T>::getSize() const {
	return (tos + 1);
}

template<typename T>
inline bool DynamicStack<T>::isEmpty() const {
	return tos == -1;
}

template<typename T>
inline void DynamicStack<T>::copy(const DynamicStack<T>& other) {
	capacity = other.capacity;
	tos = other.tos;

	data = new T[capacity];

	for (size_t i = 0; i < size; ++i) {
		data[i] = other.data[i];
	}
}

template<typename T>
inline void DynamicStack<T>::expand() {
	capacity *= 2;
	T* buffer = new T[capacity];
	for (size_t i = 0; i < getSize(); ++i) {
		buffer[i] = data[i];
	}
	delete[] data;
	data = buffer;
}

template<typename T>
inline void DynamicStack<T>::clear() {
	capacity = 0;
	tos = -1;
	delete[] data;
}

#endif // ! DYNAMIC_STACK_HPP