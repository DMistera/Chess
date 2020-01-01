#include "BackgroundScreen.h"

Texture* BackgroundScreen::m_texture = nullptr;

BackgroundScreen::BackgroundScreen()
{
	if (m_texture == nullptr) {
		m_texture = new Texture();
		if (!m_texture->loadFromFile("assets/background.jpg")) {
			std::cerr << "Faield to load background image!" << std::endl;
		}
	}

	m_background.setSize(Vector2f(AppConsts::getScreenWidth(), AppConsts::getScreenHeight()));
	m_background.setTexture(m_texture);
}

void BackgroundScreen::drawFrame(RenderTarget & target, RenderStates states) const
{
	target.draw(m_background);
}
