#include "ConnectionScreen.h"



ConnectionScreen::ConnectionScreen(ServerConnection* serverConnection)
{
	m_connection = serverConnection;
	m_text.setFont(*FontManager::getDefaultFont());
	m_text.setPosition(Vector2f(AppConsts::getScreenWidth() / 2.0, AppConsts::getScreenHeight() / 2.0f));
	m_text.setString("Connecting to server...");
	SpriteUtils::centerOrigin(&m_text);
	m_connectThread = new std::thread(&ConnectionScreen::tryConnect, this);
}


ConnectionScreen::~ConnectionScreen()
{
}

void ConnectionScreen::draw(RenderTarget & target, RenderStates states) const
{
	target.draw(m_text);
}

void ConnectionScreen::update(float deltaTime)
{
}

void ConnectionScreen::onSuccess(std::function<void()> f)
{
	m_onSuccess = f;
}

void ConnectionScreen::tryConnect()
{
	if (m_connection->init()) {
		m_onSuccess();
	}
	else {
		m_text.setString("Failed to connect!");
	}
}
