#include "Button.h"

Texture* Button::m_texture = nullptr;

Button::Button( Vector2f scale, Vector2f pos, String label) :
	m_rect(scale)
{
	m_scale = scale;
	m_position = pos;

	m_text.setString(label);
	m_text.setFont(*FontManager::getDefaultFont());
	m_text.setPosition(m_position - Vector2f(0.0f, 5.0f));
	m_text.setFillColor(Color(0, 0, 0));
	SpriteUtils::centerOrigin(m_text);
	m_rect.setPosition(m_position);

	if (m_texture == nullptr) {
		m_texture = new Texture();
		if (!m_texture->loadFromFile("assets/button.png")) {
			std::cerr << "Failed to load button texture!" << std::endl;
		}
	}

	m_rect.setTexture(m_texture);
	SpriteUtils::centerOrigin(m_rect);
}


Button::~Button()
{
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
			}
			m_clicked = true;
		}
	}
	else {
		m_clicked = false;
	}
}

void Button::drawFrame(RenderTarget & target, RenderStates states) const
{
	target.draw(m_rect);
	target.draw(m_text);
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
