#include "Button.h"

Button::Button( Vector2f scale, Vector2f pos, String label)
{
	m_scale = scale;
	m_position = pos;

	m_text = new Text();
	m_text->setString(label);
	Font* font = FontManager::getDefaultFont();
	m_text->setFont(*font);
	m_text->setPosition(m_position);
	m_text->setFillColor(Color(0, 0, 0));
	//Center text
	FloatRect textBounds = m_text->getLocalBounds();
	m_text->setOrigin(textBounds.width / 2.0f, textBounds.height / 2.0f);

	m_rect = new RectangleShape(m_scale);
	m_rect->setPosition(m_position);
	m_rect->setOrigin(scale.x / 2.0f, scale.y / 2.0f);
}


Button::~Button()
{
	delete m_text;
	delete m_rect;
}

void Button::setCallback(std::function<void()> callback)
{
	m_callback = callback;
}

void Button::update(float deltaTime)
{
	if (Mouse::isButtonPressed(Mouse::Button::Left)) {
		if (!m_clicked) {
			Vector2i mousePos = Mouse::getPosition(AppConsts::RENDER_WINDOW);
			if (pointInside(mousePos)) {
				if (m_callback) {
					m_callback();
				}
				m_clicked = true;
			}
		}
	}
	else {
		m_clicked = false;
	}
}

void Button::draw(RenderTarget & target, RenderStates states) const
{
	target.draw(*m_rect);
	target.draw(*m_text);
}

bool Button::pointInside(Vector2i p)
{
	//std::cout << p.x << " " << p.y << std::endl;
	float w = m_scale.x / 2.0f;
	float h = m_scale.y / 2.0f;
	// Check x
	bool bx = p.x > m_position.x - w && p.x < m_position.x + w;
	// Check y
	bool by = p.y > m_position.y - h && p.y < m_position.y + h;
	return bx && by;
}
