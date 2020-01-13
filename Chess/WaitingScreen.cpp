#include "WaitingScreen.h"



WaitingScreen::WaitingScreen(ServerConnection* connection)
{
	m_waitingForOpponentText = new Text();
	m_waitingForOpponentText->setFont(*FontManager::getDefaultFont());
	m_waitingForOpponentText->setString("Waiting for an opponent...");
	m_waitingForOpponentText->setPosition(Vector2f(AppConsts::getScreenWidth()/2.0f, 50.0f));
	m_waitingForOpponentText->setFillColor(Color::White);
	SpriteUtils::centerOrigin(*m_waitingForOpponentText);

	m_cancelButton = new Button(Vector2f(200, 50), Vector2f(AppConsts::getScreenWidth() / 2.0f, 150.0f), "Cancel");
	m_cancelButton->setCallback([=]() {
		connection->unreadAsync(m_readCallbackIndex);
		connection->write("C");
		m_onCancel();
	});

	m_readCallbackIndex = connection->readAsync([=](String msg) {
		if (msg[0] == 'A') {
			char sideID = msg[1];
			Side localSide;
			if (msg[1] == 'B') {
				localSide = Side::BLACK;
			}
			else if (msg[1] == 'W') {
				localSide = Side::WHITE;
			}
			else {
				std::cerr << "Invalid accept message (this should not happen)!" << std::endl;
			}
			if (m_onOpponentFound) {
				m_onOpponentFound(localSide);
			}
		}
	});

	connection->write("R");
}


WaitingScreen::~WaitingScreen()
{
}

void WaitingScreen::onOpponentFound(std::function<void(Side)> f)
{ 
	m_onOpponentFound = f;
}

void WaitingScreen::onCancel(std::function<void()> f)
{
	m_onCancel = f;
}

void WaitingScreen::drawFrame(RenderTarget & target, RenderStates states) const
{
	BackgroundScreen::drawFrame(target, states);
	target.draw(*m_waitingForOpponentText);
	target.draw(*m_cancelButton);
}

void WaitingScreen::update(float deltaTime)
{
	m_cancelButton->update(deltaTime);
}
