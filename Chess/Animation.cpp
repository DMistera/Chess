#include "Animation.h"


Animation::Animation(Sprite * sp, Vector2f s, Vector2f e) {
	m_sprite = sp;
	m_startPosition = s;
	m_endPosition = e;
	m_finished = false;
	m_elapsedTime = 0.0;
	m_duration = 0.2;
}

Animation::~Animation() {
}

void Animation::update(double deltaTime) {
	m_elapsedTime += deltaTime;
	if (m_elapsedTime > m_duration) {
		m_finished = true;
	}
	else {
		float part = m_elapsedTime / m_duration;
		Vector2f v = m_startPosition + (m_endPosition - m_startPosition)*part;
		m_sprite->setPosition(v);
	}	
}

bool Animation::hasFinished() {
	return m_finished;
}
