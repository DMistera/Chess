#include "TextField.h"



TextField::TextField(Vector2f position, String defaultValue)
{
	m_text.setFont(*FontManager::getDefaultFont());
	m_textStr = defaultValue;
	m_text.setString(m_textStr);
	m_text.setPosition(position);
	m_text.setFillColor(Color::Black);
	SpriteUtils::centerOrigin(m_text);

	m_background.setFillColor(Color::White);
	m_background.setPosition(position);
	m_background.setSize(Vector2f(200, 50));
	SpriteUtils::centerOrigin(m_background);
}


TextField::~TextField()
{
}


void TextField::handleEvent(Event event)
{
	if (event.type == Event::TextEntered) {
		Event::TextEvent textEvent = event.text;
		if (textEvent.unicode < 128) {
			// Backspace
			if (textEvent.unicode == 8) {
				if (m_textStr.getSize() > 0) {
					m_textStr.erase(m_textStr.getSize() - 1, 1);
				}
			}
			else {
				m_textStr += (char)textEvent.unicode;
			}
			m_text.setString(m_textStr);
			SpriteUtils::centerOrigin(m_text);
		}
	}
}

void TextField::drawFrame(RenderTarget & target, RenderStates states) const
{
	target.draw(m_background);
	target.draw(m_text);
}

String TextField::getValue()
{
	return m_textStr;
}
