#include "Buffer.h"

Buffer::Buffer() {
	m_buffer = new char[MAX_SIZE];
	m_size = 0;
	m_clear_buffer();
}

Buffer::~Buffer() {
	delete m_buffer;
}

int Buffer::m_get_size() {
	int size = 0;
	for (int i = 0; i < MAX_SIZE; i++) {
		if (m_buffer[i] != '\0') {
			size++;
		}
		else {
			m_size = size;
			break;
		}
	}
	return size;
}

void Buffer::m_clear_buffer() {
	for (int i = 0; i < MAX_SIZE; i++) {
		m_buffer[i] = '\0';
	}
}

char* Buffer::ReadLine() {
	m_clear_buffer();
	std::cin >> m_buffer;
	m_get_size();
	return m_buffer;
}

char* Buffer::GetBuffer() {
	return m_buffer;
}

int Buffer::Size() {
	return m_size;
}

bool Buffer::IsNumber() {
	bool isNum = true;
	for (int i = 0; i < m_size; i++) {
		if (!std::isdigit(m_buffer[i])) {
			isNum = false;
			break;
		}
	}
	return isNum;
}