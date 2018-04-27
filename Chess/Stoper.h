#pragma once

#include <chrono>

class Stoper {
public:
	Stoper();
	~Stoper();
	void start();
	void stop();
	double elapsedTime();
private:
	std::chrono::time_point<std::chrono::steady_clock> m_start;
	std::chrono::time_point<std::chrono::steady_clock> m_end;
};

