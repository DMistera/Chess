#include "Button.h"

Button::Button(RenderWindow* window, Vector2f pos) : Frame(window)
{
	m_position = pos;
}


Button::~Button()
{
}

void Button::update(float deltaTime)
{
}

void Button::draw()
{
	RectangleShape rect(m_position);
	rect.setPosition(m_position);
	m_renderWindow->draw(rect);
}
