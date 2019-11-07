#include "Menu.h"



Menu::Menu(RenderWindow* renderWindow) : Frame(renderWindow)
{
	m_playOnlineButton = new Button(renderWindow, Vector2f(10, 10));
}


Menu::~Menu()
{
}

void Menu::update(float deltaTime)
{
}

void Menu::draw()
{
	m_playOnlineButton->draw();
}
