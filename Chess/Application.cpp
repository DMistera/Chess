#include "Application.h"



Application::Application() 
{
	m_serverConnection = new ServerConnection();

	ConnectionScreen* connectionScreen = new ConnectionScreen(m_serverConnection);
	connectionScreen->onSuccess([&]() {
		Menu* menu = new Menu();
		setActiveFrame(menu);

		menu->onPlayOnline([=]() {
			WaitingScreen* waitingScreen = new WaitingScreen(m_serverConnection);
			waitingScreen->onCancel([&]() {
				setActiveFrame(menu);
			});
			waitingScreen->onOpponentFound([&](Side localSide) {
				Game* game = new OnlineGame(m_serverConnection, localSide);
				game->initPlayers();
				game->onExit([&]() {
					setActiveFrame(menu);
					//TODO Delete game here and terminate its thread somehow
				});
				setActiveFrame(game);
			});
			setActiveFrame(waitingScreen);
		});
	});
	setActiveFrame(connectionScreen);
}


Application::~Application()
{
	delete m_serverConnection;
}

void Application::update(float deltaTime)
{
	m_activeFrame->update(deltaTime);
}

void Application::setActiveFrame(Frame * frame)
{
	m_activeFrame = frame;

}

void Application::drawFrame(RenderTarget & target, RenderStates states) const
{
	target.draw(*m_activeFrame);
}

