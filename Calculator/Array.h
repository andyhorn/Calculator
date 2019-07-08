#pragma once

template <class T>
class Array {
private:
	T* m_data;
	//long m_capacity;
	long m_length;

	void empty();
	void set_size(long capacity);
protected:
	T* m_get_data();
public:
	Array();
	Array(long capacity);
	~Array();

	T& operator[](long index);
	void operator=(Array<T>& right);

	void Add(T item);
	T& Get(long index);
	void Put(T item, long index);

	//long GetCapacity();
	long Length();
};