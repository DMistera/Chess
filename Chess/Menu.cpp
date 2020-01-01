#include "Menu.h"



Menu::Menu()
{

	m_playOnlineButton = new Button(Vector2f(200, 50), Vector2f(AppConsts::RENDER_WINDOW.getSize().x/2, 50), "Play Online");
	m_playOnlineButton->setCallback([=]() {
		m_onPlayOnline();
	});
}


Menu::~Menu()
{
}

void Menu::onPlayOnline(std::function<void()> f)
{
	m_onPlayOnline = f;
}

void Menu::update(float deltaTime)
{
	m_playOnlineButton->update(deltaTime);
}

void Menu::drawFrame(RenderTarget & target, RenderStates states) const
{
	BackgroundScreen::drawFrame(target, states);
	target.draw(*m_playOnlineButton);
}