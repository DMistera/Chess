#pragma once

#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>
#include <iostream>

using namespace sf;

class Frame : public Drawable
{
public:
	Frame();
	~Frame();
	virtual void update(float deltaTime);
	virtual void drawFrame(RenderTarget & target, RenderStates states) const = 0;
	virtual void handleEvent(Event event);
	virtual void draw(RenderTarget & target, RenderStates states) const override;
protected:
	std::vector<Frame*> m_subframes;
};

