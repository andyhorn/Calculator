#pragma once

#include <chrono>

#define START_ERROR "Timer must be started first"

enum Time {
	MS,
	S,
	M,
	H
};

class Timer {
private:
	int64_t m_start_time;
	bool m_started;

	int64_t m_get_ticks();
	void m_error(const char* msg);
	
public:
	Timer();

	void Start();
	int Ms();
	float Seconds();
	float Minutes();
};