#include "ConnectionScreen.h"



ConnectionScreen::ConnectionScreen(ServerConnection* serverConnection) 
	: m_reconnectButton(Vector2f(300.0f, 50.0f), Vector2f(AppConsts::getScreenWidth() / 2.0, 350.0f), "Reconnect")
{
	m_connection = serverConnection;
	m_text.setFont(*FontManager::getDefaultFont());
	m_text.setPosition(Vector2f(AppConsts::getScreenWidth() / 2.0, AppConsts::getScreenHeight() / 2.0f));
	m_connectThread = new std::thread(&ConnectionScreen::tryConnect, this);

	m_reconnectButton.setCallback([&]() {
		m_connectThread = new std::thread(&ConnectionScreen::tryConnect, this);
	});
}


ConnectionScreen::~ConnectionScreen()
{
}

void ConnectionScreen::drawFrame(RenderTarget & target, RenderStates states) const
{
	target.draw(m_text);
	if (m_fail) {
		target.draw(m_reconnectButton);
	}
}

void ConnectionScreen::update(float deltaTime)
{
	if (m_success) {
		m_onSuccess();
	}
	if (m_fail) {
		m_reconnectButton.update(deltaTime);
	}
	SpriteUtils::centerOrigin(&m_text);
}

void ConnectionScreen::onSuccess(std::function<void()> f)
{
	m_onSuccess = f;
}

void ConnectionScreen::tryConnect()
{
	m_fail = false;
	m_text.setString("Connecting to server...");
	if (m_connection->init()) {
		m_success = true;
	}
	else {
		m_text.setString("Failed to connect!");
		m_fail = true;
	}
}
