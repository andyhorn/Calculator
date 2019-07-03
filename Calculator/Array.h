#pragma once

template <class T>
class Array {
private:
	T* m_data;
	long m_capacity;
	long m_used;
	long m_available;

	void empty();
	void set_size(long capacity);
	//long count_used();
protected:
	T* m_get_data();
public:
	Array();
	Array(long capacity);
	~Array();

	T& operator[](long index);
	void operator=(T& right);

	void Add(T item);
	T& Get(long index);
	void Put(T item, long index);
	T Remove(long index);

	long GetCapacity();
	//long GetUsed();
	//long GetAvailable();
};