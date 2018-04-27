#pragma once

#include "SFML\Graphics.hpp"
#include "SFML\System.hpp"

using namespace sf;

class Animation {
public:
	Animation(Sprite*, Vector2f, Vector2f);
	~Animation();
	void update(double deltaTime);
	bool hasFinished();
private:
	Sprite * m_sprite;
	Vector2f m_startPosition;
	Vector2f m_endPosition;
	bool m_finished;
	double m_elapsedTime;
	double m_duration;
};

