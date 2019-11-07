#include "Application.h"



Application::Application(RenderWindow * renderwindow) : Frame(renderwindow)
{
	m_menu = new Menu(renderwindow);
	m_game = new Game(renderwindow);
	m_activeFrame = m_menu;
}


Application::~Application()
{
}

void Application::update(float deltaTime)
{
	m_activeFrame->update(deltaTime);
}

void Application::draw()
{
	m_activeFrame->draw();
}
