#include "Application.h"



Application::Application() 
{
	m_serverConnection = new ServerConnection();
	m_serverConnection->init();
	m_menu = new Menu(m_serverConnection);
	m_activeFrame = m_menu;

	m_menu->onPlayOnline([=]() {
		m_game = new Game();
		m_activeFrame = m_game;
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

