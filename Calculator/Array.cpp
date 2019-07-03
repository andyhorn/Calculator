#include "Array.h"

template <class T>
Array<T>::Array() {
	m_data = nullptr;
	m_capacity = 0;
}

template <class T>
Array<T>::Array(long capacity) {
	m_capacity = capacity;

	m_data = new T[capacity];
}

template <class T>
Array<T>::~Array() {
	empty();
}

template <class T>
void Array<T>::empty() {
	if (m_data != nullptr) {
		if (m_capacity > 1) {
			delete[] m_data;
		}
		else {
			delete m_data;
		}

		m_data = nullptr;
	}

	m_capacity = 0;
}

template <class T>
void Array<T>::set_size(long capacity) {
	T* temp = new T[capacity];

	for (int i = 0; i < m_capacity; i++) {
		T val = m_data[i];
		temp[i] = val;
	}

	empty();

	m_data = temp;
	m_capacity = capacity;
}

template <class T>
T* Array<T>::m_get_data() {
	return m_data;
}

template <class T>
T& Array<T>::operator[](long index){
	if (index >= 0 && index < m_capacity) {
		return m_data[index];
	}
	else {
		throw "Error: Index out of range.";
	}
}

template <class T>
void Array<T>::operator=(Array<T>& right) {
	empty();

	m_capacity = right.GetCapacity();

	T* temp = right.m_get_data();

	m_data = new T[m_capacity];

	for (int i = 0; i < m_capacity; i++) {
		T val = temp[i];
		m_data[i] = val;
	}
}

template <class T>
void Array<T>::Add(T& item) {
	if (m_data == nullptr) {
		m_data = new T[1];
		m_data[0] = item;
		m_capacity = 1;
		//m_used = 1;
		//m_available = 0;
	}
	else {
		set_size(m_capacity + 1);
		Put(item, m_capacity - 1);
	}
}

template <class T>
T& Array<T>::Get(long index) {
	return this->operator[](index);
}

template <class T>
void Array<T>::Put(T item, long index) {
	this->operator[](index) = item;
}

//template <class T>
//T Array<T>::Remove(long index) {
//	// Get a copy of the item
//	T item = this->operator[](index);
//
//	// Starting with the index of the item removed,
//	// move each item up one index in the array
//	for (int i = index; i < m_capacity - 1; i++) {
//		m_data[i] = m_data[i + 1];
//	}
//
//	// Delete the last item and decrement the 'used' counter
//	delete m_data[m_capacity - 1];
//
//	// Return the item
//	return item;
//}

template <class T>
long Array<T>::GetCapacity() {
	return m_capacity;
}