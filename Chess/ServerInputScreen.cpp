#include "ServerInputScreen.h"



ServerInputScreen::ServerInputScreen()
	: m_textField(Vector2f(200, 150), "127.0.0.1"),
	m_acceptButton(Vector2f(200, 50), Vector2f(200, 250), "Accept")
{

	m_label.setFont(*FontManager::getDefaultFont());
	m_label.setPosition(200, 50);
	m_label.setString("Insert IP address");
	SpriteUtils::centerOrigin(m_label);

	m_subframes.push_back(&m_textField);
	m_subframes.push_back(&m_acceptButton);

	m_acceptButton.setCallback([&]() {
		m_onAccept(m_textField.getValue());
	});

}


ServerInputScreen::~ServerInputScreen()
{
}

void ServerInputScreen::onAccept(std::function<void(String)> f)
{
	this->m_onAccept = f;
}

void ServerInputScreen::drawFrame(RenderTarget & target, RenderStates states) const
{
	BackgroundScreen::drawFrame(target, states);
	target.draw(m_label);
	target.draw(m_textField);
	target.draw(m_acceptButton);
}
