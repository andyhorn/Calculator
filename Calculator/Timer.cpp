#include "Timer.h"

Timer::Timer() {
	m_start_time = 0;
	m_started = false;
}

void Timer::Start() {
	m_start_time = m_get_ticks();
	m_started = true;
}

int Timer::Ms() {
	if (m_started) {
		int64_t current_ticks = m_get_ticks();

		return static_cast<int>(current_ticks - m_start_time);
	}
	else {
		m_error(START_ERROR);
		return -1;
	}
}

float Timer::Seconds() {
	int milliseconds = Ms();

	return static_cast<float>(milliseconds / 1000);
}

float Timer::Minutes() {
	float seconds = Seconds();

	return seconds / 60;
}

int64_t Timer::m_get_ticks() {
	return std::chrono::duration_cast<std::chrono::milliseconds>(
		std::chrono::steady_clock::now().time_since_epoch()).count();
}

void Timer::m_error(const char* msg) {
	throw msg;
}