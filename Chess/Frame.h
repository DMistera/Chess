#pragma once

#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>

using namespace sf;

class Frame
{
public:
	Frame(RenderWindow*);
	~Frame();
	virtual void update(float deltaTime) = 0;
	virtual void draw() = 0;
protected:
	RenderWindow* m_renderWindow;
};

