#ifndef DYNAMIC_ARRAY_HPP
#define DYNAMIC_ARRAY_HPP

template <typename T>
inline DynamicArray<T>::DynamicArray() : capacity(100), size(0) {
	data = new T[capacity];
}

template <typename T>
inline DynamicArray<T>::DynamicArray(size_t initialCapacity) : capacity(initialCapacity), size(0) {
	data = new T[capacity];
}

template<typename T>
inline DynamicArray<T>::DynamicArray(const DynamicArray& other) {
	copy(other);
}

template<typename T>
inline DynamicArray<T>& DynamicArray<T>::operator=(const DynamicArray<T> & other) {
	if (this != &other) {
		clear();
		copy(other);
	}
	return *this;
}

template<typename T>
inline DynamicArray<T>::~DynamicArray() {
	clear();
}

template<typename T>
inline void DynamicArray<T>::insertAt(size_t index, const T& element) {
	if (size == capacity) {
		expand();
	}
	if (index >= size) {
		append(element);
		return;
	}
	for (size_t i = size; i > index; --i) {
		data[i] = data[i - 1];
	}
	data[index] = element;
	++size;
}

template<typename T>
inline void DynamicArray<T>::append(const T& element) {
	if (size == capacity) {
		expand();
	}
	data[size++] = element;
}

template<typename T>
inline void DynamicArray<T>::removeAt(size_t index) {
	if(!isIndexValid(index)) {
		std::cout << "Invalid index.\n";
		return;
	}
	for (size_t i = index; i < size - 1; ++i) {
		data[i] = data[i + 1];
	}
	--size;
}

template<typename T>
inline T DynamicArray<T>::getElementAt(size_t index) const {
	if (!isIndexValid(index))  {
		std::cout << "Invalid index.\n";
		return T();
	}
	return data[index];
}

template<typename T>
inline T& DynamicArray<T>::operator[](size_t index) const {
	if (!isIndexValid(index)) {
		std::cout << "Invalid index.\n";
		return;
	}
	return data[index];
}
	
template<typename T>
inline size_t DynamicArray<T>::getSize() const {
	return size;
}

template<typename T>
inline bool DynamicArray<T>::isEmpty() const {
	return size == 0;
}

template<typename T>
inline void DynamicArray<T>::expand() {
	capacity *= 2;
	T* buffer = new T[capacity];
	for (size_t i = 0; i < size; ++i) {
		buffer[i] = data[i];
	}
	delete[] data;
	data = buffer;
}

template<typename T>
inline void DynamicArray<T>::swap(size_t fIndex, size_t sIndex) {
	if (!isIndexValid(fIndex) || !isIndexValid(sIndex)) {
		std::cout << "Invalid index.\n";
		return;
	}
	T temp = data[fIndex];
	data[fIndex] = data[sIndex];
	data[sIndex] = temp;
}

template<typename T>
inline void DynamicArray<T>::print() const {
	for (size_t i = 0; i < size; ++i) {
		std::cout << data[i] << " ";
	}
	std::cout << std::endl;
}

template<typename T>
inline bool DynamicArray<T>::isIndexValid(size_t index) const {
	return (index >= 0 && index < size);
}

template<typename T>
inline void DynamicArray<T>::clear() {
	size = 0;
	capacity = 0;
	delete[] data;
}

template<typename T>
inline void DynamicArray<T>::copy(const DynamicArray& other) {
	capacity = other.capacity;
	size = other.size;

	data = new T[capacity];

	for (size_t i = 0; i < size; ++i) {
		data[i] = other.data[i];
	}
}

#endif // !DYNAMIC_ARRAY_HPP 
