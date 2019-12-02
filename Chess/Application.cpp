#include "Application.h"



Application::Application() 
{
	m_serverConnection = new ServerConnection();
	m_serverConnection->init();
	m_menu = new Menu();
	m_activeFrame = m_menu;

	m_menu->onPlayOnline([=]() {
		WaitingScreen* waitingScreen = new WaitingScreen(m_serverConnection);
		waitingScreen->onCancel([=]() {
			m_activeFrame = m_menu;
		});
		waitingScreen->onOpponentFound([=](Side localSide) {
			m_game = new OnlineGame(m_serverConnection, localSide);
			m_game->initPlayers();
			m_game->onExit([&]() {
				m_activeFrame = m_menu;
				//TODO Delete game here and terminate its thread somehow
			});
			m_activeFrame = m_game; 
		});
		m_activeFrame = waitingScreen;
	});
}


Application::~Application()
{
	delete m_serverConnection;
}

void Application::update(float deltaTime)
{
	m_activeFrame->update(deltaTime);
}

void Application::draw(RenderTarget & target, RenderStates states) const
{
	target.draw(*m_activeFrame);
}

