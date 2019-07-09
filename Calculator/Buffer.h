#pragma once

#include <iostream>
#include <cctype>

const int MAX_SIZE = 1024;

class Buffer
{
private:
	char* m_buffer;
	int m_size;
	int m_get_size();
	void m_clear_buffer();
public:
	Buffer();
	~Buffer();

	char* ReadLine();
	char* GetBuffer();
	int Size();
	bool IsNumber();
};