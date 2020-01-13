#include "Menu.h"



Menu::Menu() :
	m_playOnlineButton(Vector2f(200, 50), Vector2f(AppConsts::RENDER_WINDOW.getSize().x / 2, 50), "Play Online"),
	m_playLocallyButton(Vector2f(200, 50), Vector2f(AppConsts::RENDER_WINDOW.getSize().x / 2, 150), "Play Locally")
{
	m_playOnlineButton.setCallback([=]() {
		m_onPlayOnline();
	});

	m_playLocallyButton.setCallback([=]() {
		m_onPlayLocally();
	});

	m_subframes.push_back(&m_playOnlineButton);
	m_subframes.push_back(&m_playLocallyButton);
}


Menu::~Menu()
{
}

void Menu::onPlayOnline(std::function<void()> f)
{
	m_onPlayOnline = f;
}

void Menu::onPlayLocally(std::function<void()> f)
{
	m_onPlayLocally = f;
}

void Menu::drawFrame(RenderTarget & target, RenderStates states) const
{
	BackgroundScreen::drawFrame(target, states);
	target.draw(m_playOnlineButton);
	target.draw(m_playLocallyButton);
}