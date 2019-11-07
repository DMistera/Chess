#pragma once
#include "Frame.h"

using namespace sf;

class Button :
	public Frame
{
public:
	Button(RenderWindow* window, Vector2f pos);
	~Button();

	// Inherited via Frame
	virtual void update(float deltaTime) override;
	virtual void draw() override;
private:
	Vector2f m_position;
};

