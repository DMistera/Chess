#include "Application.h"



Application::Application() 
{
	m_serverInputScreen = new ServerInputScreen();
	m_serverInputScreen->onAccept([&](String node) {
		m_serverConnection = new ServerConnection(node);
		m_connectionScreen = new ConnectionScreen(m_serverConnection);
		m_connectionScreen->onSuccess([&]() {
			m_menu = new Menu();
			setActiveFrame(m_menu);

			m_menu->onPlayOnline([&]() {
				m_waitingScreen = new WaitingScreen(m_serverConnection);
				m_waitingScreen->onCancel([&]() {
					setActiveFrame(m_menu);
				});
				m_waitingScreen->onOpponentFound([&](Side localSide) {
					m_game = new OnlineGame(m_serverConnection, localSide);
					m_game->initPlayers();
					m_game->onExit([&]() {
						setActiveFrame(m_menu);
					});
					setActiveFrame(m_game);
				});
				setActiveFrame(m_waitingScreen);
			});

			m_menu->onPlayLocally([&]() {
				m_game = new LocalGame();
				m_game->initPlayers();
				m_game->onExit([&]() {
					setActiveFrame(m_menu);
				});
				setActiveFrame(m_game);
			});
		});
		m_connectionScreen->onBack([&]() {
			setActiveFrame(m_serverInputScreen);
		});
		setActiveFrame(m_connectionScreen);
	});
	setActiveFrame(m_serverInputScreen);
}


Application::~Application()
{
}

void Application::setActiveFrame(Frame * frame)
{
	m_activeFrame = frame;
	if (m_subframes.size() > 0) {
		m_subframes.pop_back();
	}
	m_subframes.push_back(m_activeFrame);
}

void Application::drawFrame(RenderTarget & target, RenderStates states) const
{
	target.draw(*m_activeFrame);
}

