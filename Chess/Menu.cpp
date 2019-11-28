#include "Menu.h"



Menu::Menu(ServerConnection* serverConnection)
{
	m_serverConnection = serverConnection;

	m_waitingForOpponentText = new Text();
	m_waitingForOpponentText->setFont(*FontManager::getDefaultFont());
	m_waitingForOpponentText->setString("Waiting for an opponent...");
	m_waitingForOpponentText->setPosition(Vector2f(50.0f, AppConsts::RENDER_WINDOW.getSize().y - 50.0f));
	m_waitingForOpponentText->setFillColor(Color::White);

	m_playOnlineButton = new Button(Vector2f(200, 50), Vector2f(AppConsts::RENDER_WINDOW.getSize().x/2, 50), "Play Online");
	m_playOnlineButton->setCallback([=]() {
		m_waitingForOpponentTextVisible = true;
		m_serverConnection->write("R");
		m_serverConnection->readAsync([=](String response) {
			if (response[0] == 'A') {
				m_onPlayOnline();
			}
		});
	});
}


Menu::~Menu()
{
}

void Menu::onPlayOnline(std::function<void()> f)
{
	m_onPlayOnline = f;
}

void Menu::update(float deltaTime)
{
	m_playOnlineButton->update(deltaTime);
}

void Menu::draw(RenderTarget & target, RenderStates states) const
{
	if (m_waitingForOpponentTextVisible) {
		target.draw(*m_waitingForOpponentText);
	}
	target.draw(*m_playOnlineButton);
}