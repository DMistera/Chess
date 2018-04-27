#include "Stoper.h"



Stoper::Stoper() {
}


Stoper::~Stoper() {
}

void Stoper::start() {
	m_start = std::chrono::high_resolution_clock::now();
}

void Stoper::stop() {
	m_end = std::chrono::high_resolution_clock::now();
}

double Stoper::elapsedTime() {
	std::chrono::duration<double> dur = m_end - m_start;
	return dur.count();
}
