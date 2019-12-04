#include "Application.h"



Application::Application() 
{
	m_serverConnection = new ServerConnection();

	ConnectionScreen* connectionScreen = new ConnectionScreen(m_serverConnection);
	connectionScreen->onSuccess([&]() {
		Menu* menu = new Menu();
		m_activeFrame = menu;

		menu->onPlayOnline([=]() {
			WaitingScreen* waitingScreen = new WaitingScreen(m_serverConnection);
			waitingScreen->onCancel([&]() {
				m_activeFrame = menu;
			});
			waitingScreen->onOpponentFound([&](Side localSide) {
				Game* game = new OnlineGame(m_serverConnection, localSide);
				game->initPlayers();
				game->onExit([&]() {
					m_activeFrame = menu;
					//TODO Delete game here and terminate its thread somehow
				});
				m_activeFrame = game;
			});
			m_activeFrame = waitingScreen;
		});
	});
	m_activeFrame = connectionScreen;
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

