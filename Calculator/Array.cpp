#include "Array.h"

template <class T>
Array<T>::Array() {
	m_data = nullptr;
	//m_capacity = 0;
	m_length = 0;
}

template <class T>
Array<T>::Array(long length) {
	//m_capacity = capacity;
	m_length = length;

	m_data = new T[length];
}

template <class T>
Array<T>::~Array() {
	empty();
}

template <class T>
void Array<T>::empty() {
	if (m_data != nullptr) {
		if (m_length > 1) {
			delete[] m_data;
		}
		else {
			delete m_data;
		}

		m_data = nullptr;
	}

	m_length = 0;
}

template <class T>
void Array<T>::set_size(long length) {
	T* temp = new T[length];

	for (int i = 0; i < m_length; i++) {
		T val = m_data[i];
		temp[i] = val;
	}

	empty();

	m_data = temp;
	m_length = length;
}

template <class T>
T* Array<T>::m_get_data() {
	return m_data;
}

template <class T>
T& Array<T>::operator[](long index) {
	if (index >= 0 && index < m_length) {
		return m_data[index];
	}
	else {
		throw "Error: Index out of range.";
	}
}

template <class T>
void Array<T>::operator=(Array<T>& right) {
	empty();

	//m_capacity = right.GetCapacity();
	m_length = right.Length();

	T* temp = right.m_get_data();

	m_data = new T[m_length];

	for (int i = 0; i < m_length; i++) {
		T val = temp[i];
		m_data[i] = val;
	}
}

template <class T>
void Array<T>::Add(T item) {
	if (m_data == nullptr) {
		m_data = new T[1];
		m_data[0] = item;
		m_length = 1;
	}
	else {
		set_size(m_length + 1);
		Put(item, m_length - 1);
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
//long Array<T>::GetCapacity() {
//	return m_capacity;
//}

template <class T>
long Array<T>::Length() {
	return m_length;
}