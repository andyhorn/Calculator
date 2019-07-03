#include "Array.h"

template <class T>
Array<T>::Array() {
	m_data = nullptr;
	m_capacity = 0;
	//m_used = 0;
	//m_available = 0;
}

template <class T>
Array<T>::Array(long capacity) {
	m_capacity = capacity;
	//m_used = 0;
	//m_available = capacity;

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
	//m_available = 0;
	//m_used = 0;
}

template <class T>
void Array<T>::set_size(long capacity) {
	T* temp = new T[capacity];

	for (int i = 0; i < capacity; i++) {
		temp[i] = m_data[i];
	}

	empty();

	m_data = temp;
	m_capacity = capacity;
	//m_used = count_used();
	//m_available = Available();
}

//template <class T>
//long Array<T>::count_used() {
//
//}

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
void Array<T>::operator=(T& right) {
	empty();

	m_capacity = right.Capacity();
	//m_used = right.Used();
	//m_available = right.Available();

	T* temp = right.m_get_data();

	m_data = new T[m_capacity];

	for (int i = 0; i < m_capacity; i++) {
		m_data[i] = temp[i];
	}
}

template <class T>
void Array<T>::Add(T item) {
	if (m_data == nullptr) {
		m_data = item;
		m_capacity = 1;
		//m_used = 1;
		//m_available = 0;
	}
	else {
		set_size(m_capacity + 1);
		//m_data[m_used++] = item;
		Put(item, m_capacity);
	}
}

template <class T>
T& Array<T>::Get(long index) {
	return this[index];
}

template <class T>
void Array<T>::Put(T item, long index) {
	this[index] = item;
}

template <class T>
T Array<T>::Remove(long index) {
	// Get a copy of the item
	T item = this[index];

	//T* temp = new T[m_capacity - 1];

	// Starting with the index of the item removed,
	// move each item up one index in the array
	for (int i = index; i < m_capacity - 1; i++) {
		m_data[i] = m_data[i + 1];
	}

	// Delete the last time and decrement the 'used' counter
	delete m_data[used--];

	// Return the item
	return item;
}

template <class T>
long Array<T>::GetCapacity() {
	return m_capacity;
}

//template <class T>
//long Array<T>::GetUsed() {
//	m_used = count_used();
//	return m_used;
//}
//
//template <class T>
//long Array<T>::GetAvailable() {
//	m_available = m_capacity - GetUsed();
//}