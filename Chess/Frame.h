#pragma once

#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>

using namespace sf;

class Frame : public Drawable
{
public:
	Frame();
	~Frame();
	virtual void update(float deltaTime) = 0;
};

